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

// APPEND — insert at end
void append(struct Array *arr, int x) {
    if (arr->length < arr->size) {
        arr->A[arr->length] = x;
        arr->length++;
    }
}

// INSERT — insert at given index
void insert(struct Array *arr, int index, int x) {
    if (index >= 0 && index <= arr->length) {
        // shift elements right to make space
        for (int i = arr->length; i > index; i--) {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;   // insert element
        arr->length++;
    }
}

int main() {

    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    display(arr);

    // APPEND — adds at end
    append(&arr, 10);
    display(arr);   // Output: 2 3 4 5 6 10

    // INSERT at index 0 — beginning
    // insert(&arr, 0, 10);
    // display(arr);   // Output: 10 2 3 4 5 6

    // INSERT at index 2 — middle
    // insert(&arr, 2, 10);
    // display(arr);   // Output: 2 3 10 4 5 6

    // INSERT at index 5 — end
    // insert(&arr, 5, 10);
    // display(arr);   // Output: 2 3 4 5 6 10

    // INSERT at invalid index — nothing happens
    // insert(&arr, -2, 10);
    // insert(&arr, 9, 10);

    return 0;
}

// 𝐇𝐨𝐰 𝐈𝐍𝐒𝐄𝐑𝐓 𝐰𝐨𝐫𝐤𝐬 (𝐢𝐧𝐬𝐞𝐫𝐭𝐢𝐧𝐠 𝟏𝟎 𝐚𝐭 𝐢𝐧𝐝𝐞𝐱 𝟐):

Before:  [2, 3, 4, 5, 6, _, _, _, _, _]
          0  1  2  3  4

Shift right from length down to index:
i=5: A[5] = A[4] = 6
i=4: A[4] = A[3] = 5
i=3: A[3] = A[2] = 4

Insert:  A[2] = 10
length++

After:   [2, 3, 10, 4, 5, 6, _, _, _, _]
          0  1   2  3  4  5

// 𝐇𝐨𝐰 𝐀𝐏𝐏𝐄𝐍𝐃 𝐰𝐨𝐫𝐤𝐬 (𝐢𝐧𝐬𝐞𝐫𝐭𝐢𝐧𝐠 𝟏𝟎):

Before:  [2, 3, 4, 5, 6, _, _, _, _, _]
          length=5

A[length] = 10
length++

After:   [2, 3, 4, 5, 6, 10, _, _, _, _]
          length=6
