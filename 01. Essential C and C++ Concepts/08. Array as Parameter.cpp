// 𝐁𝐚𝐬𝐢𝐜 𝐀𝐫𝐫𝐚𝐲 𝐰𝐢𝐭𝐡 𝐅𝐨𝐫-𝐄𝐚𝐜𝐡 𝐋𝐨𝐨𝐩 (𝐢𝐧 𝐦𝐚𝐢𝐧)

#include <iostream>
using namespace std;

int main() {
    int a[] = {2, 4, 6, 8, 10};
    int n = 5;

    for (int x : a)
        cout << x << " ";

    return 0;
}

// 𝐏𝐚𝐬𝐬𝐢𝐧𝐠 𝐀𝐫𝐫𝐚𝐲 𝐭𝐨 𝐚 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧 (𝐰𝐢𝐭𝐡 𝐬𝐢𝐳𝐞)

#include <iostream>
using namespace std;

void fun(int a[], int n) {  // Can also write int *a instead of int a[]
    // sizeof(a) here gives size of POINTER (8 bytes), not array!

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[] = {2, 4, 6, 8, 10};
    int n = 5;

    fun(a, n);  // Pass array and its size

    return 0;
}

// 𝐀𝐫𝐫𝐚𝐲 𝐏𝐚𝐬𝐬𝐞𝐝 𝐛𝐲 𝐀𝐝𝐝𝐫𝐞𝐬𝐬 — 𝐂𝐡𝐚𝐧𝐠𝐞𝐬 𝐑𝐞𝐟𝐥𝐞𝐜𝐭 𝐁𝐚𝐜𝐤

#include <iostream>
using namespace std;

void fun(int a[], int n) {
    a[0] = 15;  // Modifying first element

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[] = {2, 4, 6, 8, 10};
    int n = 5;

    fun(a, n);

    // Print again in main to verify change
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";  // Output: 15 4 6 8 10

    return 0;
}

// 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧 𝐂𝐫𝐞𝐚𝐭𝐢𝐧𝐠 & 𝐑𝐞𝐭𝐮𝐫𝐧𝐢𝐧𝐠 𝐀𝐫𝐫𝐚𝐲 𝐟𝐫𝐨𝐦 𝐇𝐞𝐚𝐩

#include <iostream>
using namespace std;

int* fun(int size) {          // Return type is pointer
    int *p = new int[size];   // Array created in Heap

    for (int i = 0; i < size; i++)
        p[i] = i + 1;         // Fill with 1, 2, 3...

    return p;                 // Return pointer to heap array
}

int main() {
    int s = 5;
    int *ptr = fun(s);        // Receive heap array pointer

    for (int i = 0; i < s; i++)
        cout << ptr[i] << endl;  // Output: 1 2 3 4 5

    delete[] ptr;  // Free heap memory

    return 0;
}
