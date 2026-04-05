#include <stdio.h>
#include <stdlib.h>

int main() {

    // STEP 1 — Create original array of size 5 in Heap
    int *p;
    p = (int *) malloc(5 * sizeof(int));

    // Fill array p with odd numbers
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    // Print original array p
    for (int i = 0; i < 5; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    // STEP 2 — Create larger array of size 10 in Heap
    int *q;
    q = (int *) malloc(10 * sizeof(int));

    // STEP 3 — Copy elements from p to q
    for (int i = 0; i < 5; i++) {
        q[i] = p[i];
    }

    // STEP 4 — Free old array, point p to new array
    free(p);        // delete old array
    p = q;          // p now points to larger array
    q = NULL;       // q points nowhere

    // Print new larger array using p
    for (int i = 0; i < 5; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    // Free final array
    free(p);

    return 0;
}

// 𝐎𝐮𝐭𝐩𝐮𝐭:

3 5 7 9 11
3 5 7 9 11

// 𝐒𝐭𝐞𝐩 𝐛𝐲 𝐬𝐭𝐞𝐩 𝐦𝐞𝐦𝐨𝐫𝐲 𝐯𝐢𝐬𝐮𝐚𝐥𝐢𝐳𝐚𝐭𝐢𝐨𝐧:

STEP 1 — p created (size 5):
p → [ 3 | 5 | 7 | 9 | 11 ]  (address: 9B0)

STEP 2 — q created (size 10):
p → [ 3 | 5 | 7 | 9 | 11 ]  (address: 9B0)
q → [ 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 ]  (address: 470)

STEP 3 — copy p into q:
p → [ 3 | 5 | 7 | 9 | 11 ]  (address: 9B0)
q → [ 3 | 5 | 7 | 9 | 11 | 0 | 0 | 0 | 0 | 0 ]  (address: 470)

STEP 4 — free p, p = q, q = NULL:
p → [ 3 | 5 | 7 | 9 | 11 | 0 | 0 | 0 | 0 | 0 ]  (address: 470)
q → NULL
old array (9B0) → freed ✓