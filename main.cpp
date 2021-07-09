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
    BankList.open("Files/Banks/BankList");

    string BankId;
    while (BankList >> BankId) {
        ifstream bank;
        bank.open("Files/Banks/" + BankId);
        string data;
        Bank newBank ("CreateNULL");
        bank >> data;
        newBank.setid(data.substr(3, data.size()));
        bank >> data;

        newBank.setfoundDate(data.substr(5, data.size()));
        bank >> data;

        newBank.setbankaddress(data.substr(4, data.size()));
        branches.push_back(newBank);
    }
    BankList.close();
    


    while (true) {
        system("clear");
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
                    system("clear");

            int command2;
            cout <<"1)Login\n2)Register" << endl;
            cin >> command2;
            if (command2 == 1) {
                pair<bool, Person> Login;
                Login = ShowLoginMenuWorker();
                if (Login.first) {

                }
            }
            else if (command2 == 2) {
                        system("clear");

                cout << "Choose your bank:" << endl;
                for (int i = 0; i < branches.size(); i++)
                    cout << i+1 << ")" << branches[i].getid() << endl;
                int id;
                cout << "Enter number of your choice:";
                cin >> id;
                cout << "1)Boss\n2)Cashier3)Counter Manager" << endl;
                int type;
                cout << "Enter The Type of your choice:";
                cin >> type;
                string TypeName = "";
                if (type == 1)
                    TypeName = "Boss";
                else if (type == 2)
                    TypeName = "Cashier";
                else 
                    TypeName = "Counter_Manager";
                ShowRegisterMenuWorker(branches[id+1], TypeName);
            }

        }
        else if (command == 3) {
                    system("clear");

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