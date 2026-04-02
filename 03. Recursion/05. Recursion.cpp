#include <stdio.h>

// TAIL Recursion — print BEFORE calling (Ascending phase)
void fun_tail(int n) {
    if (n > 0) {
        printf("%d ", n);   // executes at CALLING time
        fun_tail(n - 1);    // recursive call
    }
}

// HEAD Recursion — print AFTER calling (Descending phase)
void fun_head(int n) {
    if (n > 0) {
        fun_head(n - 1);    // recursive call
        printf("%d ", n);   // executes at RETURNING time
    }
}

int main() {
    int x = 3;

    fun_tail(x);   // Output: 3 2 1
    printf("\n");
    fun_head(x);   // Output: 1 2 3

    return 0;
}
```

---

**Stack behavior for `fun_tail(3)`:**
```
CALLING (stack builds up):
main → fun(3) prints 3 → fun(2) prints 2 → fun(1) prints 1 → fun(0) returns

RETURNING (stack unwinds):
fun(0) deleted → fun(1) deleted → fun(2) deleted → fun(3) deleted → main
```

**Stack behavior for `fun_head(3)`:**
```
CALLING (stack builds up — nothing prints):
main → fun(3) → fun(2) → fun(1) → fun(0) returns

RETURNING (stack unwinds — now prints):
fun(0) deleted → fun(1) prints 1 → fun(2) prints 2 → fun(3) prints 3 → main