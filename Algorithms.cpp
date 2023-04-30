#include <iostream>
#include <chrono>
using std::cout;
using std::endl;
using std::cin;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::time_point;

int numInput(); 

void linearSearch(int nu, int *array, int n);

void binarySearch(int number, int *arra, int count, int low, int high);



int main() 
{
    int arr[] = {2, 3, 5, 11, 17, 20, 22, 29, 32, 36, 39, 41, 42, 46, 50, 55, 56, 57, 61, 62, 63, 64, 65, 66, 67, 68, 69, 71, 72, 77, 80, 85, 88, 89, 91, 93, 95, 96, 98};
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
            cout << "You chose the linear search algorithm\n" << endl;
            numb = numInput();
            cout << "Searching the number " << numb << " in a " << hi << " element array using linear search\n" << endl;
            linearSearch(numb, arr, hi);
            break;
        case 2:
            cout << "You chose the binary search algorithm\n" << endl;
            numb = numInput();
            cout << "Searching the number " << numb << " in a " << hi << " element array using binary search\n" << endl;
            binarySearch(numb, arr, hi, lo, hi-1);
            break;
        default:
            cout << "Please choose an appropriate integer" << endl;
    }
    return 0;
}





int numInput() 
{
    int num;
    cout << "Type an integer between 1 and 99" << endl;
    cin >> num;
    while (!(num > 0 && num < 100)) {
        cout << "Please choose an appropriate integer" << endl;
        cin.clear();
        cin >> num;
    }
    cout << "You chose the number " << num << endl;
    if (num == 69) { cout << "(Nice!)" << endl; }
    cout << endl;
    return num;
}


/*  --  Bubble Sort -- 

 int bubbleSort()
 {

    // initialise array
    int arr[5];
 
    // Take user input
    cout << "Enter an array of 5 integers:\n" << endl;
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
 
    // How many ints (4 bytes) in arr[]
    int length = sizeof(arr)/sizeof(arr[0]);
 
    // Print all elements in arr[]
    for(int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
 
    int temp = 0;
 
    // Swap i with i+1 if i>(i+1)
    for(int i = 0; i < length-1; i++) {
        for(int j = i+1; j < length; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // Print all elements in arr[]
    for(int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
    return arr;
}
*/


void linearSearch(int nu, int *array, int n) 
{
    auto start = steady_clock::now();
    int i;
    for (i = 0; i < n; i++) {
        cout << "Comparing to the value at position " << i << " of the array" << endl;
        if (array[i] == nu) {
            cout << "The number " << nu << " is at position " << i << " in the array\n" << endl;
            break;
        }
    }
    if (i == n) {
        cout << "The number " << nu << " isn't in the array\n" << endl;
    }
    auto dur = steady_clock::now() - start;
    cout << "Linear search run-time: " << duration_cast<milliseconds>(dur).count() << " ms" << endl;
}


void binarySearch(int number, int *arra, int count, int low, int high) 
{
    auto start = steady_clock::now();
    int mid = (low + high)/2;
    cout << "Comparing to the value at position " << mid << " of the array" << endl;
    if (low > high || (mid >= high && number != arra[mid])) {
        cout << "The number " << number << " isn't in the array\n" << endl;
        auto dur = steady_clock::now() - start;
        cout << "Binary search run-time: " << duration_cast<milliseconds>(dur).count() << " ms" << endl;
    } else if (number == arra[mid]) {
        cout << "The number " << number << " is at position " << mid << " in the array\n" << endl;
        auto dur = steady_clock::now() - start;
        cout << "Binary search run-time: " << duration_cast<milliseconds>(dur).count() << " ms" << endl;
    } else if (number > arra[mid]) {
        cout << "Your number is above this value. Removing all elements below this position from the scope" << endl;
        binarySearch(number, arra, count, mid+1, high);
    } else if (number < arra[mid]) {
        cout << "Your number is below this value. Removing all elements above this position from the scope" << endl;
        binarySearch(number, arra, count, low, mid-1);
    }
}




