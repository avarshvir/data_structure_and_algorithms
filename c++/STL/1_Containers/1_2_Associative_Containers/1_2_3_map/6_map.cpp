#include<iostream>
#include<map>

using namespace std;
int main(){

    map<int, string> m = {{2, "c++"}, {3, "python"}, {1, "c"}, {4, "dbms"}, {0, "design"}};

    // Deleting by key
    m.erase(4); // erasing element with key 4  O(log n)
    
    // Deleting by iterator
    m.erase(m.begin()); // erasing element at the beginning (key 0)  O(1) for single element, O(n) for range

    for( auto &i : m){
        cout << i.first << " " << i.second << endl;
    }

    return 0;

}