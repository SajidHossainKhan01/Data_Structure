#include <stdio.h>

// NESTED RECURSION — argument of recursive call is itself a recursive call
int fun(int n) {
    if (n > 100)
        return n - 10;
    else
        return fun(fun(n + 11));  // nested recursive call
}

int main() {
    int r;

    r = fun(95);
    printf("%d\n", r);   // Output: 91

    r = fun(99);
    printf("%d\n", r);   // Output: 91

    r = fun(100);
    printf("%d\n", r);   // Output: 91

    r = fun(30);
    printf("%d\n", r);   // Output: 91

    r = fun(200);
    printf("%d\n", r);   // Output: 190

    return 0;
}
```

---

**Tracing `fun(95)`:**
```
fun(95)  → 95 > 100? NO  → fun(fun(106))
fun(106) → 106 > 100? YES → returns 96
fun(96)  → 96 > 100? NO  → fun(fun(107))
fun(107) → 107 > 100? YES → returns 97
fun(97)  → 97 > 100? NO  → fun(fun(108))
fun(108) → 108 > 100? YES → returns 98
fun(98)  → 98 > 100? NO  → fun(fun(109))
fun(109) → 109 > 100? YES → returns 99
fun(99)  → 99 > 100? NO  → fun(fun(110))
fun(110) → 110 > 100? YES → returns 100
fun(100) → 100 > 100? NO → fun(fun(111))
fun(111) → 111 > 100? YES → returns 101
fun(101) → 101 > 100? YES → returns 91  ✓

// 𝐖𝐡𝐚𝐭 𝐦𝐚𝐤𝐞𝐬 𝐢𝐭 𝐍𝐞𝐬𝐭𝐞𝐝 𝐑𝐞𝐜𝐮𝐫𝐬𝐢𝐨𝐧:

return fun(fun(n + 11));
//         ^^^^^^^^^^^
//     inner call result becomes
//     argument of outer call