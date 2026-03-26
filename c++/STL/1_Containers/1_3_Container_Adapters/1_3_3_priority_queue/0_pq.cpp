#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int main(){
    
    // Max Heap by default
    priority_queue<int> pq;  // Largest Element at top

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> pq2;  // Smallest Element at top
    
    // From container
    vector<int> v = {10, 20, 30};
    priority_queue<int> pq3(v.begin(), v.end());

    /*
    Core Operation
    1. push() : Insert                         --- O(log n)
    2. pop() : Remove/Delete                   --- O(log n)
    3. top() : Access priority element         --- O(1)
    4. size()
    5. empty()
    */

    // push()
    pq.push(10);
    pq.push(20);
    pq.push(30);

    cout << pq.top() << endl;
    cout << pq.size() << endl;
    cout << pq2.empty() << endl;
    cout << "pq2 is Empty" << endl;

    pq2.push(10);
    pq2.push(20);
    pq2.push(30);

    cout << pq2.top() << endl;
    cout << pq2.size() << endl;
    cout << pq2.empty() << endl;
    cout << "pq2 is not Empty" << endl;

    
    // Traversing not allowed, means no direct iteration allowed
    priority_queue<int> temp = pq;
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }

    return 0;

}