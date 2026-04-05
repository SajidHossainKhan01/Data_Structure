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

// LINEAR SEARCH — basic (no improvement)
int linearSearch(struct Array arr, int key) {
    for (int i = 0; i < arr.length; i++) {
        if (key == arr.A[i])
            return i;
    }
    return -1;
}

// IMPROVEMENT 1 — TRANSPOSITION
// Move found element one position forward
int linearSearchTransposition(struct Array *arr, int key) {
    for (int i = 0; i < arr->length; i++) {
        if (key == arr->A[i]) {
            // swap with previous element
            int temp        = arr->A[i - 1];
            arr->A[i - 1]   = arr->A[i];
            arr->A[i]       = temp;
            return i - 1;   // new index after swap
        }
    }
    return -1;
}

// IMPROVEMENT 2 — MOVE TO FRONT (Move to Head)
// Move found element directly to beginning
int linearSearchMoveToFront(struct Array *arr, int key) {
    for (int i = 0; i < arr->length; i++) {
        if (key == arr->A[i]) {
            // swap with first element
            int temp    = arr->A[0];
            arr->A[0]   = arr->A[i];
            arr->A[i]   = temp;
            return 0;   // element is now at index 0
        }
    }
    return -1;
}

int main() {

    struct Array arr1 = {{8, 3, 7, 12, 6, 1, 9, 5, 2, 4}, 10, 10};
    struct Array arr2 = {{8, 3, 7, 12, 6, 1, 9, 5, 2, 4}, 10, 10};

    printf("Original array:\n");
    display(arr1);

    // TRANSPOSITION — search for 5
    printf("\n--- Transposition ---\n");
    int idx = linearSearchTransposition(&arr1, 5);
    printf("Found at index: %d\n", idx);
    display(arr1);   // 5 moved one step forward

    // Search again — 5 moves closer each time
    idx = linearSearchTransposition(&arr1, 5);
    printf("Found at index: %d\n", idx);
    display(arr1);   // 5 moved one more step forward

    // MOVE TO FRONT — search for 5
    printf("\n--- Move To Front ---\n");
    idx = linearSearchMoveToFront(&arr2, 5);
    printf("Found at index: %d\n", idx);
    display(arr2);   // 5 moved directly to front

    // Search again — already at front, found in 1 comparison
    idx = linearSearchMoveToFront(&arr2, 5);
    printf("Found at index: %d\n", idx);
    display(arr2);

    return 0;
}

// 𝐓𝐫𝐚𝐧𝐬𝐩𝐨𝐬𝐢𝐭𝐢𝐨𝐧 — 𝐬𝐞𝐚𝐫𝐜𝐡𝐢𝐧𝐠 𝐟𝐨𝐫 𝟓 𝐫𝐞𝐩𝐞𝐚𝐭𝐞𝐝𝐥𝐲:

Start:    [8, 3, 7, 12, 6, 1, 9, 5, 2, 4]
                                   ↑ index 7

Search 1: swap with index 6
          [8, 3, 7, 12, 6, 1, 5, 9, 2, 4]  → found at 6

Search 2: swap with index 5
          [8, 3, 7, 12, 6, 5, 1, 9, 2, 4]  → found at 5

Search 3: swap with index 4
          [8, 3, 7, 12, 5, 6, 1, 9, 2, 4]  → found at 4

(moves closer by 1 each search)

// 𝐌𝐨𝐯𝐞 𝐓𝐨 𝐅𝐫𝐨𝐧𝐭 — 𝐬𝐞𝐚𝐫𝐜𝐡𝐢𝐧𝐠 𝐟𝐨𝐫 𝟓:

Start:    [8, 3, 7, 12, 6, 1, 9, 5, 2, 4]
                                   ↑ index 7

Search 1: swap with index 0
          [5, 3, 7, 12, 6, 1, 9, 8, 2, 4]  → found at 0

Search 2: already at front!
          [5, 3, 7, 12, 6, 1, 9, 8, 2, 4]  → found at 0 (1 comparison)
