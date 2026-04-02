// 𝐁𝐚𝐬𝐢𝐜 𝐂𝐥𝐚𝐬𝐬 𝐰𝐢𝐭𝐡 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧𝐬 𝐈𝐧𝐬𝐢𝐝𝐞

#include <iostream>
using namespace std;

class Arithmetic {
    private:
        int a;
        int b;

    public:
        // Constructor using 'this' pointer
        Arithmetic(int a, int b) {
            this->a = a;  // this->a = data member, a = parameter
            this->b = b;
        }

        int add() {
            int c = a + b;
            return c;
        }

        int subtract() {
            int c = a - b;
            return c;
        }
};

int main() {
    Arithmetic ar(10, 5);

    cout << "Result of add: "      << ar.add()      << endl; // 15
    cout << "Result of subtract: " << ar.subtract() << endl; // 5

    return 0;
}

// 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧𝐬 𝐈𝐦𝐩𝐥𝐞𝐦𝐞𝐧𝐭𝐞𝐝 𝐎𝐮𝐭𝐬𝐢𝐝𝐞 𝐭𝐡𝐞 𝐂𝐥𝐚𝐬𝐬

#include <iostream>
using namespace std;

class Arithmetic {
    private:
        int a;
        int b;

    public:
        Arithmetic(int a, int b) {
            this->a = a;
            this->b = b;
        }

        int add();       // Declaration inside class
        int subtract();  // Declaration inside class
};

// Definitions outside class using scope resolution operator (::)
int Arithmetic::add() {
    int c = a + b;
    return c;
}

int Arithmetic::subtract() {
    int c = a - b;
    return c;
}

int main() {
    Arithmetic ar(10, 5);

    cout << "Result of add: "      << ar.add()      << endl; // 15
    cout << "Result of subtract: " << ar.subtract() << endl; // 5

    return 0;
}

𝐂𝐨𝐧𝐯𝐞𝐫𝐭 𝐭𝐨 𝐓𝐞𝐦𝐩𝐥𝐚𝐭𝐞 𝐂𝐥𝐚𝐬𝐬 (𝐅𝐢𝐧𝐚𝐥 𝐕𝐞𝐫𝐬𝐢𝐨𝐧)

#include <iostream>
using namespace std;

template <class T>
class Arithmetic {
    private:
        T a;
        T b;

    public:
        Arithmetic(T a, T b) {
            this->a = a;
            this->b = b;
        }

        T add();
        T subtract();
};

// Outside definitions — must repeat template declaration
template <class T>
T Arithmetic<T>::add() {
    T c = a + b;
    return c;
}

template <class T>
T Arithmetic<T>::subtract() {
    T c = a - b;
    return c;
}

int main() {
    // Works with int
    Arithmetic<int> ar1(10, 5);
    cout << ar1.add()      << endl;  // 15
    cout << ar1.subtract() << endl;  // 5

    // Works with float
    Arithmetic<float> ar2(10.99, 5.44);
    cout << ar2.add()      << endl;  // 16.43
    cout << ar2.subtract() << endl;  // 5.55

    // Works with char
    Arithmetic<char> ar3('B', 'A');
    cout << (int)ar3.add()      << endl;  // overflow
    cout << (int)ar3.subtract() << endl;  // 1

    return 0;
}