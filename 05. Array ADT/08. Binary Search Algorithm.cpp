#include <stdio.h>

// Array structure
struct Array {
    int A[15];
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

// BINARY SEARCH — ITERATIVE version
int binarySearchIterative(struct Array arr, int key) {
    int low  = 0;
    int high = arr.length - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (key == arr.A[mid])
            return mid;          // found
        else if (key < arr.A[mid])
            high = mid - 1;      // search left half
        else
            low = mid + 1;       // search right half
    }

    return -1;                   // not found
}

// BINARY SEARCH — RECURSIVE version (tail recursion)
int binarySearchRecursive(int A[], int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high) / 2;

        if (key == A[mid])
            return mid;                                      // found
        else if (key < A[mid])
            return binarySearchRecursive(A, low, mid-1, key);  // left half
        else
            return binarySearchRecursive(A, mid+1, high, key); // right half
    }

    return -1;                   // not found
}

int main() {

    // SORTED array — prerequisite
    struct Array arr = {
        {3, 6, 8, 12, 14, 17, 18, 21, 24, 27, 33, 34, 38, 42, 45},
        15, 15
    };

    display(arr);

    // Iterative binary search
    printf("\n--- Iterative ---\n");
    printf("Search 18: index = %d\n", binarySearchIterative(arr, 18));  // 6
    printf("Search 34: index = %d\n", binarySearchIterative(arr, 34));  // 11
    printf("Search 25: index = %d\n", binarySearchIterative(arr, 25));  // -1

    // Recursive binary search
    printf("\n--- Recursive ---\n");
    printf("Search 18: index = %d\n",
        binarySearchRecursive(arr.A, 0, arr.length-1, 18));  // 6
    printf("Search 34: index = %d\n",
        binarySearchRecursive(arr.A, 0, arr.length-1, 34));  // 11
    printf("Search 25: index = %d\n",
        binarySearchRecursive(arr.A, 0, arr.length-1, 25));  // -1

    return 0;
}

// 𝐈𝐭𝐞𝐫𝐚𝐭𝐢𝐯𝐞 𝐚𝐥𝐠𝐨𝐫𝐢𝐭𝐡𝐦 (𝐩𝐬𝐞𝐮𝐝𝐨 𝐜𝐨𝐝𝐞 𝐟𝐫𝐨𝐦 𝐥𝐞𝐜𝐭𝐮𝐫𝐞):

BinarySearch(low, high, key):
    while low <= high:
        mid = (low + high) / 2
        if key == A[mid]:
            return mid
        else if key < A[mid]:
            high = mid - 1      // search left
        else:
            low = mid + 1       // search right
    return -1                   // not found

// 𝐑𝐞𝐜𝐮𝐫𝐬𝐢𝐯𝐞 𝐚𝐥𝐠𝐨𝐫𝐢𝐭𝐡𝐦 (𝐩𝐬𝐞𝐮𝐝𝐨 𝐜𝐨𝐝𝐞 𝐟𝐫𝐨𝐦 𝐥𝐞𝐜𝐭𝐮𝐫𝐞):

RBinarySearch(low, high, key):
    if low <= high:
        mid = (low + high) / 2
        if key == A[mid]:
            return mid
        else if key < A[mid]:
            return RBinarySearch(low, mid-1, key)   // left half
        else:
            return RBinarySearch(mid+1, high, key)  // right half
    return -1
