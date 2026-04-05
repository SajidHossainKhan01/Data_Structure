#include <stdio.h>
#include <stdlib.h>

int main() {

    // SORTED array with duplicates
    int A[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int n   = 10;   // number of elements

    // Find max element (last element since array is sorted)
    int max = A[n - 1];   // max = 20

    // STEP 1 — Create hash array of size (max+1), initialized to 0
    int *H = (int *) calloc(max + 1, sizeof(int));
    // H[0] to H[20], all zeros

    // STEP 2 — Scan array, increment count at index A[i]
    for (int i = 0; i < n; i++) {
        H[A[i]]++;   // go to index A[i] and increment
    }

    // STEP 3 — Scan hash table, print elements appearing more than once
    printf("Duplicate elements and their counts:\n");
    for (int i = 0; i <= max; i++) {
        if (H[i] > 1)
            printf("%d appears %d times\n", i, H[i]);
    }

    free(H);
    return 0;
}

// 𝐇𝐚𝐬𝐡 𝐭𝐚𝐛𝐥𝐞 𝐚𝐟𝐭𝐞𝐫 𝐬𝐜𝐚𝐧𝐧𝐢𝐧𝐠:

Array A = [3, 6, 8, 8, 10, 12, 15, 15, 15, 20]

Scanning A:
A[0]=3  → H[3]++
A[1]=6  → H[6]++
A[2]=8  → H[8]++
A[3]=8  → H[8]++   (now H[8]=2)
A[4]=10 → H[10]++
A[5]=12 → H[12]++
A[6]=15 → H[15]++
A[7]=15 → H[15]++  (now H[15]=2)
A[8]=15 → H[15]++  (now H[15]=3)
A[9]=20 → H[20]++

Hash table H:
Index: 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
H:     0  0  0  1  0  0  1  0  2  0  1  0  1  0  0  3  0  0  0  0  1
                               ↑           ↑
                           H[8]=2       H[15]=3

// 𝐎𝐮𝐭𝐩𝐮𝐭:

Duplicate elements and their counts:
8  appears 2 times
15 appears 3 times

// 𝐓𝐢𝐦𝐞 𝐜𝐨𝐦𝐩𝐥𝐞𝐱𝐢𝐭𝐲 𝐚𝐧𝐚𝐥𝐲𝐬𝐢𝐬:

Loop 1 (mark elements):  n iterations → O(n)
Loop 2 (find duplicates): max iterations → O(n)
Total: O(n) + O(n) = 2*O(n) = O(n)

Note: even though 2 separate loops,
      they are NOT nested → still O(n)
