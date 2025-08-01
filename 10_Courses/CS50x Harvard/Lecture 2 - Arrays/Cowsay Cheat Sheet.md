
![[2025-08-01_14-56-01 1.png]]
  

> **Lecture reference:** [[Lecture 2 - Arrays]]

> **Course:** [[CS50x Harvard]]

---

## **What is cowsay?**

  

A fun CLI program that prints **ASCII art** animals “saying” your text in a speech bubble.

Great for demos and for practicing command-line flags.

---

## **Install**

```
# macOS (Homebrew)
brew install cowsay

# Ubuntu/Debian
sudo apt-get update && sudo apt-get install cowsay

# Fedora
sudo dnf install cowsay

# Windows
# Use WSL and install via your Linux distro's package manager
```

---

## **Basic usage**

```
cowsay "Hello, world!"
```

Pipe input:

```
echo "RAWR" | cowsay
```

---

## **Choose an animal with -f**

```
# Default cow (no -f needed)
cowsay "Moo"

# Dragon
cowsay -f dragon "RAWR"

# Duck
cowsay -f duck "quack"

# Penguin (Tux)
cowsay -f tux "Linux!"
```

List available figures (“cowfiles”):

```
cowsay -l
```

> Tip: Figures live in “cowfiles.” Your list may include cow, dragon, duck, tux, ghostbusters, stegosaurus, turkey, etc.

---

## **Customize the face**

```
# Eyes (-e) and tongue (-T)
cowsay -e "OO" -T "U " "Spooked!"
cowsay -e "^^" -T "~~" -f dragon "Beware"
```

Common eye presets:

- -e "oo" (default), -e "OO", -e "^^", -e "--", -e "xx"
    

  

Tongue examples:

- -T "  " (none), -T "U ", -T "~~"
    

---

## **Wrapping and formatting**

```
# Wrap at 40 columns (default is 40 on many builds)
cowsay -W 40 "A very long message that should wrap nicely."

# Do not wrap (print as a single line)
cowsay -n "I will not be wrapped."
```

---

## **Thinking instead of speaking**

```
cowthink "Hmm… arrays decay to pointers."
cowthink -f duck "Quack, but thoughtfully."
```

---

## **Using with other programs**

```
fortune | cowsay -f dragon
dmesg | tail -n 5 | cowsay -f duck
```

---

## **Extend with custom cowfiles**

  

Place your .cow files in a directory and set COWPATH:

```
export COWPATH="$HOME/.cowfiles"
cowsay -f mylogo "Branding!"
```

---

## **Quick reference**

|**Flag**|**Meaning**|**Example**|
|---|---|---|
|-f|Choose figure (cowfile)|cowsay -f dragon "RAWR"|
|-l|List available figures|cowsay -l|
|-e|Eye characters (2 chars)|cowsay -e "^^" "Hi"|
|-T|Tongue (2 chars)|cowsay -T "U " "Bleh"|
|-W|Wrap width|cowsay -W 60 "Long text"|
|-n|No wrap|cowsay -n "One long line"|

---

### **TL;DR**

- cowsay "text" prints a cow.
    
- -f dragon / -f duck swap the animal.
    
- -e and -T customize the face; -W controls wrapping.
    
- Pipe anything in (echo, fortune, logs) for instant ASCII vibes. 🐄 🐉 🦆