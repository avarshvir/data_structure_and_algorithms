#include <bits/stdc++.h>
using namespace std;

int main() {
    multimap<int, string> mm = {{1, "Geeks"}, {2, "For"}, {1, "C++"}};
                     
    // Accessing 1st element
    auto f = mm.begin();
    cout << f->first << ": " << f->second<< endl;
                     
    // Accessing 2nd element
    auto it = next(f, 1);
    cout << it->first << ": " << it->second;
    
    return 0;
}