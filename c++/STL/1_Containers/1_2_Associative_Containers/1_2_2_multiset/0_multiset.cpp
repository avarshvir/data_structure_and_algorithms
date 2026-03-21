#include<iostream>
#include<set>
using namespace std;
int main(){
    multiset<int> ms = {1, 2, 3, 4, 1, 3, 6};

    for(auto i : ms){
        cout << i << " ";
    }

    cout << endl;

    ms.insert(2);
    ms.insert(10);

    for(auto it = ms.begin(); it != ms.end(); it++){
        cout << *it << " ";
    }

    cout << endl;

    //Access first element
    auto it = ms.begin();
    cout << "First element: " << *it << endl;

    // Access third element
    auto it2 = next(it, 2);
    cout << *it2;


}