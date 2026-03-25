#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<int, string> um = 
    {
        {1, "C"}, {2, "C++"}, {3, "Python"}, {1, "Ass"}
    };

    for(auto &x : um){
        cout << x.first << " -> " << x.second << endl;
    }

}