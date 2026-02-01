#include<bits/stdc++.h>
using namespace std;

int main(){

    /*
    Vector Declaration Methods:
    1. Default Declaration 
    2. With Size
    3. With Size and Value
    4. Initializer List
    5. Copying one vector to another
    6. Move Vector
    */
    // declaration
    vector<int> v1;                 // zero length vector                               O(1)
    // With size
    vector<int> v2(5);             // 5 length vector with default values               O(n)
    // With size and value     
    vector<int> v3(5, 10);         // 5 length vector with all values as 10             O(n)
    // Initializer list
    vector<int> v4 = {1, 2, 3};    // vector with values 1,2,3                          O(n)
    // Copying one vector to another
    vector<int> v5 = v4;           // copying v4 to v5                                  O(n)
    vector<int> v5a = v4;
    // Move Vector
    vector<int> v6 = move(v5a);     // moving v5 to v6                                   O(1)

    // Print all vectors size and capacity
    cout << "Vector 1: " << v1.size() << " " << v1.capacity() << endl;
    cout << "Vector 2: " << v2.size() << " " << v2.capacity() << endl;
    cout << "Vector 3: " << v3.size() << " " << v3.capacity() << endl;
    cout << "Vector 4: " << v4.size() << " " << v4.capacity() << endl;
    cout << "Vector 5: " << v5.size() << " " << v5.capacity() << endl;
    cout << "Vector 6: " << v6.size() << " " << v6.capacity() << endl;

    // Print all vectors elements
    cout << "Vector 3 elements: ";
    for(int i = 0; i < v3.size(); i++){
        cout << v3[i] << " ";
    }
    cout << endl;

    cout << "Vector 4 elements: ";
    for(int i = 0; i < v4.size(); i++){
        cout << v4[i] << " ";
    }
    cout << endl;

    cout << "Vector 5 elements: ";
    for(int i = 0; i < v5.size(); i++){
        cout << v5[i] << " ";
    }
    cout << endl;

    cout << "Vector 5a elements (after move, should be empty): ";
    for(int i = 0; i < v5a.size(); i++){
        cout << v5a[i] << " ";
    }
    cout << endl;

    cout << "Vector 6 elements: ";
    for(int i = 0; i < v6.size(); i++){
        cout << v6[i] << " ";
    }
    cout << endl;

    /*
    Vector Accessing Methods: All these methods work in O(1) time complexity
    1. at()
    2. []
    3. front()
    4. back()
    */

    cout << "Accessing Vector 4 elements using different methods:" << endl;
    cout << "Using at(): " << v4.at(1) << endl;
    cout << "Using []: " << v4[1] << endl;
    cout << "Using front(): " << v4.front() << endl;
    cout << "Using back(): " << v4.back() << endl;

    /*
    Traversing Vectors: All these methods work in O(n) time complexity
    1. Using for loop
    2. Using range-based for loop
    3. Using iterators
    4. Using for_each and lambda function
    */

    cout << "Traversing Vector 4 using different methods:" << endl;
    // Using for loop
    cout << "Using for loop: ";
    for(int i = 0; i < v4.size(); i++){
        cout << v4[i] << " ";
    }
    cout << endl;

    // Using range-based for loop
    cout << "Using range-based for loop: ";
    for(auto val : v4){
        cout << val << " ";
    }
    cout << endl;

    // Using iterators
    cout << "Using iterators: ";
    for(auto it = v4.begin(); it != v4.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    // Using for_each and lambda function
    cout << "Using for_each and lambda function: ";
    for_each(v4.begin(), v4.end(), [](int val){
        cout << val << " ";
    });
    cout << endl;

    /*
    Insertion Methods:
    1. push_back()          --- O(1) amortized
    2. insert()             --- O(n)
    3. emplace_back()       --- O(1) amortized
    4. emplace()            --- O(n)
    5. Insert multiple elements --- O(n)
    6. Insert range         --- O(n)
    */

    vector<int> v7;
    // push_back()
    v7.push_back(10);
    v7.push_back(20);
    cout << "After push_back, Vector 7: ";
    for(auto val : v7){
        cout << val << " ";
    }
    cout << endl;

    // insert()
    v7.insert(v7.begin() + 1, 15); // inserting 15 at index 1
    cout << "After insert, Vector 7: ";
    for(auto val : v7){
        cout << val << " ";
    }
    cout << endl;

    // emplace_back()
    v7.emplace_back(25);
    cout << "After emplace_back, Vector 7: ";
    for(auto val : v7){
        cout << val << " ";
    }
    cout << endl;

    // emplace()
    v7.emplace(v7.begin() + 2, 18); // emplacing 18 at index 2
    cout << "After emplace, Vector 7: ";
    for(auto val : v7){
        cout << val << " ";
    }
    cout << endl;

    // Insert multiple elements
    v7.insert(v7.end(), 3, 30); // inserting three 30s at the end
    cout << "After inserting multiple elements, Vector 7: ";
    for(auto val : v7){
        cout << val << " ";
    }
    cout << endl;

    // Insert range
    vector<int> v8 = {40, 50, 60};
    v7.insert(v7.end(), v8.begin(), v8.end()); // inserting range at the end
    cout << "After inserting range, Vector 7: ";
    for(auto val : v7){
        cout << val << " ";
    }
    cout << endl;

    /*
    Deletion Methods:
    1. pop_back()           --- O(1)
    2. erase()              --- O(n)
    3. clear()              --- O(n)
    */

    // pop_back()
    v7.pop_back();
    cout << "After pop_back, Vector 7: ";
    for(auto val : v7){
        cout << val << " ";
    }
    cout << endl;

    // erase()
    v7.erase(v7.begin() + 2); // erasing element at index 2
    cout << "After erase, Vector 7: ";
    for(auto val : v7){
        cout << val << " ";
    }
    cout << endl;

    // clear()
    v7.clear();
    cout << "After clear, Vector 7 size: " << v7.size() << endl;

    /*
    Update/Modification Methods:
    1. Using index     --- O(1)
    2. Using iterators --- O(1)
    */

    vector<int> v9 = {1, 2, 3, 4, 5};
    // Using index
    v9[2] = 10; // updating index 2 to 10
    cout << "After updating using index, Vector 9: ";
    for(auto val : v9){
        cout << val << " ";
    }
    cout << endl;
    // Using iterators
    auto it = v9.begin() + 3;
    *it = 20; // updating index 3 to 20
    cout << "After updating using iterator, Vector 9: ";
    for(auto val : v9){
        cout << val << " ";
    }
    cout << endl;

    /*
    Sorting Vectors:
    1. Using sort() from <algorithm>   --- O(n log n)
    2. Using sort(.begin(), .end(), greater<int>()) for descending order  --- O(n log n)
    */
    vector<int> v10 = {5, 2, 8, 1, 4};
    sort(v10.begin(), v10.end());
    cout << "After sorting, Vector 10: ";
    for(auto val : v10){
        cout << val << " ";
    }
    cout << endl;

    sort(v10.begin(), v10.end(), greater<int>());
    cout << "After sorting in descending order, Vector 10: ";
    for(auto val : v10){
        cout << val << " ";
    }
    cout << endl;

    /*
    Searching Vectors:
    1. Using find() from <algorithm>  --- O(n) Linear Search
    2. Using binary_search() from <algorithm> (only for sorted vectors) --- O(log n) Binary Search
    3. Using lower_bound() and upper_bound() from <algorithm> (only for sorted vectors) --- O(log n)
    */
    vector<int> v11 = {1, 2, 2, 3, 4, 5};
    // Using find()
    auto f_it = find(v11.begin(), v11.end(), 3);
    if(f_it != v11.end()){
        cout << "Element 3 found at index: " << distance(v11.begin(), f_it) << endl;
    } else {
        cout << "Element 3 not found" << endl;
    }
    
    // Using binary_search()
    sort(v11.begin(), v11.end()); // ensure vector is sorted
    bool found = binary_search(v11.begin(), v11.end(), 4);
    cout << "Element 4 " << (found ? "found" : "not found") << " using binary_search" << endl;

    // Using lower_bound() and upper_bound()
    auto lb = lower_bound(v11.begin(), v11.end(), 2);
    auto ub = upper_bound(v11.begin(), v11.end(), 2);
    cout << "Lower bound of 2 at index: " << distance(v11.begin(), lb) << endl;

    /*
    Remove-Erase Idiom:
    1. Using remove() from <algorithm> followed by erase() to remove all occurrences of a value --- O(n)
    2. Using unique() from <algorithm> followed by erase() to remove duplicates from a sorted vector --- O(n)
    */

    vector<int> v12 = {1, 2, 2, 3, 4, 2, 5};
    // Using remove() followed by erase()
    //remove() doesn’t delete — it shifts elements.
    v12.erase(remove(v12.begin(), v12.end(), 2), v12.end());
    cout << "After removing all occurrences of 2, Vector 12: ";
    for(auto val : v12){
        cout << val << " ";
    }
    cout << endl;

    // Using unique() followed by erase()
    vector<int> v13 = {1, 2, 2, 3, 4, 4, 5};
    sort(v13.begin(), v13.end()); // ensure vector is sorted
    v13.erase(unique(v13.begin(), v13.end()), v13.end());
    cout << "After removing duplicates, Vector 13: ";
    for(auto val : v13){
        cout << val << " ";
    }
    cout << endl;

    /*
    Swap Vectors:
    1. Using swap() method to swap contents of two vectors --- O(1)
    */
    vector<int> v14 = {1, 2, 3};
    vector<int> v15 = {4, 5, 6};
    cout << "Before swap, Vector 14: ";
    for(auto val : v14){
        cout << val << " ";
    }
    cout << endl;
    cout << "Before swap, Vector 15: ";
    for(auto val : v15){
        cout << val << " ";
    }
    cout << endl;
    v14.swap(v15);
    cout << "After swap, Vector 14: ";
    for(auto val : v14){
        cout << val << " ";
    }
    cout << endl;
    cout << "After swap, Vector 15: ";
    for(auto val : v15){
        cout << val << " ";
    }
    cout << endl;


    return 0;
}