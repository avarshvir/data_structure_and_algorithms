#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& v) {
    for (int val : v) {
        cout << val << " ";
    }
    cout << endl;
}

void reverseVector(vector<int>& v) {
    int left = 0;
    int right = v.size() - 1;

    while (left < right) {
        
        int temp = v[left];
        v[left] = v[right];
        v[right] = temp;

        left++;
        right--;
    }
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};

    cout << "Original Vector: ";
    printVector(v);

    reverseVector(v);

    cout << "Reversed Vector: ";
    printVector(v);

    return 0;
}
