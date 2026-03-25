#include <bits/stdc++.h>
using namespace std;

void print(unordered_map<int, string> um){
    for (auto i : um)
        cout << i.first << " " << i.second 
        << endl;
}
int main() {
    
    // Create an empty unordered_map
    unordered_map<int, string> um1;
    
    // Creating an unordered_map using
    // initializer list
    unordered_map<int, string> um2 =
    {{1, "C"}, {2, "C++"}, {3, "Python"}};
    
    print(um1);
    cout << endl;
    print(um2);
    return 0;
}