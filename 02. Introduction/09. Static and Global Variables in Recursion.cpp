#include <stdio.h>

// VERSION 1 — Without static variable (uses local n)
int fun(int n) {
    if (n > 0) {
        return fun(n - 1) + n;  // adds n at RETURNING time
    }
    return 0;
}

// VERSION 2 — With static variable
int fun_static(int n) {
    static int x = 0;           // single copy, created only once
    if (n > 0) {
        x++;                    // increments at CALLING time
        return fun_static(n - 1) + x;  // adds x at RETURNING time
    }
    return 0;
}

int main() {
    int a = 5;

    printf("Without static: %d\n", fun(a));         // Output: 15
    printf("With static:    %d\n", fun_static(a));  // Output: 25

    return 0;
}
```

---

**Tracing Version 1 — `fun(5)` (local `n`):**
```
fun(5) = fun(4) + 5
fun(4) = fun(3) + 4
fun(3) = fun(2) + 3
fun(2) = fun(1) + 2
fun(1) = fun(0) + 1
fun(0) = 0

Returning:
0 + 1 = 1
1 + 2 = 3
3 + 3 = 6
6 + 4 = 10
10 + 5 = 15  ✓
```

---

**Tracing Version 2 — `fun_static(5)` (single copy of `x`):**
```
CALLING phase (x increments each call):
fun(5) → x=1
fun(4) → x=2
fun(3) → x=3
fun(2) → x=4
fun(1) → x=5
fun(0) → returns 0   (x stays 5, no more increments)

RETURNING phase (x is now 5 for ALL calls):
0 + 5 = 5
5 + 5 = 10
10 + 5 = 15
15 + 5 = 20
20 + 5 = 25  ✓