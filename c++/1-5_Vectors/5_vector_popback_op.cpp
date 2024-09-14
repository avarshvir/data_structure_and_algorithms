#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    cout << "Size of vector : " << v.size() << endl; 
    v = {1,2,3,4,5};

    for(auto val : v){
        cout << val << " ";
    }
    cout <<"\n" << "Size : " << v.size() << endl; 

    v.pop_back();

     for(auto val : v){
        cout << val << " ";
    }
    cout << "\nSize : " << v.size() << endl;

}