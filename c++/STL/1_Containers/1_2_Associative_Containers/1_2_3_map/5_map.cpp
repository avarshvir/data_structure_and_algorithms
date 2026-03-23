#include<iostream>
#include<map>

using namespace std;

int main(){
    map<int, string> m = {
        {1, "C"}, {2, "C++"}, {3, "Python"}
    };

    //  traversing the map using range-based for loop
    for(auto &x : m){
        cout << x.first << " " << x.second << endl;
    }

    // traversing the map using iterators
    cout << "Using iterators: " << endl;
    for(auto it = m.begin(); it != m.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }

    // using for loop but this is not recommended as it may lead to out of range error if the keys are not continuous
    cout << "Using for loop: " << endl;
    for(int i = 1; i <= m.size(); ++i){
        cout << i << " " << m[i] << endl;
    }

    return 0;
}