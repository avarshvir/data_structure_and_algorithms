#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, string> um =
    {{1, "C"}, {2, "C++"}, {3, "Python"}};
    
    // Delete element which have key 2
    um.erase(2);
    
    // Delete first element
    um.erase(um.begin());
  
    for(auto it = um.begin(); it != um.end(); it++)
        cout << it->first << ": " << it->second
        << endl;
    return 0;
}