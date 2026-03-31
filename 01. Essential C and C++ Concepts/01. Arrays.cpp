// 𝐁𝐚𝐬𝐢𝐜 𝐀𝐫𝐫𝐚𝐲 𝐃𝐞𝐜𝐥𝐚𝐫𝐚𝐭𝐢𝐨𝐧 & 𝐀𝐬𝐬𝐢𝐠𝐧𝐦𝐞𝐧𝐭

#include <iostream>
using namespace std;

int main() {
    int a[5];
    a[0] = 12;
    a[1] = 15;
    a[2] = 25;

    cout << sizeof(a) << endl;  // Output: 20
    cout << a[1] << endl;       // Output: 15

    printf("%d\n", a[2]);       // Output: 25

    return 0;
}

// 𝐀𝐫𝐫𝐚𝐲 𝐈𝐧𝐢𝐭𝐢𝐚𝐥𝐢𝐳𝐚𝐭𝐢𝐨𝐧

int a[] = {2, 4, 6, 8, 10, 12, 14};  // Size auto-determined (7)

// With fixed size (extra elements become 0)
int a[10] = {2, 4, 6, 8, 10, 12};

// Initialize entire array to zero
int a[10] = {0};

// 𝐃𝐢𝐬𝐩𝐥𝐚𝐲𝐢𝐧𝐠 𝐀𝐫𝐫𝐚𝐲 𝐰𝐢𝐭𝐡 𝐟𝐨𝐫 𝐋𝐨𝐨𝐩

#include <iostream>
using namespace std;

int main() {
    int a[10] = {2, 4, 6, 8, 10, 12};

    for (int i = 0; i < 10; i++) {
        cout << a[i] << endl;
    }

    return 0;
}

// 𝐃𝐢𝐬𝐩𝐥𝐚𝐲𝐢𝐧𝐠 𝐀𝐫𝐫𝐚𝐲 𝐰𝐢𝐭𝐡 𝐟𝐨𝐫-𝐞𝐚𝐜𝐡 𝐋𝐨𝐨𝐩 (𝐂++)

#include <iostream>
using namespace std;

int main() {
    int a[10] = {2, 4, 6, 8, 10, 12};

    for (int x : a) {
        cout << x << endl;
    }

    return 0;
}

// 𝐕𝐚𝐫𝐢𝐚𝐛𝐥𝐞-𝐒𝐢𝐳𝐞𝐝 𝐀𝐫𝐫𝐚𝐲 (𝐮𝐬𝐞𝐫 𝐢𝐧𝐩𝐮𝐭)

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int a[n];  // Variable size array — cannot be initialized directly
    a[0] = 2;  // Manual assignment

    for (int x : a) {
        cout << x << endl;  // Rest will be garbage values
    }

    return 0;
}