#include<iostream>
#include<unordered_map>   // contains unordered_multimap
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
    unordered_multimap<int, string> umm1;   // empty

    // Initializer List (duplicate keys allowed)
    unordered_multimap<int, string> umm2 = {
        {1, "A"}, {1, "B"}, {2, "C"}
    };

    // Copy
    unordered_multimap<int, string> umm3 = umm2;

    // Move
    unordered_multimap<int, string> umm4 = move(umm3);

    // From another container
    vector<pair<int,string>> v = {
        {10,"X"}, {20,"Y"}, {20,"Z"}
    };
    unordered_multimap<int,string> umm5(v.begin(), v.end());

    // Print
    cout << "umm2:\n";
    for(auto p : umm2)
        cout << p.first << " " << p.second << endl;

    cout << "\numm4:\n";
    for(auto p : umm4)
        cout << p.first << " " << p.second << endl;


    /*
    ============================================
    2. Size and Capacity
    ============================================
    */

    cout << "Size: " << umm2.size() << endl;
    cout << "Empty? " << (umm1.empty() ? "Yes" : "No") << endl;
    cout << "Max size: " << umm2.max_size() << endl;


    /*
    ============================================
    3. Traversal
    ============================================
    */

    cout << "Range loop:\n";
    for(auto p : umm2)
        cout << p.first << " " << p.second << endl;

    cout << "Iterator:\n";
    for(auto it = umm2.begin(); it != umm2.end(); it++)
        cout << it->first << " " << it->second << endl;

    cout << "for_each:\n";
    for_each(umm2.begin(), umm2.end(), [](auto p){
        cout << p.first << " " << p.second << endl;
    });


    /*
    ============================================
    4. Insertion
    ============================================
    */

    // insert
    umm2.insert({3, "D"});
    umm2.insert({3, "E"});

    // emplace
    umm2.emplace(4, "F");

    cout << "After insert/emplace:\n";
    for(auto p : umm2)
        cout << p.first << " " << p.second << endl;

    // insert range
    vector<pair<int,string>> v2 = {
        {5,"G"}, {5,"H"}
    };
    umm2.insert(v2.begin(), v2.end());


    /*
    ============================================
    5. Deletion
    ============================================
    */

    // erase by key (ALL occurrences)
    umm2.erase(3);

    cout << "After erase key=3:\n";
    for(auto p : umm2)
        cout << p.first << " " << p.second << endl;

    // erase ONE using iterator
    auto it = umm2.find(5);
    if(it != umm2.end())
        umm2.erase(it);

    cout << "After erasing one (key=5):\n";
    for(auto p : umm2)
        cout << p.first << " " << p.second << endl;

    // erase range
    auto range = umm2.equal_range(5);
    umm2.erase(range.first, range.second);

    cout << "After erasing all key=5:\n";
    for(auto p : umm2)
        cout << p.first << " " << p.second << endl;

    // clear
    unordered_multimap<int,string> temp = {
        {1,"A"}, {1,"B"}
    };
    temp.clear();
    cout << "Temp size after clear: " << temp.size() << endl;


    /*
    ============================================
    6. Searching
    ============================================
    */

    // find
    auto it_find = umm2.find(2);
    if(it_find != umm2.end())
        cout << "Key 2 found\n";
    else
        cout << "Key 2 not found\n";

    // count
    cout << "Count of key=2: " << umm2.count(2) << endl;

    // equal_range
    cout << "All values for key=2:\n";
    auto range2 = umm2.equal_range(2);
    for(auto it = range2.first; it != range2.second; it++)
        cout << it->first << " " << it->second << endl;


    /*
    ============================================
    7. Bucket Interface
    ============================================
    */

    cout << "Bucket count: " << umm2.bucket_count() << endl;
    cout << "Bucket of key 2: " << umm2.bucket(2) << endl;

    cout << "Bucket details:\n";
    for(int i = 0; i < umm2.bucket_count(); i++){
        cout << "Bucket " << i << ": ";
        for(auto it = umm2.begin(i); it != umm2.end(i); it++)
            cout << "(" << it->first << "," << it->second << ") ";
        cout << endl;
    }


    /*
    ============================================
    8. Load Factor
    ============================================
    */

    cout << "Load factor: " << umm2.load_factor() << endl;
    cout << "Max load factor: " << umm2.max_load_factor() << endl;

    umm2.max_load_factor(0.7);


    /*
    ============================================
    9. Rehashing
    ============================================
    */

    umm2.rehash(20);
    cout << "After rehash: " << umm2.bucket_count() << endl;

    umm2.reserve(50);
    cout << "After reserve: " << umm2.bucket_count() << endl;


    /*
    ============================================
    10. Swap
    ============================================
    */

    unordered_multimap<int,string> umm6 = {
        {100,"AA"}, {200,"BB"}
    };

    umm2.swap(umm6);

    cout << "After swap umm2:\n";
    for(auto p : umm2)
        cout << p.first << " " << p.second << endl;


    /*
    ============================================
    11. Important Notes
    ============================================

    - No ordering
    - Duplicate keys allowed
    - Each key maps to multiple values
    - umm[key] ❌ NOT allowed
    - erase(key) removes ALL entries
    - equal_range() is most important
    */


    /*
    ============================================
    12. Time Complexity
    ============================================

    insert   : O(1) avg
    erase    : O(1) avg
    find     : O(1) avg
    count    : O(k)
    traversal: O(n)
    */

}