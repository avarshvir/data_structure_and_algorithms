#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m = {{2, "For"}, {3, "Geeks"}};

    // Inserting a key value pair
    m.insert({1, "Geeks"});    // inserting a key value pair using insert() method it will not overwrite the value if the key already exists
    
    // inserting a key value pair using operator[] it will overwrite the value if the key already exists
    m[4] = "Geeks4";

    for (auto &x: m)
        cout << x.first << " " << x.second
        << endl;
    return 0;
}