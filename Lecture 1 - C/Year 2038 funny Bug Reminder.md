

  

> [[Lecture 1 - C]] · [[CS50x Harvard]]

---

## **What happens on 19 Jan 2038?**

  

On Tuesday, **19 January 2038 @ 03:14:07 UTC**, a 32-bit signed time_t will roll over from 2 147 483 647 to –2 147 483 648 … and many old systems will think it’s **13 December 1901**.

Y2K’s grumpy little sibling is coming for embedded devices, forgotten servers, and that dusty router still running a 2004 kernel.

---

## **David Malan’s challenge**

  

> “Set a Google Calendar reminder for January 19, 2038.”

>   

> —Week 1, CS50 2025

  

Because what’s better than scheduled panic 13 years in advance?

---

## **Should I actually worry?**

|**Device / System**|**Risk level**|**Why**|
|---|---|---|
|Modern 64-bit OS (macOS, Linux)|😎 Low|Uses 64-bit time_t by default.|
|Old 32-bit embedded gear|🔥 High|Hard-coded 32-bit time counters.|
|Financial / archival DBs|🤨 Medium|Legacy backups, off-site appliances.|

---

## **Survival kit**

- **Audit legacy code**: grep for time_t, gmtime, custom epoch math.
    
- **Update firmware** on anything older than your cat.
    
- **Virtual machines**: snapshot & test booting beyond 2038.
    
- **Party plan**: cake, duck (inflatable), and a CS50 livestream at 03:14 UTC.
    

---

### **Quick demo (C)**

```
#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t t = 2147483647; // 19 Jan 2038 03:14:07 UTC
    printf("%s", ctime(&t));
    t++;
    printf("%s", ctime(&t)); // uh-oh on 32-bit!
}
```

Run this on a 32-bit system and watch the clock fall back to 1901.

Run it on 64-bit and everything’s chill.

---

**Mark your calendars**—and maybe your source code—before the clock strikes 2038.