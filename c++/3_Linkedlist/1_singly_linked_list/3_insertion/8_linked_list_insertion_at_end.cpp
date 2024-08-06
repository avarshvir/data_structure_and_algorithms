#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};

void traverse(Node *head){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


Node *insertAtEnd(Node *head, int data){
    Node *new_node = new Node();
    Node *p = head;
    new_node->data = data;
    while(p->next != nullptr){
        p = p->next;
    }
    p->next = new_node;
    new_node->next = nullptr;
    return head;
}

int main(){

    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();
    Node *fifth = new Node();

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

    cout << "Before Insertion : ";
    traverse(head);

    head = insertAtEnd(head, 60);
    cout << "After Insertion : ";
    traverse(head);

}