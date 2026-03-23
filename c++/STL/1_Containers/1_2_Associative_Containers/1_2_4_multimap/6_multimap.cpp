#include <bits/stdc++.h>
using namespace std;

int main() {
    multimap<int, string> mm = {{1, "Geeks"},{2, "For"}, {1, "C++"}};
    
    // Delete element using key
    mm.erase(2);
    
    // Delete element using iterator
    mm.erase(mm.find(1));

    for (auto x: mm)
        cout << x.first << ": " << x.second;
    return 0;
}