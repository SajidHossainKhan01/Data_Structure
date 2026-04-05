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

// GET — return element at given index
int get(struct Array arr, int index) {
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;   // invalid index
}

// SET — change element at given index
void set(struct Array *arr, int index, int x) {
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}

// MAX — find maximum element
int max(struct Array arr) {
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

// MIN — find minimum element
int min(struct Array arr) {
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

// SUM — sum of all elements
int sum(struct Array arr) {
    int s = 0;
    for (int i = 0; i < arr.length; i++)
        s += arr.A[i];
    return s;
}

// AVG — average of all elements
float avg(struct Array arr) {
    return (float)sum(arr) / arr.length;
}

int main() {

    struct Array arr = {{2, 3, 4, 5, 6, 7, 8, 9, 10, 14}, 10, 10};

    display(arr);

    // GET
    printf("\nGet index 2:  %d\n", get(arr, 2));    // Output: 4
    printf("Get index 0:  %d\n", get(arr, 0));      // Output: 2
    printf("Get index 9:  %d\n", get(arr, 9));      // Output: 14
    printf("Get index 10: %d\n", get(arr, 10));     // Output: -1 (invalid)

    // SET
    set(&arr, 0, 15);                                // change index 0 to 15
    display(arr);                                    // 2 → 15

    // MAX
    printf("Max: %d\n", max(arr));                  // Output: 15

    // MIN
    printf("Min: %d\n", min(arr));                  // Output: 3

    // SUM
    printf("Sum: %d\n", sum(arr));                  // Output: sum of all

    // AVG
    printf("Avg: %.1f\n", avg(arr));                // Output: average

    return 0;
}

// 𝐎𝐮𝐭𝐩𝐮𝐭:

Elements are:
2 3 4 5 6 7 8 9 10 14

Get index 2:  4
Get index 0:  2
Get index 9:  14
Get index 10: -1

Elements are:
15 3 4 5 6 7 8 9 10 14

Max: 15
Min: 3
Sum: 81
Avg: 8.1