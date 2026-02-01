#include<iostream>
#include<array>
#include<algorithm>

using namespace std;

int main()
{
    array<int, 6> arr = {60, 10, 20, 30, 40, 50};

    cout << "At Function: " << arr.at(2) << endl; // Accessing element at index 2
    cout << "Using [] operator: " << arr[2] << endl; // Accessing element at index 2
    cout << "Front Element: " << arr.front() << endl; // First element
    cout << "Back Element: " << arr.back() << endl; // Last element
    
    //sorting array
    cout << "Sorting Array: ";
    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Size of Array: " << arr.size() << endl; // Size of array
    cout << "Max Size of Array: " << arr.max_size() << endl; // Max size of array
    cout << "Is Array Empty: " << arr.empty() << endl; // Check if array is empty
    cout << "Data Pointer: " << arr.data() << endl; // Pointer to the underlying array
    //cout << "Capacity of Array: " << arr.capacity() << endl; // Capacity of array

    cout << "Fill Function: ";
    arr.fill(0); 
    for(int i=0; i<arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

  

    

    return 0;
}