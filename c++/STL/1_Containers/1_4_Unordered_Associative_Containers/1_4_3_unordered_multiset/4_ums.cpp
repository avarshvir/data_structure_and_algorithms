#include<iostream>
#include<unordered_set>   // contains unordered_multiset also
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    /*
    ============================================
    1. Creation and Initialization
    ============================================
    */

    // Default Declaration
    unordered_multiset<int> ums1;            // empty unordered_multiset   O(1)

    // With Initializer List (duplicates allowed)
    unordered_multiset<int> ums2 = {3, 1, 4, 1};  // duplicates kept       O(n)

    // Copying
    unordered_multiset<int> ums3 = ums2;     // O(n)

    // Move
    unordered_multiset<int> ums4 = move(ums3); // O(1)

    // From another container
    vector<int> v = {10, 20, 20, 30};
    unordered_multiset<int> ums5(v.begin(), v.end()); // O(n)

    // Print sets
    cout << "Unordered Multiset 1: ";
    for(auto x : ums1) cout << x << " ";
    cout << endl;

    cout << "Unordered Multiset 2: ";
    for(auto x : ums2) cout << x << " ";
    cout << endl;

    cout << "Unordered Multiset 3: ";
    for(auto x : ums3) cout << x << " ";
    cout << endl;

    cout << "Unordered Multiset 4: ";
    for(auto x : ums4) cout << x << " ";
    cout << endl;

    cout << "Unordered Multiset 5: ";
    for(auto x : ums5) cout << x << " ";
    cout << endl;


    /*
    ============================================
    2. Size and Capacity Methods
    ============================================
    */

    cout << "Size of ums2: " << ums2.size() << endl;        // O(1)
    cout << "Is ums1 empty? " << (ums1.empty() ? "Yes" : "No") << endl;
    cout << "Max size: " << ums2.max_size() << endl;


    /*
    ============================================
    3. Traversal Methods
    ============================================
    */

    // Range-based loop
    cout << "Range-based loop: ";
    for(auto x : ums2) cout << x << " ";
    cout << endl;

    // Iterator traversal
    cout << "Iterator traversal: ";
    for(auto it = ums2.begin(); it != ums2.end(); it++)
        cout << *it << " ";
    cout << endl;

    // for_each + lambda
    cout << "for_each traversal: ";
    for_each(ums2.begin(), ums2.end(), [](int x){
        cout << x << " ";
    });
    cout << endl;


    /*
    ============================================
    4. Insertion Methods
    ============================================
    */

    // insert single
    ums2.insert(5);   // O(1) avg
    ums2.insert(5);   // duplicate allowed

    cout << "After inserting 5,5: ";
    for(auto x : ums2) cout << x << " ";
    cout << endl;

    // insert multiple
    ums2.insert({7,8,8});
    cout << "After inserting multiple: ";
    for(auto x : ums2) cout << x << " ";
    cout << endl;

    // insert from container
    vector<int> v2 = {10,10,11};
    ums2.insert(v2.begin(), v2.end());
    cout << "After inserting from vector: ";
    for(auto x : ums2) cout << x << " ";
    cout << endl;


    /*
    ============================================
    5. Deletion Methods
    ============================================
    */

    // erase by value (removes ALL occurrences)
    ums2.erase(5);
    cout << "After erasing all 5: ";
    for(auto x : ums2) cout << x << " ";
    cout << endl;

    // erase ONE occurrence using iterator
    auto it = ums2.find(8);
    if(it != ums2.end())
        ums2.erase(it);

    cout << "After erasing one 8: ";
    for(auto x : ums2) cout << x << " ";
    cout << endl;

    // erase range (all occurrences of a value)
    auto range = ums2.equal_range(10);
    ums2.erase(range.first, range.second);

    cout << "After erasing all 10s: ";
    for(auto x : ums2) cout << x << " ";
    cout << endl;

    // clear
    unordered_multiset<int> temp = {1,2,2,3};
    temp.clear();
    cout << "After clear, size: " << temp.size() << endl;


    /*
    ============================================
    6. Searching Methods
    ============================================
    */

    // find()
    auto it_find = ums2.find(7);
    if(it_find != ums2.end())
        cout << "7 Found\n";
    else
        cout << "7 Not Found\n";

    // count() (IMPORTANT)
    cout << "Count of 8: " << ums2.count(8) << endl;

    // equal_range()
    cout << "All occurrences of 8: ";
    auto range2 = ums2.equal_range(8);
    for(auto it = range2.first; it != range2.second; it++)
        cout << *it << " ";
    cout << endl;


    /*
    ============================================
    7. Bucket Interface
    ============================================
    */

    cout << "Total buckets: " << ums2.bucket_count() << endl;
    cout << "Bucket of element 7: " << ums2.bucket(7) << endl;

    cout << "Bucket details:\n";
    for(int i = 0; i < ums2.bucket_count(); i++)
    {
        cout << "Bucket " << i << ": ";
        for(auto it = ums2.begin(i); it != ums2.end(i); it++)
            cout << *it << " ";
        cout << endl;
    }


    /*
    ============================================
    8. Load Factor Functions
    ============================================
    */

    cout << "Load factor: " << ums2.load_factor() << endl;
    cout << "Max load factor: " << ums2.max_load_factor() << endl;

    ums2.max_load_factor(0.7);
    cout << "New max load factor: " << ums2.max_load_factor() << endl;


    /*
    ============================================
    9. Rehashing and Reserving
    ============================================
    */

    ums2.rehash(20);
    cout << "After rehash(20): " << ums2.bucket_count() << endl;

    ums2.reserve(50);
    cout << "After reserve(50): " << ums2.bucket_count() << endl;


    /*
    ============================================
    10. Swap
    ============================================
    */

    unordered_multiset<int> ums6 = {100,200,200};

    cout << "Before swap ums2: ";
    for(auto x : ums2) cout << x << " ";
    cout << endl;

    cout << "Before swap ums6: ";
    for(auto x : ums6) cout << x << " ";
    cout << endl;

    ums2.swap(ums6);

    cout << "After swap ums2: ";
    for(auto x : ums2) cout << x << " ";
    cout << endl;

    cout << "After swap ums6: ";
    for(auto x : ums6) cout << x << " ";
    cout << endl;


    /*
    ============================================
    11. Important Notes
    ============================================

    - No ordering
    - Uses hashing
    - Duplicates ARE allowed
    - erase(value) removes ALL occurrences
    - count() returns number of duplicates
    - equal_range() gives range of duplicates
    - Iterators may get invalidated after rehash
    */


    /*
    ============================================
    12. Time Complexity Summary
    ============================================

    insert   : O(1) avg, O(n) worst
    erase    : O(1) avg, O(n) worst
    find     : O(1) avg, O(n) worst
    count    : O(k) (k = duplicates)
    traversal: O(n)

    Space Complexity: O(n) + bucket overhead
    */

}