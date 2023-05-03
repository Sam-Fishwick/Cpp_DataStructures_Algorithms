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

void bubbleSort(int arr[],int length);

void linearSearch(int nu, int array[], int n);

void binarySearch(int number, int arra[], int count, int low, int high);



int main() 
{
    int arr[] = 
    {
        2,99,66,3,24,87,64,10,11,13,12,28,29,30,74,82,91,41,42,
        54,21,3,6,16,82,50,15,98,89,76,45,52,38,49,22,19,67
    };

    // How many ints (4 bytes) in arr[]
    int length = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,length);

    int input, numb, lo = 0, hi = sizeof(arr)/sizeof(arr[0]);

    cout << "Which algorithm would you like to run? Enter an integer:" << endl;
    cout << "1. linear search,   2. binary search (requires ordered array)" 
        << endl;
    
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
            cout << "Searching the number " << numb << " in a " << hi 
                << " element array using linear search\n" << endl;
            linearSearch(numb, arr, hi);
            break;
        case 2:
            cout << "You chose the binary search algorithm\n" << endl;
            numb = numInput();
            cout << "Searching the number " << numb << " in a " << hi 
                << " element array using binary search\n" << endl;
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


//  --  Bubble Sort -- 
void bubbleSort(int arr[],int length)
{
    // Start run-time clock
    auto start = steady_clock::now();
    cout << "[Random] Unsorted Array:" << endl;
    // Print all elements in arr[]
    for(int i = 0; i < length; i++) {
        if(i == 0) {
            cout << "[" << arr[i];
        } else { 
            cout << "," << arr[i] ;
        }
        
        if(i == length-1) cout << "]" << endl << endl;
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

    cout << "Sorting with Bubble Sort...";

    // End run-time clock
    auto dur = steady_clock::now() - start;
    // Print run-time
    cout << " [took " << duration_cast<milliseconds>(dur).count() << " ms]" 
        << endl << endl;


    cout << "Sorting with Bubble Sort...";

    // End run-time clock
    auto dur = steady_clock::now() - start;
    // Print run-time
    cout << " [took " << duration_cast<milliseconds>(dur).count() << " ms]" << endl << endl;

    cout << "[Bubble] Sorted Array:" << endl;
    // Print all elements in arr[]
    for(int i = 0; i < length; i++) {
        if(i == 0) {
            cout << "[" << arr[i];
        } else { 
            cout << "," << arr[i] ;
        }
        
        if(i == length-1) cout << "]" << endl << endl;
    }

}


void linearSearch(int nu, int array[], int n) 
{
    auto start = steady_clock::now();
    int i;
    for (i = 0; i < n; i++) {
        cout << "Comparing to the value at position " << i << " of the array" 
            << endl;
        if (array[i] == nu) {
            cout << "The first instance of the number " << nu 
                << " is at position " << i << " in the array\n" << endl;
            break;
        }
    }
    if (i == n) {
        cout << "The number " << nu << " isn't in the array\n" << endl;
    }
    
    auto dur = steady_clock::now() - start;
    
    cout << "Linear search run-time: " 
        << duration_cast<milliseconds>(dur).count() << " ms" << endl;
}


void binarySearch(int number, int arra[], int count, int low, int high) 
{
    auto start = steady_clock::now();
    int mid = (low + high)/2;
    
    cout << "Comparing to the value at position " << mid << " of the array" 
        << endl;
    if (low > high || (mid >= high && number != arra[mid])) {
        cout << "The number " << number << " isn't in the array\n" << endl;
        
        auto dur = steady_clock::now() - start;
        
        cout << "Binary search run-time: " 
            << duration_cast<milliseconds>(dur).count() << " ms" << endl;
    } else if (number == arra[mid]) {
        cout << "The first instance of the number " << number 
            << " is at position " << mid << " in the array\n" << endl;
        
        auto dur = steady_clock::now() - start;
        
        cout << "Binary search run-time: " 
            << duration_cast<milliseconds>(dur).count() << " ms" << endl;
    } else if (number > arra[mid]) {
        cout << "Your number is above this value. " 
            << "Removing all elements below this position from the scope" 
            << endl;
        
        binarySearch(number, arra, count, mid+1, high);
    } else if (number < arra[mid]) {
        cout << "Your number is below this value. " 
            << "Removing all elements above this position from the scope" 
            << endl;
        
        binarySearch(number, arra, count, low, mid-1);
    }
}

