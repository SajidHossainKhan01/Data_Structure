#include <stdio.h>
#include <stdlib.h>

int main() {

    // List of elements (unsorted, some missing)
    // Sequence should be 1 to 12, but 5 and 8 are missing
    int A[] = {3, 7, 4, 9, 12, 6, 11, 2, 10, 1};
    int n   = 10;   // number of elements in array
    int low = 1;    // starting number of sequence
    int high = 12;  // ending number of sequence

    // STEP 1 — Create hash array of size (high+1), initialized to 0
    int *H = (int *) calloc(high + 1, sizeof(int));
    // calloc initializes all elements to 0

    // STEP 2 — Scan through array, mark presence in hash table
    for (int i = 0; i < n; i++) {
        H[A[i]]++;   // go to index A[i] and increment
    }

    // STEP 3 — Scan hash array, print indices still 0 (missing elements)
    printf("Missing elements:\n");
    for (int i = low; i <= high; i++) {
        if (H[i] == 0)
            printf("%d\n", i);
    }

    free(H);
    return 0;
}

// 𝐇𝐨𝐰 𝐢𝐭 𝐰𝐨𝐫𝐤𝐬 𝐬𝐭𝐞𝐩 𝐛𝐲 𝐬𝐭𝐞𝐩:

Array A = [3, 7, 4, 9, 12, 6, 11, 2, 10, 1]
Sequence: 1 to 12

Hash array H (size 13, all zeros initially):
Index: 0  1  2  3  4  5  6  7  8  9 10 11 12
H:     0  0  0  0  0  0  0  0  0  0  0  0  0

Scan A and increment H[A[i]]:
A[0]=3  → H[3]++
A[1]=7  → H[7]++
A[2]=4  → H[4]++
A[3]=9  → H[9]++
A[4]=12 → H[12]++
A[5]=6  → H[6]++
A[6]=11 → H[11]++
A[7]=2  → H[2]++
A[8]=10 → H[10]++
A[9]=1  → H[1]++

After marking:
Index: 0  1  2  3  4  5  6  7  8  9 10 11 12
H:     0  1  1  1  1  0  1  1  0  1  1  1  1
                      ↑           ↑
                   5 missing   8 missing

Scan H from low=1 to high=12:
H[5]=0 → print 5
H[8]=0 → print 8

// 𝐎𝐮𝐭𝐩𝐮𝐭:

Missing elements:
5
8