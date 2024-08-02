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

Node *insertAtBeg(Node *head, int data){

    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = head;
    return  new_node;

}

Node *insertAtIndex(Node *head,int data, int index){
    Node *new_node = new Node();
    Node *p = head;
    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    new_node->data = data;
    new_node->next = p->next;
    p->next = new_node;
    return head;
}

Node *insertAtEnd(Node *head, int data){
    Node *new_node = new Node();
    Node *p = head;
    while(p->next!= nullptr){
        p = p->next;
    }
    p->next = new_node;
    new_node->data = data;
    new_node->next = nullptr;
    return head;
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

    int choice;
    

    do{
        cout << "-----Menu------" << endl;
        cout << "1> Traverse " << endl;
        cout << "2> Insert at Begining " << endl;
        cout << "3> Insert at Index " << endl;
        cout << "14> Exit " << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch(choice){
            case 1:
                traverse(head);
            break;
            case 2:
                head = insertAtBeg(head,1);
                traverse(head);
            break;
            case 3:
                head = insertAtIndex(head, 35,2);
                traverse(head);
            break;
            case 4:
                head = insertAtEnd(head,90);
                traverse(head);
                break;
                case 5:
                head = insertAfterGivenNode(head,second,22);
                traverse(head);
                break;

            default:
                cout << "Enter other choice : " << endl; 

        }
    }while(choice != 14);

}