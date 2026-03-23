#include <iostream>
#include <map>
using namespace std;

int main()
{
    multimap<int, string> mm;
    int choice, key;
    string value;

    do {
        cout << "\n1 Insert\n2 Delete\n3 Display\n4 Search\n0 Exit\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cin >> key >> value;
                mm.insert({key, value});
                break;

            case 2:
                cin >> key;
                mm.erase(key);
                break;

            case 3:
                for(auto p : mm)
                    cout << p.first << " " << p.second << endl;
                break;

            case 4:
                cin >> key;
                if(mm.find(key) != mm.end())
                    cout << "Found\n";
                else
                    cout << "Not Found\n";
                break;
        }

    } while(choice != 0);
}