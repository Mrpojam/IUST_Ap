#include<bits/stdc++.h>
#include"libraries/person.h"
#include"libraries/Authentication.h"
using namespace std;

int main () {
    while(true) {
        cout << "Welcome To The Bank!!!" << endl;

        cout << "1)Login\n" << "2)Register" << endl;
        cout << "Enter Command: ";
        int command;
        cin >> command;
        system("clear");
        if (command == 1) {
            bool login = ShowLoginMenu();
            if (login) {
                cout << "You logged in sucssussfully" << endl;
            }
        }else if (command == 2) {
            ShowRegisterMenu();
        }
    }
    return 0;
}