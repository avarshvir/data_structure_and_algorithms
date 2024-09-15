#include <iostream>
#include "array_op.h"

using namespace std;

void insertAtBeg(int arr[], int &n, int new_element) {
    for (int i = n; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = new_element;
    ++n;
}

void insertAtEnd(int arr[], int &n, int new_element) {
    arr[n++] = new_element;
}

void insertAtIndex(int arr[], int &n, int new_element, int index) {
    if (index < 0 || index > n) {
        cout << "Index out of bounds" << endl;
        return;
    }
    for (int i = n; i > index; --i) {
        arr[i] = arr[i - 1];
    }
    arr[index] = new_element;
    ++n;
}

void deleteAtBeg(int arr[], int &n) {
    if (n <= 0) {
        cout << "Array is empty" << endl;
        return;
    }
    for (int i = 0; i < n - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --n;
}

void deleteAtEnd(int arr[], int &n) {
    if (n <= 0) {
        cout << "Array is empty" << endl;
        return;
    }
    --n;
}

void deleteAtIndex(int arr[], int &n, int index) {
    if (index < 0 || index >= n) {
        cout << "Index out of bounds" << endl;
        return;
    }
    for (int i = index; i < n - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --n;
}

void deleteByValue(int arr[], int &n, int value) {
    int i;
    for (i = 0; i < n; ++i) {
        if (arr[i] == value) {
            break;
        }
    }
    if (i == n) {
        cout << "Value not found" << endl;
        return;
    }
    deleteAtIndex(arr, n, i);
}

void traverse(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void linearSearch(int arr[], int n, int value) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == value) {
            cout << "Value found at index " << i << endl;
            return;
        }
    }
    cout << "Value not found" << endl;
}

void binarySearch(int arr[], int n, int value) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            cout << "Value found at index " << mid << endl;
            return;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "Value not found" << endl;
}

void sortArray(int arr[], int n) {
    // Simple bubble sort
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
