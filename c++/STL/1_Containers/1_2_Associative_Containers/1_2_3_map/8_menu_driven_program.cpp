#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> m;
    int choice, key;
    string value;

    do {
        cout << "\n1 Insert\n2 Delete\n3 Display\n4 Search\n0 Exit\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cin >> key >> value;
                m[key] = value;
                break;

            case 2:
                cin >> key;
                m.erase(key);
                break;

            case 3:
                for(auto p : m)
                    cout << p.first << " " << p.second << endl;
                break;

            case 4:
                cin >> key;
                if(m.find(key) != m.end())
                    cout << "Found\n";
                else
                    cout << "Not Found\n";
                break;
        }

    } while(choice != 0);
}