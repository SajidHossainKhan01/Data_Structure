#include <stdio.h>

// TREE RECURSION — calls itself MORE THAN ONCE
void fun(int n) {
    if (n > 0) {
        printf("%d ", n);   // print first
        fun(n - 1);         // first recursive call
        fun(n - 1);         // second recursive call
    }
}

int main() {
    fun(3);   // Output: 3 2 1 1 2 1 1
    return 0;
}
```

---

**Recursion Tree for `fun(3)`:**
```
                    fun(3) → prints 3
                   /              \
           fun(2) → prints 2    fun(2) → prints 2
           /        \            /        \
      fun(1)→p1  fun(1)→p1  fun(1)→p1  fun(1)→p1
      /    \      /    \      /    \      /    \
   f(0)  f(0)  f(0)  f(0)  f(0)  f(0)  f(0)  f(0)
```

**Output:** `3 2 1 1 2 1 1 2 1 1`

---

**Total calls levelwise (n = 3):**
```
Level 0:  1  call   (2⁰)
Level 1:  2  calls  (2¹)
Level 2:  4  calls  (2²)
Level 3:  8  calls  (2³)
          --------
Total:   15  calls  = 2⁰+2¹+2²+2³ = 2^(n+1) - 1


#include <stdio.h>

// TREE RECURSION
void fun(int n) {
    if (n > 0) {
        printf("%d ", n);   // print at calling time
        fun(n - 1);         // first recursive call
        fun(n - 1);         // second recursive call
    }
}

int main() {
    fun(3);   // Output: 3 2 1 1 2 1 1 2 1 1
    return 0;
}
```

---

**Order of function calls observed in debugger (n=3):**
```
fun(3) → prints 3
  fun(2) → prints 2
    fun(1) → prints 1
      fun(0) → returns   ← max stack depth = 4
    fun(0) → returns
  fun(1) → prints 1       ← second call of fun(2)
    fun(0) → returns
    fun(0) → returns
fun(2) → prints 2         ← second call of fun(3)
  fun(1) → prints 1
    fun(0) → returns
    fun(0) → returns
  fun(1) → prints 1
    fun(0) → returns
    fun(0) → returns

**Output:** `3 2 1 1 2 1 1 2 1 1`