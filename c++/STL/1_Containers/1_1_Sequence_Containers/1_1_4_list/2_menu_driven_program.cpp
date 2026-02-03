#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    list<int> l;
    int choice, x;

    do {
        cout << "\n1.Push Front\n2.Push Back\n3.Pop Front\n4.Pop Back";
        cout << "\n5.Display\n6.Sort\n7.Search\n8.Remove Value\n0.Exit\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cin >> x;
                l.push_front(x);
                break;

            case 2:
                cin >> x;
                l.push_back(x);
                break;

            case 3:
                if(!l.empty()) l.pop_front();
                break;

            case 4:
                if(!l.empty()) l.pop_back();
                break;

            case 5:
                for(int i : l) cout << i << " ";
                break;

            case 6:
                l.sort();
                break;

            case 7:
                cin >> x;
                if(find(l.begin(), l.end(), x) != l.end())
                    cout << "Found";
                else
                    cout << "Not Found";
                break;

            case 8:
                cin >> x;
                l.remove(x);
                break;
        }
    } while(choice != 0);
}
