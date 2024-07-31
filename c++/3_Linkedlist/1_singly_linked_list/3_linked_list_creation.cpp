#include<iostream>
using namespace std;
class SLLNC{
    public:
    int data;
    SLLNC *next;

    SLLNC(int data){
        this->data = data;
        this->next = NULL;
    }
};

int main(){
    int n;
    cout << "Enter the no of elements you want : ";
    cin >> n;

    SLLNC *head = nullptr;

    for(int i = 0; i < n; i++){
        SLLNC *node = new SLLNC(i);
        if(head == nullptr){
            head = node;
            head -> next = node;
        }
    }
}