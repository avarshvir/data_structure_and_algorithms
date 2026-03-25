#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, string> um;
    
    // Insert elements using square brackets
    um[1] = "C";
    
    // Insert elements using insert() method
    um.insert({2, "C++"});
    um.insert({3, "Python"});

    for (auto i : um) 
        cout << i.first << ": " << i.second
        << endl;
    return 0;
}