// Traversing and Deleting
#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    unordered_set<int> us = {1, 2, 3, 4, 5};
    
    // Traversing
    for (auto it = us.begin(); it != us.end(); it++)
        cout << *it << " ";
    cout << endl;

    // Delete
    us.erase(5);
    // Delete element by position
    us.erase(us.begin());

    //auto it = next(us.begin(), 2);

    for (auto x : us)
        cout << x << " ";

    return 0;
}