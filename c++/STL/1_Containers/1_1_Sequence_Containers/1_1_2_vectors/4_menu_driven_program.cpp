#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    int choice, x;

    do {
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Sort\n5. Search\n0. Exit\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cin >> x;
                v.push_back(x);
                break;

            case 2:
                if(!v.empty()) v.pop_back();
                break;

            case 3:
                for(int i : v) cout << i << " ";
                break;

            case 4:
                sort(v.begin(), v.end());
                break;

            case 5:
                cin >> x;
                if(find(v.begin(), v.end(), x) != v.end())
                    cout << "Found";
                else
                    cout << "Not Found";
                break;
        }
    } while(choice != 0);
}
