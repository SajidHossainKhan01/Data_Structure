#include <stdio.h>

int main() {

    // SORTED array with duplicates
    // 8 appears twice, 15 appears three times
    int A[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int n   = 10;

    // ============================================
    // METHOD 1 — Find duplicate elements (print once)
    // ============================================
    printf("METHOD 1 — Duplicate elements:\n");

    int lastDuplicate = 0;

    for (int i = 0; i < n - 1; i++) {
        if (A[i] == A[i + 1] && A[i] != lastDuplicate) {
            printf("%d\n", A[i]);
            lastDuplicate = A[i];
        }
    }
    // Output: 8, 15


    // ============================================
    // METHOD 2 — Count duplicates (how many times each)
    // ============================================
    printf("\nMETHOD 2 — Count of duplicates:\n");

    for (int i = 0; i < n - 1; i++) {
        if (A[i] == A[i + 1]) {
            int j = i;

            // move j forward while elements are same
            while (A[j] == A[i])
                j++;

            // j - i = count of duplicates
            printf("%d is appearing %d times\n", A[i], j - i);

            // move i to just before j (loop will do i++)
            i = j - 1;
        }
    }
    // Output:
    // 8  is appearing 2 times
    // 15 is appearing 3 times

    return 0;
}

// 𝐇𝐨𝐰 𝐌𝐞𝐭𝐡𝐨𝐝 𝟏 𝐰𝐨𝐫𝐤𝐬:

Array: [3, 6, 8, 8, 10, 12, 15, 15, 15, 20]
        0  1  2  3   4   5   6   7   8   9

lastDuplicate = 0

i=0: A[0]=3,  A[1]=6   → 3≠6,  skip
i=1: A[1]=6,  A[2]=8   → 6≠8,  skip
i=2: A[2]=8,  A[3]=8   → 8==8, 8≠lastDup(0) → print 8, lastDup=8
i=3: A[3]=8,  A[4]=10  → 8≠10, skip
i=4: A[4]=10, A[5]=12  → skip
i=5: A[5]=12, A[6]=15  → skip
i=6: A[6]=15, A[7]=15  → 15==15, 15≠lastDup(8) → print 15, lastDup=15
i=7: A[7]=15, A[8]=15  → 15==15, 15==lastDup(15) → skip (already printed)
i=8: A[8]=15, A[9]=20  → skip

Output: 8, 15 ✓

// 𝐇𝐨𝐰 𝐌𝐞𝐭𝐡𝐨𝐝 𝟐 𝐰𝐨𝐫𝐤𝐬:

Array: [3, 6, 8, 8, 10, 12, 15, 15, 15, 20]

i=2: A[2]=8==A[3]=8
     j=2, while A[j]==8: j++ → j=4
     count = j-i = 4-2 = 2
     print: "8 is appearing 2 times"
     i = j-1 = 3 (then loop does i++ → i=4)

i=4: A[4]=10≠A[5]=12 → skip
i=5: A[5]=12≠A[6]=15 → skip

i=6: A[6]=15==A[7]=15
     j=6, while A[j]==15: j++ → j=9
     count = j-i = 9-6 = 3
     print: "15 is appearing 3 times"
     i = j-1 = 8 (then loop does i++ → i=9)

Output:
8  is appearing 2 times ✓
15 is appearing 3 times ✓
