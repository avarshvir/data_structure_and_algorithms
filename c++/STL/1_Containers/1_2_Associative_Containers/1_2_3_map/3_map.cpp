#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int, string> m {{1, "One"}, {2, "Two"}, {3, "Three"}};

    m[1] = "Ones";
    m.at(2) = "Twos";

    for(auto &x : m){
        cout << x.first << " " << x.second << endl;
    }

    return 0;

}