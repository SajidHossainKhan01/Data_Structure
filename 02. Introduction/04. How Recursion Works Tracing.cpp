// 𝐁𝐚𝐬𝐢𝐜 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧 𝐂𝐚𝐥𝐥 (𝐍𝐨𝐧-𝐑𝐞𝐜𝐮𝐫𝐬𝐢𝐯𝐞) — 𝐑𝐞𝐦𝐢𝐧𝐝𝐞𝐫

void fun() {
    // statement 1
    // statement 2
    // statement 3
}

int main() {
    // statement 1
    // statement 2
    fun();        // control goes to fun, returns here after
    // statement 4
    // statement 5
}

// 𝐆𝐞𝐧𝐞𝐫𝐚𝐥 𝐅𝐨𝐫𝐦 𝐨𝐟 𝐑𝐞𝐜𝐮𝐫𝐬𝐢𝐯𝐞 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧

void fun(n) {
    if (condition) {    // base condition — stops recursion
        // statements
        fun(n);         // function calling itself
    }
}

// 𝐏𝐫𝐢𝐧𝐭 𝐁𝐄𝐅𝐎𝐑𝐄 𝐑𝐞𝐜𝐮𝐫𝐬𝐢𝐯𝐞 𝐂𝐚𝐥𝐥 → 𝐎𝐮𝐭𝐩𝐮𝐭: 𝟑 𝟐 𝟏

void fun1(int n) {
    if (n > 0) {
        printf("%d ", n);   // Step 1: print FIRST
        fun1(n - 1);        // Step 2: call AFTER
    }
}

int main() {
    int x = 3;
    fun1(x);
    // Output: 3 2 1
}
```

**Tracing Tree:**
```
fun1(3) → print 3 → fun1(2)
                        → print 2 → fun1(1)
                                        → print 1 → fun1(0)
                                                        → stop

// 𝐏𝐫𝐢𝐧𝐭 𝐀𝐅𝐓𝐄𝐑 𝐑𝐞𝐜𝐮𝐫𝐬𝐢𝐯𝐞 𝐂𝐚𝐥𝐥 → 𝐎𝐮𝐭𝐩𝐮𝐭: 𝟏 𝟐 𝟑

void fun2(int n) {
    if (n > 0) {
        fun2(n - 1);        // Step 1: call FIRST
        printf("%d ", n);   // Step 2: print AFTER (at returning time)
    }
}

int main() {
    int x = 3;
    fun2(x);
    // Output: 1 2 3
}
```

**Tracing Tree:**
```
fun2(3) → fun2(2)
              → fun2(1)
                    → fun2(0) → stop
                    ← print 1
              ← print 2
← print 3