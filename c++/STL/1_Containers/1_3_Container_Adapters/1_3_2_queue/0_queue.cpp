#include<iostream>
#include<queue>

using namespace std;
int main(){
    
    // queue creation
    queue<int> q;
    queue<int> q2;

    // pushing elements enqueue
    q.push(10);
    q.push(5);
    q.push(2);

    q2.push(10);
    q2.push(5);
    q2.push(2);

    // accessing front and back elements
    cout << "Front Element: " << q.front() << endl;
    cout << "Back Element: " << q.back() << endl;

    // dequeue Deleting/Removing an element from the front
    q.pop();
    
    cout << "Front Element: " << q.front() << endl;
    cout << "Back Element: " << q.back() << endl;


    // Deleting All Element
    q2.pop();
    while(!q2.empty()){
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;

    // checking is empty??
    queue<int> q3;
    if (q3.empty()){
        cout << "Queue is empty " << endl;
    }
    q3.push(100);
    q3.push(100);
    q3.push(100);
    if (!q3.empty()){
        cout << "Queue is not empty. Front element: " << q3.front() << endl;
    }

    // Size
    cout << "Size of queue: " << q.size() << endl;
    q.pop();
    cout << "Size of queue: " << q.size() << endl;
    
    return 0;

}