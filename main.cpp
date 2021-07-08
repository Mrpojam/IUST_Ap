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
        cout << "Choose a branch" << endl;
        for (int i = 0; i < branches.size(); i++) {
            cout << i+1 << ")";// << branches[i].getid() << endl;
        }
        cout << "c)Create Branch" << endl;
        char command;
        cin >> command;
        if (command == 'c') {
            
        }
    }

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