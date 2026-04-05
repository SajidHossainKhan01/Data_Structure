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

// BINARY SEARCH — array must be sorted
int binarySearch(struct Array arr, int key) {
    int low  = 0;
    int high = arr.length - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (key == arr.A[mid])
            return mid;         // found — return index
        else if (key < arr.A[mid])
            high = mid - 1;     // search left half
        else
            low = mid + 1;      // search right half
    }

    return -1;                  // not found
}

int main() {

    // SORTED array — prerequisite for binary search
    struct Array arr = {
        {3, 6, 8, 12, 14, 17, 18, 21, 24, 27, 33, 34, 38, 42, 45},
        15, 15
    };

    display(arr);

    // Successful search — key 18 (found at index 6)
    int idx = binarySearch(arr, 18);
    if (idx != -1)
        printf("18 found at index: %d\n", idx);   // Output: 6
    else
        printf("18 not found\n");

    // Successful search — key 34 (found at index 11)
    idx = binarySearch(arr, 34);
    if (idx != -1)
        printf("34 found at index: %d\n", idx);   // Output: 11
    else
        printf("34 not found\n");

    // Unsuccessful search — key 25 (not in array)
    idx = binarySearch(arr, 25);
    if (idx != -1)
        printf("25 found at index: %d\n", idx);
    else
        printf("25 not found\n");                  // Output: not found

    return 0;
}

// 𝐓𝐫𝐚𝐜𝐢𝐧𝐠 𝐛𝐢𝐧𝐚𝐫𝐲𝐒𝐞𝐚𝐫𝐜𝐡(𝐚𝐫𝐫, 𝟏𝟖):

Array: [3,6,8,12,14,17,18,21,24,27,33,34,38,42,45]
        0 1 2  3  4  5  6  7  8  9 10 11 12 13 14

Step 1: low=0, high=14, mid=7  → A[7]=21, 18<21 → high=6
Step 2: low=0, high=6,  mid=3  → A[3]=12, 18>12 → low=4
Step 3: low=4, high=6,  mid=5  → A[5]=17, 18>17 → low=6
Step 4: low=6, high=6,  mid=6  → A[6]=18, 18==18 → return 6 ✓

Total comparisons: 4

// 𝐓𝐫𝐚𝐜𝐢𝐧𝐠 𝐛𝐢𝐧𝐚𝐫𝐲𝐒𝐞𝐚𝐫𝐜𝐡(𝐚𝐫𝐫, 𝟐𝟓) — 𝐮𝐧𝐬𝐮𝐜𝐜𝐞𝐬𝐬𝐟𝐮𝐥:

Step 1: low=0,  high=14, mid=7  → A[7]=21, 25>21 → low=8
Step 2: low=8,  high=14, mid=11 → A[11]=34, 25<34 → high=10
Step 3: low=8,  high=10, mid=9  → A[9]=27, 25<27  → high=8
Step 4: low=8,  high=8,  mid=8  → A[8]=24, 25>24  → low=9
Step 5: low=9 > high=8 → STOP → return -1 ✗