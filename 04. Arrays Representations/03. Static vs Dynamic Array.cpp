#include <stdio.h>
#include <stdlib.h>

int main() {

    // STACK array — static, fixed size
    int a[5] = {2, 4, 6, 8, 10};

    // HEAP array — dynamic, using malloc
    int *p;
    p = (int *) malloc(5 * sizeof(int));

    // Initialize heap array with odd numbers
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 1;

    // Print stack array
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Print heap array
    for (int i = 0; i < 5; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    // Free heap memory when done
    free(p);

    return 0;
}

// 𝐎𝐮𝐭𝐩𝐮𝐭:

2 4 6 8 10
3 5 7 9 1

// 𝐌𝐞𝐦𝐨𝐫𝐲 𝐥𝐚𝐲𝐨𝐮𝐭:

STACK:
a → [ 2 | 4 | 6 | 8 | 10 ]
     a[0] a[1] a[2] a[3] a[4]

HEAP:
p → [ 3 | 5 | 7 | 9 | 1 ]
     p[0] p[1] p[2] p[3] p[4]
p is a POINTER stored in stack,
pointing to array allocated in heap