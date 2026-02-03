#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> lst;
    cout << lst.size() << endl;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    cout << lst.size() << endl;

    for(int i : lst)
        cout << i << " "; 

    cout << endl;  

    auto it = lst.begin();
    advance(it, 1); // move iterator to second element
    cout << *it << endl;
}