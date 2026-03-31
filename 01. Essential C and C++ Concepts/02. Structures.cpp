// 𝐁𝐚𝐬𝐢𝐜 𝐒𝐭𝐫𝐮𝐜𝐭𝐮𝐫𝐞 𝐃𝐞𝐟𝐢𝐧𝐢𝐭𝐢𝐨𝐧 & 𝐃𝐞𝐜𝐥𝐚𝐫𝐚𝐭𝐢𝐨𝐧

#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    struct Rectangle R1;  // Declaration inside main (local)
    return 0;
}

// 𝐆𝐥𝐨𝐛𝐚𝐥 𝐕𝐚𝐫𝐢𝐚𝐛𝐥𝐞 𝐃𝐞𝐜𝐥𝐚𝐫𝐚𝐭𝐢𝐨𝐧

struct Rectangle {
    int length;
    int breadth;
} R1, R2, R3;  // Declared globally — accessible to all functions

// 𝐈𝐧𝐢𝐭𝐢𝐚𝐥𝐢𝐳𝐚𝐭𝐢𝐨𝐧 & 𝐒𝐢𝐳𝐞 𝐨𝐟 𝐒𝐭𝐫𝐮𝐜𝐭𝐮𝐫𝐞

#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    struct Rectangle R1 = {10, 5};  // length=10, breadth=5

    printf("%lu\n", sizeof(R1));  // Output: 8 bytes (4+4)

    return 0;
}

// 𝐏𝐚𝐝𝐝𝐢𝐧𝐠 𝐃𝐞𝐦𝐨 (𝐰𝐢𝐭𝐡 𝐜𝐡𝐚𝐫 𝐦𝐞𝐦𝐛𝐞𝐫)

struct Rectangle {
    int length;    // 4 bytes
    int breadth;   // 4 bytes
    char x;        // 1 byte — but 4 bytes allocated due to padding
};

// sizeof = 12 bytes (not 9) due to memory padding

// 𝐀𝐜𝐜𝐞𝐬𝐬𝐢𝐧𝐠 & 𝐌𝐨𝐝𝐢𝐟𝐲𝐢𝐧𝐠 𝐌𝐞𝐦𝐛𝐞𝐫𝐬

#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    struct Rectangle R1 = {10, 5};

    // Display members
    cout << R1.length << endl;   // Output: 10
    cout << R1.breadth << endl;  // Output: 5

    // Modify members
    R1.length = 15;
    R1.breadth = 7;

    cout << R1.length << endl;   // Output: 15
    cout << R1.breadth << endl;  // Output: 7

    return 0;
}