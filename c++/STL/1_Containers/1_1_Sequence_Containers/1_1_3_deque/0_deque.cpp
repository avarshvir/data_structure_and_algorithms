#include<iostream>
#include<deque>
using namespace std;
int main()
{
    deque<int> d;
    cout << d.size() << endl;

    d.push_back(10);
    d.push_back(20);
    d.push_back(30);

    cout << d.size() << endl;

    for(int i : d)
        cout << i << " "; 

    cout << endl;  

    cout << d[1] << endl;

}