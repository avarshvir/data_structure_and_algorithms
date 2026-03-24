#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    /*
    1. Creation and Initialization:
    - Default: O(1)
    - Initializer List: O(n) average, O(n^2) worst
    - Copy/Move: O(n) / O(1)
    - Range: O(n) average
    */

    // Default Declaration
    unordered_set<int> us1;

    // With Initializer List (Note: Order is not preserved)
    unordered_set<int> us2 = {10, 20, 30, 40, 50};

    // Copying one unordered_set to another
    unordered_set<int> us3 = us2;

    // Move semantics
    unordered_set<int> us4 = move(us3); // us3 is now empty

    // From another container (Range constructor)
    vector<int> vec = {1, 2, 2, 3, 4, 5}; 
    unordered_set<int> us5(vec.begin(), vec.end()); // Only unique: 1, 2, 3, 4, 5

    /*
    2. Size and Capacity Methods:
    - size(): Number of elements
    - empty(): Boolean check
    - max_size(): Architectural limit
    */
    cout << "--- Capacity ---" << endl;
    cout << "us2 Size: " << us2.size() << endl;
    cout << "us1 is empty: " << (us1.empty() ? "Yes" : "No") << endl;

    /*
    3. Traversal Methods:
    Note: unordered_set does NOT support reverse iterators (rbegin/rend) 
    because it is a forward-only container.
    */
    cout << "\n--- Traversal ---" << endl;
    cout << "Range-based loop: ";
    for (const int& x : us2) cout << x << " "; 

    cout << "\nIterator-based: ";
    for (auto it = us2.begin(); it != us2.end(); ++it) cout << *it << " ";
    cout << endl;

    /*
    4. Insertion Methods:
    - Average: O(1)
    - Worst: O(n) if many collisions occur or rehashing happens
    */
    cout << "\n--- Insertion ---" << endl;
    us2.insert(60);             // Single element
    us2.emplace(70);            // Constructs in-place
    us2.insert({80, 90, 100});  // Multiple values

    /*
    5. Deletion Methods:
    - erase(val): O(1) avg
    - erase(iterator): O(1) avg
    - erase(first, last): O(n)
    */
    cout << "\n--- Deletion ---" << endl;
    us2.erase(20);              // By value
    auto it_del = us2.find(40);
    if (it_del != us2.end()) us2.erase(it_del); // By iterator

    /*
    6. Searching and Lookup:
    - find(): Returns iterator to element or end()
    - count(): Returns 1 if present, 0 if not
    */
    cout << "\n--- Searching ---" << endl;
    if (us2.find(70) != us2.end()) cout << "70 found!" << endl;
    cout << "Count of 10: " << us2.count(10) << endl;

    /*
    7. Bucket Interface (Deep Dive):
    The unordered_set is organized into buckets.
    */
    cout << "\n--- Bucket Information ---" << endl;
    cout << "Bucket count: " << us2.bucket_count() << endl;
    cout << "Load factor: " << us2.load_factor() << endl;
    cout << "Max load factor: " << us2.max_load_factor() << endl;

    // Visualizing buckets
    for (size_t i = 0; i < us2.bucket_count(); ++i) {
        cout << "Bucket #" << i << " contains: ";
        for (auto it = us2.begin(i); it != us2.end(i); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    /*
    8. Policy Management (Rehashing):
    - rehash(n): Changes number of buckets to at least n.
    - reserve(n): Prepares for n elements (prevents frequent rehashing).
    */
    us2.reserve(100); // Optimization if you know you'll store 100 elements
    us2.rehash(50);   // Manually setting bucket count

    /*
    9. Swapping and Merging:
    - swap(): O(1)
    - merge(): O(N) - (C++17 feature) Extracts nodes and inserts into target
    */
    unordered_set<int> other = {500, 600};
    us2.swap(other); // us2 now has 500, 600
    
    // Merge (moves elements from 'other' back to 'us2' if they don't exist)
    //us2.merge(other); 

    return 0;
}