#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};

Node *traverse(Node *ptr){
    while(ptr!=nullptr){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

Node *deletionAtBeg(Node *head){
    Node *ptr = head;
    head = head->next;
    //free(ptr);
    delete ptr;
    return head;
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

    cout << "After Deletion : ";
    head = deletionAtBeg(head);
    traverse(head);
}