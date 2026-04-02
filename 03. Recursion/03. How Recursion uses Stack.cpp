#include <stdio.h>

// Function 1 — Print BEFORE recursive call (Ascending phase)
void fun1(int n) {
    if (n > 0) {
        printf("%d ", n);   // Executes at CALLING time
        fun1(n - 1);        // Recursive call
    }
}

// Function 2 — Print AFTER recursive call (Descending phase)
void fun2(int n) {
    if (n > 0) {
        fun2(n - 1);        // Recursive call
        printf("%d ", n);   // Executes at RETURNING time
    }
}

int main() {
    int x = 3;
    fun1(x);   // Output: 3 2 1
    printf("\n");
    fun2(x);   // Output: 1 2 3
    return 0;
}
```

---

**How the Stack works for `fun2(3)`:**
```
Calling (Ascending) — Stack builds up:
  fun2(3) → fun2(2) → fun2(1) → fun2(0) ← base case, returns

Returning (Descending) — Stack unwinds:
  fun2(0) deleted → prints 1
  fun2(1) deleted → prints 2
  fun2(2) deleted → prints 3
  fun2(3) deleted
```

**Stack at peak (n = 3):**
```
| n = 0 |  ← top
| n = 1 |
| n = 2 |
| n = 3 |
| main  |  ← bottom