#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
};

void traverse(Node *ptr){
    while (ptr!=nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;

    }
    
}


int main(){
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->data = 10;
    head->next = second;
    head->prev = nullptr;

    second->data = 20;
    second->next = third;
    second->prev = head;

    third->data = 30;
    third->next = nullptr;
    third->prev = second;

    traverse(head);
    
}