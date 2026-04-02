// 𝐎𝐫𝐝𝐞𝐫 𝐨𝐟 𝐍 — 𝐒𝐢𝐧𝐠𝐥𝐞 𝐅𝐨𝐫 𝐋𝐨𝐨𝐩

// Processing all n elements once → O(n)
for (int i = 0; i < n; i++) {
    // add, search, count, find max, etc.
}

// 𝐎𝐫𝐝𝐞𝐫 𝐨𝐟 𝐍² — 𝐍𝐞𝐬𝐭𝐞𝐝 𝐅𝐨𝐫 𝐋𝐨𝐨𝐩

// Processing each element against all others → O(n²)
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // comparison, sorting, etc.
    }
}

// 𝐎𝐫𝐝𝐞𝐫 𝐨𝐟 𝐍² — 𝐍𝐞𝐬𝐭𝐞𝐝 𝐋𝐨𝐨𝐩 (𝐑𝐞𝐝𝐮𝐜𝐞𝐝 𝐂𝐨𝐦𝐩𝐚𝐫𝐢𝐬𝐨𝐧𝐬)

// Each element compared with remaining elements only → O(n²)
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        // processing
    }
}
// Total work = n(n-1)/2 → still O(n²)

// 𝐎𝐫𝐝𝐞𝐫 𝐨𝐟 𝐥𝐨𝐠 𝐍 — 𝐃𝐢𝐯𝐢𝐝𝐢𝐧𝐠 𝐛𝐲 𝟐 𝐞𝐚𝐜𝐡 𝐭𝐢𝐦𝐞
𝐔𝐬𝐢𝐧𝐠 𝐟𝐨𝐫 𝐥𝐨𝐨𝐩:

// Dividing problem in half each time → O(log n)
for (int i = n; i > 1; i = i / 2) {
    // processing
}

𝐔𝐬𝐢𝐧𝐠 𝐰𝐡𝐢𝐥𝐞 𝐥𝐨𝐨𝐩:

int i = n;
while (i > 1) {
    // processing
    i = i / 2;
}

// 𝐎𝐫𝐝𝐞𝐫 𝐨𝐟 𝐍² — 𝐌𝐚𝐭𝐫𝐢𝐱 𝐏𝐫𝐨𝐜𝐞𝐬𝐬𝐢𝐧𝐠

// Processing all elements of an n×n matrix → O(n²)
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // process matrix element
    }
}


