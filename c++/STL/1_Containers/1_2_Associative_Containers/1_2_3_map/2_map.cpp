#include<iostream>
#include<map>

using namespace std;
int main(){

    map<int, string> m = {{2, "C++"}, {1, "C"}, {3, "Python"}};

    // accessing values using keys
    cout << m[1] << endl; // Output: C
    cout << m[2] << endl; // Output: C++
    cout << m.at(3) << endl; // Output: Python

    return 0;


}