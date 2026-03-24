#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> us;
    int choice, x;

    do {
        cout << "\n1 Insert\n2 Delete\n3 Display\n4 Search\n0 Exit\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cin >> x;
                us.insert(x);
                break;

            case 2:
                cin >> x;
                us.erase(x);
                break;

            case 3:
                for(int v : us)
                    cout << v << " ";
                break;

            case 4:
                cin >> x;
                if(us.find(x) != us.end())
                    cout << "Found\n";
                else
                    cout << "Not Found\n";
                break;
        }

    } while(choice != 0);
}