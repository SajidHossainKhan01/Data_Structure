// 𝐅𝐮𝐥𝐥 𝐏𝐫𝐨𝐠𝐫𝐚𝐦 — 𝐒𝐭𝐫𝐮𝐜𝐭𝐮𝐫𝐞𝐬 & 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧𝐬 (𝐂 𝐒𝐭𝐲𝐥𝐞 𝐎𝐎𝐏)

#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

// Function 1: Initialize the rectangle (Call by Address)
void initialize(Rectangle *r, int l, int b) {
    r->length = l;
    r->breadth = b;
}

// Function 2: Calculate Area (Call by Value)
int area(Rectangle r) {
    return r.length * r.breadth;
}

// Function 3: Change Length (Call by Address)
void changeLength(Rectangle *r, int newLength) {
    r->length = newLength;
}

int main() {
    Rectangle R;

    // Main only calls functions — no logic of its own
    initialize(&R, 10, 5);     // Pass by address — modifies actual R
    area(R);                   // Pass by value — just computes, returns result
    changeLength(&R, 20);      // Pass by address — modifies actual R

    return 0;
}

// 𝐂𝐚𝐥𝐥 𝐛𝐲 𝐀𝐝𝐝𝐫𝐞𝐬𝐬 — 𝐒𝐭𝐫𝐮𝐜𝐭𝐮𝐫𝐞 𝐚𝐬 𝐏𝐚𝐫𝐚𝐦𝐞𝐭𝐞𝐫𝐖𝐡𝐲 𝐄𝐚𝐜𝐡 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧 𝐔𝐬𝐞𝐬 𝐈𝐭𝐬 𝐏𝐚𝐫𝐚𝐦𝐞𝐭𝐞𝐫 𝐏𝐚𝐬𝐬𝐢𝐧𝐠 𝐌𝐞𝐭𝐡𝐨𝐝

// initialize — must MODIFY actual rectangle → Call by Address
void initialize(Rectangle *r, int l, int b)

// area — only COMPUTES, doesn't modify → Call by Value
int area(Rectangle r)

// changeLength — must MODIFY actual rectangle → Call by Address
void changeLength(Rectangle *r, int newLength)

// 𝐃𝐨𝐭 𝐯𝐬 𝐀𝐫𝐫𝐨𝐰 𝐎𝐩𝐞𝐫𝐚𝐭𝐨𝐫 𝐔𝐬𝐚𝐠𝐞

// Call by Value — use dot operator (own copy)
int area(Rectangle r) {
    return r.length * r.breadth;  // dot operator
}

// Call by Address — use arrow operator (pointer)
void initialize(Rectangle *r, int l, int b) {
    r->length = l;   // arrow operator
    r->breadth = b;  // arrow operator
}