#include <iostream>
using namespace std;
int main() {
    char symbol;
    while (true) {
        int size;
        cout << "Enter the number of character: ";
        cin >> size;
        if (size <= 0) {
            cout << "Invalid value entered  " << endl;
        } else {
            cout << "Enter a character: ";
            cin >> symbol;
            for (int i = 0; i < size; i++) {
                for (int h = 0; h < size; h++) {
                    cout << symbol << ' ';
                }
                cout << endl;
            }
            break;
        }
    }
}
