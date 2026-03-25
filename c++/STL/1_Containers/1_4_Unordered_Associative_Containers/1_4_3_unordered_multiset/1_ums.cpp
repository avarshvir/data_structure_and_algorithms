#include<iostream>
#include<unordered_set>

using namespace std;
int main(){

    // Create an empty unordered multiset
    unordered_multiset<int> ums1;

    // Create and initialize elements
    // using initialzer list
    unordered_multiset<int> ums2 =
                          {5, 3, 4, 1, 1};
    
    for(auto x : ums2)
        cout << x << " ";

    return 0;

}