#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
cout << v.size() << " " << v.capacity() << endl;

v.push_back(10);
v.push_back(20);
v.push_back(30);

cout << v.size() << " " << v.capacity() << endl;

}