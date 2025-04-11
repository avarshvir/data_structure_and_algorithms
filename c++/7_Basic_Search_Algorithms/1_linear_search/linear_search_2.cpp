#include<iostream>
using namespace std;

int main(){
    int arr[6] = {23,223,34,56,776,43};
    int value = 340;
    int size = sizeof(arr)/sizeof(arr[0]);
    bool found = false;
    for(int i = 0; i < size; i++){
        if(arr[i] == value){
            cout << "value found at position in: " << i+1 << endl; 
        }
        found = true;
    }
    if(found){
        cout << "value not found!!";
    }
}