#include<bits/stdc++.h>
#include"libraries/person.h"
#include"libraries/Authentication.h"
using namespace std;

void ShowUserMenu (Person User) {
    while (true) {
        system("clear");
        int command;
        cout << "####User Menu####" << endl;


    }
}

int main () {
    while(true) {
        system("clear");
        cout << "Welcome To The Bank!!!" << endl;

        cout << "1)Login\n2)Register\n3)Exit" << endl;
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
        }else if (command == 3) {
            return 0;
        }
    }
    return 0;
}