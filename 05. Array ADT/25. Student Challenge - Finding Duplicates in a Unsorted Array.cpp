#include <stdio.h>
#include <stdlib.h>

int main() {

    // UNSORTED array with duplicates
    // 8 appears twice, 6 appears three times
    int A[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    int n   = 10;

    // ============================================
    // METHOD 1 — Brute force (nested loops)
    // Time: O(n²)
    // ============================================
    printf("METHOD 1 — Brute Force O(n²):\n");

    for (int i = 0; i < n - 1; i++) {
        if (A[i] != -1) {               // skip already counted duplicates
            int count = 1;

            for (int j = i + 1; j < n; j++) {
                if (A[i] == A[j]) {
                    count++;
                    A[j] = -1;          // mark as counted
                }
            }

            if (count > 1)
                printf("%d appears %d times\n", A[i], count);
        }
    }
    // Output:
    // 8 appears 2 times
    // 6 appears 3 times


    // ============================================
    // METHOD 2 — Hash table
    // Time: O(n)
    // ============================================
    printf("\nMETHOD 2 — Hash Table O(n):\n");

    int B[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};  // fresh copy
    int m   = 10;

    // find max element
    int max = B[0];
    for (int i = 1; i < m; i++)
        if (B[i] > max) max = B[i];

    // create hash array of size (max+1), initialized to 0
    int *H = (int *) calloc(max + 1, sizeof(int));

    // STEP 1 — scan array, increment count at index B[i]
    for (int i = 0; i < m; i++)
        H[B[i]]++;

    // STEP 2 — scan hash table, print duplicates
    for (int i = 0; i <= max; i++) {
        if (H[i] > 1)
            printf("%d appears %d times\n", i, H[i]);
    }
    // Output:
    // 6 appears 3 times
    // 8 appears 2 times

    free(H);
    return 0;
}

// 𝐌𝐞𝐭𝐡𝐨𝐝 𝟏 — 𝐁𝐫𝐮𝐭𝐞 𝐟𝐨𝐫𝐜𝐞 𝐭𝐫𝐚𝐜𝐞:

Array: [8, 3, 6, 4, 6, 5, 6, 8, 2, 7]

i=0 (A[0]=8): count=1
  j=1: 8≠3
  j=2: 8≠6
  j=3: 8≠4
  j=4: 8≠6
  j=5: 8≠5
  j=6: 8≠6
  j=7: 8==8 → count=2, A[7]=-1
  j=8: 8≠2
  j=9: 8≠7
  count=2 > 1 → print "8 appears 2 times"

i=1 (A[1]=3): count=1, no duplicates found

i=2 (A[2]=6): count=1
  j=3: 6≠4
  j=4: 6==6 → count=2, A[4]=-1
  j=5: 6≠5
  j=6: 6==6 → count=3, A[6]=-1
  j=7: A[7]=-1, skip
  count=3 > 1 → print "6 appears 3 times"

i=4: A[4]=-1 → skip (already counted)
i=6: A[6]=-1 → skip (already counted)
i=7: A[7]=-1 → skip (already counted)

// 𝐌𝐞𝐭𝐡𝐨𝐝 𝟐 — 𝐇𝐚𝐬𝐡 𝐭𝐚𝐛𝐥𝐞 𝐭𝐫𝐚𝐜𝐞:

Array: [8, 3, 6, 4, 6, 5, 6, 8, 2, 7]

After scanning:
Index: 0  1  2  3  4  5  6  7  8
H:     0  0  1  1  1  1  3  1  2
                          ↑     ↑
                       H[6]=3  H[8]=2

Scan H: H[6]=3>1 → "6 appears 3 times"
        H[8]=2>1 → "8 appears 2 times"

// 𝐖𝐡𝐲 𝐦𝐚𝐫𝐤 𝐚𝐬 -𝟏 𝐢𝐧 𝐌𝐞𝐭𝐡𝐨𝐝 𝟏?

Without -1: i=4 would find 6 again and print duplicate result
With    -1: i=4 is skipped → correct output