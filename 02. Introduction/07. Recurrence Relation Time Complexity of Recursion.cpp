#include <stdio.h>

void fun1(int n) {
    if (n > 0) {           // 1 unit of time
        printf("%d ", n);  // 1 unit of time
        fun1(n - 1);       // T(n-1) time
    }
}

int main() {
    int x = 3;
    fun1(x);
    return 0;
}
```

---

**Time Complexity — Method 1: Counting from Recursion Tree**
```
fun1(3) → prints 3
  fun1(2) → prints 2
    fun1(1) → prints 1
      fun1(0) → prints nothing (base case)
```
```
For n = 3 → 3 units of time
For n = 5 → 5 units of time
For n   → n units of time  →  O(n)
```

---

**Time Complexity — Method 2: Recurrence Relation**
```
T(n) = T(n-1) + 2      when n > 0
T(0) = 1               (only checks condition, 1 unit)
```

Treating constants as 1:
```
T(n) = T(n-1) + 1      ...(1)
T(n-1) = T(n-2) + 1   ...(2)  substitute into (1)
T(n) = T(n-2) + 2
T(n) = T(n-3) + 3
...
T(n) = T(n-k) + k      ...(k-th step)
```

**Solving — assume n - k = 0, so k = n:**
```
T(n) = T(0) + n
T(n) = 1 + n
T(n) = O(n)