---
title: "{{Topic}} Hub (Auto)"
tags: [MOC, index, auto]
note_type: moc
# Скоуп индексации: folder (по умолчанию) | vault | tag
scope: folder
scope_tag: ""   # если scope: tag, укажи без решётки, напр. "algorithms"
---


```
---
title: "{{Topic}} Hub (Auto)"
tags: [MOC, index, auto]
note_type: moc
# Скоуп индексации: folder (по умолчанию) | vault | tag
scope: folder
scope_tag: ""   # если scope: tag, укажи без решётки, напр. "algorithms"
---
```


# {{Topic}} Hub — авто-оглавление

> Требуется плагин **Dataview**. Включать не надо — достаточно иметь его установленным.

## Index

```dataviewjs
// ===== Zero-config Auto MOC =====
const here = dv.current().file;
const fm = dv.current().frontmatter ?? {};
const scope = (fm.scope ?? "folder").toString().toLowerCase();   // folder | vault | tag
const scopeTag = (fm.scope_tag ?? "").toString().trim();

function inScope(p) {
  if (scope === "vault") return true;
  if (scope === "tag" && scopeTag) {
    const tag = ("#" + scopeTag).toLowerCase();
    return (p.file.tags ?? []).some(t => t.toLowerCase() === tag);
  }
  return p.file.folder.startsWith(here.folder);
}

// Базовый пул заметок в скоупе, без самого MOC и без шаблонов/архива
let pages = dv.pages()
  .where(p => p.file.path !== here.path)
  .where(p => inScope(p))
  .where(p => !/\/(97_Templates|Templates|99_Archive)\//i.test(p.file.path));

// Утилиты
const lower = v => (v ?? "").toString().toLowerCase();

// Авто-бакеты по твоим полям из шаблонов
const concepts = pages.where(p => lower(p.type_tags).includes("concept"));
const lectures = pages.where(p => lower(p.type_tags).includes("lecture") || lower(p.lecture_tags).length > 0);
const atoms    = pages.where(p => p.atom_idx != null);

// Сводка
dv.paragraph(`В области: **${pages.length}** заметок — концептов: **${concepts.length}**, лекций: **${lectures.length}**, атомов: **${atoms.length}**.`);

// Концепты
dv.header(2, "Концепты");
dv.table(["Note","Status","Difficulty","Updated"],
  concepts
    .sort(p => p.title ?? p.file.name, 'asc')
    .map(p => [p.file.link, p.status ?? "", p.difficulty ?? "", p.file.mtime?.toFormat?.("yyyy-LL-dd") ?? ""])
);

// Лекции по курсам
dv.header(2, "Лекции по курсам");
for (const group of lectures.groupBy(p => p.course_tags ?? "—")) {
  dv.header(3, group.key);
  dv.table(["Lecture","Date","Status"],
    group.rows
      .sort(p => p.date ?? p.file.ctime, 'asc')
      .map(p => [p.file.link, (p.date ?? p.file.cday)?.toFormat?.("yyyy-LL-dd") ?? "", p.status ?? ""])
  );
}

// Лекционные атомы (по источнику/папке), сортируем по порядковому номеру
dv.header(2, "Лекционные атомы");
for (const group of atoms.groupBy(p => p.source ?? p.file.folder)) {
  dv.header(3, group.key);
  dv.table(["Atom","№","Date"],
    group.rows
      .sort(p => p.atom_idx ?? 0, 'asc')
      .map(p => [p.file.link, p.atom_idx ?? "", (p.date ?? p.file.cday)?.toFormat?.("yyyy-LL-dd") ?? ""])
  );
}

// Недавно обновлённые
dv.header(2, "Недавно обновлённые");
dv.list(pages.sort(p => p.file.mtime, 'desc').slice(0, 15).map(p => p.file.link));

// Сироты (без входящих ссылок)
dv.header(2, "Сироты (нет входящих ссылок)");
dv.list(pages.where(p => (p.file.inlinks ?? []).length === 0).map(p => p.file.link));

// Популярные теги (совместимо; без dv.func.tag)
dv.header(2, "Популярные теги");
const tagCounts = {};
for (const p of pages) for (const t of (p.file.tags ?? [])) {
  tagCounts[t] = (tagCounts[t] ?? 0) + 1;
}
const topTags = Object.entries(tagCounts)
  .sort((a, b) => b[1] - a[1])
  .slice(0, 20)
  .map(([t, c]) => [t, c]);   // просто текст тега

dv.table(["Tag", "Count"], topTags);

// Полный список
dv.header(2, "Полный список");
dv.list(pages.sort(p => p.file.name, 'asc').map(p => p.file.link));

```



