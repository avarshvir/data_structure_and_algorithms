#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<char> vec;
    cout << "Before Inserting Element : " << vec.size() << endl;

    for(int i = 0; i < 5; i++){
        char value;
        cin >> value;
        vec.push_back(value);
    }
    cout << "After Insering Element : " << vec.size() << endl;
    for(char val : vec){
        cout << val <<" ";
    }
    cout << endl;

    vec.push_back('a');
    cout << "Current Size : " << vec.size() << endl;

}