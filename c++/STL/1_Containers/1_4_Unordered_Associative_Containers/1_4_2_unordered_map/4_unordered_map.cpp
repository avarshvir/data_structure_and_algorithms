#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, string> um =
    {{1, "C"}, {2, "C++"}, {3, "Python"}, {4, "DBMS"}, {5, "Cloud"}};

    // Updating value associated with key 2
    // using [] operator
    um[4] = "Java";
    cout << um[4] << endl;
    
    // Updating value associated with key 1
    //using at() function
    um.at(5) = "MySQL";
    cout << um.at(5);
    return 0;
}