#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_multiset<int> ums;

    ums.insert(5);
    ums.insert(1);
    ums.insert(3);
    ums.insert(1);
    ums.insert(2);
    ums.insert(4);
    
    for (auto x : ums) 
        cout << x << ' ';
    
    return 0;

}