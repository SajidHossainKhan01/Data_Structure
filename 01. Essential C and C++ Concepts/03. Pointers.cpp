// 𝐁𝐚𝐬𝐢𝐜 𝐏𝐨𝐢𝐧𝐭𝐞𝐫 𝐃𝐞𝐜𝐥𝐚𝐫𝐚𝐭𝐢𝐨𝐧 & 𝐃𝐞𝐫𝐞𝐟𝐞𝐫𝐞𝐧𝐜𝐢𝐧𝐠

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int a = 10;
    int *p;
    p = &a;  // Store address of a in pointer p

    cout << a << endl;           // Output: 10
    printf("using pointer %d\n", *p);  // Output: using pointer 10

    // Print address
    printf("%d\n", p);   // prints address stored in p
    printf("%d\n", &a);  // prints address of a — both are same!

    return 0;
}

// 𝐏𝐨𝐢𝐧𝐭𝐞𝐫 𝐭𝐨 𝐚𝐧 𝐀𝐫𝐫𝐚𝐲 (𝐒𝐭𝐚𝐜𝐤)

#include <iostream>
using namespace std;

int main() {
    int a[5] = {2, 4, 6, 8, 10};
    int *p;

    p = a;       // Correct — array name is already the starting address
    // p = &a;   // Wrong syntax
    // p = &a[0]; // This is also valid

    // Access using array name
    for (int i = 0; i < 5; i++)
        cout << a[i] << endl;

    // Access using pointer
    for (int i = 0; i < 5; i++)
        cout << p[i] << endl;  // pointer acts as array name

    return 0;
}

// 𝐀𝐫𝐫𝐚𝐲 𝐢𝐧 𝐇𝐞𝐚𝐩 — 𝐂 𝐬𝐭𝐲𝐥𝐞 (𝐦𝐚𝐥𝐥𝐨𝐜)

#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    int *p;
    p = (int*)malloc(5 * sizeof(int));  // Allocate array in Heap

    p[0] = 10;
    p[1] = 15;
    p[2] = 14;
    p[3] = 21;
    p[4] = 31;

    for (int i = 0; i < 5; i++)
        cout << p[i] << endl;

    free(p);  // Deallocate in C

    return 0;
}

// 𝐀𝐫𝐫𝐚𝐲 𝐢𝐧 𝐇𝐞𝐚𝐩 — 𝐂++ 𝐬𝐭𝐲𝐥𝐞 (𝐧𝐞𝐰/𝐝𝐞𝐥𝐞𝐭𝐞)

#include <iostream>
using namespace std;

int main() {
    int *p;
    p = new int[5];  // C++ syntax — simpler than malloc

    p[0] = 10;
    p[1] = 15;
    p[2] = 14;
    p[3] = 21;
    p[4] = 31;

    for (int i = 0; i < 5; i++)
        cout << p[i] << endl;

    delete[] p;  // Deallocate array in C++ (use [] for arrays)

    return 0;
}

// 𝐒𝐢𝐳𝐞 𝐨𝐟 𝐃𝐢𝐟𝐟𝐞𝐫𝐞𝐧𝐭 𝐏𝐨𝐢𝐧𝐭𝐞𝐫 𝐓𝐲𝐩𝐞𝐬

#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    int    *p1;
    char   *p2;
    float  *p3;
    double *p4;
    struct Rectangle *p5;

    cout << sizeof(p1) << endl;  // 8
    cout << sizeof(p2) << endl;  // 8
    cout << sizeof(p3) << endl;  // 8
    cout << sizeof(p4) << endl;  // 8
    cout << sizeof(p5) << endl;  // 8

    return 0;
}