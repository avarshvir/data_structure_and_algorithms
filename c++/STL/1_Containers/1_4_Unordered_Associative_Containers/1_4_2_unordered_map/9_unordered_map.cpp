#include <iostream>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    /*
    Creation and Initialization:
    Note: unordered_map does not support a custom comparator like std::greater in the 
    template arguments in the same way map does, as it relies on a Hash function and Key Equal function.
    */

    // 1. Default Declaration
    unordered_map<int, string> um1;                         // O(1)
    
    // 2. With Initializer List
    unordered_map<int, string> um2 = {{1, "One"}, {2, "Two"}, {3, "Three"}}; // Avg: O(n)
    
    // 3. Copying
    unordered_map<int, string> um3 = um2;                   // O(n)
    
    // 4. Move Map
    unordered_map<int, string> um4 = move(um3);             // O(1)

    cout << "--- Initial Traversal (Order is not guaranteed) ---\n";
    for (const auto& pair : um2) {
        cout << pair.first << ": " << pair.second << " | ";
    }
    cout << "\n\n";

    /*
    Size Methods: O(1)
    */
    cout << "Size of um2: " << um2.size() << endl;
    cout << "Is um1 empty? " << (um1.empty() ? "Yes" : "No") << endl;

    /*
    Traversal Methods:
    Note: Reverse iterators (rbegin/rend) do NOT exist for unordered_map.
    */
    cout << "\n--- Traversal Methods ---\n";
    // Range-based
    for (const auto& [key, val] : um2) cout << key << "->" << val << " ";
    cout << endl;

    // Iterator-based
    for (auto it = um2.begin(); it != um2.end(); ++it) {
        cout << it->first << ":" << it->second << " ";
    }
    cout << endl;

    /*
    Insertion Methods:
    Average: O(1), Worst Case: O(n) if rehashing occurs
    */
    um2[4] = "Four";                // Insert/Update
    um2.insert({5, "Five"});        // Insert (fails if exists)
    um2.emplace(6, "Six");          // In-place construction
    
    // Insert from another container
    vector<pair<int, string>> v = {{7, "Seven"}, {8, "Eight"}};
    um2.insert(v.begin(), v.end());

    /*
    Deletion Methods:
    Average: O(1)
    */
    um2.erase(5);                   // By key
    auto it_del = um2.find(6);
    if(it_del != um2.end()) um2.erase(it_del); // By iterator

    /*
    Searching & Access:
    Note: lower_bound and upper_bound do NOT exist in unordered_map because it's unsorted.
    */
    cout << "\n--- Searching ---\n";
    if (um2.find(3) != um2.end()) {
        cout << "Found 3: " << um2.at(3) << endl; // at() is safe, [] is not
    }
    cout << "Count of key 2: " << um2.count(2) << endl; // Returns 0 or 1

    /*
    Bucket Interface & Load Factor (Unique to Unordered)
    */
    cout << "\n--- Internal Stats ---\n";
    cout << "Bucket count: " << um2.bucket_count() << endl;
    cout << "Load factor: " << um2.load_factor() << endl;
    cout << "Max load factor: " << um2.max_load_factor() << endl;
    
    // Find which bucket a key is in
    int key = 2;
    cout << "Key " << key << " is in bucket #" << um2.bucket(key) << endl;

    /*
    Memory Management:
    rehash(n) -> sets bucket count to at least n
    reserve(n) -> prepares for n elements
    */
    um2.reserve(20); 

    return 0;
}