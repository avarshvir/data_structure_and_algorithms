#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

// Define the Node class
class Node {
public:
    int data;
    Node* next;
};

// Function prototypes
void traverse(Node* head);
Node* insertAtBeg(Node* head, int data);
Node* insertAtEnd(Node* head, int data);
Node* insertAtIndex(Node* head, int data, int index);
Node* insertAfterNode(Node* head, Node* prev, int data);
Node* deletionAtBeg(Node* head);
Node* deletionAtEnd(Node* head);

#endif // SINGLY_LINKED_LIST_H
