#include<iostream>
#include<map>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

    /*
    Creation and Initialization of multimap:
    1. Default Declaration
    2. With Initializer List
    3. Copying one multimap to another
    4. Move multimap
    5. Custom Comparator for multimap
    */

    // Default Declaration
    multimap<int, string> mm1;                     // empty multimap          O(1)

    // With Initializer List (duplicates allowed)
    multimap<int, string> mm2 = {
        {1, "One"}, {2, "Two"}, {2, "Two Again"}, {3, "Three"}
    }; // O(n log n)

    // Copying
    multimap<int, string> mm3 = mm2;               // O(n)

    // Move
    multimap<int, string> mm4 = move(mm3);         // O(1)

    // Custom Comparator (descending)
    multimap<int, string, greater<int>> mm5 = {
        {1, "One"}, {2, "Two"}, {2, "Duplicate"}, {3, "Three"}
    };

    // Print
    cout << "Multimap 2:\n";
    for (const auto& p : mm2) {
        cout << p.first << " : " << p.second << endl;
    }

    /*
    Size Methods:
    1. size --- O(1)
    2. empty --- O(1)
    */
    cout << "Size: " << mm2.size() << endl;
    cout << "Empty? " << (mm1.empty() ? "Yes" : "No") << endl;

    /*
    Traversal Methods:
    1. Range Based Loop 
    2. Iterator based Loop
    3. Reverse Traversal
    */
    cout << "\nTraversal:\n";

    // Range loop
    for (const auto& p : mm2)
        cout << p.first << " : " << p.second << endl;

    // Iterator
    for (auto it = mm2.begin(); it != mm2.end(); ++it)
        cout << it->first << " : " << it->second << endl;

    // Reverse
    for (auto it = mm2.rbegin(); it != mm2.rend(); ++it)
        cout << it->first << " : " << it->second << endl;

    /*
    Insertion Methods:
    NOTE: No [] operator in multimap
    1. insert() --- O(log n)
    2. emplace() --- 
    3. Insert with hint
    4. Range insert
    */

    // insert()
    mm2.insert({4, "Four"});
    mm2.insert({2, "Two More"});   // duplicate key allowed

    // emplace()
    mm2.emplace(5, "Five");

    // insert with hint
    auto it = mm2.find(2);
    mm2.insert(it, {2, "Hint Inserted"});

    // range insert
    vector<pair<int, string>> v = {{6, "Six"}, {7, "Seven"}};
    mm2.insert(v.begin(), v.end());

    /*
    Deletion Methods:
    1. Erase by Key
    2. Erase by iterator
    3. Clear()
    4. Erase range
    5. 
    */

    // erase by key (removes ALL entries with that key)
    mm2.erase(2);

    // erase by iterator
    auto it2 = mm2.find(3);
    if(it2 != mm2.end())
        mm2.erase(it2);

    // clear
    // mm2.clear();

    /*
    Searching Methods:
    */

    // find() -> returns first occurrence
    auto f = mm2.find(4);
    if (f != mm2.end())
        cout << "Found: " << f->first << " => " << f->second << endl;

    // count() -> number of elements with key
    cout << "Count of key 2: " << mm2.count(2) << endl;

    // equal_range()
    auto range = mm2.equal_range(2);
    cout << "All values with key 2:\n";
    for (auto it = range.first; it != range.second; ++it)
        cout << it->first << " : " << it->second << endl;

    // lower_bound()
    auto lb = mm2.lower_bound(3);
    if(lb != mm2.end())
        cout << "Lower bound: " << lb->first << endl;

    // upper_bound()
    auto ub = mm2.upper_bound(3);
    if(ub != mm2.end())
        cout << "Upper bound: " << ub->first << endl;

    /*
    Accessing Elements:
    NOTE:
    - No [] operator
    - No at()
    - Must use iterators or equal_range
    */

    cout << "\nAccess all values with key 4:\n";
    auto r = mm2.equal_range(4);
    for(auto it = r.first; it != r.second; ++it)
        cout << it->second << endl;

    /*
    Swapping:
    */

    multimap<int, string> mm6 = {{10, "Ten"}, {11, "Eleven"}};

    cout << "\nBefore swap:\n";
    for(auto &p : mm2) cout << p.first << ":" << p.second << " ";
    cout << endl;

    mm2.swap(mm6);

    cout << "After swap:\n";
    for(auto &p : mm2) cout << p.first << ":" << p.second << " ";
    cout << endl;

    return 0;
}