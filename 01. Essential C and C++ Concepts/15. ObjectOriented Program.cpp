// 𝐒𝐭𝐫𝐮𝐜𝐭𝐮𝐫𝐞 𝐰𝐢𝐭𝐡 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧𝐬 𝐈𝐧𝐬𝐢𝐝𝐞 (𝐂++ 𝐒𝐭𝐫𝐮𝐜𝐭)

#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle {
    int length;
    int breadth;

    // Functions moved INSIDE the structure
    void initialize(int l, int b) {
        length = l;   // directly accessible
        breadth = b;  // directly accessible
    }

    int area() {
        return length * breadth;  // directly accessible
    }

    int perimeter() {
        return 2 * (length + breadth);  // directly accessible
    }
};

int main() {
    Rectangle r;

    int l, b;
    printf("Enter length and breadth: ");
    scanf("%d %d", &l, &b);

    r.initialize(l, b);  // call using dot operator

    printf("Area = %d\n", r.area());
    printf("Perimeter = %d\n", r.perimeter());

    return 0;
}

// 𝐂𝐨𝐧𝐯𝐞𝐫𝐭 𝐭𝐨 𝐂𝐥𝐚𝐬𝐬 (𝐎𝐛𝐣𝐞𝐜𝐭 𝐎𝐫𝐢𝐞𝐧𝐭𝐞𝐝 — 𝐅𝐢𝐧𝐚𝐥 𝐕𝐞𝐫𝐬𝐢𝐨𝐧)

#include <iostream>
#include <stdio.h>
using namespace std;

class Rectangle {
    private:
        int length;   // private by default in class
        int breadth;

    public:
        void initialize(int l, int b) {
            length = l;
            breadth = b;
        }

        int area() {
            return length * breadth;
        }

        int perimeter() {
            return 2 * (length + breadth);
        }
};

int main() {
    Rectangle r;  // Object of class Rectangle

    int l, b;
    printf("Enter length and breadth: ");
    scanf("%d %d", &l, &b);

    r.initialize(l, b);

    printf("Area = %d\n", r.area());
    printf("Perimeter = %d\n", r.perimeter());

    return 0;
}
```

**Output:**
```
Enter length and breadth: 10 5
Area = 50
Perimeter = 30

// 𝐂𝐨𝐦𝐩𝐥𝐞𝐭𝐞 𝐄𝐯𝐨𝐥𝐮𝐭𝐢𝐨𝐧 𝐨𝐟 𝐀𝐥𝐥 𝟒 𝐒𝐭𝐲𝐥𝐞𝐬

// STYLE 1 — Monolithic
int main() { /* everything here */ }

// STYLE 2 — Modular/Procedural
int area(int l, int b) { ... }
int perimeter(int l, int b) { ... }

// STYLE 3 — Structure & Functions
struct Rectangle { int length, breadth; };
int area(Rectangle r) { ... }

// STYLE 4 — Object Oriented (Class)
class Rectangle {
    private: int length, breadth;
    public:  int area() { ... }
};