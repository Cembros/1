#include <iostream>
using namespace std;
int main() {
    int size;
    char symbol;
    cout << "Enter the number of character: ";
    cin >> size;
    if (size <=0){
        cout<<"Invalid value entered" ;
        return 1;
    }
    cout << "Enter a character: ";
    cin >> symbol;
    for(int i = 0; i < size; i++){
        for(int h = 0; h < size; h++){
            cout << symbol << ' ';
        }
        cout << endl;
    }
}
