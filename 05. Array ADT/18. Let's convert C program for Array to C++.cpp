#include <iostream>
using namespace std;

class Array {
private:
    int *A;
    int size;
    int length;

    // private helper
    void swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

public:
    // Non-parameterized Constructor
    Array() {
        size   = 10;
        length = 0;
        A      = new int[size];
    }

    // Parameterized Constructor
    Array(int sz) {
        size   = sz;
        length = 0;
        A      = new int[size];
    }

    // Destructor
    ~Array() {
        delete[] A;
    }

    // DISPLAY
    void display() {
        cout << "Elements are:" << endl;
        for (int i = 0; i < length; i++)
            cout << A[i] << " ";
        cout << endl;
    }

    // INSERT
    void insert(int index, int x) {
        if (index >= 0 && index <= length) {
            for (int i = length; i > index; i--)
                A[i] = A[i - 1];
            A[index] = x;
            length++;
        }
    }

    // DELETE
    int Delete(int index) {
        int x = 0;
        if (index >= 0 && index < length) {
            x = A[index];
            for (int i = index; i < length - 1; i++)
                A[i] = A[i + 1];
            length--;
        }
        return x;
    }

    // LINEAR SEARCH
    int linearSearch(int key) {
        for (int i = 0; i < length; i++)
            if (key == A[i])
                return i;
        return -1;
    }

    // BINARY SEARCH
    int binarySearch(int key) {
        int low  = 0;
        int high = length - 1;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (key == A[mid])  return mid;
            else if (key < A[mid]) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }

    // GET
    int get(int index) {
        if (index >= 0 && index < length)
            return A[index];
        return -1;
    }

    // SET
    void set(int index, int x) {
        if (index >= 0 && index < length)
            A[index] = x;
    }

    // MAX
    int max() {
        int max = A[0];
        for (int i = 1; i < length; i++)
            if (A[i] > max) max = A[i];
        return max;
    }

    // MIN
    int min() {
        int min = A[0];
        for (int i = 1; i < length; i++)
            if (A[i] < min) min = A[i];
        return min;
    }

    // SUM
    int sum() {
        int s = 0;
        for (int i = 0; i < length; i++)
            s += A[i];
        return s;
    }

    // AVERAGE
    float avg() {
        return (float)sum() / length;
    }

    // REVERSE
    void reverse() {
        int i = 0, j = length - 1;
        while (i < j) {
            swap(&A[i], &A[j]);
            i++; j--;
        }
    }

    // IS SORTED
    int isSorted() {
        for (int i = 0; i < length - 1; i++)
            if (A[i] > A[i + 1]) return 0;
        return 1;
    }

    // INSERT SORTED
    void insertSort(int x) {
        if (length == size) return;
        int i = length - 1;
        while (i >= 0 && A[i] > x) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = x;
        length++;
    }

    // REARRANGE — negatives left, positives right
    void rearrange() {
        int i = 0, j = length - 1;
        while (i < j) {
            while (A[i] < 0) i++;
            while (A[j] >= 0) j--;
            if (i < j) swap(&A[i], &A[j]);
        }
    }

    // MERGE
    Array* merge(Array arr2) {
        Array *arr3 = new Array(length + arr2.length);
        int i = 0, j = 0, k = 0;

        while (i < length && j < arr2.length) {
            if (A[i] < arr2.A[j])
                arr3->A[k++] = A[i++];
            else
                arr3->A[k++] = arr2.A[j++];
        }
        while (i < length)    arr3->A[k++] = A[i++];
        while (j < arr2.length) arr3->A[k++] = arr2.A[j++];

        arr3->length = k;
        return arr3;
    }

    // UNION
    Array* unionArr(Array arr2) {
        Array *arr3 = new Array(length + arr2.length);
        int i = 0, j = 0, k = 0;

        while (i < length && j < arr2.length) {
            if (A[i] < arr2.A[j])
                arr3->A[k++] = A[i++];
            else if (arr2.A[j] < A[i])
                arr3->A[k++] = arr2.A[j++];
            else { arr3->A[k++] = A[i++]; j++; }
        }
        while (i < length)      arr3->A[k++] = A[i++];
        while (j < arr2.length) arr3->A[k++] = arr2.A[j++];

        arr3->length = k;
        return arr3;
    }

    // INTERSECTION
    Array* intersection(Array arr2) {
        Array *arr3 = new Array(length + arr2.length);
        int i = 0, j = 0, k = 0;

        while (i < length && j < arr2.length) {
            if (A[i] < arr2.A[j])       i++;
            else if (arr2.A[j] < A[i])  j++;
            else { arr3->A[k++] = A[i++]; j++; }
        }

        arr3->length = k;
        return arr3;
    }

    // DIFFERENCE
    Array* difference(Array arr2) {
        Array *arr3 = new Array(length + arr2.length);
        int i = 0, j = 0, k = 0;

        while (i < length && j < arr2.length) {
            if (A[i] < arr2.A[j])       arr3->A[k++] = A[i++];
            else if (arr2.A[j] < A[i])  j++;
            else { i++; j++; }
        }
        while (i < length) arr3->A[k++] = A[i++];

        arr3->length = k;
        return arr3;
    }
};

// ============ MENU DRIVEN MAIN ============
int main() {

    Array *arr1;
    int sz, ch, x, index, key;

    cout << "Enter size of array: ";
    cin >> sz;
    arr1 = new Array(sz);

    do {
        cout << "\n===== ARRAY MENU =====" << endl;
        cout << "1. Insert"   << endl;
        cout << "2. Delete"   << endl;
        cout << "3. Search"   << endl;
        cout << "4. Sum"      << endl;
        cout << "5. Display"  << endl;
        cout << "6. Exit"     << endl;
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter element and index: ";
                cin >> x >> index;
                arr1->insert(index, x);
                break;

            case 2:
                cout << "Enter index to delete: ";
                cin >> index;
                cout << "Deleted: " << arr1->Delete(index) << endl;
                break;

            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                index = arr1->linearSearch(key);
                if (index != -1)
                    cout << "Found at index: " << index << endl;
                else
                    cout << "Not found" << endl;
                break;

            case 4:
                cout << "Sum = " << arr1->sum() << endl;
                break;

            case 5:
                arr1->display();
                break;

            case 6:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (ch < 6);

    delete arr1;
    return 0;
}

// 𝐂𝐨𝐧𝐬𝐭𝐫𝐮𝐜𝐭𝐨𝐫 𝐭𝐲𝐩𝐞𝐬:

Array()       → default size 10
Array(int sz) → user-specified size
~Array()      → frees memory automatically
