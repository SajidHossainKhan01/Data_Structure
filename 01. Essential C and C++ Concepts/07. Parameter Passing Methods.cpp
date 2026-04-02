// 𝐂𝐚𝐥𝐥 𝐛𝐲 𝐕𝐚𝐥𝐮𝐞

#include <iostream>
using namespace std;

int add(int a, int b) {
    a++;  // Modifying formal parameter
    cout << a << endl;    // Output: 11 (a is changed)
    return a + b;
}

int main() {
    int num1 = 10;
    int num2 = 15;

    add(num1, num2);

    cout << num1 << endl;  // Output: 10 (num1 is NOT changed)

    return 0;
}

// 𝐂𝐚𝐥𝐥 𝐛𝐲 𝐀𝐝𝐝𝐫𝐞𝐬𝐬

#include <iostream>
using namespace std;

void swap(int *x, int *y) {  // Formal parameters are pointers
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int num1 = 10;
    int num2 = 15;

    swap(&num1, &num2);  // Pass addresses of actual parameters

    cout << num1 << endl;  // Output: 15
    cout << num2 << endl;  // Output: 10

    return 0;
}

// 𝐂𝐚𝐥𝐥 𝐛𝐲 𝐑𝐞𝐟𝐞𝐫𝐞𝐧𝐜𝐞 (𝐂++ 𝐨𝐧𝐥𝐲)

#include <iostream>
using namespace std;

void swap(int &x, int &y) {  // Formal parameters are references
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int num1 = 10;
    int num2 = 15;

    swap(num1, num2);  // No & needed when calling

    cout << num1 << endl;  // Output: 15
    cout << num2 << endl;  // Output: 10

    return 0;
}

// 𝐌𝐢𝐱𝐞𝐝 𝐏𝐚𝐫𝐚𝐦𝐞𝐭𝐞𝐫 𝐏𝐚𝐬𝐬𝐢𝐧𝐠

void swap(int &x, int *y) {  // x = call by reference, y = call by address
    int temp = x;
    x = *y;
    *y = temp;
}
