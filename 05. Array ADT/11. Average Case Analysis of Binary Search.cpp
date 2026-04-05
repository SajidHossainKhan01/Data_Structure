#include <stdio.h>
#include <math.h>

// Array structure
struct Array {
    int A[15];
    int size;
    int length;
};

// Binary search — counts comparisons made
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

    // 15 element sorted array (n=15)
    struct Array arr = {
        {3, 8, 10, 15, 18, 21, 27, 29, 33, 37, 39, 41, 43, 47, 52},
        15, 15
    };

    int count;
    int totalComparisons = 0;
    int n = arr.length;

    printf("=== Successful Search Analysis ===\n");
    printf("%-10s %-8s %-12s\n", "Key", "Index", "Comparisons");

    // Search for every element in array
    for (int i = 0; i < n; i++) {
        binarySearchCount(arr, arr.A[i], &count);
        printf("%-10d %-8d %-12d\n", arr.A[i], i, count);
        totalComparisons += count;
    }

    printf("\nTotal comparisons (all successful): %d\n", totalComparisons);
    printf("Average comparisons (successful):   %.2f\n",
           (float)totalComparisons / n);
    printf("log2(n) = %.2f\n\n", log2(n));

    printf("=== Unsuccessful Search Analysis ===\n");
    printf("%-10s %-12s\n", "Key", "Comparisons");

    // Search for elements NOT in array
    int notFound[]     = {1, 6, 9, 12, 16, 22, 28, 31, 35, 38, 40, 42, 45, 50, 55, 60};
    int totalUnsuccessful = 0;
    int numUnsuccessful   = 16;   // n+1 external nodes

    for (int i = 0; i < numUnsuccessful; i++) {
        binarySearchCount(arr, notFound[i], &count);
        printf("%-10d %-12d\n", notFound[i], count);
        totalUnsuccessful += count;
    }

    printf("\nTotal comparisons (all unsuccessful): %d\n", totalUnsuccessful);
    printf("Average comparisons (unsuccessful):   %.2f\n",
           (float)totalUnsuccessful / numUnsuccessful);
    printf("log2(n+1) = %.2f\n\n", log2(n + 1));

    // Summary
    printf("=== Summary ===\n");
    printf("n = %d\n", n);
    printf("Internal nodes (successful cases):   %d\n", n);
    printf("External nodes (unsuccessful cases): %d\n", n + 1);
    printf("E = I + 2n relationship:\n");

    int I = totalComparisons - n;   // sum of paths of internal nodes
    int E = totalUnsuccessful;      // sum of paths of external nodes
    printf("  I (sum of internal paths) = %d\n", I);
    printf("  E (sum of external paths) = %d\n", E);
    printf("  I + 2n = %d + %d = %d\n", I, 2*n, I + 2*n);
    printf("  E == I + 2n? %s\n", (E == I + 2*n) ? "YES ✓" : "NO");

    return 0;
}

// 𝐂𝐨𝐦𝐩𝐚𝐫𝐢𝐬𝐨𝐧𝐬 𝐛𝐲 𝐥𝐞𝐯𝐞𝐥 (𝐧=𝟏𝟓):

Level 1: 1 element  × 1 comparison = 1   (root)
Level 2: 2 elements × 2 comparisons = 4
Level 3: 4 elements × 3 comparisons = 12
Level 4: 8 elements × 4 comparisons = 32
                              Total = 49

Average = 49/15 ≈ 3.27 ≈ log₂(15) ≈ 3.9

//  𝐊𝐞𝐲 𝐦𝐚𝐭𝐡𝐞𝐦𝐚𝐭𝐢𝐜𝐚𝐥 𝐫𝐞𝐥𝐚𝐭𝐢𝐨𝐧𝐬𝐡𝐢𝐩𝐬:

Internal nodes (I) = sum of paths of circular nodes (successful)
External nodes (E) = sum of paths of square nodes (unsuccessful)

Facts:
1. E = I + 2n          (always true)
2. External nodes = n + 1  (always one more than internal)
3. E ≈ n·log(n)

Deriving average successful time:
  = 1 + I/n
  = 1 + (E - 2n)/n
  = 1 + E/n - 2
  = 1 + n·log(n)/n - 2
  ≈ log(n)

Average unsuccessful time:
  = E/(n+1)
  ≈ n·log(n)/n
  ≈ log(n)