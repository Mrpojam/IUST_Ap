#include"person.h"
class Account {
    private:
    string AccountNumber;
    long long AccountAmount;
    string FoundDate;
    long long transactionamount;
    public:
    Account(string _Number, long long _Amount, string _Date) {
        this->AccountNumber = _Number;
        this->AccountAmount = _Amount;
        this->FoundDate = _Date;
    }
    Account() {
        return;
    }
     void setAccountNumber(string accn);
     void setAccountAmount(long long accam);
     void setFoundDate(string fdt);
     void ChangeAccount(Person person);
     
    string getAccountNumber();
    long long getAccountAmount();
    string getFoundDate();
    
    static int Counter;

    string GetShaba () {
        return "IR0000" + AccountNumber;
    }

    void Deposit (long long _Amount) {
        if (this->AccountAmount - _Amount < 0) {
            cout << "Not enough money!" << endl;
            return;
        }
        this->AccountAmount -= _Amount;
    }
    
    void Withdraw (long long _Amount) {
        this->AccountAmount += _Amount;
    }

    void UpdateFile(string nCode);
};

void transfermoney( Account *AccountNumber1 , Account *AccountNumber2 , long long transactionamount, string PayCode, string TakeCode ) {
    if ( AccountNumber1->getAccountAmount() < transactionamount ) {
        cout<< "Dont Have Enough Money!!!" <<endl;
    }
    else {
        AccountNumber1->Deposit(transactionamount);
        AccountNumber2->Withdraw(transactionamount);
        AccountNumber1->UpdateFile(PayCode);
        AccountNumber2->UpdateFile(TakeCode);
        cout<< "The Transaction was successful !!!" <<endl;
    }
}

void Account::setAccountNumber(string accn) {
    AccountNumber = accn;
}
void Account::setAccountAmount(long long accam) {
    AccountAmount = accam;
}
void Account::setFoundDate(string fdt) {
    FoundDate = fdt;
}
string Account::getAccountNumber() {
    return AccountNumber;
}
long long Account::getAccountAmount() {
    return AccountAmount;
}
string Account::getFoundDate() {
    return FoundDate;
}

void ShowAccountMenu (Person person) {
    Account *NewAccount = new Account();
    string GetString;
    long long Getlonglong;
    vector<string> JsonKeys;
    vector<string> JsonValues;

    JsonKeys.push_back("nnum");
    JsonValues.push_back(person.getNcode());

    cout << "Account Number:";
    cin >> GetString;
    JsonKeys.push_back("accn");
    JsonValues.push_back(GetString);
    NewAccount->setAccountNumber(GetString);

    cout << "Account Amount:";
    cin >> Getlonglong;
    JsonKeys.push_back("accam");
    JsonValues.push_back(to_string(Getlonglong));
    NewAccount->setAccountAmount(Getlonglong);

    cout << "Found Date:";
    cin >> GetString;
    JsonKeys.push_back("fdt");
    JsonValues.push_back(GetString);
    NewAccount->setFoundDate(GetString);

    string filedata = CreateData(JsonKeys, JsonValues);
    string fileadress = "Files/Accounts/" + NewAccount->getAccountNumber();
    ofstream Fin;
    Fin.open(fileadress);
    Fin << filedata;
    Fin.close();

    ofstream AllAcc;
    AllAcc.open("Files/Accounts/All", ios::app);
    AllAcc << person.getNcode() << "#" << NewAccount->getAccountNumber() << endl;
    AllAcc.close();
}

void Account::ChangeAccount(Person person) {
    cout<<"Please select to change each section."<<endl;
    int aq ;
    cout<<"1.Change Account Number."<<endl<<"2.Change Account Amount."<<endl<<"3.Back."<<endl;
    cin>>aq;
    long long Getlonglong;
    string  GetString;
    if (aq==1) {
        cout << "Account Number:";
        cin >> GetString;
        setAccountNumber(GetString);
        cout<<"Updated Successfully!!"<<endl;
    }
    if (aq==2) {
        cout << "Account Amount:";
        cin >> Getlonglong;
        setAccountAmount(Getlonglong);
        cout<<"Updated Successfully!!"<<endl;
    }
    if (aq==3) {
        return;
    }
    else {
        cout<<"Error!!!"<<endl;
    }
    UpdateFile(person.getNcode());
}

void Account::UpdateFile(string Ncode) {
     vector<string> JsonKeys;
    vector<string> JsonValues;

    JsonKeys.push_back("nnum");
    JsonValues.push_back(Ncode);

    JsonKeys.push_back("accn");
    JsonValues.push_back(this->AccountNumber);

    JsonKeys.push_back("accam");
    JsonValues.push_back(to_string(this->AccountAmount));
    
    JsonKeys.push_back("fdt");
    JsonValues.push_back(this->FoundDate);

    string filedata = CreateData(JsonKeys, JsonValues);
    string fileadress = "Files/Accounts/" + this->getAccountNumber();
    ofstream Fin;
    Fin.open(fileadress);
    Fin << filedata;
    Fin.close();

    ofstream AllAcc;
    AllAcc.open("Files/Accounts/All", ios::app);
    AllAcc << Ncode << "#" << this->getAccountNumber() << endl;
    AllAcc.close();
}

vector <Account> ShowUserAccounts (Person User) {
    string nCode = User.getNcode();
    vector<Account> ret;
    ifstream Acc;
    Acc.open("Files/Accounts/All");
    string card;
    while (Acc >> card) {
        int index = 0;
        string number = "";
        for (int i = 0; i < card.size(); i++) {
            if (card[i] == '#')
                break;
            number += card[i];
            index++;
        }
        index++;
        if (nCode == number) {
            string AccNum = "";
            for (int i = index; i < card.size(); i++)
                AccNum += card[i];
            ifstream Accounts;
            Accounts.open("Files/Accounts/" + AccNum);
            string data;
            Accounts >> data;
            Account newAccount;
            
            newAccount.setAccountNumber(ExtractData("accn", data));
            newAccount.setAccountAmount(stol(ExtractData("accam", data), nullptr, 10));
            newAccount.setFoundDate(ExtractData("fdt", data));

            ret.push_back(newAccount);
        }
    }
    return ret;
}