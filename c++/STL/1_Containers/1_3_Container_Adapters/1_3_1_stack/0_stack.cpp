#include<iostream>
#include<stack>

using namespace std;

int main(){
    
    stack<int> st0;
    
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    stack<int> st2;

    // Insertion
    st2.push(10);
    st2.push(20);
    st2.push(30);
    
    // check empty or not
    if(st0.empty()){
        cout << "stack st0 is empty" << endl;
    }

    // Accessing Top element
    cout << "Top of st is: " << st.top() << endl;

    // Checking Size of stack
    cout << "Size of st2 is: " << st2.size() << endl;

    // Deleting Element
    st.pop();
    cout << "Top of st is now: " << st.top() << endl;
    cout << "Size of st is now: " << st.size() << endl; 

    // Deleting All Element
    st.pop();
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    //cout << st.top();
    cout << st.size() << endl;

    // Pseudo Traversal

    stack<int> temp(st2);

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }

    return 0;

}