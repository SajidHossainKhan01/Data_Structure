// Basic Array Declaration & Assignment

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

// Array Initialization

int a[] = {2, 4, 6, 8, 10, 12, 14};  // Size auto-determined (7)

// With fixed size (extra elements become 0)
int a[10] = {2, 4, 6, 8, 10, 12};

// Initialize entire array to zero
int a[10] = {0};

// Displaying Array with for Loop

#include <iostream>
using namespace std;

int main() {
    int a[10] = {2, 4, 6, 8, 10, 12};

    for (int i = 0; i < 10; i++) {
        cout << a[i] << endl;
    }

    return 0;
}

// Displaying Array with for-each Loop (C++)

#include <iostream>
using namespace std;

int main() {
    int a[10] = {2, 4, 6, 8, 10, 12};

    for (int x : a) {
        cout << x << endl;
    }

    return 0;
}

// Variable-Sized Array (user input)

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