#include<iostream>
#include<map>
using namespace std;
int main(){

    // creating an empty map
    map<int, string>m1; 

    // inserting values in the map
    m1[1] = "One";
    m1[2] = "Two";
    m1[3] = "Three";

    // printing the map
    cout << "Map m1: " << endl;
    for (const auto& pair : m1) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // creating a map with string key
    map<string, int>m2;
    m2["One"] = 1;
    m2["Two"] = 2;  
    m2["Three"] = 3;

    for(auto pair : m2){
        cout << pair.first << ": " << pair.second << endl;
    }


    // creating map with key and values
    map<int, string> m3 = {{1, "One"}, {2, "Two"}, {3, "Three"}};

    for(auto &pair :m3){
        cout << pair.first << ": " << pair.second << endl;
    }



}