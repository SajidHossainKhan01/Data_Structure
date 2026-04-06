#include <stdio.h>

int main() {

    // Array with various elements
    int A[] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};
    int n   = 10;

    // Initialize both min and max with first element
    int min = A[0];
    int max = A[0];

    // Single scan to find both min and max
    for (int i = 1; i < n; i++) {
        if (A[i] < min)
            min = A[i];       // update min, skip max check
        else if (A[i] > max)
            max = A[i];       // update max only if not less than min
    }

    printf("Minimum = %d\n", min);   // Output: -1
    printf("Maximum = %d\n", max);   // Output: 10

    return 0;
}

// 𝐒𝐭𝐞𝐩 𝐛𝐲 𝐬𝐭𝐞𝐩 𝐭𝐫𝐚𝐜𝐞:

Array: [5, 8, 3, 9, 6, 2, 10, 7, -1, 4]
min=5, max=5

i=1: A[1]=8,  8<5? No  → 8>5?  Yes → max=8
i=2: A[2]=3,  3<5? Yes → min=3 (skip max check)
i=3: A[3]=9,  9<3? No  → 9>8?  Yes → max=9
i=4: A[4]=6,  6<3? No  → 6>9?  No  (neither)
i=5: A[5]=2,  2<3? Yes → min=2 (skip max check)
i=6: A[6]=10, 10<2? No → 10>9? Yes → max=10
i=7: A[7]=7,  7<2? No  → 7>10? No  (neither)
i=8: A[8]=-1, -1<2? Yes → min=-1 (skip max check)
i=9: A[9]=4,  4<-1? No → 4>10? No  (neither)

Result: min=-1, max=10 ✓

// 𝐊𝐞𝐲 𝐨𝐩𝐭𝐢𝐦𝐢𝐳𝐚𝐭𝐢𝐨𝐧 — 𝐮𝐬𝐢𝐧𝐠 𝐞𝐥𝐬𝐞 𝐢𝐟:

if (A[i] < min)           // if smaller than min...
    min = A[i];           // update min
else if (A[i] > max)      // ONLY check max if NOT less than min
    max = A[i];           // update max

// 𝐖𝐡𝐲 𝐭𝐡𝐢𝐬 𝐬𝐚𝐯𝐞𝐬 𝐜𝐨𝐦𝐩𝐚𝐫𝐢𝐬𝐨𝐧𝐬:

A number smaller than min CANNOT be greater than max
→ no need to check max when min condition is true
→ saves one comparison per iteration in best case

// 𝐁𝐞𝐬𝐭 𝐜𝐚𝐬𝐞 𝐞𝐱𝐚𝐦𝐩𝐥𝐞 (𝐝𝐞𝐬𝐜𝐞𝐧𝐝𝐢𝐧𝐠):

[10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Every element < current min → only 1 comparison each time
Total = n-1 comparisons

// 𝐖𝐨𝐫𝐬𝐭 𝐜𝐚𝐬𝐞 𝐞𝐱𝐚𝐦𝐩𝐥𝐞 (𝐚𝐬𝐜𝐞𝐧𝐝𝐢𝐧𝐠):

[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Every element > min (fails) → then checked against max
Total = 2(n-1) comparisons