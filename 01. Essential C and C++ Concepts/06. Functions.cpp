// 𝐁𝐚𝐬𝐢𝐜 𝐒𝐭𝐫𝐮𝐜𝐭𝐮𝐫𝐞 𝐰𝐢𝐭𝐡 𝐃𝐨𝐭 𝐎𝐩𝐞𝐫𝐚𝐭𝐨𝐫𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧 𝐭𝐨 𝐀𝐝𝐝 𝐓𝐰𝐨 𝐍𝐮𝐦𝐛𝐞𝐫𝐬

#include <iostream>
using namespace std;

// Function definition (above main)
int add(int a, int b) {
    int c = a + b;
    return c;
}

int main() {
    int num1 = 10;
    int num2 = 15;
    int sum;

    sum = add(num1, num2);  // Function call

    cout << "Sum is " << sum << endl;  // Output: Sum is 25

    return 0;
}

// 𝐀𝐜𝐭𝐮𝐚𝐥 𝐯𝐬 𝐅𝐨𝐫𝐦𝐚𝐥 𝐏𝐚𝐫𝐚𝐦𝐞𝐭𝐞𝐫𝐬

sum = add(num1, num2);  // num1, num2 = Actual parameters (passed by caller)

int add(int a, int b)   // a, b = Formal parameters (used inside function)
// Values of actual parameters are COPIED into formal parameters

// 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧 𝐒𝐭𝐫𝐮𝐜𝐭𝐮𝐫𝐞 𝐛𝐫𝐞𝐚𝐤𝐝𝐨𝐰𝐧

int       add      (int a, int b)
↑          ↑              ↑
Return    Function      Parameters
type      name