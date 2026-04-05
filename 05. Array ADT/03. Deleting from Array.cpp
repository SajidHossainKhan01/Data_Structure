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

// DELETE — remove element at given index, return deleted value
int delete(struct Array *arr, int index) {
    int x = 0;

    if (index >= 0 && index < arr->length) {
        x = arr->A[index];          // save deleted value

        // shift elements left
        for (int i = index; i < arr->length - 1; i++) {
            arr->A[i] = arr->A[i + 1];
        }

        arr->length--;              // reduce length
    }

    return x;                       // return deleted value (0 if invalid)
}

int main() {

    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    display(arr);

    // Delete at index 4 (last element — value 6)
    printf("Deleted: %d\n", delete(&arr, 4));
    display(arr);   // Output: 2 3 4 5

    // Delete at index 0 (first element — value 2)
    // printf("Deleted: %d\n", delete(&arr, 0));
    // display(arr);   // Output: 3 4 5 6

    return 0;
}

// 𝐇𝐨𝐰 𝐃𝐄𝐋𝐄𝐓𝐄 𝐰𝐨𝐫𝐤𝐬 (𝐝𝐞𝐥𝐞𝐭𝐢𝐧𝐠 𝐚𝐭 𝐢𝐧𝐝𝐞𝐱 𝟎):

Before:  [2, 3, 4, 5, 6, _, _, _, _, _]
          0  1  2  3  4      length=5

Save x = A[0] = 2

Shift left:
i=0: A[0] = A[1] = 3
i=1: A[1] = A[2] = 4
i=2: A[2] = A[3] = 5
i=3: A[3] = A[4] = 6

length--

After:   [3, 4, 5, 6, 6, _, _, _, _, _]
          0  1  2  3          length=4
                   ↑ stale value, ignored
Return: 2

