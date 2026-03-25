#include <iostream>
#include <unordered_set> // unordered_multiset is defined here
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    /*
    ============================================
    1. Creation and Initialization
    ============================================
    */

    // Default Declaration
    unordered_multiset<int> ums1;               // Empty                        O(1)

    // With Initializer List (Duplicates ARE allowed)
    unordered_multiset<int> ums2 = {3, 1, 4, 1, 1}; // Stores all three 1s       O(n)

    // Copying
    unordered_multiset<int> ums3 = ums2;         // O(n)

    // Move
    unordered_multiset<int> ums4 = move(ums3);   // O(1)

    // From another container
    vector<int> v = {10, 20, 30, 20, 20};
    unordered_multiset<int> ums5(v.begin(), v.end()); // Stores all three 20s   O(n)

    cout << "Unordered Multiset 2 (with duplicates): ";
    for(auto x : ums2) cout << x << " "; // Output might be: 4 3 1 1 1
    cout << endl;


    /*
    ============================================
    2. Size and Capacity Methods
    ============================================
    */

    cout << "Size of ums2: " << ums2.size() << endl;          // Returns 5
    cout << "Is ums1 empty? " << (ums1.empty() ? "Yes" : "No") << endl;
    cout << "Max size: " << ums2.max_size() << endl;


    /*
    ============================================
    3. Traversal Methods
    ============================================
    */

    // Range-based loop (Standard way to see all duplicates)
    cout << "Range-based loop: ";
    for(auto x : ums2) cout << x << " ";
    cout << endl;

    // Iterator traversal
    cout << "Iterator traversal: ";
    for(auto it = ums2.begin(); it != ums2.end(); it++)
        cout << *it << " ";
    cout << endl;


    /*
    ============================================
    4. Insertion Methods
    ============================================
    */

    // Insert single
    ums2.insert(5);       // Average O(1)
    
    // Insert duplicate (Unlike unordered_set, this IS added)
    ums2.insert(5);       
    cout << "After inserting 5 twice: ";
    for(auto x : ums2) cout << x << " ";
    cout << endl;

    // Insert multiple via initializer list
    ums2.insert({7, 8, 7});
    
    // Insert from container range
    vector<int> v2 = {10, 11, 10};
    ums2.insert(v2.begin(), v2.end());


    /*
    ============================================
    5. Deletion Methods (CRITICAL DIFFERENCE)
    ============================================
    */

    // A. Erase by VALUE: Removes ALL occurrences of that value
    // If ums2 has three 1s, this removes ALL of them.
    ums2.erase(1);    
    cout << "After erasing ALL 1s: ";
    for(auto x : ums2) cout << x << " ";
    cout << endl;

    // B. Erase by ITERATOR: Removes only ONE specific occurrence
    auto it_single = ums2.find(5);
    if(it_single != ums2.end()) {
        ums2.erase(it_single); // Only one '5' is removed
    }
    cout << "After erasing ONE 5 by iterator: ";
    for(auto x : ums2) cout << x << " ";
    cout << endl;

    // C. Clear
    unordered_multiset<int> temp = {1, 1, 2};
    temp.clear(); 


    /*
    ============================================
    6. Searching Methods
    ============================================
    */

    // find(): Returns iterator to ONE of the instances
    auto it_find = ums2.find(7);
    if(it_find != ums2.end()) cout << "Found at least one 7\n";

    // count(): Returns the number of times an element exists
    cout << "Count of 10: " << ums2.count(10) << endl; // Returns 2

    // equal_range(): Returns a pair of iterators (start and end of a specific value)
    auto range = ums2.equal_range(7);
    cout << "Printing all 7s using equal_range: ";
    for (auto it = range.first; it != range.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;


    /*
    ============================================
    7. Bucket Interface
    ============================================
    */

    cout << "Total buckets: " << ums2.bucket_count() << endl;
    cout << "Bucket of element 7: " << ums2.bucket(7) << endl;

    // Note: Duplicates are usually stored in the same bucket
    cout << "Bucket 7 size: " << ums2.bucket_size(ums2.bucket(7)) << endl;


    /*
    ============================================
    8. Load Factor and Rehashing
    ============================================
    */

    cout << "Load factor: " << ums2.load_factor() << endl;
    ums2.reserve(100); // Pre-allocate for 100 elements to avoid rehashes


    /*
    ============================================
    9. Swap
    ============================================
    */

    unordered_multiset<int> ums6 = {100, 100, 200};
    ums2.swap(ums6);   // O(1)


    /*
    ============================================
    10. Important Notes & Summary
    ============================================
    */
    /*
    - DIfference from Set: Allows duplicate keys.
    - find(val): Returns an iterator to ANY one of the elements with that value.
    - erase(val): Removes ALL instances.
    - erase(iterator): Removes ONLY that instance.
    - equal_range(val): The most efficient way to get all duplicates of a value.
    
    TIME COMPLEXITY (Average):
    - Insert: O(1)
    - Erase:  O(1)
    - Find:   O(1)
    - Count:  O(number of matches)
    */

    return 0;
}