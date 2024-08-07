#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};

void traverse(Node *ptr){
    while(ptr!=nullptr){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

Node *deletionAtEnd(Node *head){
    Node *ptr = head;
    while(ptr!=nullptr){
        ptr = ptr->next;
    }
    
}

int main(){
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();

    head->data = 11;
    head->next = second;

    second->data = 22;
    second->next = third;

    third->data = 33;
    third->next = fourth;

    fourth->data = 44;
    fourth->next = nullptr;

    cout << "Before Deletion : ";
    traverse(head);

}