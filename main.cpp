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

    ifstream BankList;
    BankList.open("Files/Banks/BanksList");

    string BankId;
    while (BankList >> BankId) {
        ifstream bank;
        bank.open("Files/Banks/" + BankId);
        string data;
        Bank newBank ("CreateNULL");
        bank >> data;
        newBank.setid(data.substr(4, data.size()));
        bank >> data;
        newBank.setfoundDate(data.substr(6, data.size()));
        bank >> data;
        newBank.setbankaddress(data.substr(5, data.size()));
    }

    while (true) {
        cout << "1)Login/Register Users\n2)Login/Register Workers\n3)Create New bank branch\n" << endl;

        int command;

        cout << "Enter command number :";
        cin >> command;
        system("clear");
        if (command == 1) {
            int command2;
            cout << "1)Login\n2)Register" << endl;
            
            cout << "Enter command number :";
            cin >> command2;
            if (command2 == 1) {
                pair<bool, Person> Login;
                Login = ShowLoginMenu();
                if (Login.first) {
                    ShowUserMenu(Login.second);
                }
            }
            else if (command == 2) {
                ShowRegisterMenu();
            }
        }
        else if (command == 2) {
            int command2;
            cout <<"1)Login\n2)Register" << endl;
            cin >> command2;
            if (command2 == 1) {
                
            }
            else if (command == 2) {
                
            }

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