#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    int choice, x;

    do {
        cout << "\n1 Push\n2 Pop\n3 Front\n4 Back\n5 Size\n6 Display\n0 Exit\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cin >> x;
                q.push(x);
                break;

            case 2:
                if(!q.empty()) q.pop();
                else cout << "Queue Empty\n";
                break;

            case 3:
                if(!q.empty()) cout << q.front();
                else cout << "Queue Empty\n";
                break;

            case 4:
                if(!q.empty()) cout << q.back();
                else cout << "Queue Empty\n";
                break;

            case 5:
                cout << q.size();
                break;

            case 6:
            {
                queue<int> temp = q;
                while(!temp.empty())
                {
                    cout << temp.front() << " ";
                    temp.pop();
                }
                break;
            }
        }

    } while(choice != 0);
}