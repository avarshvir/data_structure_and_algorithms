/*#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    unordered_set<int> us = {1, 2, 3, 4, 5};

    auto it = us.find(4);
    if (it != us.end())
        cout << *it;
    else
        cout << "Element not Found!";
    return 0;
}*/

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> us = {1, 2, 3, 4, 5};

    auto it = us.find(5);
    if (it != us.end()) {
        int pos = distance(us.begin(), it);
        cout << "Found at pseudo-position: " << pos;
    } else {
        cout << "Element not Found!";
    }

    cout << endl;

    for(auto &x : us){
        cout << x << " ";
    }

    return 0;
}