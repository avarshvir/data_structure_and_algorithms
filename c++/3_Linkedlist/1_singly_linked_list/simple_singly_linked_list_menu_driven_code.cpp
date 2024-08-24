#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};

void traverse(Node* head){
    while(head!=nullptr){
        cout << head->data << " ";
        head= head->next;
    }
    cout << endl;
}

Node* insertAtBeg(Node* head, int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

Node* insertAtEnd(Node*head, int data){
    Node* new_node = new Node();
    Node* ptr = head;
    while(ptr->next!=nullptr){
        ptr=ptr->next;
    }
    new_node->data = data;
    ptr->next=new_node;
    new_node->next = nullptr;
    return head;
}

Node *insertAtIndex(Node* head, int data, int index){
    Node* new_node = new Node();
    Node* ptr = head;
    int i = 0;
    while(i < index-1){
        ptr=ptr->next;
        i++;
    }
    new_node->data = data;
    new_node->next = ptr->next;
    ptr->next = new_node;
    return head;
}

Node *insertAfterNode(Node* head, Node* prev, int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = prev->next;
    prev->next = new_node;
    return head;
}

Node* deletionAtBeg(Node* head){
    Node *p = head;
    head= head->next;
    delete p;
    return head;
}

Node* deletionAtEnd(Node* head){
    Node* ptr = head;
    while(ptr!=nullptr){
       ptr=ptr->next; 
    }

}

int main(){
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    
    head->data = 11;
    head->next = second;

    second->data = 21;
    second->next = third;

    third->data = 31;
    third->next = fourth;

    fourth->data = 41;
    fourth->next = nullptr;

    //traverse(head);
    int choice;

    do{
        cout << "1-> Traverse \n2-> Insertion At Beg \n3-> Insertion At End \n4-> Insertion at Index \n5-> Insertion After given node" << endl;
        cout << "6-> Deletion At Beg \n7-> Deletion At End \n8-> Deletion in Between" << endl;
        
        cout << "Enter choice " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            traverse(head);
            break;
        case 2:
            head = insertAtBeg(head,1);
            break;
        case 3:
            head = insertAtEnd(head,55);
            break;
        case 4:
            head = insertAtIndex(head,32,2);
            break;
        case 5:
            head = insertAfterNode(head,second,47);
            break;
        case 6:
            head = deletionAtBeg(head);
            break;
        case 7:
            head = deletionAtEnd(head);
            traverse(head);
            break;
        default:
            cout << "Enter other choice" << endl;
            break;
        }
    }while(choice !=14);

}