#include<iostream>
#include<forward_list>
#include<algorithm>
using namespace std;

int main(){

    /*
    Creation and Initialization of forward_list:
    1. Default Declaration
    2. With Size
    3. With Size and Value
    4. Initializer List
    5. Copying one forward_list to another
    6. Move forward_list
    7. Note: forward_list does NOT support size() method
    */

    // Default Declaration
    forward_list<int> fl1;                     // zero length forward_list                      O(1)
    // With Size
    forward_list<int> fl2(5);                  // 5 length forward_list with default values        O(n)
    // With Size and Value
    forward_list<int> fl3(5, 10);              // 5 length forward_list with all values as 10      O(n)
    // Initializer List
    forward_list<int> fl4 = {1, 2, 3};         // forward_list with values 1,2,3                     O(n)
    // Copying one forward_list to another
    forward_list<int> fl5 = fl4;               // copying fl4 to fl5                                 O(n)
    forward_list<int> fl5a = fl4;              // copying fl4 to fl5a                                O(n)
    // Move forward_list
    forward_list<int> fl6 = move(fl5a);        // moving fl5a to fl6                                 O(1)
    // Print all forward_lists size (manually counting as size() is not available)
    auto count_size = [](forward_list<int>& fl){
        int count = 0;
        for(auto it = fl.begin(); it != fl.end(); ++it){
            count++;
        }
        return count;
    };
    cout << "Forward List 1: " << count_size(fl1) << endl;
    cout << "Forward List 2: " << count_size(fl2) << endl;
    cout << "Forward List 3: " << count_size(fl3) << endl;
    cout << "Forward List 4: " << count_size(fl4) << endl;
    cout << "Forward List 5: " << count_size(fl5) << endl;
    cout << "Forward List 6: " << count_size(fl6) << endl;

    /*
    Element Access Methods: (Limited compared to vector, deque, and list)
    1. front()       --- O(1)
    2. No back(), [] operator, or at() available for forward_list
    */

    // front()
    if(!fl4.empty()){
        cout << "Front element of Forward List 4: " << fl4.front() << endl;
    }

    /*
    1. Traversing forward_list: All these methods work in O(n) time complexity
    1. Using range-based for loop
    2. Using iterators (most common method for forward_list)
    3. Using for_each and lambda function
    Note: reverse iterators and traditional for loop are NOT possible as forward_list is singly linked
    and does not support indexing and in one way only.
    */

    // Using range-based for loop
    cout << "Using range-based for loop: ";
    for(auto val : fl4){
        cout << val << " ";
    }
    cout << endl;

    // Using iterators
    cout << "Using iterators: ";
    for(auto it = fl4.begin(); it != fl4.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    // Using for_each and lambda function
    cout << "Using for_each and lambda function: ";
    for_each(fl4.begin(), fl4.end(), [](int val){
        cout << val << " ";
    });
    cout << endl;

    /*
    Insertion Methods:
    1. push_front()      --- O(1)
    2. insert_after()    --- O(1) for single element, O(n) for range
    3. emplace_after()   --- O(1) for single element, O
    */

    // push_front()
    fl4.push_front(0);
    cout << "After push_front, Forward List 4: ";
    for(auto val : fl4){
        cout << val << " ";
    }
    cout << endl;

    // insert_after()
    auto it = fl4.begin();
    advance(it, 2); // move iterator to index 2
    fl4.insert_after(it, 15); // inserting 15 after index 2
    cout << "After insert_after, Forward List 4: ";
    for(auto val : fl4){
        cout << val << " ";
    }
    cout << endl;

    // emplace_after()
    it = fl4.begin();
    advance(it, 2); // move iterator to index 2
    fl4.emplace_after(it, 18); // emplacing 18 after index 2
    cout << "After emplace_after, Forward List 4: ";
    for(auto val : fl4){
        cout << val << " ";
    }
    cout << endl;

    /*
    Deletion Methods:
    1. pop_front()       --- O(1)
    2. erase_after()     --- O(1) for single element, O(n) for range
    3. remove()          --- O(n)
    4. clear()           --- O(n)
    5. remove_if()       --- O(n)
    */

    // pop_front()
    fl4.pop_front();
    cout << "After pop_front, Forward List 4: ";
    for(auto val : fl4){
        cout << val << " ";
    }
    cout << endl;
    
    // erase_after()
    it = fl4.begin();
    advance(it, 2); // move iterator to index 2
    fl4.erase_after(it); // erasing element after index 2
    cout << "After erase_after, Forward List 4: ";
    for(auto val : fl4){
        cout << val << " ";
    }
    cout << endl;

    // clear()
    fl4.clear();
    cout << "After clear, Forward List 4 size: " << count_size(fl4) << endl;
    
    // Re-initialize Forward List 4
    fl4 = {1, 2, 3, 4, 5, 2, 6};
    
    // remove()
    fl4.remove(2); // removing all occurrences of 2
    cout << "After remove, Forward List 4: ";
    for(auto val : fl4){
        cout << val << " ";
    }
    cout << endl;
    
    // remove_if()
    fl4.remove_if([](int val){ return val % 2 == 0; }); // removing all even numbers
    cout << "After remove_if, Forward List 4: ";
    for(auto val : fl4){
        cout << val << " ";
    }
    cout << endl;

    /*
    Sorting and Reversing:
    - forward_list does NOT have sort() method like list
    1. .sort() from <algorithm> uses merge sort  --- O(n log n)
    2. reverse()                 --- O(n)
    */

    // Re-initialize Forward List 4
    fl4 = {4, 2, 5, 1, 3};

    // sort() from <algorithm> using merge sort
    fl4.sort();
    cout << "After sort, Forward List 4: ";
    for(auto val : fl4){
        cout << val << " ";
    }
    cout << endl;

    // reverse()  Pointer reversal, not data movement. O(n)
    fl4.reverse();
    cout << "After reverse, Forward List 4: ";
    for(auto val : fl4){
        cout << val << " ";
    }
    cout << endl;

    /*
    Splice:
    1. splice_after()  --- O(1) for single element, O(n) for range
    */

    // Re-initialize Forward Lists
    forward_list<int> fl7 = {100, 200, 300};
    fl4.splice_after(fl4.before_begin(), fl7); // splicing entire fl7 at the beginning of fl4
    cout << "After splice_after, Forward List 4: ";
    for(auto val : fl4){
        cout << val << " ";
    }
    // before_begin() is unique to forward_list.
    cout << endl;
    cout << "After splice_after, Forward List 7 size: " << count_size(fl7) << endl;
   
    return 0;

}