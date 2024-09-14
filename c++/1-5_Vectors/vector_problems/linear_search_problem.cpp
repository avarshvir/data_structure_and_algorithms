#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v = {1,2,3,4,5};
    cout << "Vector Elements : ";
    for(auto val : v){
        cout << val << " ";
    }
    cout << endl;
    cout << "capacity : " << v.capacity() << endl;

    int target = 3;
    bool found = false;

    for(int i = 0; i < v.size(); i++){
        if(v[i] == target){
            cout << "Element is present at index : " << i << endl;
            found = true;
            break;
        }
    }
    if(!found){
        cout << "Element is not found!" << endl;
    }
}