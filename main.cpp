#include"libraries/Authentication.h"
#include"libraries/loan.h"
#include"libraries/utils.h"

void ShowUserMenu (Person User) {
    while (true) {
        system("cls");
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
            User.ChangeProfile();
        }
        else if (command==4) {
                system("cls");
                cout << "Choose the bank:" << endl;
                for (int i = 0; i < branches.size(); i++)
                    cout << i+1 << ")" << branches[i].getid() << endl;
                int BankId;
                cout << "Your Choice : ";
                cin >> BankId;
                system("cls");
                cout << "Choose the account:" << endl;
                for (int i = 0; i < accounts.size(); i++) 
                    cout << i+1 << ")" << accounts[i].getAccountNumber() << endl;
                int AccNum;
                cout << "Your Choice : ";
                cin >> AccNum;
                CreateLoan(branches[BankId-1].getid(), accounts[AccNum-1].getAccountNumber());
        }
        else if (command==5) {
            system("cls");
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
        else if (command == 7) {    
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
        system("cls");
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
            cout << i+1 << ")" << "Account:" << ManagerLoans[i].getaccountnum() << " Bank:" << ManagerLoans[i].getcodebranch() << " Amount:" << ManagerLoans[i].getloanamount() << endl; 

        int choice;
        cout << "choose a loan to accept:";
        cin >> choice;
        ManagerLoans[choice-1].update();
        UpdateLoans();
    }
    else if (command4==3) {
        User2.ChangeProfile();
    }
    else if (command4==4) {
        system("cls");
        cout << "1.Boss" << endl;
        cout << "2.Counter Manager" << endl;
        cout << "3.Cashier" << endl;
        int c;
        cin >> c;
        string type[] = {"Boss", "Counter_Manager", "Cashier"};
        User2.UpdatePosition(type[c-1]);
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
        for (int i = 0; i < BossLoans.size(); i++)
            cout << i+1 << ")" << "Account:" << BossLoans[i].getaccountnum() << " Bank:" << BossLoans[i].getcodebranch() << " Amount:" << BossLoans[i].getloanamount() << endl; 

        int choice;
        cout << "Choose a loan to accept:";
        cin >> choice;
        BossLoans[choice-1].update(); 
        UpdateLoans();
    }
    else if (command3==2) {
        vector<Loan> BossLoans;
        for (int i = 0; i < loans.size(); i++) {
            if (loans[i].getSit() == 1) BossLoans.push_back(loans[i]);
        }
         for (int i = 0; i < BossLoans.size(); i++)
            cout << i+1 << ")" << "Account:" << BossLoans[i].getaccountnum() << " Bank:" << BossLoans[i].getcodebranch() << " Amount:" << BossLoans[i].getloanamount() << endl; 
        cout << "Choose a loan to accept:";
        int choice;
        cin >> choice;
        BossLoans[choice-1].refuse();
        UpdateLoans();
    }
    else if (command3==3) {
        User1.ChangeProfile();
    }
    else if (command3==4) {
system("cls");
        cout << "1.Boss" << endl;
        cout << "2.Counter Manager" << endl;
        cout << "3.Cashier" << endl;
        int c;
        cin >> c;
        string type[] = {"Boss", "Counter_Manager", "Cashier"};
        User1.UpdatePosition(type[c-1]);
    }
    else if (command3==5) {
        return ;
    }
    else {
        cout<< "Error!!!" <<endl;
    }
}

void ShowCashier (Worker User3) {
    int command5;
    while (1) {
    cout << "####Cashier Menu####" << endl;
    cout << "1.Get Check Data" <<endl<< "2.Change Cashier Information" <<endl<< "3.Change Position" << "4.Back" <<endl;
    cin>>command5;
    if (command5==1) {
        cout << "Enter Check number:";
        string checknumber;
        cin >> checknumber;
        for (int i = 0; i < checks.size(); i++) {
            cout << checks[i].getchecknumber() << endl;
            if (checks[i].getchecknumber() == checknumber) {
                cout << "Fond" << endl;
                if (checks[i].done) {
                    cout << "Check has been passed" << endl;
                }
                else {
                    string accnum1 = checks[i].PayPerson;
                    string accnum2 = checks[i].TakePerson;
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
                    
                    transfermoney(&Pay, &Take, checks[i].getcheckamount(), PayCode, TakeCode);
                }
                break;
            }
        }
    }
    else if (command5==2) {
        User3.ChangeProfile();
    }
    else if (command5==3) {
        system("cls");
        cout << "1.Boss" << endl;
        cout << "2.Counter Manager" << endl;
        cout << "3.Cashier" << endl;
        int c;
        cin >> c;
        string type[] = {"Boss", "Counter_Manager", "Cashier"};
        User3.UpdatePosition(type[c-1]);
    }
    else if (command5==4) {
        return ;
    }
    else {
        cout<< "Error!!!" <<endl;
    }
    }
}

void ShowBankServices () {
    int command7;
    cout << "####Bank Services####" << endl;
    cout  <<endl<< "1.Search for people(4 ways)" <<endl<< "2.Find cards connected to the account" <<endl<< "3.Find accounts connected to the card" <<endl << "4.Find a accounts of a person" << endl <<"5.Find a person cards" << endl << "6.Show todays birthdays" << endl << "7.Find Persons with higher amount"<<endl<< "8.Back" <<endl;
    cin>>command7;
    if (command7==1) {
        system("cls");
        cout << "1.By Name" << endl << "2.Mobile Number" << endl << "3.Account Number" << endl << "4.Card"<< endl;
        int c;
        cout << "Enter your choice : ";
        cin >> c;
        if (c == 1) {
            cout << "Enter Name : ";
            string fname;
            cin >> fname;
            FindPersonByName(fname);
        } else if (c == 2) {
            cout << "Enter Mobile Number : ";
            string mob;
            cin >> mob;
            FindPersonByMobile(mob);

        } else if (c == 3) {
            cout << "Enter Account Number : ";
            string num;
            cin >> num;
            FindPersonByAccount(num);
        }else if (c == 4) {
            cout << "Enter Card Number : ";
            string num;
            cin >> num;
            ShowPersonByCard(num);
        }

    }
    else if (command7==2) {
        system("cls");
        cout << "Enter Account Number : ";
        string num;
        cin >> num;
        FindCardsByAccount(num);
    }
    else if (command7==3) {
        system("cls");
        cout << "Enter Card Number : ";
        string num;
        cin >> num;
        FindAccountsByCard(num);
    }
    else if (command7==4) {
        system("cls");
        cout << "Enter National Code : ";
        string num;
        cin >> num;
        FindAccountsByPerson(num);
    }
    else if (command7==5) {
        system("cls");
        cout << "Enter National Code : ";
        string num;
        cin >> num;
        FindCardsByPerson(num);
    }
    else if (command7 == 6) {
        ShowTodaysBirthDay();
    }else if (command7 == 7) {
        system("cls");
        cout << "Enter Amount : ";
        long long am;
        cin >> am;
        ShowUsersWithHigherAmount(am);
    }
    else if (command7==8) {
        return ;
    }
    else {
        cout<<"Error!!!"<<endl;
    }
    string s;
    cout << "Enter something to continue : ";
    cin >> s;
}

int main () {

    UpdateBanks();
    UpdateLoans();
    UpdateChecks();
    while (true) {
        system("cls");
        cout << "#########KhodSazandegan Bank#########" << endl;
        cout << "1.Login/Register Users\n2.Login/Register Workers\n3.Create New bank branch\n4.Bank Services" << endl;

        int command;
        cout << "Enter command number :";
        cin >> command;
        system("cls");
        if (command == 1) {
            int command2;
            cout << "1.Login\n2.Register" << endl;
            
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
                    system("cls");

            int command2;
            cout <<"\n1.Login Counter Manager\n2.Login Cashier\n3.Login Boss\n4.Register" << endl;
            cin >> command2;
            if (command2 == 1 || command2 == 2 || command2 == 3) {
                pair<bool, Worker> Login;
                Login = ShowLoginMenuWorker();
                if (Login.first) {
                    if (command2 == 1)
                    ShowCounterManager(Login.second);
                    else if (command2 == 2)
                    ShowCashier(Login.second);
                    else if (command2 == 3)
                    ShowBossMenu(Login.second);
                }
            }
            else if (command2 == 4) {
                        system("cls");

                cout << "Choose your bank:" << endl;
                for (int i = 0; i < branches.size(); i++)
                    cout << i+1 << ")" << branches[i].getid() << endl;
                int id;
                cout << "Enter number of your choice:";
                cin >> id;
                cout << "1.Boss\n2.Cashier\n3.Counter Manager" << endl;
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
                ShowRegisterMenuWorker(branches[id-1], TypeName);
            }
        }
        else if (command == 3) {
                    system("cls");

                Bank *newBank = new Bank();
                branches.push_back(*newBank);
                system("cls");
        }else if (command == 4) {
            ShowBankServices();
        }
    }   

    while(true) {
        system("cls");
    }
    return 0;
}