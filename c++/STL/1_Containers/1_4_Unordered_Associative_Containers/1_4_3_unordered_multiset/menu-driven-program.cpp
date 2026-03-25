#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_multiset<int> ums;
    int choice, x;

    do {
        cout << "\n1 Insert\n2 Delete\n3 Display\n4 Count\n0 Exit\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cin >> x;
                ums.insert(x);
                break;

            case 2:
                cin >> x;
                ums.erase(x);
                break;

            case 3:
                for(int v : ums)
                    cout << v << " ";
                break;

            case 4:
                cin >> x;
                cout << ums.count(x);
                break;
        }

    } while(choice != 0);
}