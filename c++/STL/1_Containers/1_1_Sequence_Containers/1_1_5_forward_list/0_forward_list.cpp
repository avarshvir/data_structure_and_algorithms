#include<iostream>
#include<forward_list>
using namespace std;

int main(){
    forward_list<int> fl;
    //cout << fl.size() << endl; // Note: size() is not available for forward_list

    fl.push_front(10);
    fl.push_front(20);
    fl.push_front(30);

    // forward_list does not support size(), so we count manually
    int count = 0;
    for(auto it = fl.begin(); it != fl.end(); ++it){
        count++;
    }
    cout << count << endl;

    for(int i : fl)
        cout << i << " "; 

    cout << endl;  

    auto it = fl.begin();
    advance(it, 1); // move iterator to second element
    cout << *it << endl;
}