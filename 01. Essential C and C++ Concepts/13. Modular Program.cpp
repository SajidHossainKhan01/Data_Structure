// 𝐌𝐨𝐝𝐮𝐥𝐚𝐫/𝐏𝐫𝐨𝐜𝐞𝐝𝐮𝐫𝐚𝐥 𝐒𝐭𝐲𝐥𝐞 — 𝐀𝐫𝐞𝐚 & 𝐏𝐞𝐫𝐢𝐦𝐞𝐭𝐞𝐫 𝐨𝐟 𝐑𝐞𝐜𝐭𝐚𝐧𝐠𝐥𝐞

#include <iostream>
#include <stdio.h>
using namespace std;

// Function 1: Calculate Area
int area(int length, int breadth) {
    return length * breadth;
}

// Function 2: Calculate Perimeter
int perimeter(int length, int breadth) {
    int p = 2 * (length + breadth);
    return p;
}

int main() {
    // User interaction — handled by main
    int length = 0;
    int breadth = 0;

    printf("Enter length and breadth: ");
    scanf("%d %d", &length, &breadth);

    // Processing — handled by functions
    int a    = area(length, breadth);
    int peri = perimeter(length, breadth);

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

// 𝐌𝐨𝐧𝐨𝐥𝐢𝐭𝐡𝐢𝐜 𝐯𝐬 𝐌𝐨𝐝𝐮𝐥𝐚𝐫 𝐂𝐨𝐦𝐩𝐚𝐫𝐢𝐬𝐨𝐧

// MONOLITHIC — everything in main
int main() {
    int area = length * breadth;           // main calculates itself
    int peri = 2 * (length + breadth);     // main calculates itself
}

// MODULAR — main delegates to functions
int main() {
    int a    = area(length, breadth);      // function calculates
    int peri = perimeter(length, breadth); // function calculates
}