#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};

void traverse(Node *ptr){
    while(ptr!=nullptr){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

Node *deletionByValue(Node *head, int value){
    Node* p = head;
    Node* q = head->next;
    while(q->data!=value && q->next!=nullptr){
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}


int main(){
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

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
    head = deletionByValue(head, 33);
    traverse(head);   
    
}