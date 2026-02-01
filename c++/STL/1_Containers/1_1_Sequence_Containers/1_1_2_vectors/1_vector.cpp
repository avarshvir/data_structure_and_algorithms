#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    
    
    for(auto i : arr){
        cout << i << " ";
    }

    arr.pop_back();
cout << endl;
     for(auto i : arr){
        cout << i << " ";
    }

}