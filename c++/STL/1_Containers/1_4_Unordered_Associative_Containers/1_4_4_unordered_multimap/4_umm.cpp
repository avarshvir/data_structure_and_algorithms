#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_multimap<int, string> umm =
    {{1, "Geeks"}, {2, "For"},{3, "C++"},
                             {1, "STL"}};
    
    // Delete all elements which are 
    // associated with key 1
    umm.erase(1);
    
    // Delete first element
    // using iterator
    umm.erase(umm.begin());
    
    for(auto x: umm)
        cout << x.first << " " << x.second;
    return 0;
}