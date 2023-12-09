#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct User {
    int id;
    string login;
    string password;
    bool psswrdHasCaplet;
    bool psswrdHasSmllet;
    double balance;
    string registerDate;
};

vector<User> database;

bool isUserExists(const string& login, const string& password) {
    for (const User& user : database) {
        if (user.login == login && user.password == password) {
            return true;
        }
    }
    return false;
}

bool isLoginExists(const string& login) {
    for (const User& user : database) {
        if (user.login == login) {
            return true;
        }
    }
    return false;
}

int getUserIndex(const string& login, const string& password) {
    for (size_t i = 0; i < database.size(); ++i) {
        if (database[i].login == login && database[i].password == password) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void showBalance(const User& user) {
    cout << "Balance for user " << user.login << ": $" << user.balance << endl;
}

void withdrawCash(User& user, double amount) {
    if (amount > 0) {
        if (amount <= user.balance) {
            user.balance -= amount;
            cout << "Withdrawal successful. Remaining balance: $" << user.balance << endl;
        } else {
            cout << "Error: Insufficient balance. You cannot withdraw more than your current balance." << endl;
        }
    } else {
        cout << "Error: Invalid withdrawal amount." << endl;
    }
}

void depositCash(User& user, double amount) {
    if (amount > 0) {
        user.balance += amount;
        cout << "Deposit successful. You added $" << amount << " to your balance. New balance: $" << user.balance << endl;
    } else {
        cout << "Error: Invalid deposit amount." << endl;
    }
}

void registerUser() {
    User newUser;
    while (true) {
        cout << "Enter login: ";
        cin >> newUser.login;

        if (isLoginExists(newUser.login)) {
            cout << "Error: User with this login already exists. Please choose a different login." << endl;
        } else {
            break;
        }
    }

    while (true) {
        cout << "Enter password: ";
        cin >> newUser.password;

        if (newUser.password.length() < 6) {
            cout << "Error: Password must be at least 6 characters long." << endl;
            continue;
        }

        int letterCount = 0;
        newUser.psswrdHasCaplet = false;
        newUser.psswrdHasSmllet = false;

        for (char ch : newUser.password) {
            if (isalpha(ch)) {
                letterCount++;
                if (isupper(ch)) {
                    newUser.psswrdHasCaplet = true;
                } else if (islower(ch)) {
                    newUser.psswrdHasSmllet = true;
                }
            }
        }

        if (letterCount < 2 || !newUser.psswrdHasCaplet || !newUser.psswrdHasSmllet) {
            cout << "Error: Password must contain at least 2 letters, including at least 1 uppercase and 1 lowercase letter." << endl;
        } else {
            break;
        }
    }

    cout << "Enter initial balance: $";
    cin >> newUser.balance;

    newUser.id = static_cast<int>(database.size()) + 1;
    newUser.registerDate = "2023-11-27";

    database.push_back(newUser);

    cout << "Registration successful. Your ID: " << newUser.id << endl;
}

int main() {
    bool exitProgram = false;
    User currentUser;

    while (!exitProgram) {
        cout << "Welcome to the bank system!" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string login, password;
                cout << "Enter login: ";
                cin >> login;

                cout << "Enter password: ";
                cin >> password;

                if (isUserExists(login, password)) {
                    int userIndex = getUserIndex(login, password);
                    currentUser = database[userIndex];

                    while (true) {
                        cout << "1. Show Balance" << endl;
                        cout << "2. Withdraw Cash" << endl;
                        cout << "3. Deposit Cash" << endl;
                        cout << "4. Logout" << endl;
                        cout << "Choose an option: ";

                        int userChoice;
                        cin >> userChoice;

                        switch (userChoice) {
                            case 1:
                                showBalance(currentUser);
                                break;
                            case 2: {
                                double amount;
                                cout << "Enter amount to withdraw: $";
                                cin >> amount;
                                withdrawCash(currentUser, amount);
                                break;
                            }
                            case 3: {
                                double amount;
                                cout << "Enter amount to deposit: $";
                                cin >> amount;
                                depositCash(currentUser, amount);
                                break;
                            }
                            case 4:
                                cout << "Logging out..." << endl;
                                break;
                            default:
                                cout << "Invalid option. Try again." << endl;
                        }

                        if (userChoice == 4) {
                            break;
                        }
                    }
                } else {
                    cout << "Invalid login or password. Please try again." << endl;
                }
                break;
            }
            case 2:
                registerUser();
                break;
            case 3:
                cout << "Exiting the bank system. Goodbye!" << endl;
                exitProgram = true;
                break;
            default:
                cout << "Invalid option. Try again." << endl;
        }
    }

    return 0;
}