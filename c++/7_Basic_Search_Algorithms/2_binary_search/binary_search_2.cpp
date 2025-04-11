#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int value = 90;
    int start = 0; 
    int size = sizeof(arr)/sizeof(arr[0]);
    int end = size - 1;
    int mid;
    bool found = false;
    while(start <= end){
        mid = start + (end-start)/2;
        if(arr[mid] == value){
            cout << "value found at: " << arr[mid] << endl;
            found = true;
            break;
        }
        else if(value > arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    if(!found){
        cout << "Element not found!! "<< endl;
    }
}