#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, string> um;
    int choice, key;
    string value;

    do {
        cout << "\n1 Insert\n2 Delete\n3 Display\n4 Search\n0 Exit\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cin >> key >> value;
                um[key] = value;
                break;

            case 2:
                cin >> key;
                um.erase(key);
                break;

            case 3:
                for(auto p : um)
                    cout << p.first << " " << p.second << endl;
                break;

            case 4:
                cin >> key;
                if(um.find(key) != um.end())
                    cout << "Found\n";
                else
                    cout << "Not Found\n";
                break;
        }

    } while(choice != 0);
}