![[2025-08-01_14-56-01 2.png]]

> **Lecture reference:** [[Lecture 2 - Arrays]]

> **Course:** [[CS50x Harvard]]

---

## **Install (macOS Homebrew example)**

```
brew install cowsay
```

After a successful pour you’ll see something like:

```
🍺  /opt/homebrew/Cellar/cowsay/3.8.4: 62 files, 91.7KB
```

---

## **Listing available “cowfiles”**

```
cowsay -l
```

Typical Homebrew build (v 3.8.4) ships **40+ figures**, e.g.:

```
actually  alpaca  beavis.zen  default  dragon
fox       ghostbusters  kitty  luke-koala  stegosaurus
tux       vader        www   …
```

> **Notice:** There is **no duck cowfile** in the default set, so

```
cowsay -f duck "quack"
```

> returns

> cowsay: Could not find cowfile for 'duck'!

---

## **Basic usage examples**

|**Figure**|**Command**|**Output snapshot**|
|---|---|---|
|**Default cow**|cowsay "Moo"|^__^ cow art|
|**Dragon**|cowsay -f dragon "RAWR"|ASCII dragon breathing fire|
|**Tux (penguin)**|cowsay -f tux "Linux!"|Penguin with speech bubble|

### **Example: Dragon**

```
cowsay -f dragon "RAWR"
```

```
 ______
< RAWR >
 ------
      \                    / \  //\
       \    |\___/|      /   \//  \\
       … (dragon ASCII) …
```

---

## **Common flags**

| **Flag**     | **Purpose**                      | **Example**                 |
| ------------ | -------------------------------- | --------------------------- |
| -f <cowfile> | Choose figure                    | cowsay -f dragon "Hi"       |
| -l           | List available figures           | cowsay -l                   |
| -e XX        | Set eyes (2 chars)               | cowsay -e "^^" "Wow"        |
| -T YY        | Set tongue (2 chars)             | cowsay -T "U "              |
| -W N         | Wrap text at _N_ columns         | cowsay -W 60 "Long message" |
| -n           | Disable wrapping                 | cowsay -n "No wrap"         |
| **cowthink** | Thought bubble instead of speech | cowthink "hmm…"             |

---

## **Quoting gotchas**

- **Symptom:** prompt shows dquote> and appears “stuck.”
    
    **Cause:** you opened a double-quote but never closed it.
    
    **Fix:** press Ctrl-C to cancel, then re-run with matching quotes:
    

```
# WRONG – missing the closing "
cowsay "Hello, world!

# RIGHT
cowsay "Hello, world!"
```

---

## **Extending cowsay**

1. **Add cowfiles**
    
    Place custom .cow files in a directory and set COWPATH:
    

```
export COWPATH="$HOME/.cowfiles"
cowsay -f mylogo "Branding!"
```

1.   
    
2. **Pipe other programs**
    

```
fortune | cowsay -f dragon
dmesg | tail -5 | cowsay
```

  

---

### **TL;DR**

- cowsay "<text>" → ASCII cow.
    
- -f <figure> chooses another animal; use cowsay -l to see what’s installed.
    
- Homebrew’s default set **doesn’t include duck**; pick dragon, tux, etc. instead.
    
- Watch your quotes—unmatched " drops you into the dquote> prompt.
- 