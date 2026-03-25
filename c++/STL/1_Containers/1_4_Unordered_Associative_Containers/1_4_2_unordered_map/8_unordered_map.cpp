#include<iostream>
#include<unordered_map>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

    /*
    Creation and Initialization of unordered_map:
    1. Default Declaration
    2. With Initializer List
    3. Copying one unordered_map to another
    4. Move unordered_map
    */

    // Default Declaration
    unordered_map<int, string> um1;   // empty unordered_map    O(1)

    // With Initializer List
    unordered_map<int, string> um2 = {
        {1, "One"}, {2, "Two"}, {3, "Three"}
    }; // O(n) average

    // Copy
    unordered_map<int, string> um3 = um2; // O(n)

    // Move
    unordered_map<int, string> um4 = move(um3); // O(1)

    // Print maps (Order NOT guaranteed)
    cout << "Unordered Map 2:\n";
    for (const auto& p : um2) {
        cout << p.first << ": " << p.second << endl;
    }

    /*
    Size Methods:
    */

    cout << "Size: " << um2.size() << endl;       // O(1)
    cout << "Empty: " << um1.empty() << endl;     // O(1)
    cout << "Max Size: " << um2.max_size() << endl; // O(1)

    /*
    Traversal Methods:
    */

    // Range loop
    for (auto p : um2) {
        cout << p.first << ": " << p.second << endl;
    }

    // Iterator
    for (auto it = um2.begin(); it != um2.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    // for_each
    for_each(um2.begin(), um2.end(), [](auto p){
        cout << p.first << ": " << p.second << endl;
    });

    /*
    Insertion Methods:
    */

    // [] operator
    um2[4] = "Four";           // insert O(1) avg
    um2[2] = "Two Updated";    // update O(1)

    // insert()
    um2.insert({5, "Five"});   // no overwrite if exists

    // emplace()
    um2.emplace(6, "Six");

    // insert multiple
    um2.insert({{7, "Seven"}, {8, "Eight"}});

    // from vector
    vector<pair<int,string>> v = {{9,"Nine"}, {10,"Ten"}};
    um2.insert(v.begin(), v.end());

    /*
    Deletion Methods:
    */

    // erase by key
    um2.erase(5); // O(1) avg

    // erase by iterator
    auto it = um2.find(6);
    if(it != um2.end())
        um2.erase(it);

    // clear
    um2.clear(); // O(n)

    // reinitialize
    um2 = {{1,"One"}, {2,"Two"}, {3,"Three"}, {4,"Four"}};

    /*
    Searching Methods:
    */

    // find()
    auto it_find = um2.find(2); // O(1) avg
    if (it_find != um2.end())
        cout << "Found: " << it_find->second << endl;

    // count()
    cout << "Count of 2: " << um2.count(2) << endl; // 0 or 1

    /*
    Accessing Elements:
    */

    cout << um2[1] << endl;   // may create if not exist
    cout << um2.at(2) << endl; // safe

    um2[1] = "One Updated";
    um2.at(2) = "Two Updated";

    /*
    Bucket Interface (UNIQUE to unordered_map)
    */

    cout << "Bucket count: " << um2.bucket_count() << endl;

    cout << "Bucket of key 2: " << um2.bucket(2) << endl;

    // Iterate a specific bucket
    int b = um2.bucket(2);
    cout << "Elements in bucket " << b << ":\n";
    for (auto it = um2.begin(b); it != um2.end(b); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    /*
    Load Factor & Rehashing
    */

    cout << "Load factor: " << um2.load_factor() << endl;
    cout << "Max load factor: " << um2.max_load_factor() << endl;

    um2.max_load_factor(0.7); // set

    um2.rehash(20);  // rehash buckets
    um2.reserve(50); // reserve capacity

    /*
    Swapping
    */

    unordered_map<int,string> um5 = {{10,"Ten"}, {20,"Twenty"}};

    cout << "Before swap:\n";
    for(auto p : um2) cout << p.first << " ";
    cout << endl;

    for(auto p : um5) cout << p.first << " ";
    cout << endl;

    um2.swap(um5); // O(1)

    cout << "After swap:\n";
    for(auto p : um2) cout << p.first << " ";
    cout << endl;

    for(auto p : um5) cout << p.first << " ";
    cout << endl;

    return 0;
}