#include <stdio.h>

int main() {

    // SORTED array — prerequisite for this method
    int A[] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    int n   = 10;
    int k   = 10;   // target sum

    int i = 0;          // start from left
    int j = n - 1;      // start from right

    printf("Pairs with sum = %d:\n", k);

    // TWO POINTER technique
    while (i < j) {
        if (A[i] + A[j] == k) {
            // pair found
            printf("%d + %d = %d\n", A[i], A[j], k);
            i++;    // move both pointers
            j--;
        }
        else if (A[i] + A[j] < k) {
            // sum too small — move to larger number
            i++;
        }
        else {
            // sum too large — move to smaller number
            j--;
        }
    }
    // Output:
    // 1 + 9  = 10
    // 4 + 6  = 10

    return 0;
}

// 𝐒𝐭𝐞𝐩 𝐛𝐲 𝐬𝐭𝐞𝐩 𝐭𝐫𝐚𝐜𝐞:

Array: [1, 3, 4, 5, 6, 8, 9, 10, 12, 14]
        0  1  2  3  4  5  6   7   8   9
k = 10

i=0, j=9: A[0]+A[9] = 1+14 = 15 > 10 → j--
i=0, j=8: A[0]+A[8] = 1+12 = 13 > 10 → j--
i=0, j=7: A[0]+A[7] = 1+10 = 11 > 10 → j--
i=0, j=6: A[0]+A[6] = 1+9  = 10 == 10 → print "1+9=10", i++, j--
i=1, j=5: A[1]+A[5] = 3+8  = 11 > 10 → j--
i=1, j=4: A[1]+A[4] = 3+6  =  9 < 10 → i++
i=2, j=4: A[2]+A[4] = 4+6  = 10 == 10 → print "4+6=10", i++, j--
i=3, j=3: i >= j → STOP

// 𝐃𝐞𝐜𝐢𝐬𝐢𝐨𝐧 𝐫𝐮𝐥𝐞𝐬 — 𝐓𝐰𝐨 𝐏𝐨𝐢𝐧𝐭𝐞𝐫 𝐭𝐞𝐜𝐡𝐧𝐢𝐪𝐮𝐞:

sum == k  → pair found! i++, j--
sum < k   → need larger number → i++
sum > k   → need smaller number → j--
i >= j    → STOP

// 𝐖𝐡𝐲 𝐭𝐡𝐢𝐬 𝐰𝐨𝐫𝐤𝐬 (𝐬𝐨𝐫𝐭𝐞𝐝 𝐚𝐫𝐫𝐚𝐲):

Smaller numbers → left side
Larger numbers  → right side

If sum too large: decrease larger number (j--)
If sum too small: increase smaller number (i++)