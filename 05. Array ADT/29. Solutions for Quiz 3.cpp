#include <stdio.h>
#include <stdlib.h>

// ============ HELPER FUNCTIONS ============

void display(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void reverse(int A[], int start, int end) {
    while (start < end) {
        int temp    = A[start];
        A[start]    = A[end];
        A[end]      = temp;
        start++;
        end--;
    }
}

// ============ Q1 — Three Reverses = Left Rotate by K ============
void leftRotateByK(int A[], int n, int k) {
    // Step 1: reverse first k elements
    reverse(A, 0, k - 1);
    // Step 2: reverse remaining elements
    reverse(A, k, n - 1);
    // Step 3: reverse entire array
    reverse(A, 0, n - 1);
}

// ============ Q2 — Frequency of elements > 50 ============
void frequencyAbove50(int A[], int n) {
    // Only need array of size 50 (for marks 51 to 100)
    int freq[50] = {0};   // index 0 = mark 51, index 49 = mark 100

    for (int i = 0; i < n; i++)
        if (A[i] > 50)
            freq[A[i] - 51]++;   // map mark to index

    printf("Frequencies of marks > 50:\n");
    for (int i = 0; i < 50; i++)
        if (freq[i] > 0)
            printf("Mark %d: %d students\n", i + 51, freq[i]);
}

// ============ Q3 — Pair with difference = S (sorted array) ============
void pairWithDifference(int A[], int n, int s) {
    int i = 0, j = 1;

    printf("Pairs with difference = %d:\n", s);

    while (j < n) {
        if (A[j] - A[i] == s) {
            printf("%d - %d = %d\n", A[j], A[i], s);
            i++;
            j++;
        }
        else if (A[j] - A[i] < s)   // difference too small → move j
            j++;
        else                          // difference too large → move i
            i++;
    }
}

// ============ Q4 — Element neither min nor max ============
int neitherMinNorMax(int A[]) {
    // Only check first 3 elements — constant time O(1)
    int a = A[0], b = A[1], c = A[2];

    // return the middle value (not min, not max)
    if ((a > b && a < c) || (a > c && a < b)) return a;
    if ((b > a && b < c) || (b > c && b < a)) return b;
    return c;
}

// ============ Q5 — Second largest element ============
int secondLargest(int A[], int n) {
    // First scan — find largest
    int largest = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > largest)
            largest = A[i];

    // Second scan — find largest excluding 'largest'
    int second = -1;
    for (int i = 0; i < n; i++)
        if (A[i] != largest)
            if (second == -1 || A[i] > second)
                second = A[i];

    return second;
}

// ============ MAIN ============
int main() {

    // Q1 — Three reverses = Left rotate by K
    printf("=== Q1: Left Rotate by K ===\n");
    int A1[] = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    printf("Before: "); display(A1, 7);
    leftRotateByK(A1, 7, k);
    printf("After left rotate by %d: ", k);
    display(A1, 7);
    // Output: 4 5 6 7 1 2 3


    // Q2 — Frequency of marks > 50
    printf("\n=== Q2: Frequency > 50 ===\n");
    // Simulated marks of students
    int marks[] = {51, 72, 85, 51, 90, 72, 85, 85, 95, 51};
    frequencyAbove50(marks, 10);
    // Array size needed: only 50 (not 500 or 100)


    // Q3 — Pair with difference S in sorted array
    printf("\n=== Q3: Pair with Difference ===\n");
    int A3[] = {2, 4, 8, 9, 13, 16, 19};
    pairWithDifference(A3, 7, 10);
    // Output: 19 - 9 = 10


    // Q4 — Neither min nor max (constant time)
    printf("\n=== Q4: Neither Min Nor Max ===\n");
    int A4[] = {8, 3, 7, 12, 5, 9, 4};
    printf("Element neither min nor max: %d\n",
           neitherMinNorMax(A4));
    // Output: 7 (middle of first 3: 8,3,7)


    // Q5 — Second largest
    printf("\n=== Q5: Second Largest ===\n");
    int A5[] = {8, 3, 7, 12, 5, 9, 4};
    printf("Second largest: %d\n", secondLargest(A5, 7));
    // Output: 9

    return 0;
}

// 𝐐𝟏 — 𝐓𝐡𝐫𝐞𝐞 𝐫𝐞𝐯𝐞𝐫𝐬𝐞𝐬 = 𝐋𝐞𝐟𝐭 𝐫𝐨𝐭𝐚𝐭𝐢𝐨𝐧 𝐛𝐲 𝐊:

Original:    [1, 2, 3, 4, 5, 6, 7]   k=3

Step 1 — reverse A[0..k-1]:  [3, 2, 1, 4, 5, 6, 7]
Step 2 — reverse A[k..n-1]:  [3, 2, 1, 7, 6, 5, 4]
Step 3 — reverse A[0..n-1]:  [4, 5, 6, 7, 1, 2, 3]

Same as left rotating 3 times ✓

// 𝐐𝟐 — 𝐀𝐫𝐫𝐚𝐲 𝐬𝐢𝐳𝐞 𝐟𝐨𝐫 𝐟𝐫𝐞𝐪𝐮𝐞𝐧𝐜𝐢𝐞𝐬 > 𝟓𝟎:

Marks range: 0 to 100
We need only marks 51 to 100 → 50 values

Array size needed = 50 (not 500, not 101)
index 0 → mark 51
index 1 → mark 52
...
index 49 → mark 100

Mapping: freq[mark - 51]++

// 𝐐𝟑 — 𝐏𝐚𝐢𝐫 𝐰𝐢𝐭𝐡 𝐝𝐢𝐟𝐟𝐞𝐫𝐞𝐧𝐜𝐞 𝐒 (𝐬𝐨𝐫𝐭𝐞𝐝 𝐚𝐫𝐫𝐚𝐲):

Array: [2, 4, 8, 9, 13, 16, 19], S=10
i=0, j=1

A[j]-A[i] < S  → j++   (difference too small)
A[j]-A[i] > S  → i++   (difference too large)
A[j]-A[i] == S → found! i++, j++

// 𝐐𝟒 — 𝐍𝐞𝐢𝐭𝐡𝐞𝐫 𝐦𝐢𝐧 𝐧𝐨𝐫 𝐦𝐚𝐱 𝐢𝐧 𝐎(𝟏):

Only check FIRST 3 elements!
[8, 3, 7] → min=3, max=8, middle=7

7 is neither min nor max ✓
Time: O(1) — constant, no full scan needed

// 𝐐𝟓 — 𝐒𝐞𝐜𝐨𝐧𝐝 𝐥𝐚𝐫𝐠𝐞𝐬𝐭 𝐢𝐧 𝐎(𝐧):

Scan 1: find largest  = 12  → O(n)
Scan 2: find largest excluding 12 = 9 → O(n)
Total: 2n = O(n)