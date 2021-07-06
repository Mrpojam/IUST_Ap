#include<bits/stdc++.h>
#include"libraries/person.h"
#include"libraries/Authentication.h"
using namespace std;

void ShowUserMenu (Person User) {
    system("clear");
    cout << "UserMenu" << endl;
}

int main () {
    while(true) {
        system("clear");
        cout << "Welcome To The Bank!!!" << endl;

        cout << "1)Login\n" << "2)Register" << endl;
        cout << "Enter Command: ";
        int command;
        cin >> command;
        system("clear");
        if (command == 1) {
            pair<bool, Person> Login;
            Login = ShowLoginMenu();
            if (Login.first) {
                ShowUserMenu(Login.second);
            }
        }else if (command == 2) {
            ShowRegisterMenu();
        }
    }
    return 0;
}