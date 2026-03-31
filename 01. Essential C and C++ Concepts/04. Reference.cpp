// 𝐁𝐚𝐬𝐢𝐜 𝐑𝐞𝐟𝐞𝐫𝐞𝐧𝐜𝐞 𝐃𝐞𝐜𝐥𝐚𝐫𝐚𝐭𝐢𝐨𝐧

#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int &r = a;  // r is a reference to a — must be initialized at declaration

    cout << a << endl;  // Output: 10
    cout << r << endl;  // Output: 10 — both are same

    return 0;
}

// 𝐂𝐡𝐚𝐧𝐠𝐢𝐧𝐠 𝐕𝐚𝐥𝐮𝐞 𝐯𝐢𝐚 𝐑𝐞𝐟𝐞𝐫𝐞𝐧𝐜𝐞

#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int &r = a;

    // Change a directly
    a = 25;
    cout << a << endl;  // Output: 25
    cout << r << endl;  // Output: 25 — r is same as a

    // Change via reference
    r = 25;
    cout << a << endl;  // Output: 25
    cout << r << endl;  // Output: 25

    return 0;
}

// 𝐑𝐞𝐟𝐞𝐫𝐞𝐧𝐜𝐞 𝐂𝐚𝐧𝐧𝐨𝐭 𝐛𝐞 𝐑𝐞𝐛𝐨𝐮𝐧𝐝

#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 30;
    int &r = a;  // r is reference to a

    r = b;  // This is NOT making r a reference to b
            // This assigns value of b (30) into r, which means a becomes 30

    cout << a << endl;  // Output: 30
    cout << r << endl;  // Output: 30

    return 0;
}