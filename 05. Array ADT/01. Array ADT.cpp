#include <stdio.h>
#include <stdlib.h>

// Array structure definition
struct Array {
    int A[20];   // fixed size array
    int size;    // maximum size
    int length;  // current number of elements
};

// Display function
void display(struct Array arr) {
    printf("Elements are:\n");
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

int main() {

    // METHOD 1 — Dynamic array using pointer (Heap)
    // struct Array *arr;
    // arr->size = 10;
    // arr->A = (int *) malloc(arr->size * sizeof(int));
    // arr->length = 0;

    // METHOD 2 — Fixed size array (used for explanation)
    struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};
    //                   ^elements        ^size ^length

    display(arr);

    return 0;
}

// 𝐎𝐮𝐭𝐩𝐮𝐭:

Elements are:
2 3 4 5 6

// 𝐒𝐭𝐫𝐮𝐜𝐭𝐮𝐫𝐞 𝐛𝐫𝐞𝐚𝐤𝐝𝐨𝐰𝐧:

struct Array {
    int A[20];    // stores actual elements
    int size;     // max capacity (20)
    int length;   // current count (5)
}

Memory:
A    → [2, 3, 4, 5, 6, 0, 0, 0, 0, 0, ...]  (20 slots)
size → 20
length → 5

// 𝐈𝐧𝐢𝐭𝐢𝐚𝐥𝐢𝐳𝐚𝐭𝐢𝐨𝐧 𝐬𝐲𝐧𝐭𝐚𝐱 𝐞𝐱𝐩𝐥𝐚𝐢𝐧𝐞𝐝:

struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};
//                  ^^^^^^^^^^^^^^^  ^^  ^
//                  elements         size length
//                  (first member)