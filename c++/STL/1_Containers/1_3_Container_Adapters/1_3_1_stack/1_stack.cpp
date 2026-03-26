#include<iostream>
#include<stack>
#include<vector>
#include<list>
#include<deque>

using namespace std;

int main(){
    // Basic Declaration
    stack<int> s;                      // O(1)

    // Using different underlying containers
    stack<int, vector<int>> s1;
    stack<int, deque<int>> s2;        // default
    stack<int, list<int>> s3;

    /*
    Core Operations
    1. push  --- O(1)
    2. pop   --- O(1)
    3. top   --- O(1)
    */

    // push
    s.push(10);
    s.push(20);
    s.push(30);
    s2.push(20);
    s2.push(20);
    s2.push(20);
    
    // top
    cout << s.top() << endl;
    // pop
    s.pop();
    // top
    cout << s.top() << endl;

    /*
    Size Operations
    1. size    --- O(1)
    2. empty   --- O(1)
    */

    // size
    cout << "Size of stack s: "<< s.size() << endl;
    cout << "Size of stack s1: "<< s1.size() << endl;
    cout << "Size of stack s2: "<< s2.size() << endl;
    
    
    // empty
    if(s.empty()){
        cout << "stack s is empty" << endl;
    }

    if(s1.empty()){
        cout << "stack s1 is empty" << endl;
    }

    // Clear all element of s2 --- O(n)
    while (!s2.empty()) {
    s2.pop();
    }
    cout << "S2 is now empty" << endl;

    /*
    Traversing
    Psedo Traversing
    */
   stack<int> temp = s;

    while(!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }

    /*
    Swaping Stack  --- O(1)
    */
   stack<int> s5, s6;

    s5.push(10);
    s6.push(20);
    cout << "Before Swap: " << endl;
    cout << "s5: " << s5.top() << endl;
    cout << "s6: " << s6.top() << endl;
    // swap 
    s5.swap(s6);
    cout << "After Swap: " << endl;
    cout << "s5: " << s5.top() << endl;
    cout << "s6: " << s6.top() << endl;

    /*
    push → push_back()
    pop  → pop_back()
    top  → back()
    */
    
    /*
    Space Complexity: O(n)
    */


}