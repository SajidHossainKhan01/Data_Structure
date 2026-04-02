// 𝐒𝐭𝐫𝐮𝐜𝐭𝐮𝐫𝐞 & 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧𝐬 𝐒𝐭𝐲𝐥𝐞 — 𝐀𝐫𝐞𝐚 & 𝐏𝐞𝐫𝐢𝐦𝐞𝐭𝐞𝐫 𝐨𝐟 𝐑𝐞𝐜𝐭𝐚𝐧𝐠𝐥𝐞

#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

// Function 1: Initialize rectangle (Call by Address)
void initialize(Rectangle *r, int l, int b) {
    r->length = l;
    r->breadth = b;
}

// Function 2: Calculate Area (Call by Value)
int area(Rectangle r) {
    return r.length * r.breadth;
}

// Function 3: Calculate Perimeter (Call by Value)
int perimeter(Rectangle r) {
    int p = 2 * (r.length + r.breadth);
    return p;
}

int main() {
    // Declare structure variable
    Rectangle r = {0, 0};

    // User interaction — temporary variables for input
    int l, b;
    printf("Enter length and breadth: ");
    scanf("%d %d", &l, &b);

    // Initialize rectangle via function
    initialize(&r, l, b);

    // Processing — handled by functions
    int a    = area(r);
    int peri = perimeter(r);

    // Display results
    printf("Area = %d\n", a);
    printf("Perimeter = %d\n", peri);

    return 0;
}
```

**Output:**
```
Enter length and breadth: 10 5
Area = 50
Perimeter = 30

// 𝐄𝐯𝐨𝐥𝐮𝐭𝐢𝐨𝐧 𝐨𝐟 𝐏𝐫𝐨𝐠𝐫𝐚𝐦𝐦𝐢𝐧𝐠 𝐒𝐭𝐲𝐥𝐞𝐬 (𝐀𝐥𝐥 𝟑 𝐒𝐨 𝐅𝐚𝐫)

// STYLE 1 — Monolithic (everything in main)
int main() {
    int area = length * breadth;
    int peri = 2 * (length + breadth);
}

// STYLE 2 — Modular/Procedural (functions, separate variables)
int area(int length, int breadth) { ... }
int perimeter(int length, int breadth) { ... }

// STYLE 3 — Structure & Functions (data grouped in structure)
int area(Rectangle r) { ... }
int perimeter(Rectangle r) { ... }
void initialize(Rectangle *r, int l, int b) { ... }