#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void traverse(Node* ptr) {
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

Node* insertAtIndex(Node* head, int data, int index) {
    Node* new_node = new Node();
    new_node->data = data;

    // Handle insertion at the head
    if (index == 0) {
        new_node->next = head;
        return new_node;
    }

    Node* p = head;
    int i = 0;
    while (p != nullptr && i < index - 1) {
        p = p->next;
        i++;
    }

    if (p == nullptr) {
        // Index is out of bounds
        cout << "Index out of bounds." << endl;
        delete new_node;  // Clean up the newly created node
        return head;
    }

    new_node->next = p->next;
    p->next = new_node;

    return head;
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = nullptr;

    cout << "Before Insertion: ";
    traverse(head);

    head = insertAtIndex(head, 35, 2);
    cout << "After Insertion: ";
    traverse(head);

    // Clean up memory
    deleteList(head);

    return 0;
}
