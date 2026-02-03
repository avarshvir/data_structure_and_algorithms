#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    deque<int> dq;
    int choice, x;

    do {
        cout << "\n1.Push Front\n2.Push Back\n3.Pop Front\n4.Pop Back";
        cout << "\n5.Display\n6.Sort\n7.Search\n0.Exit\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cin >> x;
                dq.push_front(x);
                break;

            case 2:
                cin >> x;
                dq.push_back(x);
                break;

            case 3:
                if(!dq.empty()) dq.pop_front();
                break;

            case 4:
                if(!dq.empty()) dq.pop_back();
                break;

            case 5:
                for(int i : dq) cout << i << " ";
                break;

            case 6:
                sort(dq.begin(), dq.end());
                break;

            case 7:
                cin >> x;
                if(find(dq.begin(), dq.end(), x) != dq.end())
                    cout << "Found";
                else
                    cout << "Not Found";
                break;
        }
    } while(choice != 0);
}
