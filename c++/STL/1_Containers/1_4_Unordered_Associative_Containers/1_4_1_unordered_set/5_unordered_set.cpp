#include<iostream>
#include<unordered_set>
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
    unordered_set<int> us1;                  // empty unordered_set        O(1)

    // With Initializer List
    unordered_set<int> us2 = {3, 1, 4, 1};   // duplicates ignored         O(n) average

    // Copying
    unordered_set<int> us3 = us2;            // O(n)

    // Move
    unordered_set<int> us4 = move(us3);      // O(1)

    // From another container
    vector<int> v = {10, 20, 30, 20};
    unordered_set<int> us5(v.begin(), v.end()); // O(n)

    // Print sets (order is NOT guaranteed)
    cout << "Unordered Set 1: ";
    for(auto x : us1) cout << x << " ";
    cout << endl;

    cout << "Unordered Set 2: ";
    for(auto x : us2) cout << x << " ";
    cout << endl;

    cout << "Unordered Set 3: ";
    for(auto x : us3) cout << x << " ";
    cout << endl;

    cout << "Unordered Set 4: ";
    for(auto x : us4) cout << x << " ";
    cout << endl;

    cout << "Unordered Set 5: ";
    for(auto x : us5) cout << x << " ";
    cout << endl;


    /*
    ============================================
    2. Size and Capacity Methods
    ============================================
    */

    cout << "Size of us2: " << us2.size() << endl;          // O(1)
    cout << "Is us1 empty? " << (us1.empty() ? "Yes" : "No") << endl; // O(1)
    cout << "Max size: " << us2.max_size() << endl;         // O(1)


    /*
    ============================================
    3. Traversal Methods
    ============================================
    */

    // Range-based loop
    cout << "Range-based loop: ";
    for(auto x : us2) cout << x << " ";
    cout << endl;

    // Iterator traversal
    cout << "Iterator traversal: ";
    for(auto it = us2.begin(); it != us2.end(); it++)
        cout << *it << " ";
    cout << endl;

    // for_each + lambda
    cout << "for_each traversal: ";
    for_each(us2.begin(), us2.end(), [](int x){
        cout << x << " ";
    });
    cout << endl;


    /*
    ============================================
    4. Insertion Methods
    ============================================
    */

    // insert single
    us2.insert(5);       // Average O(1)
    us2.insert(6);

    cout << "After inserting 5,6: ";
    for(auto x : us2) cout << x << " ";
    cout << endl;

    // insert duplicate
    us2.insert(5);   // ignored
    cout << "After inserting duplicate 5: ";
    for(auto x : us2) cout << x << " ";
    cout << endl;

    // insert multiple
    us2.insert({7,8,9});
    cout << "After inserting multiple: ";
    for(auto x : us2) cout << x << " ";
    cout << endl;

    // insert from container
    vector<int> v2 = {10,11,12};
    us2.insert(v2.begin(), v2.end());
    cout << "After inserting from vector: ";
    for(auto x : us2) cout << x << " ";
    cout << endl;


    /*
    ============================================
    5. Deletion Methods
    ============================================
    */

    // erase by value
    us2.erase(5);    // Average O(1)
    cout << "After erasing 5: ";
    for(auto x : us2) cout << x << " ";
    cout << endl;

    // erase by iterator
    auto it = us2.find(6);
    if(it != us2.end())
        us2.erase(it);

    cout << "After erasing 6 by iterator: ";
    for(auto x : us2) cout << x << " ";
    cout << endl;

    // clear
    unordered_set<int> temp = {1,2,3};
    temp.clear();    // O(n)
    cout << "After clear, size: " << temp.size() << endl;


    /*
    ============================================
    6. Searching Methods
    ============================================
    */

    // find()
    auto it_find = us2.find(7);   // Average O(1)
    if(it_find != us2.end())
        cout << "7 Found\n";
    else
        cout << "7 Not Found\n";

    // count()
    cout << "Count of 7: " << us2.count(7) << endl;  // 0 or 1


    /*
    ============================================
    7. Bucket Interface (UNIQUE FEATURE)
    ============================================
    */

    cout << "Total buckets: " << us2.bucket_count() << endl;

    cout << "Bucket of element 7: " << us2.bucket(7) << endl;

    // Print bucket wise elements
    cout << "Bucket details:\n";
    for(int i = 0; i < us2.bucket_count(); i++)
    {
        cout << "Bucket " << i << ": ";
        for(auto it = us2.begin(i); it != us2.end(i); it++)
            cout << *it << " ";
        cout << endl;
    }


    /*
    ============================================
    8. Load Factor Functions
    ============================================
    */

    cout << "Load factor: " << us2.load_factor() << endl;
    cout << "Max load factor: " << us2.max_load_factor() << endl;

    us2.max_load_factor(0.7);   // change threshold
    cout << "New max load factor: " << us2.max_load_factor() << endl;


    /*
    ============================================
    9. Rehashing and Reserving
    ============================================
    */

    us2.rehash(20);   // force bucket count >= 20
    cout << "After rehash(20), bucket count: " << us2.bucket_count() << endl;

    us2.reserve(50);  // prepare for 50 elements
    cout << "After reserve(50), bucket count: " << us2.bucket_count() << endl;


    /*
    ============================================
    10. Swap
    ============================================
    */

    unordered_set<int> us6 = {100,200,300};

    cout << "Before swap us2: ";
    for(auto x : us2) cout << x << " ";
    cout << endl;

    cout << "Before swap us6: ";
    for(auto x : us6) cout << x << " ";
    cout << endl;

    us2.swap(us6);   // O(1)

    cout << "After swap us2: ";
    for(auto x : us2) cout << x << " ";
    cout << endl;

    cout << "After swap us6: ";
    for(auto x : us6) cout << x << " ";
    cout << endl;


    /*
    ============================================
    11. Important Notes
    ============================================

    - No ordering (unlike set)
    - Uses hashing internally
    - Duplicate elements NOT allowed
    - Iterators may get invalidated after rehash
    */


    /*
    ============================================
    12. Time Complexity Summary
    ============================================

    insert   : O(1) avg, O(n) worst
    erase    : O(1) avg, O(n) worst
    find     : O(1) avg, O(n) worst
    traversal: O(n)

    Space Complexity: O(n) + bucket overhead
    */

}