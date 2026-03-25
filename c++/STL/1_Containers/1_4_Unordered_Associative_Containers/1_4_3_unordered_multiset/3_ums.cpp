// Deleting and Traversing

#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_multiset<int> ums =
                       {5, 1, 3, 2, 4, 1, 2};

    // Delete all occurrences of element 1
    ums.erase(1);
    
    // Delete 2 using iterator
    ums.erase(ums.find(2));

    // Delete 4 using iterator
    ums.erase(ums.find(4));
    
    // Traverse using range based loop
    for (auto x: ums) 
        cout << x << " ";

    cout << endl;

    // Traverse using iterator
    for(auto it = ums.begin(); it != ums.end(); it++){
        cout << *it << " ";
    }

    return 0;
}