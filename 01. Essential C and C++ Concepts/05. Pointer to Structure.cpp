// 𝐁𝐚𝐬𝐢𝐜 𝐒𝐭𝐫𝐮𝐜𝐭𝐮𝐫𝐞 𝐰𝐢𝐭𝐡 𝐃𝐨𝐭 𝐎𝐩𝐞𝐫𝐚𝐭𝐨𝐫

#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    Rectangle R = {10, 5};  // In C++, 'struct' keyword is optional

    // Access using dot operator (normal variable)
    cout << R.length << endl;   // Output: 10
    cout << R.breadth << endl;  // Output: 5

    return 0;
}

// 𝐏𝐨𝐢𝐧𝐭𝐞𝐫 𝐭𝐨 𝐒𝐭𝐫𝐮𝐜𝐭𝐮𝐫𝐞 𝐰𝐢𝐭𝐡 𝐀𝐫𝐫𝐨𝐰 𝐎𝐩𝐞𝐫𝐚𝐭𝐨𝐫

#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    Rectangle R = {10, 5};
    Rectangle *P = &R;  // Pointer to structure

    // Access using arrow operator (pointer)
    cout << P->length << endl;   // Output: 10
    cout << P->breadth << endl;  // Output: 5

    return 0;
}

// 𝐒𝐭𝐫𝐮𝐜𝐭𝐮𝐫𝐞 𝐎𝐛𝐣𝐞𝐜𝐭 𝐢𝐧 𝐇𝐞𝐚𝐩 — 𝐂 𝐒𝐭𝐲𝐥𝐞 (𝐦𝐚𝐥𝐥𝐨𝐜)

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    struct Rectangle *P;
    P = (struct Rectangle*)malloc(sizeof(struct Rectangle));  // 8 bytes in Heap

    P->length = 15;
    P->breadth = 7;

    cout << P->length << endl;   // Output: 15
    cout << P->breadth << endl;  // Output: 7

    free(P);  // Deallocate heap memory

    return 0;
}

// 𝐒𝐭𝐫𝐮𝐜𝐭𝐮𝐫𝐞 𝐎𝐛𝐣𝐞𝐜𝐭 𝐢𝐧 𝐇𝐞𝐚𝐩 — 𝐂++ 𝐒𝐭𝐲𝐥𝐞 (𝐧𝐞𝐰)

#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    Rectangle *P = new Rectangle;  // Simpler C++ syntax

    P->length = 15;
    P->breadth = 7;

    cout << P->length << endl;   // Output: 15
    cout << P->breadth << endl;  // Output: 7

    delete P;  // Deallocate heap memory

    return 0;
}
