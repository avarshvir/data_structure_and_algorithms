#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a = 5;
    vector<char> vec(5);
    for(int i = 0; i < a;i++){
        cin >> vec[i];
    }
    for(char value: vec){
        cout << value << " ";
    }
    cout <<"--------------"<< endl;
    for(int i = 0; i < a; i++){
        cout << vec[i] << endl;
    }
}