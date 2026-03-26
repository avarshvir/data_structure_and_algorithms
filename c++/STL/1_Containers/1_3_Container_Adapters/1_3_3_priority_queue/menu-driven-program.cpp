#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> pq;
    int choice, x;

    do {
        cout << "\n1 Push\n2 Pop\n3 Top\n4 Size\n5 Display\n0 Exit\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cin >> x;
                pq.push(x);
                break;

            case 2:
                if(!pq.empty()) pq.pop();
                else cout << "Empty\n";
                break;

            case 3:
                if(!pq.empty()) cout << pq.top();
                else cout << "Empty\n";
                break;

            case 4:
                cout << pq.size();
                break;

            case 5:
            {
                priority_queue<int> temp = pq;
                while(!temp.empty())
                {
                    cout << temp.top() << " ";
                    temp.pop();
                }
                break;
            }
        }

    } while(choice != 0);
}