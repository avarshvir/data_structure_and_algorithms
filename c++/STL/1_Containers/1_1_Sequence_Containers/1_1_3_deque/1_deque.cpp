#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int main(){
    /*
    Deque Declaration Methods:
    1. Default Declaration 
    2. With Size
    3. With Size and Value
    4. Initializer List
    5. Copying one deque to another
    6. Move Deque
    */
    // declaration
    deque<int> d1;                 // zero length deque                               O(1)
    // With size
    deque<int> d2(5);             // 5 length deque with default values               O(n)
    // With size and value     
    deque<int> d3(5, 10);         // 5 length deque with all values as 10             O(n)
    // Initializer list
    deque<int> d4 = {1, 2, 3};    // deque with values 1,2,3                          O(n)
    // Copying one deque to another
    deque<int> d5 = d4;           // copying d4 to d5                                  O(n)
    deque<int> d5a = d4;
    // Move Deque
    deque<int> d6 = move(d5a);     // moving d5 to d6                                   O(1)

    // Print all deques size
    cout << "Deque 1: " << d1.size() << endl;
    cout << "Deque 2: " << d2.size() << endl;
    cout << "Deque 3: " << d3.size() << endl;
    cout << "Deque 4: " << d4.size() << endl;
    cout << "Deque 5: " << d5.size() << endl;
    cout << "Deque 6: " << d6.size() << endl;

    /*
    Size and Capacity Methods:
    1. size()       --- O(1)
    2. empty()      --- O(1)
    3. max_size()   --- O(1)
    4. deque does NOT have capacity().
    */

    // size()
    cout << "Size of Deque 4: " << d4.size() << endl;
    // empty()
    cout << "Is Deque 1 empty? " << (d1.empty() ? "Yes" : "No") << endl;
    // max_size()
    cout << "Max size of Deque 4: " << d4.max_size() << endl;

    /*
    Element Access Methods:
    1. at()          --- O(1)
    2. operator[]    --- O(1)
    3. front()       --- O(1)
    4. back()        --- O(1)
    */

    // Accessing Deque 4 elements using different methods:
    cout << "Using at(): " << d4.at(1) << endl;
    cout << "Using []: " << d4[1] << endl;
    cout << "Using front(): " << d4.front() << endl;
    cout << "Using back(): " << d4.back() << endl;

    /*
    Traversing Deques: All these methods work in O(n) time complexity
    1. Using for loop
    2. Using range-based for loop
    3. Using iterators
    4. Using for_each and lambda function
    5. Using reverse iterators
    */

    // Using for loop
    cout << "Using for loop: ";
    for(int i = 0; i < d4.size(); i++){
        cout << d4[i] << " ";
    }
    cout << endl;

    // Using range-based for loop
    cout << "Using range-based for loop: ";
    for(auto val : d4){
        cout << val << " ";
    }
    cout << endl;

    // Using iterators
    cout << "Using iterators: ";
    for(auto it = d4.begin(); it != d4.end(); it++){
        cout << *it << " ";
    }

    // Using for_each and lambda function
    cout << endl << "Using for_each and lambda function: ";
    for_each(d4.begin(), d4.end(), [](int val){
        cout << val << " ";
    });
    cout << endl;

    // Using reverse iterators
    cout << "Using reverse iterators: ";
    for(auto rit = d4.rbegin(); rit != d4.rend(); rit++){
        cout << *rit << " ";
    }
    cout << endl;

    /*
    Insertion Methods:
    1. push_back()       --- O(1)
    2. push_front()      --- O(1)
    3. insert()          --- O(n)
    4. emplace()         --- O(n)
    5. emplace_back()    --- O(1)
    6. emplace_front()   --- O(1)
    7. Insert multiple elements --- O(n)
    */

    // push_back()
    d4.push_back(4);
    cout << "After push_back, Deque 4: ";   
    for(auto val : d4){
        cout << val << " ";
    }
    cout << endl;

    // push_front()
    d4.push_front(0);
    cout << "After push_front, Deque 4: ";
    for(auto val : d4){
        cout << val << " ";
    }
    cout << endl;

    // insert()
    d4.insert(d4.begin() + 2, 15); // inserting 15 at index 2
    cout << "After insert, Deque 4: ";
    for(auto val : d4){
        cout << val << " ";
    }
    cout << endl;
    
    // emplace()
    d4.emplace(d4.begin() + 2, 18); // emplacing 18 at index 2
    cout << "After emplace, Deque 4: ";
    for(auto val : d4){
        cout << val << " ";
    }
    cout << endl;

    // emplace_back()
    d4.emplace_back(5);
    cout << "After emplace_back, Deque 4: ";
    for(auto val : d4){
        cout << val << " ";
    }
    cout << endl;

    // emplace_front()
    d4.emplace_front(-1);
    cout << "After emplace_front, Deque 4: ";
    for(auto val : d4){
        cout << val << " ";
    }
    cout << endl;

    // Insert multiple elements
    d4.insert(d4.end(), 3, 20); // inserting three 20s at the end
    cout << "After inserting multiple elements, Deque 4: ";
    for(auto val : d4){
        cout << val << " ";
    }
    cout << endl;

    /*
    Deletion Methods:
    1. pop_back()        --- O(1)
    2. pop_front()       --- O(1)
    3. erase()           --- O(n)
    4. clear()           --- O(n)
    */

    // pop_back()
    d4.pop_back();
    cout << "After pop_back, Deque 4: ";
    for(auto val : d4){
        cout << val << " ";
    }
    cout << endl;

    // pop_front()
    d4.pop_front();
    cout << "After pop_front, Deque 4: ";
    for(auto val : d4){
        cout << val << " ";
    }
    cout << endl;

    // erase()
    d4.erase(d4.begin() + 2); // erasing element at index
    cout << "After erase, Deque 4: ";
    for(auto val : d4){
        cout << val << " ";
    }
    cout << endl;

    // clear()
    d4.clear();
    cout << "After clear, Deque 4 size: " << d4.size() << endl;

    /*
    Updating Elements:
    1. Using index     --- O(1)
    2. Using at()      --- O(1)
    3. Using iterators --- O(1)
    */

    // Re-initialize Deque 4
    d4 = {1, 2, 3, 4, 5};
    // Using index
    d4[2] = 10; // updating index 2 to 10
    cout << "After updating using index, Deque 4: ";
    for(auto val : d4){
        cout << val << " ";
    }
    cout << endl;

    // Using at()
    d4.at(3) = 20; // updating index 3 to 20
    cout << "After updating using at(), Deque 4: ";
    for(auto val : d4){
        cout << val << " ";
    }
    cout << endl;

    // Using iterators
    auto it = d4.begin() + 4;
    *it = 30; // updating index 4 to 30
    cout << "After updating using iterator, Deque 4: ";
    for(auto val : d4){
        cout << val << " ";
    }
    cout << endl;

    /*
    Sorting Deques:
    1. Using sort() from <algorithm>   --- O(n log n)
    2. Using sort(.begin(), .end(), greater<int>()) for descending order  --- O(n log n)
    */

    deque<int>d91 = {5, 2, 8, 1, 4};
    // Using sort()
    sort(d91.begin(), d91.end());
    cout << "After sorting, Deque 91: ";
    for(auto val : d91){
        cout << val << " ";
    }
    cout << endl;

    // Using sort() for descending order
    sort(d91.begin(), d91.end(), greater<int>());
    cout << "After sorting in descending order, Deque 91: ";
    for(auto val : d91){
        cout << val << " ";
    }
    cout << endl;

    /*
    Searching Deques:
    1. Using find() from <algorithm>          --- O(n)
    2. Using binary_search() from <algorithm>  --- O(log n) (only for sorted deques)
    3. Using lower_bound() and upper_bound() from <algorithm> (only for sorted deques) --- O(log n)
    */

    // Using find()
    auto f_it = find(d91.begin(), d91.end(), 4);
    if(f_it != d91.end()){
        cout << "Element 4 found at index: " << distance(d91.begin(), f_it) << endl;
    } else {
        cout << "Element 4 not found" << endl;
    }
    
    // Using binary_search()
    sort(d91.begin(), d91.end()); // ensure deque is sorted
    bool found = binary_search(d91.begin(), d91.end(), 5);
    cout << "Element 5 " << (found ? "found" : "not found") << " using binary_search" << endl;

    // Using lower_bound() and upper_bound()
    auto lb = lower_bound(d91.begin(), d91.end(), 2);
    cout << "Lower bound of 2 at index: " << distance(d91.begin(), lb) << endl;
    auto ub = upper_bound(d91.begin(), d91.end(), 2);
    cout << "Upper bound of 2 at index: " << distance(d91.begin(), ub) << endl;
    
    /*
    Remove - Erase Idiom:
    1. remove() from <algorithm> shifts elements to be removed to the end and returns new logical end --- O(n)
    2. erase() actually removes the elements from the container --- O(n)
    */

    // Using remove() followed by erase()
    deque<int> d92 = {1, 2, 2, 3, 4, 2, 5};
    d92.erase(remove(d92.begin(), d92.end(), 2), d92.end());
    cout << "After remove-erase idiom to remove 2s, Deque92: ";
    for(auto val : d92){
        cout << val << " ";
    }
    cout << endl;

    // Using unique() followed by erase()
    deque<int> d93 = {1, 2, 2, 3, 4, 4, 5};
    sort(d93.begin(), d93.end()); // unique works on sorted containers
    d93.erase(unique(d93.begin(), d93.end()), d93.end());
    cout << "After unique-erase idiom to remove duplicates, Deque93: ";
    for(auto val : d93){
        cout << val << " ";
    }
    cout << endl;

    /*
    Swapping Deques:
    1. Using swap() method      --- O(1)
    */

    // Using swap()
    deque<int> dA = {1, 2, 3};
    deque<int> dB = {4, 5, 6, 7};
    dA.swap(dB);
    cout << "After swapping, Deque A: ";
    for(auto val : dA){
        cout << val << " ";
    }
    cout << endl;
    cout << "After swapping, Deque B: ";
    for(auto val : dB){
        cout << val << " ";
    }
    cout << endl;

    return 0;
    
}