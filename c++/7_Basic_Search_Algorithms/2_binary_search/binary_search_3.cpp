#include<iostream>
using namespace std;

int binarySearch(int arr[], int start, int end){
    int value = 7;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(value == arr[mid]){
            return mid;
        }
        if(value > arr[mid]){
            start = mid + 1;
        }
        if(value < arr[mid]){
            end = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11};
    int value = 7;
    int size = sizeof(arr)/sizeof(arr[0]);
    int end = size - 1;
    int index = binarySearch(arr, 0, end);
    cout << index << endl;

}