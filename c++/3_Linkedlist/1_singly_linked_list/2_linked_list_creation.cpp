#include<iostream>
using namespace std;
class SinglyLLNodeWithConstructor{
    public:
    int data;
    SinglyLLNodeWithConstructor *next;

    // constructor
    SinglyLLNodeWithConstructor(int data){
        this->data = data;
        this->next = NULL;
    }
};
int main(){
        SinglyLLNodeWithConstructor *node1 = new SinglyLLNodeWithConstructor(7);

        cout << node1->data << endl;
        cout << node1->next << endl;
}