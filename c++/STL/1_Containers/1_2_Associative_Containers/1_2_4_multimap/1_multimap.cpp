#include<iostream>
#include<map>

using namespace std;

int main(){

    multimap<int, string> mm = {
        {1, "C++"}, {0, "C"}, {2, "Python"}
    };

    mm.insert({0, "Assembly"});
    mm.insert({3, "Java"});
    
    for(auto &x : mm){
        cout << x.first << " -> " << x.second << endl;
    }

}