#include <stdio.h>
#include <math.h>

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

// Binary Search — counts comparisons
int binarySearchCount(struct Array arr, int key, int *count) {
    int low  = 0;
    int high = arr.length - 1;
    int mid;
    *count = 0;

    while (low <= high) {
        (*count)++;
        mid = (low + high) / 2;

        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main() {

    // 15 element sorted array
    struct Array arr = {
        {3, 8, 10, 15, 18, 21, 27, 29, 33, 37, 39, 41, 43, 47, 52},
        15, 15
    };

    display(arr);

    int count;
    int idx;

    // Best case — middle element (1 comparison)
    idx = binarySearchCount(arr, 27, &count);
    printf("\nSearch 27 (middle): index=%d, comparisons=%d\n", idx, count);
    // Output: comparisons = 1

    // Level 2 — found in 2 comparisons
    idx = binarySearchCount(arr, 15, &count);
    printf("Search 15 (level 2): index=%d, comparisons=%d\n", idx, count);

    idx = binarySearchCount(arr, 41, &count);
    printf("Search 41 (level 2): index=%d, comparisons=%d\n", idx, count);

    // Level 3 — found in 3 comparisons
    idx = binarySearchCount(arr, 8, &count);
    printf("Search 8  (level 3): index=%d, comparisons=%d\n", idx, count);

    idx = binarySearchCount(arr, 21, &count);
    printf("Search 21 (level 3): index=%d, comparisons=%d\n", idx, count);

    // Worst case — leaf elements (4 comparisons)
    idx = binarySearchCount(arr, 3, &count);
    printf("Search 3  (level 4): index=%d, comparisons=%d\n", idx, count);

    idx = binarySearchCount(arr, 52, &count);
    printf("Search 52 (level 4): index=%d, comparisons=%d\n", idx, count);

    // Unsuccessful search — always log n
    idx = binarySearchCount(arr, 25, &count);
    printf("Search 25 (not found): index=%d, comparisons=%d\n", idx, count);

    // Show log2(n+1) formula
    printf("\nn = %d\n", arr.length);
    printf("log2(n+1) = %.2f\n", log2(arr.length + 1));
    printf("Max comparisons needed = %d\n", (int)ceil(log2(arr.length + 1)));

    return 0;
}

// 𝐁𝐢𝐧𝐚𝐫𝐲 𝐒𝐞𝐚𝐫𝐜𝐡 𝐓𝐫𝐚𝐜𝐢𝐧𝐠 𝐓𝐫𝐞𝐞 (𝟏𝟓 𝐞𝐥𝐞𝐦𝐞𝐧𝐭𝐬):

Level 1 (1 comparison):
                    [27] index=7

Level 2 (2 comparisons):
          [15]                    [41]
         index=3                index=11

Level 3 (3 comparisons):
    [8]       [21]        [37]        [47]
   idx=1     idx=5       idx=9       idx=13

Level 4 (4 comparisons):
  [3] [10] [18] [24] [29] [39] [43] [52]
  0    2    4    6    8   10   12   14

//  𝐖𝐡𝐲 𝐁𝐢𝐧𝐚𝐫𝐲 𝐒𝐞𝐚𝐫𝐜𝐡 𝐢𝐬 𝐎(𝐥𝐨𝐠 𝐧):

n=16 elements:
16 → 8 → 4 → 2 → 1
  ÷2   ÷2  ÷2  ÷2
  = 4 divisions = log₂(16) = 4

General: n ÷ 2^k = 1
         2^k = n
         k = log₂(n)