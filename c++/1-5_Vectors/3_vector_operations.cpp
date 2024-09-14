#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> vec = {1,2,3,4,5};
    cout << "size : " << vec.size() << endl;
    //int size = sizeof(vec) / sizeof(vec[0]);
    //cout << "manually size" << size << endl;

    cout << vec.at(4) << endl;
}