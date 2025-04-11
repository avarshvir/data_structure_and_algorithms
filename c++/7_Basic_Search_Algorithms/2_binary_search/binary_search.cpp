#include<iostream>
using namespace std;
int main(){
    int arr[] = {2,3,4,5,6,7,8,9,10};
    int value = 700;
    int size = sizeof(arr)/sizeof(arr[0]);
    int mid;
    int start = 0;
    int end = size-1;
    bool found = false;
    
    while(start <= end){
        mid =  start + (end - start) / 2;
        if(value == arr[mid]){
            cout << "Element found at: " << mid+1 << endl;
            found = true;
            break;
        }
        else if(value > arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    if(!found){
        cout << "Element not found";
    }
    return 0;

}