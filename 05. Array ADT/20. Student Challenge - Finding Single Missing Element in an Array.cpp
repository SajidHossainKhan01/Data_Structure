#include <stdio.h>

int main() {

    // METHOD 1 — Single missing element in first n natural numbers
    // Array: first n natural numbers with one missing
    int A[] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};
    int n = 12;   // last number in sequence
    int size = 11; // number of elements in array

    // Sum of all elements in array
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += A[i];

    // Sum of first n natural numbers using formula
    int S = n * (n + 1) / 2;

    printf("METHOD 1 (First n natural numbers):\n");
    printf("Missing number = %d\n\n", S - sum);
    // Output: 7


    // METHOD 2 — Single missing element using index difference
    // Array starts from any number (not necessarily 1)
    int B[]  = {6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17};
    int low  = 6;    // starting number
    int high = 17;   // ending number
    int m    = 11;   // number of elements

    // difference = low - 0 = low (first element - first index)
    int diff = low - 0;

    printf("METHOD 2 (Sequence starting from any number):\n");

    for (int i = 0; i < m; i++) {
        if (B[i] - i != diff) {
            printf("Missing number = %d\n\n", i + diff);
            break;
        }
    }
    // Output: 12


    // METHOD 3 — Multiple missing elements using index difference
    int C[]  = {6, 7, 9, 10, 11, 13, 14, 16, 17};
    int low2 = 6;
    int m2   = 9;
    int diff2 = low2 - 0;

    printf("METHOD 3 (Multiple missing elements):\n");

    for (int i = 0; i < m2; i++) {
        if (C[i] - i != diff2) {
            // print all missing numbers until difference matches again
            while (diff2 != C[i] - i) {
                printf("Missing number = %d\n", i + diff2);
                diff2++;
            }
        }
    }

    return 0;
}

// 𝐌𝐞𝐭𝐡𝐨𝐝 𝟏 — 𝐒𝐮𝐦 𝐟𝐨𝐫𝐦𝐮𝐥𝐚 (𝐟𝐢𝐫𝐬𝐭 𝐧 𝐧𝐚𝐭𝐮𝐫𝐚𝐥 𝐧𝐮𝐦𝐛𝐞𝐫𝐬):

Array: [1, 2, 3, 4, 5, 6, _, 8, 9, 10, 11, 12]
                              ^ 7 is missing

Formula sum S = n*(n+1)/2 = 12*13/2 = 78
Actual  sum   = 1+2+...+6+8+...+12  = 71

Missing = S - sum = 78 - 71 = 7 ✓

// 𝐌𝐞𝐭𝐡𝐨𝐝 𝟐 — 𝐈𝐧𝐝𝐞𝐱 𝐝𝐢𝐟𝐟𝐞𝐫𝐞𝐧𝐜𝐞 (𝐚𝐧𝐲 𝐬𝐭𝐚𝐫𝐭𝐢𝐧𝐠 𝐧𝐮𝐦𝐛𝐞𝐫):

Array: [6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17]
Index:  0  1  2  3   4   5   6   7   8   9  10

Difference = low - 0 = 6

Check A[i] - i:
i=0: 6-0=6  ✓
i=1: 7-1=6  ✓
i=2: 8-2=6  ✓
i=3: 9-3=6  ✓
i=4: 10-4=6 ✓
i=5: 11-5=6 ✓
i=6: 13-6=7 ✗ → difference changed!

Missing = i + diff = 6 + 6 = 12 ✓