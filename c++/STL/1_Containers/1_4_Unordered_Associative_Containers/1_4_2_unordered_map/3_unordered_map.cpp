#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, string> um =
    {{1, "C"}, {2, "C++"}, {3, "Python"}};

    // Access value associated with key 2
    // using [] operator
    cout << um[2] << endl;
    
    // Access value associated with key 1
    // using at() function
    cout << um.at(1);
    return 0;
}