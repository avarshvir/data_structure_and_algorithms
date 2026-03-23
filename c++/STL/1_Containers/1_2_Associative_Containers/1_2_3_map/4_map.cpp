#include<iostream>
#include<map>

using namespace std;

int main(){
    map<int, string> m = {
        {1, "C"}, {2, "C++"}, {3, "Python"}
    };

    //finding the element with key 2
    auto it = m.find(2); // finding element with key 2  O(log n)
    if (it != m.end()) {
        cout << "Element found: " << it->first << " => " << it->second << endl;
    } else {
        cout << "Key not found" << endl;
    }

    return 0;

}