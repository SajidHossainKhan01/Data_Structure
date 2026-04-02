#include <stdio.h>

int main() {
    int a;      // integer - takes 2 bytes (assumed for explanation)
    float b;    // float   - takes 4 bytes

    return 0;
}

// 𝐒𝐞𝐪𝐮𝐞𝐧𝐜𝐞 𝐨𝐟 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧 𝐂𝐚𝐥𝐥𝐬 (𝐒𝐭𝐚𝐜𝐤 𝐃𝐞𝐦𝐨)

#include <stdio.h>

void fun2(int i) {
    int a;
    // some statements
}

void fun1() {
    int x;
    fun2(x);
    // some statement
}

int main() {
    int a;
    float b;
    fun1();
    // some statement
    return 0;
}

// 𝐃𝐲𝐧𝐚𝐦𝐢𝐜 𝐌𝐞𝐦𝐨𝐫𝐲 𝐀𝐥𝐥𝐨𝐜𝐚𝐭𝐢𝐨𝐧 𝐢𝐧 𝐇𝐞𝐚𝐩 (𝐂++)

#include <iostream>
using namespace std;

int main() {
    int *p;                      // pointer allocated in stack (2 bytes)
    p = new int[5];              // allocates array of 5 integers in Heap

    // use the memory...

    delete[] p;                  // release Heap memory
    p = NULL;                    // pointer set to null

    return 0;
}

// 𝐃𝐲𝐧𝐚𝐦𝐢𝐜 𝐌𝐞𝐦𝐨𝐫𝐲 𝐀𝐥𝐥𝐨𝐜𝐚𝐭𝐢𝐨𝐧 𝐢𝐧 𝐇𝐞𝐚𝐩 (𝐂)

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;                                      // pointer allocated in stack
    p = (int*) malloc(5 * sizeof(int));          // allocates array of 5 integers in Heap

    // use the memory...

    free(p);                                     // release Heap memory
    p = NULL;                                    // pointer set to null

    return 0;
}
