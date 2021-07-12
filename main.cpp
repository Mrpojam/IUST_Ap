#include"libraries/Authentication.h"

#include"libraries/loan.h"

vector<Bank> branches;
vector<Loan> loans;

void ShowUserMenu (Person User) {
    while (true) {
        system("clear");
        vector<Account> accounts = ShowUserAccounts(User);
        int command;
        cout << "####User Menu####" << endl;
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
                system("clear");
                cout << "Choose the bank:" << endl;
                for (int i = 0; i < branches.size(); i++)
                    cout << i+1 << ")" << branches[i].getid() << endl;
                int BankId;
                cout << "Your Choice : ";
                cin >> BankId;
                system("clear");
                cout << "Choose the account:" << endl;
                for (int i = 0; i < accounts.size(); i++) 
                    cout << i+1 << ")" << accounts[i].getAccountNumber() << endl;
                int AccNum;
                cout << "Your Choice : ";
                cin >> AccNum;
                CreateLoan(branches[BankId-1].getid(), accounts[AccNum-1].getAccountNumber());
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

void ShowCounterManager (Worker User2) {
    int command4;
    cout << "####Counter Menu####" << endl;
    cout << "1.Get Apply for Loan " <<endl<< "2.Transaction" <<endl<< "3.Change Counter Manager Information" <<endl<< "4.Change Postition" <<endl<< "5.Back" <<endl;
    cin>>command4;
    if (command4==2) {
        system("clear");
        string accnum1;
        cout << "Enter Account number which is about to pay:";
        cin >> accnum1;
        cout << "Enter Account number which is about to take:";
        string accnum2;
        cin >> accnum2;
        cout << "Enter Amount:";
        long long amount;
        cin >> amount;
        
        Account Pay;
        Account Take;
        cout << "1 : " << accnum1 << " 2 : " << accnum2 << endl;
        ifstream PayFile;
        PayFile.open("Files/Accounts/" + accnum1);
        ifstream TakeFile;
        TakeFile.open("Files/Accounts/" + accnum2);
        
        string GetString1, GetString2;

        PayFile >> GetString1;
        TakeFile >> GetString2;

        cout << GetString1 << endl;
        cout << GetString2 << endl;
        string PayCode = ExtractData("nnum", GetString1);
        string TakeCode = ExtractData("nnum", GetString2);

        cout << "Transaction be made from " << GetString1 << " to " << GetString2 << endl;

        Pay.setAccountNumber(ExtractData("accn", GetString1));
        Pay.setAccountAmount (stol (ExtractData("accam", GetString1), nullptr, 10));
        Pay.setFoundDate(ExtractData("fdt", GetString1));
        
        Take.setAccountNumber(ExtractData("accn", GetString2));
        Take.setAccountAmount (stol (ExtractData("accam", GetString2), nullptr, 10));
        Take.setFoundDate(ExtractData("fdt", GetString2));
        

        transfermoney(&Pay, &Take, amount, PayCode, TakeCode);


    }
    else if (command4==1) {
        int index = 1;
        vector<Loan> ManagerLoans;
        for (int i = 0; i < loans.size(); i++) {
            if (loans[i].getSit() == 0) ManagerLoans.push_back(loans[i]);
        }
        cout << ManagerLoans.size() << endl;
        for (int i = 0; i < ManagerLoans.size(); i++)
            cout << i+1 << ")" << "account:" << ManagerLoans[i].getaccountnum() << " bank:" << ManagerLoans[i].getcodebranch() << " amount:" << ManagerLoans[i].getloanamount() << endl; 

        int choice;
        cout << "choose a loan to accept:";
        cin >> choice;
        ManagerLoans[choice-1].update();
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


void ShowBossMenu (Worker User1) {
    int command3;
    cout << "####Boss Menu####" << endl;
    cout << "1.Accept Loan" <<endl<< "2.Refuse Loan" <<endl<< "3.Change Boss Information" <<endl<< "4.Change Position" <<endl<< "5.Back" <<endl;
    cin>>command3;
    if (command3==1) {
        vector<Loan> BossLoans;
        for (int i = 0; i < loans.size(); i++) {
            if (loans[i].getSit() == 1) BossLoans.push_back(loans[i]);
        }
        cout << BossLoans.size() << endl;
        for (int i = 0; i < BossLoans.size(); i++)
            cout << i+1 << ")" << "account:" << BossLoans[i].getaccountnum() << " bank:" << BossLoans[i].getcodebranch() << " amount:" << BossLoans[i].getloanamount() << endl; 

        int choice;
        cout << "choose a loan to accept:";
        cin >> choice;
        BossLoans[choice-1].update(); 
    }
    else if (command3==2) {

    }
    else if (command3==3) {
        //Change_Worker_Profile();
    }
    else if (command3==4) {

    }
    else if (command3==5) {
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
    
    ifstream LoanList;
    LoanList.open("Files/Loans/All");

    string loan;
    while (LoanList >> loan) {
        Loan newLoan;
        ifstream loanfile;
        loanfile.open("Files/Loans/" + loan);
        string data;
        loanfile >> data;
        
        newLoan.setcodebranch(ExtractData("codebranch", data));
        newLoan.setaccountnum(ExtractData("accountnum", data));
        newLoan.setloanamount(stol(ExtractData("loanamount", data), nullptr, 10));
        newLoan.setsit(stoi(ExtractData("sit", data)));
        loans.push_back(newLoan);
        loanfile.close();
    }

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
            cout <<"1)Login Counter Manager\n2)Cashier\n3)Boss\n4)Register" << endl;
            cin >> command2;
            if (command2 == 1 || command2 == 2 || command2 == 3) {
                pair<bool, Worker> Login;
                Login = ShowLoginMenuWorker();
                if (Login.first) {
                    if (command2 == 1)
                    ShowCounterManager(Login.second);
                    else if (command2 == 3)
                    ShowBossMenu(Login.second);
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