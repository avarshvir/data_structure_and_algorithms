#include<iostream>
#include<map>

using namespace std;
int main(){

    // Creating an empty multimap
    multimap<int, string> mm1; 

    // multimap with values
    multimap<int, string> mm2;
    mm2 = {{1, "C++"}, {0, "Assembly"}, {0, "C"}, {2, "Python"}, {3, "Java"}};

    for(auto i : mm2){
        cout << i.first << " " << i.second << endl;
    }

    return 0;

}