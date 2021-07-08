#include"libraries/Authentication.h"

void ShowUserMenu (Person User) {
    while (true) {
        system("clear");
        int command;
        cout << "####User Menu####" << endl;


    }
}



vector<Bank> branches;

int main () {

    while (true) {
        cout << "1)Login User\n2)Register New User\n3)Create New bank branch\n" << endl;

        int command;

        cout << "Enter command number :";
        cin >> command;
        if (command == 1) {
            pair<bool, Person> Login;
            Login = ShowLoginMenu();
        if (Login.first) {
                ShowUserMenu(Login.second);
            }
        }else if (command == 2) {
            ShowRegisterMenu();
        }
        else if (command == 3) {
            cout << "c)Create Branch" << endl;
            char command;
            cin >> command;
            if (command == 'c') {
                Bank *newBank = new Bank();
                branches.push_back(*newBank);
                system("clear");
            }
        }
    }

    while(true) {
        system("clear");
      
      
    }
    return 0;
}