#include <iostream>
using namespace std;


int numInput() {
    int num;
    cout << "Type an integer between 1 and 99" << endl;
    cin >> num;
    while (!(num > 0 && num < 100)) {
        cout << "Please choose an appropriate integer" << endl;
        cin.clear();
        cin >> num;
    }
    if (num == 69) { cout << "Nice!" << endl; }
    cout << "You chose the number " << num << endl;
    return num;
}


void linearSearch(int nu, int *array, int n) {
    int i;
    for (i = 0; i < n; i++) {
        cout << "Checking the number at position " << i+1 << " of the array" << endl;
        if (array[i] == nu) {
            cout << "The number " << nu << " is at position " << i+1 << " in the array" << endl;
            break;
        }
    }
    if (i == n) {
        cout << "The number " << nu << " isn't in the array" << endl;
    }
}


void binarySearch(int number, int *arra, int count, int low, int high) {
    int mid = (low + high)/2;
    if (low > high || mid+1 > high) {
        cout << "The number " << number << " isn't in the array" << endl;
    } else if (number == arra[mid]) {
        cout << "The number " << number << " is at position " << mid+1 << " in the array" << endl;
    } else if (number > arra[mid]) {
        cout << "The number " << number << " is higher than the value at position " << mid+1 << " in the array" << endl;
        cout << "Removing all elements equal to or lesser than " << arra[mid] << " from the scope" << endl;
        binarySearch(number, arra, count, mid+1, high);
    } else if (number < arra[mid]) {
        cout << "The number " << number << " is lower than the value at position " << mid+1 << " in the array" << endl;
        cout << "Removing all elements equal to or greater than " << arra[mid] << " from the scope" << endl;
        binarySearch(number, arra, count, low, mid-1);
    }
}


int main() {
    int arr[] = {1, 5, 17, 20, 22, 29, 46, 50, 69, 77, 89, 93};
    int input, numb, lo = 0, hi = sizeof(arr)/sizeof(arr[0]);
    cout << "Which algorithm would you like to run? Enter an integer:" << endl;
    cout << "1. linear search,   2. binary search (requires ordered array)" << endl;
    cin >> input;
    while (!(input == 1 || input == 2)) {
        cout << "Please choose an appropriate integer" << endl;
        cin.clear();
        cin >> input;
    }
    switch (input) {
        case 1:
            cout << "You have chosen the linear search algorithm" << endl;
            numb = numInput();
            cout << "Searching the number " << numb << " in a " << hi << " element array using linear search" << endl;
            linearSearch(numb, arr, hi);
            break;
        case 2:
            cout << "You have chosen the binary search algorithm" << endl;
            numb = numInput();
            cout << "Searching the number " << numb << " in a " << hi << " element array using binary search" << endl;
            binarySearch(numb, arr, hi, lo, hi);
            break;
        default:
            cout << "Please choose an appropriate integer\n" << endl;
    }
    return 0;
}

