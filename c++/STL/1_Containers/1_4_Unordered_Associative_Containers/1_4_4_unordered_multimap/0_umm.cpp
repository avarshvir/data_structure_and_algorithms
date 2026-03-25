#include <bits/stdc++.h>
using namespace std;

int main() {
    
    // Creating an empty unordered_multimap
    unordered_multimap<int, string> umm1;
    
    // Creating unordered_multimap using
    // initializer list
    unordered_multimap<int, string> umm2 =
    {{1, "C"}, {2, "C++"}, {1, "Python"}};

    for (auto x : umm2) 
        cout << x.first << ": " << x.second
        << endl;
    return 0;
}