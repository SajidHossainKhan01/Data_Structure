#include <stdio.h>
#include <stdlib.h>

int main() {

    // Array with unique elements
    int A[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    int n   = 10;
    int k   = 10;   // target sum

    // ============================================
    // METHOD 1 — Brute Force (nested loops)
    // Time: O(n²)
    // ============================================
    printf("METHOD 1 — Brute Force O(n²):\n");
    printf("Pairs with sum = %d:\n", k);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] + A[j] == k)
                printf("%d + %d = %d\n", A[i], A[j], k);
        }
    }
    // Output:
    // 3 + 7 = 10
    // 8 + 2 = 10


    // ============================================
    // METHOD 2 — Hash Table
    // Time: O(n)
    // ============================================
    printf("\nMETHOD 2 — Hash Table O(n):\n");
    printf("Pairs with sum = %d:\n", k);

    // find max element
    int max = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > max) max = A[i];

    // create hash array of size (max+1), initialized to 0
    int *H = (int *) calloc(max + 1, sizeof(int));

    for (int i = 0; i < n; i++) {
        int complement = k - A[i];  // what we need to pair with A[i]

        // check if complement already exists in hash table
        if (complement >= 0 && complement <= max && H[complement] != 0)
            printf("%d + %d = %d\n", A[i], complement, k);

        // mark current element in hash table
        H[A[i]]++;
    }
    // Output:
    // 7 + 3 = 10
    // 2 + 8 = 10

    free(H);
    return 0;
}

// 𝐌𝐞𝐭𝐡𝐨𝐝 𝟏 — 𝐁𝐫𝐮𝐭𝐞 𝐟𝐨𝐫𝐜𝐞 𝐭𝐫𝐚𝐜𝐞:

Array: [6, 3, 8, 10, 16, 7, 5, 2, 9, 14]
k = 10

i=0 (6): j=1: 6+3=9  j=2: 6+8=14  j=3: 6+10=16 ...  no pair
i=1 (3): j=2: 3+8=11 j=3: 3+10=13 j=4: 3+16=19
         j=5: 3+7=10 ✓ → print "3 + 7 = 10"
i=2 (8): j=3: 8+10=18 j=4: 8+16=24 j=5: 8+7=15
         j=6: 8+5=13  j=7: 8+2=10 ✓ → print "8 + 2 = 10"
...

// 𝐌𝐞𝐭𝐡𝐨𝐝 𝟐 — 𝐇𝐚𝐬𝐡 𝐭𝐚𝐛𝐥𝐞 𝐭𝐫𝐚𝐜𝐞:

Array: [6, 3, 8, 10, 16, 7, 5, 2, 9, 14]
k = 10

i=0: A[0]=6,  complement=4,  H[4]=0 → not found, H[6]++
i=1: A[1]=3,  complement=7,  H[7]=0 → not found, H[3]++
i=2: A[2]=8,  complement=2,  H[2]=0 → not found, H[8]++
i=3: A[3]=10, complement=0,  H[0]=0 → not found, H[10]++
i=4: A[4]=16, complement=-6 → out of range, H[16]++
i=5: A[5]=7,  complement=3,  H[3]=1 → FOUND! print "7 + 3 = 10"
     H[7]++
i=6: A[6]=5,  complement=5,  H[5]=0 → not found, H[5]++
i=7: A[7]=2,  complement=8,  H[8]=1 → FOUND! print "2 + 8 = 10"
     H[2]++
i=8: A[8]=9,  complement=1,  H[1]=0 → not found, H[9]++
i=9: A[9]=14, complement=-4 → out of range, H[14]++

// 𝐒𝐩𝐚𝐜𝐞-𝐓𝐢𝐦𝐞 𝐭𝐫𝐚𝐝𝐞𝐨𝐟𝐟:

More space (hash table) → Less time  O(n)
Less space (no hash)    → More time  O(n²)