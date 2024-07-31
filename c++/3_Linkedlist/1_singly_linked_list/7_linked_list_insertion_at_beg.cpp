#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};

void traversal(Node *ptr){
    while(ptr!= nullptr){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

Node* insertionAtBeg(Node *head, int data){
    Node *new_node = new Node();
    new_node->next = head;
    new_node->data = data;
    return new_node;

}

int main(){
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    
    head->data = 11;
    head->next = second;

    second->data = 22;
    second->next = third;
    
    third->data = 33;
    third->next = nullptr;
    
    cout << "Before Insertion : ";
    traversal(head);

    cout << endl;

    cout << "After Insertion : ";
    head = insertionAtBeg(head,1);
    traversal(head);

}