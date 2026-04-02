// 𝐂 𝐋𝐚𝐧𝐠𝐮𝐚𝐠𝐞 𝐒𝐭𝐲𝐥𝐞 (𝐁𝐞𝐟𝐨𝐫𝐞 𝐓𝐫𝐚𝐧𝐬𝐟𝐨𝐫𝐦𝐚𝐭𝐢𝐨𝐧)

#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

void initialize(Rectangle *r, int l, int b) {
    r->length = l;
    r->breadth = b;
}

int area(Rectangle r) {
    return r.length * r.breadth;
}

void changeLength(Rectangle *r, int newLength) {
    r->length = newLength;
}

int main() {
    Rectangle R;

    initialize(&R, 10, 5);
    area(R);
    changeLength(&R, 20);

    return 0;
}

// 𝐂++ 𝐒𝐭𝐲𝐥𝐞 — 𝐂𝐥𝐚𝐬𝐬 𝐖𝐢𝐭𝐡𝐨𝐮𝐭 𝐂𝐨𝐧𝐬𝐭𝐫𝐮𝐜𝐭𝐨𝐫

#include <iostream>
using namespace std;

class Rectangle {
    private:
        int length;   // Data members — private
        int breadth;

    public:
        void initialize(int l, int b) {  // No need to pass Rectangle
            length = l;                  // directly accessible
            breadth = b;
        }

        int area() {
            return length * breadth;     // directly accessible
        }

        void changeLength(int newLength) {
            length = newLength;          // directly accessible
        }
};

int main() {
    Rectangle R;         // Object (not variable)

    R.initialize(10, 5); // Call using dot operator
    R.area();
    R.changeLength(20);

    return 0;
}

// 𝐂++ 𝐒𝐭𝐲𝐥𝐞 — 𝐂𝐥𝐚𝐬𝐬 𝐖𝐢𝐭𝐡 𝐂𝐨𝐧𝐬𝐭𝐫𝐮𝐜𝐭𝐨𝐫 (𝐅𝐢𝐧𝐚𝐥 𝐕𝐞𝐫𝐬𝐢𝐨𝐧)

#include <iostream>
using namespace std;

class Rectangle {
    private:
        int length;
        int breadth;

    public:
        // Constructor — same name as class, no return type
        // Called automatically when object is created
        Rectangle(int l, int b) {
            length = l;
            breadth = b;
        }

        int area() {
            return length * breadth;
        }

        void changeLength(int newLength) {
            length = newLength;
        }
};

int main() {
    Rectangle R(10, 5);  // Object created + Constructor called automatically

    R.area();            // Output: 50
    R.changeLength(20);  // length becomes 20

    return 0;
}