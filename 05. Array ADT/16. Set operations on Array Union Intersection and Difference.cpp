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

// UNION of two sorted arrays
struct Array* unionArr(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;

    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    arr3->size = 10;

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])           // arr1 element smaller
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])      // arr2 element smaller
            arr3->A[k++] = arr2->A[j++];
        else {                                  // both equal — copy once
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    // copy remaining from arr1
    while (i < arr1->length)
        arr3->A[k++] = arr1->A[i++];

    // copy remaining from arr2
    while (j < arr2->length)
        arr3->A[k++] = arr2->A[j++];

    arr3->length = k;   // length = actual elements copied
    return arr3;
}

// INTERSECTION of two sorted arrays
struct Array* intersection(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;

    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    arr3->size = 10;

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])           // arr1 smaller — skip
            i++;
        else if (arr2->A[j] < arr1->A[i])      // arr2 smaller — skip
            j++;
        else {                                  // both equal — copy
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    // NO remaining elements copied
    arr3->length = k;
    return arr3;
}

// DIFFERENCE — arr1 minus arr2
struct Array* difference(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;

    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    arr3->size = 10;

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])           // arr1 smaller — copy
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])      // arr2 smaller — skip arr2
            j++;
        else {                                  // both equal — skip both
            i++;
            j++;
        }
    }

    // copy remaining from arr1 ONLY
    while (i < arr1->length)
        arr3->A[k++] = arr1->A[i++];

    // do NOT copy remaining from arr2

    arr3->length = k;
    return arr3;
}

int main() {

    // Two SORTED arrays with some common elements
    struct Array arr1 = {{2,  6, 10, 15, 25}, 10, 5};
    struct Array arr2 = {{3,  6,  7, 15, 20}, 10, 5};

    printf("Array 1: "); display(arr1);
    printf("Array 2: "); display(arr2);

    // UNION
    struct Array *arr3 = unionArr(&arr1, &arr2);
    printf("\nUnion (no duplicates):\n");
    display(*arr3);   // Output: 2 3 6 7 10 15 20 25
    free(arr3);

    // INTERSECTION
    arr3 = intersection(&arr1, &arr2);
    printf("Intersection (common elements):\n");
    display(*arr3);   // Output: 6 15
    free(arr3);

    // DIFFERENCE (arr1 - arr2)
    arr3 = difference(&arr1, &arr2);
    printf("Difference arr1-arr2 (in arr1 not arr2):\n");
    display(*arr3);   // Output: 2 10 25
    free(arr3);

    return 0;
}

// 𝐇𝐨𝐰 𝐞𝐚𝐜𝐡 𝐨𝐩𝐞𝐫𝐚𝐭𝐢𝐨𝐧 𝐡𝐚𝐧𝐝𝐥𝐞𝐬 𝐞𝐪𝐮𝐚𝐥 𝐞𝐥𝐞𝐦𝐞𝐧𝐭𝐬:

arr1 = [2,  6, 10, 15, 25]
arr2 = [3,  6,  7, 15, 20]
            ^       ^
            common elements: 6 and 15

// 𝐑𝐞𝐬𝐮𝐥𝐭𝐬:

Union:        [2, 3, 6, 7, 10, 15, 20, 25]  (no duplicates)
Intersection: [6, 15]                         (common only)
Difference:   [2, 10, 25]                     (in arr1, not in arr2)
