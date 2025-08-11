---
title: Exit status and echo $?
lang_tags: "#lang/c #lang/bash"
type_tags: "#type/lecture"
course_tags: "#course/cs50x/intoduction_to_CS"
lecture_tags: "#lecture/week_2_Arrays"
tool_tags: "#tool/shell/bash #tool/os/linux"
atom_idx: 3
status: done
difficulty: easy
date: 2025-08-11
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/2/
review_next: ""
---

  

---

  

// Место для фото материалов

  

![[2025-08-01_15-07-54.png]]

  

---
## Summary

Every Unix process returns an **exit status** (0–255). The **shell** stores the last one in **$?**; printing it with **echo $?** shows whether the previous command **succeeded (0)** or **failed (non‑zero)**. In C, **return** from **main** (or calling **exit(...)**) sets that status.

  

## Key Points

- **0 = success**, **non‑zero = error/special condition** — lets scripts branch reliably.

- The variable **$?** always holds the **previous command’s** exit code.

- In C, `return code;` from **main** or `exit(code);` sets the **process exit status**.

- Many shells follow the convention **128 + signal** (e.g., 130 = **SIGINT**, 137 = **SIGKILL**).

- Exit codes are **one byte**; values outside 0–255 get **truncated modulo 256** by the OS.

  

## Details

A program signals its outcome via an **exit status**. The **shell** reads that status and stores it in **$?**. This is the glue that makes **pipelines**, **Makefiles**, and **CI** behave: commands can be chained with `&&` / `||`, and scripts can check outcomes without parsing text.

  

Common conventions you’ll see in Unix-y environments:

- **1** — generic error (bad args, missing file, validation failed).

- **2** — shell misuse (per Bash docs).

- **126** — command invoked but **not executable** (permissions/format).

- **127** — **command not found** (typo/`$PATH`).

- **130** — terminated by **Ctrl‑C** (**SIGINT**).

- **≥128** — exited due to a **signal** (**128 + signal number**).

  

None of these are hard standards, but they’re widely used and safe to rely on in scripts.

  

## Examples

  

### C demo (`status.c`)

```c

#include <cs50.h>

#include <stdio.h>

#include <stdlib.h>

  

int main(int argc, string argv[])

{

    if (argc != 2)

    {

        printf("Missing command-line argument\n");

        return 1;                 // non-zero → shell sees failure

    }

  

    printf("hello, %s\n", argv[1]);

    return 0;                     // zero → success

}

```

  

### Shell runs

```

$ ./status David

hello, David

$ echo $?

0                 # previous command succeeded

  

$ ./status

Missing command-line argument

$ echo $?

1                 # our program signaled an error

```

  

### Using it in scripts

```

./build && ./deploy || echo "deploy failed with code $?"

if ./check; then echo "OK"; else echo "not OK (code $?)"; fi

```

  

## **Why It Matters**

Exit statuses let you write **composable**, **robust** automation: CI/CD pipelines, `make` rules, and shell scripts make decisions based on precise **return codes** instead of fragile string matching.

  

## Questions

- What code should this tool use for **validation errors vs runtime failures**?

- Do we need to **reserve** specific codes (e.g., 64–78 like BSD `sysexits.h`) for clarity?

  

## Related Concepts

- [[Command-line arguments]] – ties into how programs receive inputs that determine **exit status** paths.

- [[Command Line Flags Cheat Sheet]] – parsing **flags** often decides which **return code** to emit.

- [[Signals in Unix]] – explains why codes ≥128 map to **signals**.

- [[Return vs exit in C]] – difference between `return` from **main** and `exit(...)`.

- [[Process termination (C runtime)]] – what actually happens when a process **exits**.

  

## See also

- [[Command-line arguments]]

- [[Command Line Flags Cheat Sheet]]

- [Bash Reference Manual — Exit Status]({{https://www.gnu.org/software/bash/manual/bash.html#Exit-Status}})

- [Bash — Special Parameters (`$?`)]({{https://www.gnu.org/software/bash/manual/bash.html#Special-Parameters}})

- [glibc `exit(3)` man page]({{https://man7.org/linux/man-pages/man3/exit.3.html}})

  

## Terms

[[$?]], [[exit status]], [[return code]], [[shell]], [[main]], [[exit(3)]], [[signal]], [[SIGINT]], [[SIGKILL]]