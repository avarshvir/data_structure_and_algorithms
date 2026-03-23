/*
Multimap can be traversed by either range-based for loop or 
using begin() and end() iterators with a loop.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    multimap<int, string> mm = {{1, "Geeks"},{2, "For"}, {1, "C++"}};
    
    // Traverse multimap
    for(auto it = mm.begin(); it != mm.end(); it++)
        cout << it->first << " " << it->second<< "\n";
    
    cout << endl;
    
    // Traverse with range based
    for(auto &i : mm){
        cout << i.first << " -> " << i.second << endl;
    }
    
        return 0;
}