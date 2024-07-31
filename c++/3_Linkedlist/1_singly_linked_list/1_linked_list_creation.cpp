#include<iostream>
using namespace std;

// implementation
class SinglyLLNode{
    public:
    int data;
    SinglyLLNode *next;
};

int main(){
    SinglyLLNode *head = new SinglyLLNode();  // or we can SinglyLLNode *head = (SinglyLLNode *) malloc(sizeof(SinglyLLNode));
    SinglyLLNode *second = new SinglyLLNode();


    cout << "Before Initialization : " << endl;
    cout <<"head -> date : " << head->data << endl;
    cout <<"head -> next : " << head->next << endl;
    
    head -> data = 7;
    head -> next = second;
    second -> data = 8;
    second -> next = NULL;
    
    cout << "After Initialization : " << endl;
    cout <<"head -> data : " << head->data << endl;
    cout <<"head -> next : " << head->next << endl;
    cout << "second -> data : " << second->data << endl;
    cout << "second -> next : " << second->next << endl;
    

}