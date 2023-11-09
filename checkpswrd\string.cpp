#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
bool checkPassword(const string& password) {
    int numb = 0;
    int specChar = 0;
    int smallLetter = 0;
    int capLetter = 0;
    for (char ch: password) {
        if (isdigit(ch)) {
            numb++;
        } else if (isalpha(ch)) {
            if (islower(ch)) {
                smallLetter++;
            } else if (isupper(ch)) {
                capLetter++;
            }
        } else {
            specChar++;
        }
    }
    return numb >= 5 && specChar >=2 && smallLetter >= 1 && capLetter >= 1;
}
int main() {
    string userPassword;
    do {
        cout << "Enter  password: ";
        cin >> userPassword;

        if (!checkPassword(userPassword)) {
            std::cout << "Password does not meet requirements" << endl;
        }
    } while (!checkPassword(userPassword));

    cout << "Everything's fine" << endl;

    return 0;
}
