// 𝐂𝐨𝐦𝐩𝐥𝐞𝐭𝐞 𝐂++ 𝐂𝐥𝐚𝐬𝐬 — 𝐑𝐞𝐜𝐭𝐚𝐧𝐠𝐥𝐞

#include <iostream>
using namespace std;

class Rectangle {
    private:
        int length;
        int breadth;

    public:
        // Default Constructor (Non-parameterized)
        Rectangle() {
            length = 0;
            breadth = 0;
        }

        // Parameterized Constructor
        Rectangle(int l, int b) {
            length = l;
            breadth = b;
        }

        // Mutator functions (setters)
        void setLength(int l) {
            length = l;
        }

        void setBreadth(int b) {
            breadth = b;
        }

        // Accessor functions (getters)
        int getLength() {
            return length;
        }

        int getBreadth() {
            return breadth;
        }

        // Actual methods
        int area() {
            return length * breadth;
        }

        int perimeter() {
            return 2 * (length + breadth);
        }

        // Destructor
        ~Rectangle() {
            cout << "Destructor called" << endl;
        }
};

int main() {
    Rectangle r(10, 5);  // Parameterized Constructor called

    cout << r.area() << endl;       // Output: 50
    cout << r.perimeter() << endl;  // Output: 30

    return 0;
    // Destructor called automatically when object goes out of scope
}
```

**Output:**
```
50
30
Destructor called

// 𝐀𝐥𝐥 𝐌𝐞𝐭𝐡𝐨𝐝𝐬 𝐚𝐭 𝐚 𝐆𝐥𝐚𝐧𝐜𝐞

// Constructors
Rectangle()           // Default — sets length=0, breadth=0
Rectangle(int l, int b) // Parameterized — sets given values

// Mutators (Setters) — for modifying properties
void setLength(int l)
void setBreadth(int b)

// Accessors (Getters) — for reading properties
int getLength()
int getBreadth()

// Core methods
int area()            // returns length * breadth
int perimeter()       // returns 2 * (length + breadth)

// Destructor
~Rectangle()          // called automatically when object is destroyed