#include<iostream>
#include<queue>
#include<list>

using namespace std;

int main(){
    /*
    Basic Declaration
    */

    queue<int> q;  // O(1)

    // Using custom underlying container
    queue<int, deque<int>> q1;   // default
    queue<int, list<int>> q2;   

    /*
    Core Operations
    1. push(): Insert element at back (rear)   --- O(1)
    2. pop(): Remove element from front        --- O(1)
    3. front(): Access first element           --- O(1)
    4. back(): Access last element             --- O(1)
    */

    // Push : Insert
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Front: " << q.front() << ", " << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;

    // Pop : Remove
    q.pop();
    cout << "Front: " << q.front() << ", " << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;

    // Access Elements : Front and Back
    if(!q.empty())
        cout << "Front: " << q.front() << ", " << "Back: " << q.back() << endl;
    
    
    /*
    Size:
    1. size()
    2. empty()
    */

    // size
    cout << "Size of q: " << q.size() << endl; 
    // empty
    queue<int> empty_q;
    if(empty_q.empty()){
        cout << "Queue is Empty" << endl;
    }

    /*
    Traversing
    Psedo Traversing
    */
    queue<int> temp = q;
    while(!temp.empty()){
        cout << temp.front() << " ";
        temp.pop();
    }

    /*
    Swapping
    O(1)
    */
    queue<int> q3, q4;
    q3.push(10);
    q4.push(20);
    cout << "Before Swap: " << endl;
    cout << "Q3: " << q3.front() << endl;
    cout << "Q4: " << q4.front() << endl;
    cout << "After Swap: " << endl;
    q3.swap(q4); 
    cout << "Q3: " << q3.front() << endl;
    cout << "Q4: " << q4.front() << endl;
    
    return 0;

}