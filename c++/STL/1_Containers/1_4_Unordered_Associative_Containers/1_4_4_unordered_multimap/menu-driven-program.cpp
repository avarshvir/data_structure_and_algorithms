#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_multimap<int, string> umm;
    int choice, key;
    string value;

    do {
        cout << "\n1 Insert\n2 Delete\n3 Display\n4 Count\n0 Exit\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cin >> key >> value;
                umm.insert({key, value});
                break;

            case 2:
                cin >> key;
                umm.erase(key);
                break;

            case 3:
                for(auto p : umm)
                    cout << p.first << " " << p.second << endl;
                break;

            case 4:
                cin >> key;
                cout << umm.count(key);
                break;
        }

    } while(choice != 0);
}