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
    int n = v.size(); // Get the size of the vector
    for (int i = 0; i < n / 2; i++) {
        int temp = v[i];
        v[i] = v[n - i - 1];
        v[n - i - 1] = temp;
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
