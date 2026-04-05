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

// BINARY SEARCH — ITERATIVE version
int binarySearch(struct Array arr, int key) {
    int low  = 0;
    int high = arr.length - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (key == arr.A[mid])
            return mid;           // found
        else if (key < arr.A[mid])
            high = mid - 1;       // search left half
        else
            low = mid + 1;        // search right half
    }

    return -1;                    // not found
}

// BINARY SEARCH — RECURSIVE version
int rBinSearch(int A[], int low, int high, int key) {
    int mid;

    if (low <= high) {
        mid = (low + high) / 2;

        if (key == A[mid])
            return mid;                                    // found
        else if (key < A[mid])
            return rBinSearch(A, low, mid - 1, key);      // left half
        else
            return rBinSearch(A, mid + 1, high, key);     // right half
    }

    return -1;                    // not found
}

int main() {

    // SORTED array — required for binary search
    struct Array arr = {{2, 3, 4, 5, 6, 7, 8, 9}, 10, 8};

    display(arr);

    // Iterative binary search
    printf("\n--- Iterative Binary Search ---\n");
    printf("Search 5:  index = %d\n", binarySearch(arr, 5));   // Output: 3
    printf("Search 2:  index = %d\n", binarySearch(arr, 2));   // Output: 0
    printf("Search 10: index = %d\n", binarySearch(arr, 10));  // Output: -1
    printf("Search 15: index = %d\n", binarySearch(arr, 15));  // Output: -1

    // Recursive binary search
    printf("\n--- Recursive Binary Search ---\n");
    printf("Search 5: index = %d\n",
        rBinSearch(arr.A, 0, arr.length - 1, 5));   // Output: 3
    printf("Search 2: index = %d\n",
        rBinSearch(arr.A, 0, arr.length - 1, 2));   // Output: 0
    printf("Search 9: index = %d\n",
        rBinSearch(arr.A, 0, arr.length - 1, 9));   // Output: 7 (last element)
    printf("Search 9: index = %d\n",
        rBinSearch(arr.A, 0, arr.length - 1, 10));  // Output: -1

    return 0;
}

// 𝐎𝐮𝐭𝐩𝐮𝐭:

Elements are:
2 3 4 5 6 7 8 9

--- Iterative Binary Search ---
Search 5:  index = 3
Search 2:  index = 0
Search 10: index = -1
Search 15: index = -1

--- Recursive Binary Search ---
Search 5:  index = 3
Search 2:  index = 0
Search 9:  index = 7
Search 10: index = -1

// 𝐓𝐫𝐚𝐜𝐢𝐧𝐠 𝐬𝐞𝐚𝐫𝐜𝐡 𝐟𝐨𝐫 𝐤𝐞𝐲=𝟓 𝐢𝐧 [𝟐,𝟑,𝟒,𝟓,𝟔,𝟕,𝟖,𝟗]:

low=0, high=7, mid=3 → A[3]=5 == 5 → return 3 ✓ (found in 1 step!)

// 𝐓𝐫𝐚𝐜𝐢𝐧𝐠 𝐬𝐞𝐚𝐫𝐜𝐡 𝐟𝐨𝐫 𝐤𝐞𝐲=𝟏𝟎 (𝐧𝐨𝐭 𝐟𝐨𝐮𝐧𝐝):

low=0, high=7, mid=3 → A[3]=5,  10>5  → low=4
low=4, high=7, mid=5 → A[5]=7,  10>7  → low=6
low=6, high=7, mid=6 → A[6]=8,  10>8  → low=7
low=7, high=7, mid=7 → A[7]=9,  10>9  → low=8
low=8 > high=7 → return -1 ✗