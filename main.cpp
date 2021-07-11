#include"libraries/Authentication.h"


vector<Bank> branches;

void ShowUserMenu (Person User) {
    while (true) {
        system("clear");
        vector<Account> accounts = ShowUserAccounts(User);
        int command;
        cout << "####User Menu####" << endl;
        cout << "Your birthdat" << User.getBD() << endl;
        cout << "1.Change User Information" <<endl<< "2.Create Account" <<endl<< "3.Change Account" <<endl<< "4.Bank Loans" <<endl<< "5.Create Card" <<endl<< "6.Get Shaba" <<endl<< "7.Back" <<endl;
        cin>>command;
        if (command==1) {
            User.ChangeProfile();
        }
        else if (command==2) {
            ShowAccountMenu(User);
        }
        else if (command==3) {

         //   ChangeAccount(Person person)
        }
        else if (command==4) {

        }
        else if (command==5) {
            system("clear");
            for (int i = 0; i < accounts.size(); i++)
                cout << i+1 << ")" << accounts[i].getAccountNumber() << endl;
            
            cout << "Choose an Account:";
            int accnum;
            cin >> accnum;
            ShowCardMenu(accounts[accnum-1].getAccountNumber());

        }
        else if (command==6) {
            for (int i = 0; i < accounts.size(); i++)
                cout << i+1 << ")" << accounts[i].getAccountNumber() << endl;
            cout << "Choose an Account:";
            int accnum;
            cin >> accnum;
            cout << accounts[accnum-1].GetShaba() << endl;
            char c;
            cout << "Enter something to continue:";
            cin >> c;
        }
        else if (command==7) {
            return ;
        }
        else {
            cout<< "Error!!!" <<endl;
        }

    }
}

void ShowCounterManager (Counter_Manager User2) {
    int command4;
    cout << "####Counter Menu####" << endl;
    cout << "1.Get Apply for Loan " <<endl<< "2.Transaction" <<endl<< "3.Change Counter Manager Information" <<endl<< "4.Change Postition" <<endl<< "5.Back" <<endl;
    cin>>command4;
    if (command4==1) {
        system("clear");
        int accnum1;
        cout << "Enter Account number which is about to pay:";
        cin >> accnum1;
        cout << "Enter Account number which is about to take:";
        int accnum2;
        cin >> accnum2;
        cout << "Enter Amount:";
        long long amount;
        cin >> amount;
        
        Account Pay;
        Account Take;
        
        ifstream PayFile;
        PayFile.open("Files/Accounts/" + accnum1);
        ifstream TakeFile;
        TakeFile.open("Files/Accounts" + accnum2);
        
        string GetString1, GetString2;

        PayFile >> GetString1;
        TakeFile >> GetString1;

        string PayCode = ExtractData("nnum", GetString1);
        string TakeCode = ExtractData("nnum", GetString2);

        cout << "Transaction be made from " << GetString1 << " to " << GetString2 << endl;

        Pay.setAccountNumber(ExtractData("accnum", GetString1));
        Pay.setAccountAmount (stol (ExtractData("accam", GetString1), nullptr, 10));
        Pay.setFoundDate(ExtractData("fdt", GetString1));
        
        Take.setAccountNumber(ExtractData("accnum", GetString2));
        Take.setAccountAmount (stol (ExtractData("accam", GetString2)));
        Take.setFoundDate(ExtractData("fdt", GetString2));
        

        transfermoney(&Pay, &Take, amount, PayCode, TakeCode);


    }
    else if (command4==2) {

    }
    else if (command4==3) {
      //  Change_Worker_Profile();
    }
    else if (command4==4) {

    }
    else if (command4==5) {
        return ;
    }
    else {
        cout<< "Error!!!" <<endl;
    }

}

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
        newBank.setid(ExtractData("id", data));
        newBank.setfoundDate(ExtractData("id", data));
        newBank.setbankaddress(ExtractData("Add", data));
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
            else if (command2 == 2) {
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
                cout << "1)Boss\n2)Cashier3)\nCounter Manager" << endl;
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

                Bank *newBank = new Bank();
                branches.push_back(*newBank);
                system("clear");
            
        }
    }

    while(true) {
        system("clear");
      
      
    }
    return 0;
}