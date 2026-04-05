#include <stdio.h>

int main() {

    // METHOD 1 — Single missing element (first n natural numbers)
    int A[]   = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};
    int n     = 12;    // last number
    int size  = 11;    // number of elements

    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += A[i];

    int S = n * (n + 1) / 2;   // formula for sum of first n natural numbers

    printf("METHOD 1 — Single missing (first n naturals):\n");
    printf("Missing = %d\n\n", S - sum);   // Output: 7


    // METHOD 2 — Single missing element (any starting number)
    int B[]  = {6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17};
    int low  = 6;
    int m    = 11;
    int diff = low - 0;   // difference = starting element - 0

    printf("METHOD 2 — Single missing (any start):\n");

    for (int i = 0; i < m; i++) {
        if (B[i] - i != diff) {
            printf("Missing = %d\n\n", i + diff);
            break;
        }
    }
    // Output: 12


    // METHOD 3 — Multiple missing elements (sorted array)
    // Array: 6 7 8 9 [10 missing] 11 12 [13 14 missing] 15 16 17 18 19
    int C[]   = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
    int low2  = 6;
    int m2    = 11;
    int diff2 = low2 - 0;   // starting difference = 6

    printf("METHOD 3 — Multiple missing elements:\n");

    for (int i = 0; i < m2; i++) {
        // while current element doesn't match expected value
        while (C[i] - i != diff2) {
            printf("Missing = %d\n", i + diff2);
            diff2++;   // increase difference to check next missing
        }
    }

    return 0;
}

// 𝐇𝐨𝐰 𝐌𝐞𝐭𝐡𝐨𝐝 𝟑 𝐰𝐨𝐫𝐤𝐬 𝐬𝐭𝐞𝐩 𝐛𝐲 𝐬𝐭𝐞𝐩:

Array: [6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19]
Index:  0  1  2  3   4   5   6   7   8   9  10

diff = 6 (starting difference)

i=0: C[0]-0 = 6-0 = 6 == diff ✓
i=1: C[1]-1 = 7-1 = 6 == diff ✓
i=2: C[2]-2 = 8-2 = 6 == diff ✓
i=3: C[3]-3 = 9-3 = 6 == diff ✓
i=4: C[4]-4 = 11-4 = 7 ≠ 6
     → print i+diff = 4+6 = 10  (10 missing!)
     → diff++ → diff=7
     → 11-4 = 7 == diff ✓ (stop while)
i=5: C[5]-5 = 12-5 = 7 == diff ✓
i=6: C[6]-6 = 15-6 = 9 ≠ 7
     → print i+diff = 6+7 = 13  (13 missing!)
     → diff++ → diff=8
     → 15-6 = 9 ≠ 8
     → print i+diff = 6+8 = 14  (14 missing!)
     → diff++ → diff=9
     → 15-6 = 9 == diff ✓ (stop while)
i=7 to i=10: all match ✓

Output:
Missing = 10
Missing = 13
Missing = 14