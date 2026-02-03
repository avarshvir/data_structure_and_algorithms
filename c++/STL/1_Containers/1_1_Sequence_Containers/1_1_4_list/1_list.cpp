#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int main(){

    /*
    Creating Lists:
    1. Default Declaration
    2. With Size
    3. With Size and Value
    4. Initializer List
    5. Copying one list to another
    6. Move List
    */

    // Default Declaration
    list<int> l1;                  // zero length list                               O(1)
    // With Size
    list<int> l2(5);               // 5 length list with default values               O(n)
    // With Size and Value
    list<int> l3(5, 10);           // 5 length list with all values as 10             O(n)
    // Initializer List
    list<int> l4 = {1, 2, 3};      // list with values 1,2,3                          O(n)
    // Copying one list to another
    list<int> l5 = l4;             // copying l4 to l5                                O(n)
    list<int> l5a = l4;            // copying l4 to l5a                               O(n)
    // Move List
    list<int> l6 = move(l5a);     // moving l5a to l6                                 O(1)
    // Print all lists size
    cout << "List 1: " << l1.size() << endl;
    cout << "List 2: " << l2.size() << endl;
    cout << "List 3: " << l3.size() << endl;
    cout << "List 4: " << l4.size() << endl;
    cout << "List 5: " << l5.size() << endl;
    cout << "List 6: " << l6.size() << endl;

    /*
    Size and Capacity Methods:
    1. size()       --- O(1)
    2. empty()      --- O(1)
    3. max_size()   --- O(1)
    4. list does NOT have capacity().
    */

    // size()
    cout << "Size of List 4: " << l4.size() << endl;
    // empty()
    cout << "Is List 1 empty? " << (l1.empty() ? "Yes" : "No") << endl;
    // max_size()
    cout << "Max size of List 4: " << l4.max_size() << endl;

    /*
    Element Access Methods: (Limited compared to vector and deque)
    1. front()       --- O(1)
    2. back()        --- O(1)
    3. [] operator and at() are NOT available for list
    */

    // front()
    cout << "Front of List 4: " << l4.front() << endl;
    // back()
    cout << "Back of List 4: " << l4.back() << endl;

    /*
    Traversing Lists: All these methods work in O(n) time complexity
    1. Using range-based for loop
    2. Using iterators (most common method for lists)
    3. Using for_each and lambda function
    4. Using reverse iterators
    5. Using traditional for loop is NOT possible as list does not support indexing
    */

    // Using range-based for loop
    cout << "Using range-based for loop: ";
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;

    // Using iterators
    cout << "Using iterators: ";
    for(auto it = l4.begin(); it != l4.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    // Using for_each and lambda function
    cout << "Using for_each and lambda function: ";
    for_each(l4.begin(), l4.end(), [](int val){
        cout << val << " ";
    });
    cout << endl;

    // Using reverse iterators
    cout << "Using reverse iterators: ";
    for(auto rit = l4.rbegin(); rit != l4.rend(); rit++){
        cout << *rit << " ";
    }
    cout << endl;

    /*
    Insertion Methods:
    1. push_back()       --- O(1)
    2. push_front()      --- O(1)
    3. insert()          --- O(n)
    4. emplace_back()    --- O(1)
    5. emplace_front()   --- O(1)
    6. emplace()         --- O(n)
    7. insert multiple elements --- O(n)
    */

    // push_back()
    l4.push_back(4);
    cout << "After push_back, List 4: ";
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;

    // push_front()
    l4.push_front(0);
    cout << "After push_front, List 4: ";
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;

    // insert()
    auto it = l4.begin();
    advance(it, 3); // move iterator to index 3
    l4.insert(it, 15); // inserting 15 at index 3
    cout << "After insert, List 4: ";
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;

    // emplace_back()
    l4.emplace_back(5);
    cout << "After emplace_back, List 4: ";
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;

    // emplace_front()
    l4.emplace_front(-1);
    cout << "After emplace_front, List 4: ";
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;

    // emplace()
    it = l4.begin();
    advance(it, 2); // move iterator to index 2
    l4.emplace(it, 18); // emplacing 18 at index 2
    cout << "After emplace, List 4: ";
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;

    // insert multiple elements
    it = l4.begin();
    advance(it, 4); // move iterator to index 4
    l4.insert(it, 3, 20); // inserting three 20s at index 4
    cout << "After inserting multiple elements, List 4: ";
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;

    /*
    Deletion Methods:
    1. pop_back()    --- O(1)
    2. pop_front()   --- O(1)
    3. erase()       --- O(n)
    4. clear()       --- O(n)
    5. remove()      --- O(n)
    6. remove_if()   --- O(n)
    */

    // pop_back()
    l4.pop_back();
    cout << "After pop_back, List 4: ";
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;

    //  pop_front()
    l4.pop_front();
    cout << "After pop_front, List 4: ";
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;

    // erase()
    it = l4.begin();
    advance(it, 2); // move iterator to index 2
    l4.erase(it); // erasing element at index 2
    cout << "After erase, List 4: ";
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;

    // clear()
    l4.clear();
    cout << "After clear, List 4 size: " << l4.size() << endl;
    // Re-initialize List 4
    l4 = {1, 2, 3, 4, 5, 2, 6};
    // remove()
    l4.remove(2); // removing all occurrences of 2
    cout << "After remove, List 4: ";
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;
    // remove_if()
    l4.remove_if([](int val){ return val % 2 == 0; }); // removing all even numbers
    cout << "After remove_if, List 4: ";    
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;

    /*
    Update Elements:
    1. Using iterators --- O(1)
    2. Using range-based for loop with reference --- O(1)
    */

    // Re-initialize List 4
    l4 = {1, 2, 3, 4, 5};
    // Using iterators
    for(auto it = l4.begin(); it != l4.end(); it++){
        *it += 10; // adding 10 to each element
    }
    cout << "After updating using iterators, List 4: ";
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;

    // Using range-based for loop with reference
    for(auto &val : l4){
        val += 20; // adding 20 to each element
    }
    cout << "After updating using range-based for loop, List 4: ";
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;

    /*
    Sorting and Reversing:
    - we use .sort() not sort() from <algorithm>
    e.g., lst.sort(); not sort(lst.begin(), lst.end());
    1. sort()      --- O(n log n)
    2. custom sort with comparator --- O(n log n)
    3. reverse()   --- O(n)
    */

    // sort()
    l4.sort();
    cout << "After sort, List 4: ";
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;

    // custom sort with comparator (descending order)
    l4.sort(greater<int>());
    cout << "After custom sort (descending), List 4: ";
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;

    // reverse()
    l4.reverse();
    cout << "After reverse, List 4: ";
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;

    /*
    Searching Lists:
    1. Linear Search using find() from <algorithm> --- O(n)
    2. No binary_search(), lower_bound(), upper_bound() as list is not random access
    */

    // Re-initialize List 4
    l4 = {10, 20, 30, 40, 50};
    // Using find()
    auto f_it = find(l4.begin(), l4.end(), 30);
    if(f_it != l4.end()){
        cout << "Element 30 found in List 4" << endl;
    } else {
        cout << "Element 30 not found in List 4" << endl;
    }
    
    /*
    Splice Method:
    - Transfers elements from one list to another
    1. splice() --- O(1) for single element, O(n) for range
    move() and splice() are different; move() transfers ownership, splice() transfers elements
    */

    // Re-initialize Lists
    list<int> l7 = {100, 200, 300};
    l4.splice(l4.end(), l7); // splicing entire l7 at the end of l4
    cout << "After splice, List 4: ";
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;
    cout << "After splice, List 7 size: " << l7.size() << endl;

    /*
    Merging Lists:
    - Both lists should be sorted before merging
    splice() and merge() are different; splice() transfers elements, merge() combines two sorted lists
    1. merge() --- O(n)
    Internally merge use algorithms like merge sort
    */

    // Re-initialize Lists
    l4 = {1, 3, 5, 7};
    l7 = {2, 4, 6, 8};
    l4.merge(l7); // merging l7 into l4
    cout << "After merge, List 4: ";
    for(auto val : l4){
        cout << val << " ";
    }
    cout << endl;
    cout << "After merge, List 7 size: " << l7.size() << endl;
        
    return 0;

}