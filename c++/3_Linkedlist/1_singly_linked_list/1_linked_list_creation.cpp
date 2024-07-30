#include <iostream>

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node(); // Allocate memory for the new node
    newNode->data = data;       // Set the data
    newNode->next = nullptr;    // Initialize the next pointer to nullptr
    return newNode;
}

// Function to initialize the linked list with some nodes
Node* initializeList() {
    // Create the head node
    Node* head = createNode(1);
    
    // Create more nodes and link them
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    
    return head;
}

// Function to display the linked list
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Initialize the linked list
    Node* head = initializeList();
    
    // Display the linked list
    std::cout << "Linked list: ";
    displayList(head);
    
    return 0;
}
