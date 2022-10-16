#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Hello World! What is your name?" << endl;
    getline(cin >> ws, input);
    cout << "Hello " << input << "!" << endl;
    return 0;
}
