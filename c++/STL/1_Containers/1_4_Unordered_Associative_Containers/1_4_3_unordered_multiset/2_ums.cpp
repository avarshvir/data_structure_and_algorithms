//Accessing Elements and Finding Elements
// we can't update elements

#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_multiset<int> ums =
                    {5, 1, 3, 2, 4, 1};

    // Accessing element using iterator
    auto it = next(ums.begin(), 2);
    cout << *it;

    cout << endl;

    // FInding 3
    auto it2 = ums.find(3);
    
    if (it2 != ums.end()) cout << *it2;
    else cout << "Element not Found!";

    return 0;
}