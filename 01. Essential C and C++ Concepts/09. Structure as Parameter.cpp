// 𝐂𝐚𝐥𝐥 𝐛𝐲 𝐕𝐚𝐥𝐮𝐞 — 𝐒𝐭𝐫𝐮𝐜𝐭𝐮𝐫𝐞 𝐚𝐬 𝐏𝐚𝐫𝐚𝐦𝐞𝐭𝐞𝐫

#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

void fun(Rectangle rect) {       // Copy of structure is created
    rect.length = 20;            // Only modifies local copy
    cout << rect.length << endl; // Output: 20
    cout << rect.breadth << endl;// Output: 5
}

int main() {
    Rectangle R = {10, 5};

    printf("Length: %d\n", R.length);  // Output: 10
    printf("Breadth: %d\n", R.breadth);// Output: 5

    fun(R);  // Pass by value

    // Original R is unchanged
    printf("Length: %d\n", R.length);  // Output: 10
    printf("Breadth: %d\n", R.breadth);// Output: 5

    return 0;
}

// 𝐂𝐚𝐥𝐥 𝐛𝐲 𝐀𝐝𝐝𝐫𝐞𝐬𝐬 — 𝐒𝐭𝐫𝐮𝐜𝐭𝐮𝐫𝐞 𝐚𝐬 𝐏𝐚𝐫𝐚𝐦𝐞𝐭𝐞𝐫

#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

void fun(Rectangle *p) {         // Pointer to structure
    p->length = 20;              // Modifies actual structure
    cout << p->length << endl;   // Output: 20
    cout << p->breadth << endl;  // Output: 5
}

int main() {
    Rectangle R = {10, 5};

    fun(&R);  // Pass address of structure

    // Original R is modified
    cout << R.length << endl;    // Output: 20
    cout << R.breadth << endl;   // Output: 5

    return 0;
}

// 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧 𝐂𝐫𝐞𝐚𝐭𝐢𝐧𝐠 & 𝐑𝐞𝐭𝐮𝐫𝐧𝐢𝐧𝐠 𝐒𝐭𝐫𝐮𝐜𝐭𝐮𝐫𝐞 𝐟𝐫𝐨𝐦 𝐇𝐞𝐚𝐩

#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

Rectangle* fun() {               // Returns pointer to structure
    Rectangle *p = new Rectangle;// Object created in Heap (C++)

    // C language equivalent:
    // struct Rectangle *p = (struct Rectangle*)malloc(sizeof(struct Rectangle));

    p->length = 15;
    p->breadth = 7;

    return p;                    // Return pointer to heap object
}

int main() {
    Rectangle *ptr = fun();      // Receive pointer to heap object

    cout << ptr->length << endl; // Output: 15
    cout << ptr->breadth << endl;// Output: 7

    delete ptr;                  // Free heap memory

    return 0;
}