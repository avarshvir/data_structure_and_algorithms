// Insertion & Accessing
#include<iostream>
#include<unordered_set>

using namespace std;

int main(){
    
    unordered_set<int> us = {1, 2, 3, 4, 5};

    // Insertion
    us.insert(1);
    us.insert(2);
    us.insert(0);
    us.insert(1);

    for(auto &x : us){
        cout << x << " ";
    }

    // Accessing elements
    /*
    We can’t access elements of an unordered set by index like in an array or vector. 
    We have to increment or decrement iterator obtained from begin() or end() methods 
    respectively to access the element by position. 
    This can also be done with the help of next() or advance() function.
    */

    cout << endl;
    // Accessing the third 3rd element
    auto it = next(us.begin(), 2);
    cout << *it;
    return 0;
    

}