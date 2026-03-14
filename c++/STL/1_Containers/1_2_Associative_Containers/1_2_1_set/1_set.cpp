#include<iostream>
#include<set>
using namespace std;

int main(){
    
    // Initialize set with values
    set<int> s = {2, 3};

    // Inserting an element
    s.insert(1);

    // Traversing the set
    for (auto x : s)
        cout << x << endl;

    // Accessing elements using find()
    auto it = s.find(1);
    if (it != s.end())
        cout << "Element found: " << *it << endl;

    // Accessing elements using count()
    if (s.count(2))
        cout << "2 exists in the set" << endl;

    // Accessing all elements by traversal
    cout << "All elements: ";
    for (auto x : s)
        cout << x << " ";
    cout << endl;

    s.insert(4);

    // Deleting by value
    s.erase(2);

    // Deleting by iterator
    s.erase(s.begin());

    // Traversing the set
    for (auto i : s)
        cout << i << " ";
    cout << endl;

}