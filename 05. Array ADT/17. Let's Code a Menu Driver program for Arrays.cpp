#include <stdio.h>
#include <stdlib.h>

// Array structure — using pointer for dynamic size
struct Array {
    int *A;
    int size;
    int length;
};

// ============ ALL FUNCTIONS ============

void display(struct Array arr) {
    printf("Elements are:\n");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insert(struct Array *arr, int index, int x) {
    if (index >= 0 && index <= arr->length) {
        for (int i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
}

int delete(struct Array *arr, int index) {
    int x = 0;
    if (index >= 0 && index < arr->length) {
        x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
    }
    return x;
}

int linearSearch(struct Array arr, int key) {
    for (int i = 0; i < arr.length; i++)
        if (key == arr.A[i])
            return i;
    return -1;
}

int sum(struct Array arr) {
    int s = 0;
    for (int i = 0; i < arr.length; i++)
        s += arr.A[i];
    return s;
}

int max(struct Array arr) {
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
        if (arr.A[i] > max)
            max = arr.A[i];
    return max;
}

int min(struct Array arr) {
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
        if (arr.A[i] < min)
            min = arr.A[i];
    return min;
}

// ============ MAIN — MENU DRIVEN ============

int main() {

    struct Array arr;
    int x, index, key, ch;

    // Create array of required size
    printf("Enter size of array: ");
    scanf("%d", &arr.size);
    arr.A      = (int *) malloc(arr.size * sizeof(int));
    arr.length = 0;

    // Menu driven program
    do {
        printf("\n===== ARRAY MENU =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element and index: ");
                scanf("%d %d", &x, &index);
                insert(&arr, index, x);
                break;

            case 2:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                printf("Deleted element: %d\n", delete(&arr, index));
                break;

            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                index = linearSearch(arr, key);
                if (index != -1)
                    printf("Element found at index: %d\n", index);
                else
                    printf("Element not found\n");
                break;

            case 4:
                printf("Sum = %d\n", sum(arr));
                break;

            case 5:
                display(arr);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (ch < 6);

    free(arr.A);
    return 0;
}

// 𝐒𝐚𝐦𝐩𝐥𝐞 𝐫𝐮𝐧:

Enter size of array: 10

===== ARRAY MENU =====
1. Insert  2. Delete  3. Search  4. Sum  5. Display  6. Exit
Enter your choice: 1
Enter element and index: 2 0

Enter your choice: 1
Enter element and index: 3 1

Enter your choice: 5
Elements are: 2 3

Enter your choice: 1
Enter element and index: 15 0

Enter your choice: 5
Elements are: 15 2 3

Enter your choice: 2
Enter index to delete: 0
Deleted element: 15

Enter your choice: 4
Sum = 5

Enter your choice: 6
Exiting...