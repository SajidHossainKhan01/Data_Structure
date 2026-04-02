#include <stdio.h>

// RECURSIVE factorial
int fact(int n) {
    if (n == 0)
        return 1;
    else
        return fact(n - 1) * n;
}

// ITERATIVE factorial
int ifact(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) {
        f = f * i;
    }
    return f;
}

int main() {
    int r;

    r = fact(5);
    printf("%d\n", r);    // Output: 120

    r = fact(4);
    printf("%d\n", r);    // Output: 24

    r = fact(0);
    printf("%d\n", r);    // Output: 1

    // r = fact(-1);      // ⚠️ Stack Overflow! — infinite calls

    r = ifact(5);
    printf("%d\n", r);    // Output: 120

    return 0;
}
```

---

**Tracing `fact(5)` — Recursive:**
```
fact(5) = fact(4) * 5
fact(4) = fact(3) * 4
fact(3) = fact(2) * 3
fact(2) = fact(1) * 2
fact(1) = fact(0) * 1
fact(0) = 1

Returning:
1 * 1 = 1
1 * 2 = 2
2 * 3 = 6
6 * 4 = 24
24 * 5 = 120 ✓
```

**Tracing `ifact(5)` — Iterative:**
```
i=1: f = 1 * 1 = 1
i=2: f = 1 * 2 = 2
i=3: f = 2 * 3 = 6
i=4: f = 6 * 4 = 24
i=5: f = 24 * 5 = 120 ✓

// 𝐖𝐡𝐚𝐭 𝐡𝐚𝐩𝐩𝐞𝐧𝐬 𝐰𝐢𝐭𝐡 𝐧𝐞𝐠𝐚𝐭𝐢𝐯𝐞 𝐢𝐧𝐩𝐮𝐭:

fact(-1) → fact(-2) → fact(-3) → ... → 26254 calls → STACK OVERFLOW 💥

// 𝐅𝐢𝐱 𝐭𝐨 𝐡𝐚𝐧𝐝𝐥𝐞 𝐧𝐞𝐠𝐚𝐭𝐢𝐯𝐞 𝐧𝐮𝐦𝐛𝐞𝐫𝐬:

int fact(int n) {
    if (n < 0)
        return -1;       // guard against negative input
    if (n == 0)
        return 1;
    else
        return fact(n - 1) * n;
}