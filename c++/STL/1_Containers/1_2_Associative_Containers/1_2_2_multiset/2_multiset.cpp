// traversing a multiset
//  Deleting Elements


#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<int> ms = {5, 3, 3, 1};

    // Traversing using range-based for loop
    for (auto i : ms)
        cout << i << " ";

    
    multiset<int> ms = {5, 3, 3, 1};

    //-----------------------

    // Delete first element
    ms.erase(ms.begin());

    // Delete all occurrences of 3
    ms.erase(3);

    // Print remaining elements
    for (auto x : ms)
        cout << x << " ";

    return 0;
}