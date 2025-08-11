---
title: Arithmetic Operators in C
lang_tags: "#lang/c"
type_tags: "#type/cheatsheet"
course_tags: "#course/cs50x/introduction_to_CS"
lecture_tags: "#shorts/week_1_C/operators"
tool_tags: ""
atom_idx: 2
status: done
difficulty: easy
date: 2025-08-11
timecode: ""
source: https://cs50.harvard.edu/x/2025/weeks/1/
review_next: ""
---
  

![[Screenshot 2025-07-17 at 10.57.20.png]]

---

## **One-liner**

  

Quick reference to C’s arithmetic operators — + - * / % plus *_\unary*_ sign and **\increment**/**\decrement** — with rules for **\integer division*_, **\truncation*_, and **\operator precedence**.

  

## **Common Commands / Syntax**

|**Operation**|**Expression**|**Meaning**|**Notes**|
|---|---|---|---|
|Add|x + y|Sum|Also works on float/double.|
|Subtract|x - y|Difference|Unary -x flips sign (**\unary minus**).|
|Multiply|x * y|Product|Same precedence tier as / and %.|
|Divide (ints)|x / y|Quotient|*_\Integer division*_ truncates toward zero: 6/4 -> 1, -6/4 -> -1. **Divide by 0** → **\undefined behavior**.|
|Divide (floats)|a / b|Floating quotient|If either operand is float/double, use floating division: 6.0/4 -> 1.5.|
|Remainder|x % y|Remainder of integer division|Integers only. Sign follows **dividend**: -7 % 3 == -1. % 0 → **UB**. For floats use fmod(a,b) from <math.h>.|
|Increment|i++, ++i|Add 1|Both add 1; **postfix** (i++) yields old value, **prefix** (++i) yields new value.|
|Decrement|i--, --i|Subtract 1|Same prefix/postfix rule.|
|Grouping|( … )|Force order|Parentheses beat precedence.|
|Cast to float|(double)x / y|Prevent truncation|Forces *_\type promotion*_ to floating division.|

> Precedence (high → low, excerpt): **unary** + - ++ -- → * / % → + -. When in doubt, add parentheses.

  

## **Frequently Used Patterns**

- **Even/odd check:** if (n % 2 == 0) { /* even */ }
    
- **Round-robin index:** i = (i + 1) % n;
    
- **Safe integer division:** if (y != 0) q = x / y;
    
- **Avoid truncation:** double avg = (double)sum / count;
    
- **Float remainder:** double r = fmod(a, b);  // <math.h>
    

  

## **Shortcuts**

- **i++ vs ++i:** Both add 1; choose prefix in complex expressions to avoid surprises.
    
- **Compound assign (see separate note):** x += y, x -= y, x *= y, x /= y, x %= y.
    

  

## **Tips & Gotchas**

- *_\Integer division*_ drops the fractional part; it does **not** round.
    
- % works **only** on integer types. For floats, use **\fmod**.
    
- *_\Signed overflow*_ is **undefined behavior**; **unsigned** wraps modulo 2^N.
    
- **\Usual arithmetic conversions**: smaller integer types (char, short) promote to int; if one operand is double, the other is converted to double.
    
- Always parenthesize when mixing * / % with + - to make intent explicit.
    

  

## **Examples**

```
#include <stdio.h>
#include <math.h>

int main(void) {
    int x = 6, y = 4;
    double a = 6.0, b = 4.0;

    printf("%d + %d = %d\n", x, y, x + y);           // 10
    printf("%d - %d = %d\n", x, y, x - y);           // 2
    printf("%d * %d = %d\n", x, y, x * y);           // 24
    printf("%d / %d = %d\n", x, y, x / y);           // 1 (truncates)
    printf("%d %% %d = %d\n", x, y, x % y);          // 2

    printf("%.1f / %.1f = %.2f\n", a, b, a / b);     // 1.50
    printf("-7 %% 3 = %d\n", -7 % 3);                // -1 (sign of dividend)

    int i = 5;
    printf("i++ -> %d\n", i++);  // prints 5, i becomes 6
    printf("++i -> %d\n", ++i);  // i becomes 7, prints 7

    return 0;
}
```

## **Related Concepts**

- [[Arithmetic Shorthand Operators in C]] – companion note for +=, -=, *=, /=, %=.
    
- [[Operator Precedence in C]] – how expressions bind and evaluate.
    
- [[Integer Division and Modulo in C]] – edge cases, negatives, and %.
    
- [[Casting in C]] – controlling *_\type promotion*_ and conversions.
    
- [[Printf Format Specifiers]] – printing ints vs floats correctly.
    
- [[Char Type in C]] – integer promotions from smaller types.
    
- [[C Type Sizes and Memory]] – overflow implications for integer math.
    

  

## **See Also**

- [C operator precedence (cppreference)](https://en.cppreference.com/w/c/language/operator_precedence)
    
- [Usual arithmetic conversions (cppreference)](https://en.cppreference.com/w/c/language/conversion)
    
- [CS50 Shorts: Operators](https://cs50.harvard.edu/x/2025/shorts/operators/)
    

  

## **Terms**

  

[[operator precedence]], [[integer division]], [[truncation]], [[remainder operator]], [[increment operator]], [[decrement operator]], [[unary operator]], [[binary operator]], [[type promotion]], [[cast]], [[undefined behavior]], [[overflow]], [[fmod]]