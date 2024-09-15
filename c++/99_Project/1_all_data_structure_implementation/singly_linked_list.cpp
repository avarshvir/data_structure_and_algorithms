#include <iostream>
#include "singly_linked_list.h"

using namespace std;

void traverse(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* insertAtBeg(Node* head, int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

Node* insertAtEnd(Node* head, int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    if (head == nullptr) {
        return new_node;
    }
    Node* ptr = head;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return head;
}

Node* insertAtIndex(Node* head, int data, int index) {
    if (index < 0) {
        cout << "Index out of bounds" << endl;
        return head;
    }
    Node* new_node = new Node();
    new_node->data = data;
    if (index == 0) {
        new_node->next = head;
        return new_node;
    }
    Node* ptr = head;
    for (int i = 0; i < index - 1; ++i) {
        if (ptr == nullptr) {
            cout << "Index out of bounds" << endl;
            delete new_node;
            return head;
        }
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
    return head;
}

Node* insertAfterNode(Node* head, Node* prev, int data) {
    if (prev == nullptr) {
        cout << "Previous node cannot be null" << endl;
        return head;
    }
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = prev->next;
    prev->next = new_node;
    return head;
}

Node* deletionAtBeg(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return nullptr;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deletionAtEnd(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return nullptr;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}
