#include <stdio.h>

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

// SWAP helper function
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// BASIC Linear Search — call by value (no modification)
int linearSearch(struct Array arr, int key) {
    for (int i = 0; i < arr.length; i++) {
        if (key == arr.A[i])
            return i;
    }
    return -1;
}

// IMPROVEMENT 1 — Transposition (call by address to modify array)
int linearSearchTransposition(struct Array *arr, int key) {
    for (int i = 0; i < arr->length; i++) {
        if (key == arr->A[i]) {
            if (i > 0)                              // avoid swapping index 0
                swap(&arr->A[i], &arr->A[i - 1]);  // swap with previous
            return i - 1;
        }
    }
    return -1;
}

// IMPROVEMENT 2 — Move To Head (call by address to modify array)
int linearSearchMoveToHead(struct Array *arr, int key) {
    for (int i = 0; i < arr->length; i++) {
        if (key == arr->A[i]) {
            swap(&arr->A[i], &arr->A[0]);   // swap with first element
            return 0;
        }
    }
    return -1;
}

int main() {

    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    display(arr);

    // Basic linear search
    printf("Basic search:\n");
    printf("Index of 4: %d\n", linearSearch(arr, 4));    // Output: 2
    printf("Index of 6: %d\n", linearSearch(arr, 6));    // Output: 4
    printf("Index of 15: %d\n", linearSearch(arr, 15));  // Output: -1

    // Transposition
    printf("\nTransposition search for 5:\n");
    printf("Found at index: %d\n", linearSearchTransposition(&arr, 5));
    display(arr);   // 5 moves one step forward

    // Move To Head
    struct Array arr2 = {{2, 3, 4, 5, 6}, 10, 5};
    printf("\nMove To Head search for 5:\n");
    printf("Found at index: %d\n", linearSearchMoveToHead(&arr2, 5));
    display(arr2);  // 5 moved to front

    return 0;
}

// 𝐎𝐮𝐭𝐩𝐮𝐭:

Elements are:
2 3 4 5 6

Basic search:
Index of 4:  2
Index of 6:  4
Index of 15: -1

Transposition search for 5:
Found at index: 2
Elements are:
2 3 5 4 6

Move To Head search for 5:
Found at index: 0
Elements are:
5 3 4 2 6