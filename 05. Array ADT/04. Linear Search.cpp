#include <stdio.h>

// Array structure
struct Array {
    int A[10];
    int size;
    int length;
};

// Display function
void display(struct Array arr) {
    printf("Elements are:\n");
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

// LINEAR SEARCH — returns index if found, -1 if not found
int linearSearch(struct Array arr, int key) {
    for (int i = 0; i < arr.length; i++) {
        if (key == arr.A[i])
            return i;       // found — return index
    }
    return -1;              // not found
}

int main() {

    struct Array arr = {{8, 3, 7, 12, 6, 1, 9, 5, 2, 4}, 10, 10};

    display(arr);

    // Successful search
    int index = linearSearch(arr, 5);
    if (index != -1)
        printf("Element found at index: %d\n", index);  // Output: 7
    else
        printf("Element not found\n");

    // Unsuccessful search
    index = linearSearch(arr, 12);
    if (index != -1)
        printf("Element found at index: %d\n", index);
    else
        printf("Element not found\n");                  // Output: not found

    return 0;
}

// 𝐇𝐨𝐰 𝐋𝐢𝐧𝐞𝐚𝐫 𝐒𝐞𝐚𝐫𝐜𝐡 𝐰𝐨𝐫𝐤𝐬:

Array: [8, 3, 7, 12, 6, 1, 9, 5, 2, 4]
        0  1  2   3  4  5  6  7  8  9

Search key = 5:
i=0: 5==8? No
i=1: 5==3? No
i=2: 5==7? No
i=3: 5==12? No
i=4: 5==6? No
i=5: 5==1? No
i=6: 5==9? No
i=7: 5==5? YES → return 7 ✓

Search key = 12 (not in array):
i=0 to i=9: no match → return -1 ✗

// 𝐀𝐯𝐞𝐫𝐚𝐠𝐞 𝐜𝐚𝐬𝐞 𝐝𝐞𝐫𝐢𝐯𝐚𝐭𝐢𝐨𝐧:

Comparisons needed:
  1st element → 1
  2nd element → 2
  3rd element → 3
  ...
  nth element → n

Average = (1+2+3+...+n) / n
        = n(n+1)/2 / n
        = (n+1)/2
        = O(n)