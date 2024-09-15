#include <iostream>
#include "array_op.h"
#include "singly_linked_list.h"

using namespace std;

// Function to print menu options for array operations
void printArrayMenu() {
    cout << "Array Operations:" << endl;
    cout << "1> Insertion At Beginning" << endl;
    cout << "2> Insertion At End" << endl;
    cout << "3> Insertion via Index" << endl;
    cout << "4> Insertion at Position" << endl;
    cout << "5> Deletion At Beginning" << endl;
    cout << "6> Deletion At End" << endl;
    cout << "7> Deletion via Index" << endl;
    cout << "8> Deletion by Value" << endl;
    cout << "9> Traversing" << endl;
    cout << "10> Linear Search" << endl;
    cout << "11> Binary Search" << endl;
    cout << "12> Sorting" << endl;
    cout << "13> Return to Main Menu" << endl;
}

// Function to handle array operations
void handleArrayOperations() {
    int arr[100];
    int n, new_element, index, value;
    cout << "Enter Size of Array: ";
    cin >> n;
    cout << "Enter Array Elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int choice;
    do {
        printArrayMenu();
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter new element: ";
                cin >> new_element;
                insertAtBeg(arr, n, new_element);
                break;
            case 2:
                cout << "Enter new element: ";
                cin >> new_element;
               // insertAtEnd(arr, n, new_element);
                break;
            case 3:
                cout << "Enter new element and index: ";
                cin >> new_element >> index;
               // insertAtIndex(arr, n, new_element, index);
                break;
            case 4:
                // Note: Insertion at a specific position (not index-based) could be implemented if needed
                break;
            case 5:
                // Implement deletion at beginning if needed
                break;
            case 6:
                // Implement deletion at end if needed
                break;
            case 7:
                // Implement deletion via index if needed
                break;
            case 8:
                // Implement deletion by value if needed
                break;
            case 9:
                traverse(arr, n);
                break;
            case 10:
                // Implement linear search if needed
                break;
            case 11:
                // Implement binary search if needed
                break;
            case 12:
                // Implement sorting if needed
                break;
            case 13:
                // Return to main menu
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    } while (choice != 13);
}

// Function to print menu options for linked list operations
void printLinkedListMenu() {
    cout << "Singly Linked List Operations:" << endl;
    cout << "1> Traverse" << endl;
    cout << "2> Insertion At Beginning" << endl;
    cout << "3> Insertion At End" << endl;
    cout << "4> Insertion At Index" << endl;
    cout << "5> Insertion After Given Node" << endl;
    cout << "6> Deletion At Beginning" << endl;
    cout << "7> Deletion At End" << endl;
    cout << "8> Deletion In Between" << endl;
    cout << "9> Return to Main Menu" << endl;
}

// Function to handle linked list operations
void handleLinkedListOperations() {
    Node* head = nullptr; // Initialize head to null
    int choice;
    int data, index;

    do {
        // Display the menu
        cout << "\nLinked List Operations Menu" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert at Index" << endl;
        cout << "4. Insert After Node" << endl;
        cout << "5. Delete at Beginning" << endl;
        cout << "6. Delete at End" << endl;
        cout << "7. Delete at Index" << endl;
        cout << "8. Delete by Value" << endl;
        cout << "9. Traverse List" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Insert at Beginning
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                head = insertAtBeg(head, data);
                break;
            }
            case 2: {
                // Insert at End
                cout << "Enter data to insert at the end: ";
                cin >> data;
                head = insertAtEnd(head, data);
                break;
            }
            case 3: {
                // Insert at Index
                cout << "Enter data to insert and index: ";
                cin >> data >> index;
                head = insertAtIndex(head, data, index);
                break;
            }
            case 4: {
                // Insert After Node
                int prevData;
                cout << "Enter data to insert and the data of the node after which to insert: ";
                cin >> data >> prevData;
                Node* temp = head;
                while (temp != nullptr && temp->data != prevData) {
                    temp = temp->next;
                }
                if (temp != nullptr) {
                    head = insertAfterNode(head, temp, data);
                } else {
                    cout << "Node with data " << prevData << " not found" << endl;
                }
                break;
            }
            case 5: {
                // Delete at Beginning
                head = deletionAtBeg(head);
                break;
            }
            case 6: {
                // Delete at End
                head = deletionAtEnd(head);
                break;
            }
            case 7: {
                // Delete at Index
                cout << "Enter index to delete: ";
                cin >> index;
                //head = deletionAtIndex(head, index);
                break;
            }
            case 8: {
                // Delete by Value
                cout << "Enter value to delete: ";
                cin >> data;
               // head = deletionByValue(head, data);
                break;
            }
            case 9: {
                // Traverse List
                traverse(head);
                break;
            }
            case 0:
                // Exit
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 0);
}


int main() {
    int choice;
    do {
        cout << "Main Menu:" << endl;
        cout << "1> Array Operations" << endl;
        cout << "2> Singly Linked List Operations" << endl;
        cout << "3> Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                handleArrayOperations();
                break;
            case 2:
                handleLinkedListOperations();
                break;
            case 3:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
