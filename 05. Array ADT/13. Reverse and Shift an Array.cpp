#include <stdio.h>
#include <stdlib.h>

// Array structure
struct Array {
    int A[10];
    int size;
    int length;
};

// Display function
void display(struct Array arr) {
    printf("Elements are:\n");
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

// SWAP helper
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// REVERSE — Method 1: using auxiliary array
void reverse(struct Array *arr) {
    int *B;
    int i, j;

    // create auxiliary array in heap
    B = (int *) malloc(arr->length * sizeof(int));

    // copy A into B in reverse order
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++) {
        B[j] = arr->A[i];
    }

    // copy B back into A
    for (i = 0; i < arr->length; i++) {
        arr->A[i] = B[i];
    }

    free(B);
}

// REVERSE — Method 2: swap from both ends (no auxiliary array)
void reverse2(struct Array *arr) {
    int i = 0;
    int j = arr->length - 1;

    while (i < j) {
        swap(&arr->A[i], &arr->A[j]);
        i++;
        j--;
    }
}

int main() {

    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    display(arr);

    // Method 1 — auxiliary array
    reverse(&arr);
    printf("After reverse (Method 1):\n");
    display(arr);   // Output: 6 5 4 3 2

    // Reset
    struct Array arr2 = {{2, 3, 4, 5, 6}, 10, 5};

    // Method 2 — swap from both ends
    reverse2(&arr2);
    printf("After reverse (Method 2):\n");
    display(arr2);  // Output: 6 5 4 3 2

    return 0;
}

// 𝐇𝐨𝐰 𝐌𝐞𝐭𝐡𝐨𝐝 𝟏 𝐰𝐨𝐫𝐤𝐬 (𝐚𝐮𝐱𝐢𝐥𝐢𝐚𝐫𝐲 𝐚𝐫𝐫𝐚𝐲):

A = [2, 3, 4, 5, 6]
     0  1  2  3  4

Copy A→B (right to left → left to right):
i=4,j=0: B[0]=A[4]=6
i=3,j=1: B[1]=A[3]=5
i=2,j=2: B[2]=A[2]=4
i=1,j=3: B[3]=A[1]=3
i=0,j=4: B[4]=A[0]=2

B = [6, 5, 4, 3, 2]

Copy B→A:
A = [6, 5, 4, 3, 2] ✓

// 𝐇𝐨𝐰 𝐌𝐞𝐭𝐡𝐨𝐝 𝟐 𝐰𝐨𝐫𝐤𝐬 (𝐬𝐰𝐚𝐩 𝐟𝐫𝐨𝐦 𝐛𝐨𝐭𝐡 𝐞𝐧𝐝𝐬):

A = [2, 3, 4, 5, 6]
     i           j

Step 1: swap(A[0], A[4]) → [6, 3, 4, 5, 2]  i=1, j=3
Step 2: swap(A[1], A[3]) → [6, 5, 4, 3, 2]  i=2, j=2
Step 3: i >= j → STOP

Result: [6, 5, 4, 3, 2] ✓


