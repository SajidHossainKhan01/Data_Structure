#include <iostream>
using namespace std;

// TEMPLATE class for generic array
template <class T>
class Array {
private:
    T *A;
    int size;
    int length;

public:
    // Non-parameterized Constructor — default size 10
    Array() {
        size   = 10;
        length = 0;
        A      = new T[size];
    }

    // Parameterized Constructor — user-specified size
    Array(int sz) {
        size   = sz;
        length = 0;
        A      = new T[size];
    }

    // Destructor — release heap memory
    ~Array() {
        delete[] A;
    }

    // Function prototypes
    void display();
    void insert(int index, T x);
    T    Delete(int index);
};

// ============ FUNCTION IMPLEMENTATIONS ============

// DISPLAY
template <class T>
void Array<T>::display() {
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

// INSERT
template <class T>
void Array<T>::insert(int index, T x) {
    if (index >= 0 && index <= length) {
        // shift elements right
        for (int i = length - 1; i >= index; i--)
            A[i + 1] = A[i];
        A[index] = x;
        length++;
    }
}

// DELETE
template <class T>
T Array<T>::Delete(int index) {
    T x = 0;
    if (index >= 0 && index < length) {
        x = A[index];
        // shift elements left
        for (int i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
    }
    return x;
}

// ============ MAIN ============
int main() {

    // INTEGER array
    cout << "--- Integer Array ---" << endl;
    Array<int> arr(10);
    arr.insert(0, 5);
    arr.insert(1, 6);
    arr.insert(2, 9);
    arr.display();              // Output: 5 6 9

    cout << arr.Delete(0) << endl;  // Output: 5 (deleted)
    arr.display();              // Output: 6 9

    // FLOAT array
    cout << "\n--- Float Array ---" << endl;
    Array<float> arr2(10);
    arr2.insert(0, 5.2);
    arr2.insert(1, 6.4);
    arr2.insert(2, 9.1);
    arr2.display();             // Output: 5.2 6.4 9.1

// 𝐎𝐮𝐭𝐩𝐮𝐭:

--- Integer Array ---
5 6 9
5
6 9

--- Float Array ---
5.2 6.4 9.1
5.2
6.4 9.1

--- Character Array ---
A C D
A
C D

// 𝐂 → 𝐂++ → 𝐓𝐞𝐦𝐩𝐥𝐚𝐭𝐞 𝐩𝐫𝐨𝐠𝐫𝐞𝐬𝐬𝐢𝐨𝐧:

// C struct
struct Array { int *A; int size; int length; };
void display(struct Array arr) { ... }

// C++ class (int only)
class Array {
    int *A; int size; int length;
public:
    void display() { ... }   // no array parameter needed
};

// C++ template (any type)
template <class T>
class Array {
    T *A; int size; int length;
public:
    void display() { ... }
};
Array<int>   arr1;    // integer array
Array<float> arr2;    // float array
Array<char>  arr3;    // character array