#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

    /*
    Creation and Initialization of set:
    1. Default Declaration
    2. With Initializer List
    3. Copying one set to another
    4. Move set
    5. Custom Comparator for set
    */

    // Default Declaration
    set<int> s1;                     // empty set                      O(1)
    // With Initializer List
    set<int> s2 = {3, 1, 4};         // set with values 3,1,4          O(n log n) due to sorting during insertion
    // Copying one set to another
    set<int> s3 = s2;               // copying s2 to s3   or s3(s2)    O(n) due to copying elements from s2 to s3
    // Move set
    set<int> s4 = move(s3);        // moving s3 to s4                  O(1) due to move semantics (s3 becomes empty after this operation)
    // Custom Comparator for set (descending order)
    set<int, greater<int>> s5 = {5, 2, 8}; // set with values 5,2,8 in descending order  O(n log n) due to sorting during insertion
    // Print all sets
    cout << "Set 1: ";
    for (const auto& elem : s1) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "Set 2: ";
    for (const auto& elem : s2) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "Set 3: ";
    for (const auto& elem : s3) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "Set 4: ";
    for (const auto& elem : s4) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "Set 5: ";
    for (const auto& elem : s5) {
        cout << elem << " ";
    }
    cout << endl;

    /*
    Size and Capacity Methods:
    1. size()          --- O(1)
    2. empty()         --- O(1)
    3. max_size()      --- O(1)
    */

    // size()
    cout << "Size of Set 2: " << s2.size() << endl;
    // empty()
    cout << "Is Set 1 empty? " << (s1.empty() ? "Yes" : "No") << endl;
    // max_size()
    cout << "Maximum size of Set 2: " << s2.max_size() << endl;

    /*
    Traversal Methods:
    1. Using range-based for loop
    2. Using iterators
    3. Using for_each and lambda function
    4. Reverse traversal using reverse iterators (if supported by the container)
    */

    // Using range-based for loop
    cout << "Using range-based for loop: ";
    for (const auto& elem : s2) {
        cout << elem << " ";
    }
    cout << endl;
    // Using iterators
    cout << "Using iterators: ";
    for (auto it = s2.begin(); it != s2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    // Using for_each and lambda function
    cout << "Using for_each and lambda function: ";
    for_each(s2.begin(), s2.end(), [](const int& elem) {
        cout << elem << " ";
    });
    cout << endl;
    // Reverse traversal
    cout << "Reverse traversal: ";
    for(auto it = s2.rbegin(); it != s2.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    /*
    Insertion Methods:
    1. insert()        --- O(log n) for single element, O(n log
    2. emplace()       --- O(log n) for single element, O(n log n) for range
    3. insert with hint --- O(1) if hint is correct, O(log n) otherwise
    4. Insert multiple values  --- O(n log n) for n values due to sorting during insertion
    5. Insert from another container  --- O(n log n) for n values due to sorting during insertion
    */

    // insert()
    s2.insert(5); // inserting single element  O(log n)
    cout << "After inserting 5: ";
    for (const auto& elem : s2) {
        cout << elem << " ";
    }
    cout << endl;
    // emplace()
    s2.emplace(6); // emplacing single element  O(log n)
    cout << "After emplacing 6: ";
    for (const auto& elem : s2) {
        cout << elem << " ";
    }
    cout << endl;
    // insert with hint
    auto it = s2.find(4); // finding position of 4 to use as hint
    s2.insert(it, 7); // inserting 7 with hint  O(1) if hint is correct, O(log n) otherwise
    cout << "After inserting 7 with hint: ";
    for (const auto& elem : s2) {
        cout << elem << " ";
    }
    cout << endl;
    // Insert multiple values
    s2.insert({8, 9, 10}); // inserting multiple values  O (n log n) for n values due to sorting during insertion
    cout << "After inserting multiple values: ";
    for (const auto& elem : s2) {
        cout << elem << " ";
    }
    cout << endl;
    // Insert from another container
    vector<int> v = {11, 12, 13};
    s2.insert(v.begin(), v.end()); // inserting from another container  O(n log n) for n values due to sorting during insertion
    cout << "After inserting from another container: ";
    for (const auto& elem : s2) {
        cout << elem << " ";
    }
    cout << endl;

    /*
    Deletion Methods:
    1. erase()         --- O(log n) for single element, O(n)
    2. clear()         --- O(n)
    3. erase with iterator range --- O(n) for range
    4. erase by iterator --- O(1) for single element, O(n) for range
    5. erase by value --- O(log n) for single element, O(n) for range
    6. erase range  --- O(n) for range
    */

    // erase() by value
    s2.erase(5); // erasing single element by value  O(log n)
    cout << "After erasing 5: ";
    for (const auto& elem : s2) {
        cout << elem << " ";
    }
    cout << endl;
    // clear()
    s2.clear(); // clearing the set  O(n)
    cout << "After clearing the set, size: " << s2.size() << endl;
    // Re-initialize set for further deletion examples
    s2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // erase with iterator range
    auto it1 = s2.find(3); // finding position of 3
    auto it2 = s2.find(6); // finding position of 6
    s2.erase(it1, it2); // erasing range from 3 to 6 (exclusive)  O(n) for range
    cout << "After erasing range from 3 to 6: ";
    for (const auto& elem : s2) {
        cout << elem << " ";
    }
    cout << endl;
    // erase by iterator
    it1 = s2.find(7); // finding position of 7
    s2.erase(it1); // erasing by iterator  O(1) for single element
    cout << "After erasing 7 by iterator: ";
    for (const auto& elem : s2) {
        cout << elem << " ";
    }
    cout << endl;
    // erase by value
    s2.erase(8); // erasing by value  O(log n) for single element
    cout << "After erasing 8 by value: ";
    for (const auto& elem : s2) {
        cout << elem << " ";
    }
    cout << endl;
    // erase range
    it1 = s2.find(9); // finding position of 9
    it2 = s2.find(10); // finding position of 10
    s2.erase(it1, it2); // erasing range from 9 to 10 (exclusive)  O(n) for range
    cout << "After erasing range from 9 to 10: ";
    for (const auto& elem : s2) {
        cout << elem << " ";
    }
    cout << endl;

    /*
    Searching Methods:
    1. find()          --- O(log n)
    2. count()         --- O(log n)
    3. equal_range()   --- O(log n)
    4. lower_bound()   --- O(log n)
    5. upper_bound()   --- O(log n)
    */

    // Re-initialize set for searching examples
    s2 = {1, 2, 3, 4, 5,
            6, 7, 8, 9, 10};
    
    // find()
    auto it_find = s2.find(5); // finding element 5  O(log
    if (it_find != s2.end()) {
        cout << "Element found: " << *it_find << endl;
    } else {
        cout << "Element not found" << endl;
    }
    // count()
    int count_5 = s2.count(5); // counting occurrences of 5  O(log n)
    cout << "Count of 5: " << count_5 << endl;
    // equal_range()
    auto range = s2.equal_range(5); // finding equal range for 5  O(log n)
    cout << "Equal range for 5: [" << *range.first << ", " << *range.second << ")" << endl;
    // lower_bound()
    auto it_lower = s2.lower_bound(5); // finding lower bound for 5  O(log n)
    if (it_lower != s2.end()) {
        cout << "Lower bound for 5: " << *it_lower << endl;
    } else {
        cout << "Lower bound not found" << endl;
    }
    // upper_bound()
    auto it_upper = s2.upper_bound(5); // finding upper bound for 5  O(log n)
    if (it_upper != s2.end()) {
        cout << "Upper bound for 5: " << *it_upper << endl;
    } else {
        cout << "Upper bound not found" << endl;
    }

    /*
    Range Queries:
    1. equal_range()   --- O(log n)
    2. lower_bound()   --- O(log n)
    3. upper_bound()   --- O(log n)
    */

    // equal_range()
    auto range_query = s2.equal_range(5); // finding equal range for 5  O(log n)
    cout << "Equal range for 5: [" << *range_query.first << ", " << *range_query.second << ")" << endl;
    // lower_bound()
    auto it_lower_bound = s2.lower_bound(5); // finding lower bound for 5  O(log n)
    if (it_lower_bound != s2.end()) {
        cout << "Lower bound for 5: " << *it_lower_bound << endl;
    } else {
        cout << "Lower bound not found" << endl;
    }
    // upper_bound()
    auto it_upper_bound = s2.upper_bound(5); // finding upper bound for 5  O(log n)
    if (it_upper_bound != s2.end()) {
        cout << "Upper bound for 5: " << *it_upper_bound << endl;
    } else {
        cout << "Upper bound not found" << endl;
    }


    /*
    Swapping and Merging:
    1. swap()          --- O(1)
    2. merge()         --- O(n) for merging two sets of size n
    */

    //  swap()
    set<int> s6 = {11, 12, 13};
    cout << "Before swapping, Set 2: ";
    for (const auto& elem : s2) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "Before swapping, Set 6: ";
    for (const auto& elem : s6) {
        cout << elem << " ";
    }
    cout << endl;
    s2.swap(s6); // swapping s2 and s6  O(1)
    cout << "After swapping, Set 2: ";
    for (const auto& elem : s2) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "After swapping, Set 6: ";
    for (const auto& elem : s6) {
        cout << elem << " ";
    }
    cout << endl;
    // merge()
    /*set<int> s7 = {14, 15, 16};
    cout << "Before merging, Set 2: ";
    for (const auto& elem : s2) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "Before merging, Set 7: ";
    for (const auto& elem : s7) {
        cout << elem << " ";
    }
    cout << endl;
    s2.merge(s7); // merging s7 into s2  O(n) for merging two sets of size n
    cout << "After merging, Set 2: ";
    for (const auto& elem : s2) {
        cout << elem << " ";
    } 
    cout << endl;
    cout << "After merging, Set 7: ";
    for (const auto& elem : s7) {
        cout << elem << " ";
    }*/

    

}