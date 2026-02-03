#include <iostream>
#include <forward_list>
#include <algorithm>
using namespace std;

int main()
{
    forward_list<int> fl;
    int choice, x;

    do {
        cout << "\n1.Push Front\n2.Pop Front\n3.Insert After";
        cout << "\n4.Delete After\n5.Display\n6.Sort\n7.Search\n0.Exit\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cin >> x;
                fl.push_front(x);
                break;

            case 2:
                if(!fl.empty()) fl.pop_front();
                break;

            case 3:
                cin >> x;
                fl.insert_after(fl.before_begin(), x);
                break;

            case 4:
                fl.erase_after(fl.before_begin());
                break;

            case 5:
                for(int i : fl) cout << i << " ";
                break;

            case 6:
                fl.sort();
                break;

            case 7:
                cin >> x;
                if(find(fl.begin(), fl.end(), x) != fl.end())
                    cout << "Found";
                else
                    cout << "Not Found";
                break;
        }
    } while(choice != 0);
}
