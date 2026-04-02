// 𝐒𝐰𝐚𝐩 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧 — 𝐎(𝟏) 𝐂𝐨𝐧𝐬𝐭𝐚𝐧𝐭 𝐓𝐢𝐦𝐞

// 3 simple statements → T(n) = 3 → O(1)
swap(x, y) {
    temp = x;   // 1 unit
    x = y;      // 1 unit
    y = temp;   // 1 unit
}

// 𝐒𝐮𝐦 𝐨𝐟 𝐀𝐫𝐫𝐚𝐲 𝐄𝐥𝐞𝐦𝐞𝐧𝐭𝐬 — 𝐎(𝐧)

// T(n) = 2n + 3 → O(n)
sum(A, n) {
    s = 0;              // 1 unit

    for (i = 0; i < n; i++) {   // n+1 (condition checked n+1 times)
        s = s + A[i];            // n units (runs n times)
    }

    return s;           // 1 unit
}

// 𝐍𝐞𝐬𝐭𝐞𝐝 𝐋𝐨𝐨𝐩 — 𝐎(𝐧²)

// T(n) = 2n² + 2n + 1 → O(n²)
fun(n) {
    for (i = 0; i < n; i++) {        // n+1
        for (j = 0; j < n; j++) {    // n * (n+1)
            // statement              // n * n
        }
    }
}

// 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧 𝐂𝐚𝐥𝐥𝐢𝐧𝐠 𝐀𝐧𝐨𝐭𝐡𝐞𝐫 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧 — 𝐎(𝐧)

// fun1 calls fun2, so fun1 inherits fun2's time complexity
fun1() {
    fun2();     // NOT O(1) — must look inside fun2!
}

fun2() {
    for (i = 0; i < n; i++) {   // O(n)
        // statement
    }
}
// Time of fun1 = O(n), NOT O(1)