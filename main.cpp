#include <iostream>
using namespace std;
int main() {
    int size;
    char symbol;
    cout << "Enter a character: ";
    cin >> symbol;
    cout << "Enter the number of character: ";
    cin >> size;
    for(int i = 0; i < size; i++){
        for(int h = 0; h < size; h++){
            cout << symbol << ' ';
        }
        cout << endl;
    }
}

