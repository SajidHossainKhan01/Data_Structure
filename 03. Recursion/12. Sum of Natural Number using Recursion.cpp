#include <stdio.h>

// RECURSIVE sum of first n natural numbers
int sum(int n) {
    if (n == 0)
        return 0;
    else
        return sum(n - 1) + n;
}

// ITERATIVE sum of first n natural numbers
int isum(int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s = s + i;
    }
    return s;
}

int main() {
    int r;

    r = sum(5);       // recursive
    printf("%d\n", r);   // Output: 15

    r = isum(5);      // iterative
    printf("%d\n", r);   // Output: 15

    return 0;
}
```

---

**Tracing `sum(5)` — Recursive:**
```
sum(5) = sum(4) + 5
sum(4) = sum(3) + 4
sum(3) = sum(2) + 3
sum(2) = sum(1) + 2
sum(1) = sum(0) + 1
sum(0) = 0

Returning:
0 + 1 = 1
1 + 2 = 3
3 + 3 = 6
6 + 4 = 10
10 + 5 = 15 ✓
```

**Tracing `isum(5)` — Iterative:**
```
i=1: s = 0 + 1 = 1
i=2: s = 1 + 2 = 3
i=3: s = 3 + 3 = 6
i=4: s = 6 + 4 = 10
i=5: s = 10 + 5 = 15 ✓