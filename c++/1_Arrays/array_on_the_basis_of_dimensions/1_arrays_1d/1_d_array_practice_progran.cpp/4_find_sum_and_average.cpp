#include<iostream>
using namespace std;
int main(){
    int arr[5] = {1,2,3,4,5};
    int sum = 0;
    float avg;
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < 5; i++){
        sum = sum + arr[i];
    }
    cout << "sum : " << sum << endl;
    avg = sum/size;
    cout << "average : " << avg << endl;
}