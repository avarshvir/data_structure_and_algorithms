#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_multimap<int, string> umm =
    {{2, "For"}, {3, "C++"}, {2, "Geeks"}};
    
    // Searching for key '2' using find()
    auto it = umm.find(2);
    
    if (it != umm.end())
        cout << it->first << ": " <<
            it->second;
    else
        cout << "Element not Found!";
    return 0;
}