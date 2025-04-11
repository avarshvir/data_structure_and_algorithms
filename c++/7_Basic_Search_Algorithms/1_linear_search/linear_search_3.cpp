#include<iostream>
using namespace std;

int linearSearch(int arr[], int value, int size){
    for(int i = 0; i < size; i++){
        if(value == arr[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int value = 6;
    int size = sizeof(arr)/sizeof(arr[0]);
    int index = linearSearch(arr, value, size);
    cout << index;

}