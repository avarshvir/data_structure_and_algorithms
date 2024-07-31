#include <iostream>
using namespace std;

class SLLNode {
public:
    int data;
    SLLNode *next;

    SLLNode(int data) {
        this->data = data;
        this->next = nullptr; // Use nullptr for modern C++
    }
};

// Function to traverse and print the linked list
void SLLTraversal(SLLNode *ptr) {
    while (ptr != nullptr) {
        cout << ptr->data << " "; // Added a space for better readability
        ptr = ptr->next;
    }
    cout << endl;
}

// Function to add a node at the end of the list
void appendNode(SLLNode *&head, int newData) {
    SLLNode *newNode = new SLLNode(newData); // Create a new node with the given data
    if (head == nullptr) { // If the list is empty, make newNode the head
        head = newNode;
        return;
    }
    SLLNode *temp = head;
    while (temp->next != nullptr) { // Traverse to the end of the list
        temp = temp->next;
    }
    temp->next = newNode; // Add the new node at the end
}

int main() {
    SLLNode *head = nullptr; // Start with an empty list

    // Add nodes to the list
    appendNode(head, 10);
    appendNode(head, 20);
    appendNode(head, 30); // Add more nodes as needed
    appendNode(head, 40);

    // Print the list
    cout << "Linked List: ";
    SLLTraversal(head);

    // Clean up memory (deleting all nodes in the list)
    SLLNode *temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
