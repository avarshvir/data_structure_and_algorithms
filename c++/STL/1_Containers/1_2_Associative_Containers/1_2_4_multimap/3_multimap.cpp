/*
In multimap, the key of any element cannot be modified. 
But we can modify the value using the iterator to that element.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    multimap<int, string> mm = {{1, "Geeks"},{2, "For"}, {1, "Java"}};
                     
                     
    // Updating 2nd element value
    auto it = next(mm.begin(), 1);
    it->second = "C++";
    
    for (auto x: mm)
        cout << x.first << ": " << x.second<< endl;
    return 0;
}