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

Node *insertAfterGivenNode(Node *head, Node *prevNode, int data){
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = prevNode->next;
    prevNode->next = new_node;
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

    head = insertAfterGivenNode(head, second, 34);
    cout << "After Insertion : " ;
    traverse(head);    
}