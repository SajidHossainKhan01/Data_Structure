#include <stdio.h>

// Forward declaration (prototype) needed because A calls B before B is defined
void funB(int n);

void funA(int n) {
    if (n > 0) {
        printf("%d ", n);
        funB(n - 1);        // A calls B
    }
}

void funB(int n) {
    if (n > 1) {
        printf("%d ", n);
        funA(n / 2);        // B calls A
    }
}

int main() {
    funA(20);   // Output: 20 19 9 8 4 3 1
    return 0;
}
```

---

**Tracing `funA(20)`:**
```
funA(20) → prints 20 → calls funB(19)
funB(19) → prints 19 → calls funA(9)
funA(9)  → prints 9  → calls funB(8)
funB(8)  → prints 8  → calls funA(4)
funA(4)  → prints 4  → calls funB(3)
funB(3)  → prints 3  → calls funA(1)
funA(1)  → prints 1  → calls funB(0)
funB(0)  → 0 > 1? NO → returns
```

**Output:** `20 19 9 8 4 3 1`

---

**What makes it Indirect Recursion:**
```
funA → calls funB → calls funA → calls funB → ...

// 𝐖𝐡𝐲 𝐭𝐡𝐞 𝐩𝐫𝐨𝐭𝐨𝐭𝐲𝐩𝐞 𝐢𝐬 𝐧𝐞𝐞𝐝𝐞𝐝:

void funB(int n);   // ✅ declare BEFORE use — tells compiler funB exists                     
		    // without this, funA calling funB causes an error