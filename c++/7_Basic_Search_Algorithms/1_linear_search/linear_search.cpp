#include<iostream>
using namespace std;

int main(){
    int arr[6] = {23,11,34,134,45,23};
    int value = 23;
    int s = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < s; i++){
        if(arr[i]==value){
            cout << "Element present in : " << i+1 << "position "<< endl;
        }
    }
}