#ifndef ARRAY_OP_H
#define ARRAY_OP_H

// Function prototypes
void insertAtBeg(int arr[], int &n, int new_element);
void insertAtEnd(int arr[], int &n, int new_element);
void insertAtIndex(int arr[], int &n, int new_element, int index);
void deleteAtBeg(int arr[], int &n);
void deleteAtEnd(int arr[], int &n);
void deleteAtIndex(int arr[], int &n, int index);
void deleteByValue(int arr[], int &n, int value);
void traverse(int arr[], int n);
void linearSearch(int arr[], int n, int value);
void binarySearch(int arr[], int n, int value);
void sortArray(int arr[], int n);

#endif // ARRAY_OP_H
