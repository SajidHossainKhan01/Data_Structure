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

// MERGE — merge two sorted arrays into a third sorted array
struct Array* merge(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;

    // create third array in heap
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    arr3->size   = 10;
    arr3->length = 0;

    // compare and copy elements one by one
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }

    // copy remaining elements of arr1 (if any)
    while (i < arr1->length)
        arr3->A[k++] = arr1->A[i++];

    // copy remaining elements of arr2 (if any)
    while (j < arr2->length)
        arr3->A[k++] = arr2->A[j++];

    // set length of merged array
    arr3->length = arr1->length + arr2->length;

    return arr3;
}

int main() {

    // Two SORTED arrays
    struct Array arr1 = {{2, 6, 10, 15, 25}, 10, 5};
    struct Array arr2 = {{3, 4, 7, 18, 20},  10, 5};

    printf("Array 1:\n");
    display(arr1);

    printf("Array 2:\n");
    display(arr2);

    // Merge
    struct Array *arr3 = merge(&arr1, &arr2);

    printf("Merged Array:\n");
    display(*arr3);   // Output: 2 3 4 6 7 10 15 18 20 25

    free(arr3);

    return 0;
}

// 𝐇𝐨𝐰 𝐌𝐄𝐑𝐆𝐄 𝐰𝐨𝐫𝐤𝐬 𝐬𝐭𝐞𝐩 𝐛𝐲 𝐬𝐭𝐞𝐩:

arr1 = [2,  6, 10, 15, 25]
arr2 = [3,  4,  7, 18, 20]
arr3 = []

i=0,j=0: 2 < 3  → arr3[0]=2,  i=1
i=1,j=0: 6 > 3  → arr3[1]=3,  j=1
i=1,j=1: 6 > 4  → arr3[2]=4,  j=2
i=1,j=2: 6 < 7  → arr3[3]=6,  i=2
i=2,j=2: 10 > 7 → arr3[4]=7,  j=3
i=2,j=3: 10 < 18→ arr3[5]=10, i=3
i=3,j=3: 15 < 18→ arr3[6]=15, i=4
i=4,j=3: 25 > 18→ arr3[7]=18, j=4
i=4,j=4: 25 > 20→ arr3[8]=20, j=5

j exhausted → copy remaining arr1:
arr3[9]=25

Result: [2, 3, 4, 6, 7, 10, 15, 18, 20, 25] ✓

// 𝐓𝐡𝐫𝐞𝐞 𝐩𝐡𝐚𝐬𝐞𝐬 𝐨𝐟 𝐦𝐞𝐫𝐠𝐞:

Phase 1: Compare & copy (both arrays have elements)
Phase 2: Copy remaining from arr1 (if arr2 exhausted first)
Phase 3: Copy remaining from arr2 (if arr1 exhausted first)

