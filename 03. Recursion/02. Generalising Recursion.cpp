void fun(int n) {
    if (n > 0) {
        printf("%d ", n);   // Statement 1 — executes at CALLING time (Ascending phase)
        fun(n - 1);         // Recursive call
        printf("%d ", n);   // Statement 2 — executes at RETURNING time (Descending phase)
    }
}
```

**Example call:** `fun(3)`

**Ascending phase (calling time):**
```
prints 3 → calls fun(2)
prints 2 → calls fun(1)
prints 1 → calls fun(0)
fun(0) → base case, returns
```

**Descending phase (returning time):**
```
returns to fun(1) → prints 1
returns to fun(2) → prints 2
returns to fun(3) → prints 3
```

**Final output:** `3 2 1 1 2 3`

---

**The key formula from the lecture:**
```
void fun(int n) {
    if (n > 0) {
        // ↑ BEFORE recursive call → Ascending phase (calling time)
        
        fun(n - 1);
        
        // ↓ AFTER recursive call → Descending phase (returning time)
    }
}