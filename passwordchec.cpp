#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
bool checkPassword(const char* password) {
    int numb = 0;
    int specChar = 0;
    int letter = 0;
    bool capLet = false;
    bool smallLet = false;

    for (int i = 0; i < strlen(password); i++){
        if(isdigit(password[i])){
            numb++;
        } else if (isalpha(password[i])){
            letter++;
            if (islower(password[i])){
                smallLet = true;
            } else if(isupper(password[i])){
                capLet = true;
            }
        } else {
            specChar++;
        }
    }
    return numb >= 5 && specChar >= 2 && letter >= 3 && (capLet || smallLet);
}
int main() {
    string userPassword;
    do{
        cout << "Enter password: ";
        cin >> userPassword;
        if (!checkPassword(userPassword.c_str())){
            cout << "Password does not meet the requirements" << endl;
        }
    } while (!checkPassword(userPassword.c_str()));
    cout << "Everything's fine" << endl;
    return 0;
}
