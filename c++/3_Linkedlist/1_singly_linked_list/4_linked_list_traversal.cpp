#include<iostream>
using namespace std;
class SLLNode{
    public:
    int data;
    SLLNode *next;

    SLLNode(int data){
        this->data = data;
        this->next = NULL;
    }
};

void SLLTrabversal(SLLNode *ptr){
    while(ptr!= NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

}

int main(){
    SLLNode *head = new SLLNode(10);
    SLLNode *second = new SLLNode(20);

    head->next = second;


    cout << head->data << endl;
    cout << head->next << endl;

    SLLTrabversal(head);

}