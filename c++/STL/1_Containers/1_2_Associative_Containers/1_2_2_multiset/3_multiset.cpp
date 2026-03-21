#include<iostream>
#include<set>
#include<iterator>
#include<algorithm>
#include<vector>

using namespace std;

int main(){

    /*
    Creation and Initialization of multiset:
    1. Default Declaration
    2. With Initializer List
    3. Copying one multiset to another
    4. Move multiset
    5. Custom Comparator for multiset
    */

    // Default Declaration
    multiset<int> ms1;                     // empty multiset                      O(1)
    // With Initializer List
    multiset<int> ms2 = {3, 1, 4, 1, 3};         // multiset with values 3,1,4,1,3          O(n log n) due to sorting during insertion
    // Copying one multiset to another
    multiset<int> ms3 = ms2;               // copying ms2 to ms3   or ms3(ms2)    O(n) due to copying elements from ms2 to ms3
    // Move multiset
    multiset<int> ms4 = move(ms3);        // moving ms3 to ms4                  O(1) due to move semantics (ms3 becomes empty after this operation)
    // Custom Comparator for multiset (descending order)
    multiset<int, greater<int>> ms5 = {5, 2, 8, 2, 5}; // multiset with values 5,2,8,2,5 in descending order  O(n log n) due to sorting during insertion
    
    // Print all multisets
    cout << "Multiset 1: ";
    for (const auto& elem : ms1) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "Multiset 2: ";
    for (const auto& elem : ms2) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "Multiset 3: ";
    for (const auto& elem : ms3) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "Multiset 4: ";
    for (const auto& elem : ms4) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "Multiset 5: ";
    for (const auto& elem : ms5) {
        cout << elem << " ";
    }
    cout << endl;

    /*
    Size and Capacity Methods:
    1. size()          --- O(1)
    2. empty()         --- O(1)
    3. max_size()      --- O(1)
    4. count()         --- O(log n) for single element, O(n) for range
    */

    // size()
    cout << "Size of Multiset 2: " << ms2.size() << endl;
    // empty()
    cout << "Is Multiset 1 empty? " << (ms1.empty() ? "Yes" : "No") << endl;
    // max_size()
    cout << "Maximum size of Multiset 2: " << ms2.max_size() << endl;
    // count()
    int count_3 = ms2.count(3); // counting occurrences of 3  O(log n) for single element, O(n) for range
    cout << "Count of 3 in Multiset 2: " << count_3 << endl;

    /*
    Traversal Methods:
    1. Range-based for loop
    2. Iterators
    3. for_each and lambda function
    4. Reverse traversal using reverse iterators (if supported by the container)
    */

    // Range-based for loop
    cout << "Using range-based for loop: ";
    for (const auto& elem : ms2) {
        cout << elem << " ";
    }
    cout << endl;
    // Iterators
    cout << "Using iterators: ";
    for (auto it = ms2.begin(); it != ms2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    // for_each and lambda function
    cout << "Using for_each and lambda function: ";
    for_each(ms2.begin(), ms2.end(), [](const int& elem) {
        cout << elem << " ";
    });
    cout << endl;
    // Reverse traversal
    cout << "Reverse traversal: ";
    for(auto it = ms2.rbegin(); it != ms2.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    /*
    Insertion Methods:
    1. insert()        --- O(log n) for single element, O(n log n) for range
    2. emplace()       --- O(log n) for single element, O(n log n) for range
    3. emplace_hint()  --- O(1) if hint is correct, O(log n) otherwise
    4. insert with hint --- O(1) if hint is correct, O(log n) otherwise
    5. Insert multiple values --- O(n log n) for n values due to sorting during insertion
    6. Insert from another container --- O(n log n) for n values due to sorting during insertion
    */

    // insert()
    ms2.insert(6); // inserting single element  O(log n)
    cout << "After inserting 6: ";
    for (const auto& elem : ms2) {
        cout << elem << " ";
    }
    cout << endl;
    // emplace()
    ms2.emplace(7); // emplacing single element  O(log n)
    cout << "After emplacing 7: ";
    for (const auto& elem : ms2) {
        cout << elem << " ";
    }
    cout << endl;
    // emplace_hint()
    auto it = ms2.find(5); // finding position of 5 to use as hint
    ms2.emplace_hint(it, 5); // emplacing 5 with hint  O(1) if hint is correct, O(log n) otherwise
    cout << "After emplacing 5 with hint: ";
    for (const auto& elem : ms2) {
        cout << elem << " ";
    }
    cout << endl;
    // insert with hint
    auto it2 = ms2.find(4); // finding position of 4 to use as hint
    ms2.insert(it2, 4); // inserting 4 with hint  O(1) if hint is correct, O(log n) otherwise
    cout << "After inserting 4 with hint: ";
    for (const auto& elem : ms2) {
        cout << elem << " ";
    }
    cout << endl;
    // Insert multiple values
    ms2.insert({8, 9, 10}); // inserting multiple values  O(n log n) for n values due to sorting during insertion
    cout << "After inserting multiple values: ";
    for (const auto& elem : ms2) {
        cout << elem << " ";
    }
    cout << endl;
    // Insert from another container
    vector<int> v = {11, 12, 13};
    ms2.insert(v.begin(), v.end()); // inserting from another container  O(n log n) for n values due to sorting during insertion
    cout << "After inserting from another container: ";
    for (const auto& elem : ms2) {
        cout << elem << " ";
    }
    cout << endl;

    /*
    Deletion Methods:
    1. erase()         --- O(log n) for single element, O(n) for range
    2. clear()         --- O(n)
    3. erase with iterator range --- O(n) for range
    4. erase by iterator --- O(1) for single element, O(n) for range
    5. erase range  --- O(n) for range
    */

    // erase()
    ms2.erase(5); // erasing by value  O(log n) for single element, O(n) for range
    cout << "After erasing 5: ";
    for (const auto& elem : ms2) {
        cout << elem << " ";
    }
    cout << endl;
    // clear()
    ms2.clear(); // clearing the multiset  O(n)
    cout << "After clearing the multiset, size: " << ms2.size() << endl;
    // Re-insert elements for further deletion examples
    ms2 = {1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10};
    // erase with iterator range
    auto it1 = ms2.find(3); // finding position of 3
    auto it6 = ms2.find(6); // finding position of 6
    ms2.erase(it1, it6); // erasing range from 3 to 6 (exclusive)  O(n) for range
    cout << "After erasing range from 3 to 6: ";
    for (const auto& elem : ms2) {
        cout << elem << " ";
    }
    cout << endl;
    // erase by iterator
    auto it3 = ms2.find(7); // finding position of 7
    ms2.erase(it3); // erasing by iterator  O(1) for single
    cout << "After erasing 7 by iterator: ";
    for (const auto& elem : ms2) {
        cout << elem << " ";
    }
    cout << endl;

    /*
    Searching Methods:
    1. find()          --- O(log n)
    2. count()         --- O(log n) for single element, O(n) for range
    3. equal_range()   --- O(log n)
    4. lower_bound()   --- O(log n)
    5. upper_bound()   --- O(log n)        
    */

    // find()
    auto it_find = ms2.find(4); // finding element 4  O(log n)
    if (it_find != ms2.end()) {
        cout << "Element found: " << *it_find << endl;
    } else {
        cout << "Element not found" << endl;
    }
    // count()
    int count_3_again = ms2.count(3); // counting occurrences of 3  O(log n) for single element, O(n) for range
    cout << "Count of 3 in Multiset 2: " << count_3_again << endl;
    // equal_range()
    auto range = ms2.equal_range(3); // finding equal range for 3  O(log n)
    cout << "Equal range for 3: [" << *range.first << ", " << *range.second << ")" << endl;
    // lower_bound()
    auto it_lower = ms2.lower_bound(3); // finding lower bound for 3  O(log n)
    if (it_lower != ms2.end()) {
        cout << "Lower bound for 3: " << *it_lower << endl;
    } else {
        cout << "Lower bound not found" << endl;
    }
    // upper_bound()
    auto it_upper = ms2.upper_bound(3); // finding upper bound for 3  O(log n)
    if (it_upper != ms2.end()) {
        cout << "Upper bound for 3: " << *it_upper << endl;
    } else {
        cout << "Upper bound not found" << endl;
    }
    
    /*
    Swapping and Merging:
    1. swap()          --- O(1)
    2. merge()         --- O(n) for merging two multisets of size n
    */
    
    // swap()
    multiset<int> ms6 = {11, 12, 13};
    cout << "Before swapping:" << endl;
    cout << "Multiset 2: ";
    for (const auto& elem : ms2) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "Multiset 6: ";
    for (const auto& elem : ms6) {
        cout << elem << " ";
    }
    cout << endl;
    ms2.swap(ms6); // swapping ms2 and ms6  O(1)
    cout << "After swapping:" << endl;
    cout << "Multiset 2: ";
    for (const auto& elem : ms2) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "Multiset 6: ";
    for (const auto& elem : ms6) {
        cout << elem << " ";
    }
    cout << endl;

    // merge()
    /*multiset<int> ms7 = {14, 15, 16};
    cout << "Before merging:" << endl;
    cout << "Multiset 2: ";
    for (const auto& elem : ms2) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "Multiset 7: ";
    for (const auto& elem : ms7) {
        cout << elem << " ";
    }
    cout << endl;
    ms2.merge(ms7); // merging ms7 into ms2  O(n) for merging two multisets of size n
    cout << "After merging:" << endl;
    cout << "Multiset 2: ";
    for (const auto& elem : ms2) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "Multiset 7: ";
    for (const auto& elem : ms7) {
        cout << elem << " ";
    }
    cout << endl;
    */


    return 0;

}