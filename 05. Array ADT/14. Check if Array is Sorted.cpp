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

// INSERT in SORTED array
void insertSort(struct Array *arr, int x) {
    if (arr->length == arr->size)   // no space
        return;

    int i = arr->length - 1;

    // shift larger elements right
    while (i >= 0 && arr->A[i] > x) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }

    arr->A[i + 1] = x;     // insert at correct position
    arr->length++;
}

// IS SORTED — returns 1 if sorted, 0 if not
int isSorted(struct Array arr) {
    for (int i = 0; i < arr.length - 1; i++) {
        if (arr.A[i] > arr.A[i + 1])
            return 0;       // not sorted
    }
    return 1;               // sorted
}

// REARRANGE — negatives on left, positives on right
void rearrange(struct Array *arr) {
    int i = 0;
    int j = arr->length - 1;

    while (i < j) {
        while (arr->A[i] < 0) i++;     // find positive from left
        while (arr->A[j] >= 0) j--;    // find negative from right
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}

int main() {

    // Sorted array for insertSort and isSorted
    struct Array arr = {{2, 3, 5, 10, 15}, 10, 5};

    display(arr);

    // INSERT in sorted position
    insertSort(&arr, 20);
    printf("After inserting 20:\n");
    display(arr);   // Output: 2 3 5 10 15 20

    insertSort(&arr, 12);
    printf("After inserting 12:\n");
    display(arr);   // Output: 2 3 5 10 12 15 20

    insertSort(&arr, 4);
    printf("After inserting 4:\n");
    display(arr);   // Output: 2 3 4 5 10 12 15 20

    insertSort(&arr, 1);
    printf("After inserting 1:\n");
    display(arr);   // Output: 1 2 3 4 5 10 12 15 20

    // IS SORTED
    struct Array arr2 = {{2, 3, 5, 10, 15}, 10, 5};
    printf("\nisSorted (sorted array):   %d\n", isSorted(arr2));  // Output: 1

    struct Array arr3 = {{2, 3, 25, 10, 15}, 10, 5};
    printf("isSorted (unsorted array): %d\n", isSorted(arr3));   // Output: 0

    // REARRANGE — negatives left, positives right
    struct Array arr4 = {{2, -5, 3, -3, 25, -7}, 10, 6};
    printf("\nBefore rearrange:\n");
    display(arr4);
    rearrange(&arr4);
    printf("After rearrange:\n");
    display(arr4);  // Output: negatives left, positives right

    return 0;
}

// 𝐇𝐨𝐰 𝐈𝐍𝐒𝐄𝐑𝐓 𝐒𝐎𝐑𝐓𝐄𝐃 𝐰𝐨𝐫𝐤𝐬 (𝐢𝐧𝐬𝐞𝐫𝐭𝐢𝐧𝐠 𝟒 𝐢𝐧𝐭𝐨 [𝟐,𝟑,𝟓,𝟏𝟎,𝟏𝟓]):

i=4: A[4]=15 > 4 → A[5]=15, i=3
i=3: A[3]=10 > 4 → A[4]=10, i=2
i=2: A[2]=5  > 4 → A[3]=5,  i=1
i=1: A[1]=3  > 4? NO → stop

Insert at i+1 = 2: A[2]=4
Result: [2, 3, 4, 5, 10, 15] ✓

// 𝐇𝐨𝐰 𝐑𝐄𝐀𝐑𝐑𝐀𝐍𝐆𝐄 𝐰𝐨𝐫𝐤𝐬 ([𝟐,-𝟓,𝟑,-𝟑,𝟐𝟓,-𝟕]):

i=0, j=5
A[0]=2  ≥ 0 → stop i     A[5]=-7 < 0 → stop j
swap(A[0], A[5]) → [-7,-5,3,-3,25,2]  i=1,j=4

A[1]=-5 < 0 → i++        A[4]=25 ≥ 0 → stop j
A[2]=3  ≥ 0 → stop i
swap(A[2], A[4]) → [-7,-5,-3,3,25,2]  -- wait j moved
...
Result: [-7,-5,-3, 2,3,25] ✓