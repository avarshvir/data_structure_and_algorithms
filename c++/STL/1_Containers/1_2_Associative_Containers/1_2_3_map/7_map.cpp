#include<iostream>
#include<map>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

    /*
    Creation and Initialization of map:
    1. Default Declaration
    2. With Initializer List
    3. Copying one map to another
    4. Move Map
    5. Custom Comparator for Map
    */

    // Default Declaration
    map<int, string> m1;                     // empty map                      O(1)
    // With Initializer List
    map<int, string> m2 = {{1, "One"}, {2, "Two"}, {3, "Three"}};         // map with values 1,2,3          O(n log n) due to sorting during insertion
    // Copying one map to another
    map<int, string> m3 = m2;               // copying m2 to m3   or m3(m2)    O(n) due to copying elements from m2 to m3
    // Move Map
    map<int, string> m4 = move(m3);        // moving m3 to m4                  O(1) due to move semantics (m3 becomes empty after this operation)
    // Custom Comparator for Map (descending order)
    map<int, string, greater<int>> m5 = {{1, "One"}, {2, "Two"}, {3, "Three"}}; // map with values 1,2,3 in descending order  O(n log n) due to sorting during insertion

    // Print all maps
    cout << "Map 1: ";
    for (const auto& pair : m1) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Map 2: ";
    for (const auto& pair : m2) {   
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Map 3: ";
    for (const auto& pair : m3) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Map 4: ";
    for (const auto& pair : m4) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Map 5: ";
    for (const auto& pair : m5) {
        cout << pair.first << ": " << pair.second << endl;
    }

    /*
    Size Methods:
    1. size()          --- O(1)
    2. empty()         --- O(1)
    3. max_size()      --- O(1)
    */

    // size()
    cout << "Size of Map 2: " << m2.size() << endl;
    // empty()
    cout << "Is Map 1 empty? " << (m1.empty() ? "Yes" : "No") << endl;
    // max_size()
    cout << "Maximum size of Map 2: " << m2.max_size() << endl;

    /*
    Traversal Methods:
    1. Range-based for loop                      --- O(n)
    2. Iterators                                 --- O(n)
    3. for_each and lambda function              --- O(n)
    4. Reverse traversal                         --- O(n)
    5. Using for loop with keys (not recommended) --- O(n) but may lead to out of range error if keys are not continuous
    */

    // Range-based for loop
    cout << "Using range-based for loop: ";
    for (const auto& pair : m2) {
        cout << pair.first << ": " << pair.second << endl;
    }
    // Iterators
    for(auto it = m2.begin(); it != m2.end(); ++it){
        cout << it->first << ": " << it->second << endl;
    }
    // for_each and lambda function
    for_each(m2.begin(), m2.end(), [](const pair<int, string>& pair) {
        cout << pair.first << ": " << pair.second << endl;
    });
    // Reverse traversal
    for (auto it = m2.rbegin(); it != m2.rend(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
    // Using for loop with keys (not recommended)
    for (int i = 1; i <= m2.size(); ++i) {
        cout << i << ": " << m2[i] << endl; // may lead to out of range error if keys are not continuous
    }

    /*
    Insertion Methods:
    1. [] operator                             --- O(log n) for new key, O(1) for existing key (overwrites value) and updates values
    2. insert() method                         --- O(log n) for single element, O(n log n) for multiple elements due to sorting during insertion
    3. emplace() method                        --- O(log n) for single element, O(n log n) for multiple elements due to sorting during insertion
    4. insert with hint                          --- O(1) if hint is correct, O(log n) otherwise
    5. emplace_hint()                          --- O(1) if hint is correct, O(log n) otherwise
    6. Insert multiple values using initializer list --- O(n log n) for n values due to sorting during insertion
    7. Insert from another container using insert() method --- O(n log n) for n values due to sorting during insertion
    */

    // [] operator
    m2[4] = "Four"; // inserting new key 4 with value "Four"  O(log n) for new key
    m2[2] = "Two Updated"; // updating existing key 2 with new value "Two Updated"  O(1) for existing key
    // insert() method
    m2.insert({5, "Five"}); // inserting single element  O(log n)
    m2.insert({{6, "Six"}, {7, "Seven"}});  // inserting multiple elements  O(n log n) for n values due to sorting during insertion
    // emplace() method
    m2.emplace(8, "Eight"); // emplacing single element  O(log n)
    m2.emplace(9, "Nine"); // emplacing single element  O(log n)
    // insert with hint
    auto it = m2.find(5); // finding position of key 5 to use
    m2.insert(it, {5, "Five Updated"}); // inserting with hint  O(1) if hint is correct, O(log n) otherwise
    // emplace_hint()
    auto it2 = m2.find(6); // finding position of key 6 to use as hint
    m2.emplace_hint(it2, 6, "Six Updated"); // emplacing with hint  O(1) if hint is correct, O(log n) otherwise
    // Insert multiple values using initializer list
    m2.insert({{10, "Ten"}, {11, "Eleven"}});  // inserting multiple elements  O(n log n) for n values due to sorting during insertion
    // Insert from another container using insert() method
    vector<pair<int, string>> v = {{12, "Twelve"}, {13, "Thirteen"}};
    m2.insert(v.begin(), v.end()); // inserting from another container  O(n log n) for n values due to sorting during insertion

    /*
    Deletion Methods:
    1. Erase by Key                      --- O(log n)
    2. Erase by Iterator                   --- O(1) for single element, O(n) for range
    3. Erase by Iterator Range             --- O(n) for range
    4. clear()                             --- O(n)
    */

    // Erase by Key
    m2.erase(5); // erasing element with key 5  O(log n)
    // Erase by Iterator
    auto it3 = m2.find(6); // finding position of key 6
    m2.erase(it3); // erasing element at iterator position  O(1) for single element
    // Erase by Iterator Range
    auto it4 = m2.find(7); // finding position of key 7
    auto it5 = m2.find(9); // finding position of key 9
    m2.erase(it4, it5); // erasing range from key 7 to key 9 (exclusive)  O(n) for range
    // clear()
    m2.clear(); // clearing the map  O(n)

    // redeclare m2 for further operations
    m2 = {{1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}};

    /*
    Searching Methods:
    1. find()          --- O(log n)
    2. count()         --- O(log n) for single element, O(n) for range
    3. equal_range()   --- O(log n)
    4. lower_bound()   --- O(log n)
    5. upper_bound()   --- O(log n)
    */

    // find()
    auto it_find = m2.find(3); // finding element with key 3  O(log n)
    if (it_find != m2.end()) {
        cout << "Element found: " << it_find->first << " => " << it_find->second << endl;
    } else {
        cout << "Key not found" << endl;
    }
    // count()
    int count_2 = m2.count(2); // counting occurrences of key 2  O(log n) for single element, O(n) for range
    cout << "Count of key 2 in Map 2: " << count_2 << endl;
    // equal_range()
    auto range = m2.equal_range(3); // finding equal range for key 3  O(log n)
    cout << "Equal range for key 3: [" << (range.first != m2.end() ? to_string(range.first->first) : "end") << ", " << (range.second != m2.end() ? to_string(range.second->first) : "end") << ")" << endl;
    // lower_bound()
    auto it_lower = m2.lower_bound(3); // finding lower bound for key 3  O(log n)
    if (it_lower != m2.end()) {
        cout << "Lower bound for key 3: " << it_lower->first << " => " << it_lower->second << endl;
    } else {
        cout << "Lower bound not found" << endl;
    }
    // upper_bound()
    auto it_upper = m2.upper_bound(3); // finding upper bound for key 3  O(log n)
    if (it_upper != m2.end()) {
        cout << "Upper bound for key 3: " << it_upper->first << " => " << it_upper->second << endl;
    } else {
        cout << "Upper bound not found" << endl;
    }

    /*
    Accessing and Modifying Elements:
    1. Accessing values using keys (operator[] and at()) --- O(log n) for new key, O(1) for existing key (overwrites value) and updates values
    2. Modifying values using keys (operator[] and at()) --- O(log n) for new key, O(1) for existing key (overwrites value) and updates values
    */
    // [] -> Creates element if not exists and at() -> Safe but Throws exception if key not found
    // Accessing values using keys
    cout << m2[1] << endl; // Accessing value with key 1  O(log n) for new key, O(1) for existing key
    cout << m2.at(2) << endl; // Accessing value with key 2 using at() method  O(log n) for new key, O(1) for existing key
    // Modifying values using keys  
    m2[1] = "One Updated"; // Modifying value with key 1 using operator[]  O(log n) for new key, O(1) for existing key
    m2.at(2) = "Two Updated"; // Modifying value with key 2 using at() method  O(log n) for new key, O(1) for existing key

    for (const auto& pair : m2) {
        cout << pair.first << ": " << pair.second << endl;
    }

    /*
    Swapping and Merging:
    1. swap()          --- O(1)
    */

    // swap()
    map<int, string> m6 = {{14, "Fourteen"}, {15, "Fifteen"}};
    cout << "Before swapping:" << endl;
    cout << "Map 2: ";
    for (const auto& pair : m2) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Map 6: ";
    for (const auto& pair : m6) {
        cout << pair.first << ": " << pair.second << endl;
    }
    m2.swap(m6); // swapping m2 and m6  O(1)
    cout << "After swapping:" << endl;
    cout << "Map 2: ";
    for (const auto& pair : m2) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Map 6: ";
    for (const auto& pair : m6) {
        cout << pair.first << ": " << pair.second << endl;
    }
    


    return 0;


}