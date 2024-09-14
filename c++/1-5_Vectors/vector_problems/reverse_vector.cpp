#include<iostream>
#include<vector>
using namespace std;

void printVector(const vector<int> &v){
    for(int val : v){
        cout << val << " ";
    }
    cout << endl;
}

void reverseVector(vector<int> &v){
    for(int i = v.size()-1; i >= 0; i--){
        cout << v[i] << " ";
    }
    cout << endl;
}


int main(){
    vector<int> v = {1,2,3,4,5,6};
    printVector(v);
    reverseVector(v);
    //printVector(v);
}