#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
};

void traverse(Node *ptr){
    while(ptr!= nullptr){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

Node* insertAtBeg(Node *&head, int data){      //& because I want dont want copy I need original, It is our choice we can also run without &
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = head;
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
    traverse(head);

    cout << "After Insertion : ";
    head = insertAtBeg(head, 1);
    traverse(head);

    
    
}