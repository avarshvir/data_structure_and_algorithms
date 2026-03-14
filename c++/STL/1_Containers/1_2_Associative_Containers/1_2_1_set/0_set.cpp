#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(10);

    for(int x : s){
        cout << x << " ";
    }
    cout << endl;
    
    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    
    return 0;

}