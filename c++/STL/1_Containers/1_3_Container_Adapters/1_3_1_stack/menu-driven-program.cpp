#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    int choice, x;

    do {
        cout << "\n1 Push\n2 Pop\n3 Top\n4 Size\n5 Display\n0 Exit\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cin >> x;
                s.push(x);
                break;

            case 2:
                if(!s.empty()) s.pop();
                else cout << "Stack Empty\n";
                break;

            case 3:
                if(!s.empty()) cout << s.top();
                else cout << "Stack Empty\n";
                break;

            case 4:
                cout << s.size();
                break;

            case 5:
            {
                stack<int> temp = s;
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