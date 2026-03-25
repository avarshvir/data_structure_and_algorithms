// Insertion and Accessing Value
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_multimap<int, string> umm;
    
    // Insert elements using insert()
    umm.insert({2, "For"});
    umm.insert({3, "C++"});
    umm.insert({2, "Geeks"});
    
    for (auto x : umm) 
        cout << x.first << ": "
        << x.second << endl;

    // Find 2nd element
    /*
    Elements can be accessed by its position by moving begin() and end() iterators, 
    but it is not useful. In unordered multimap, accessing value by their key is the 
    primary operation. This can be done by using find() method.
    */
    auto it = next(umm.begin(), 1);
    
    if (it != umm.end())
        cout << it->first << ": " <<
        it->second;
    else
        cout << "Element not found!";
    return 0;
}