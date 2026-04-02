#include <stdio.h>

// VERSION 1 — Normal recursion (no static/global)
int fun(int n) {
    if (n > 0)
        return fun(n - 1) + n;
    return 0;
}

// VERSION 2 — With static variable
int fun_static(int n) {
    static int x = 0;       // single copy, initialized only once
    if (n > 0) {
        x++;
        return fun_static(n - 1) + x;
    }
    return 0;
}

// VERSION 3 — With global variable
int x = 0;                  // global, accessible to all functions

int fun_global(int n) {
    if (n > 0) {
        x++;
        return fun_global(n - 1) + x;
    }
    return 0;
}

int main() {
    int r;

    // Version 1
    r = fun(5);
    printf("%d\n", r);          // Output: 15

    // Version 2
    r = fun_static(5);
    printf("%d\n", r);          // Output: 25

    // Version 3 — called TWICE to show global side effect
    r = fun_global(5);
    printf("%d\n", r);          // Output: 25  (x goes from 0 to 5)

    r = fun_global(5);
    printf("%d\n", r);          // Output: 50  (x goes from 5 to 10)

    return 0;
}
```

---

**Why second call to `fun_global(5)` gives 50:**
```
First call:   x starts at 0 → increments to 5 → adds 5 five times = 25
Second call:  x starts at 5 → increments to 10 → adds 10 five times = 50