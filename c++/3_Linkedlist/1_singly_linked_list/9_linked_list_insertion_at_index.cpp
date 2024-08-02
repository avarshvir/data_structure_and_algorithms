#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};

void traverse(Node *head){
    while(head!=nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *insertAtIndex(Node *head, int data, int index){
    Node *new_node = new Node();
    Node *p = head;
    int i = 0;
    while(i < index-1){
        p = p->next;
        i++;
    }
    new_node->data = data;
    new_node->next = p->next;
    p->next = new_node;
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

    head = insertAtIndex(head, 35,2);
    cout << "After Insertion : ";
    traverse(head);
    
}