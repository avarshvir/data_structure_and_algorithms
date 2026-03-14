#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    int choice, x;

    do
    {
        cout<<"\n1 Insert\n2 Delete\n3 Display\n4 Search\n0 Exit\n";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cin>>x;
                s.insert(x);
                break;

            case 2:
                cin>>x;
                s.erase(x);
                break;

            case 3:
                for(int v : s)
                    cout<<v<<" ";
                break;

            case 4:
                cin>>x;
                if(s.find(x)!=s.end())
                    cout<<"Found";
                else
                    cout<<"Not Found";
                break;
        }

    }while(choice!=0);
}