
class Account {
    private:
    string AccountNumber;
    long long AccountAmount;
    string FoundDate;
    public:
    Account(string _Number, long long _Amount, string _Date) {
        this->AccountNumber = _Number;
        this->AccountAmount = _Amount;
        this->FoundDate = _Date;
    }
    Account();
     void setAccountNumber(string accn);
     void setAccountAmount(long long accam);
     void setFoundDate(string fdt);
     void ChangeAccount();
    
    string getAccountNumber();
    long long getAccountAmount();
    string getFoundDate();

    static int Counter;

    string GetShaba () {
        return "IR" + AccountNumber;
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
};

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
void CreateAcoount(Person person, long long ammount) {
    string AccNum = "1000" + person.getNcode();
    // string DoundDate = ""
    Account NewAccount(AccNum, ammount, "");
    
}

void ShowAccountMenu () {
    Account NewAccount;
    string GetString;
    long long Getlonglong;
    vector<string> JsonKeys;
    vector<string> JsonValues;

    cout << "Account Number:";
    cin >> GetString;
    JsonKeys.push_back("accn");
    JsonValues.push_back(GetString);
    NewAccount.setAccountNumber(GetString);

    cout << "Account Amount:";
    cin >> Getlonglong;
    JsonKeys.push_back("accam");
    JsonValues.push_back(to_string(Getlonglong));
    NewAccount.setAccountAmount(Getlonglong);

    cout << "Found Date:";
    cin >> GetString;
    JsonKeys.push_back("fdt");
    JsonValues.push_back(GetString);
    NewAccount.setFoundDate(GetString);


    string filedata = CreateData(JsonKeys, JsonValues);
    string fileadress = "Files/Users/" + NewAccount.getAccountNumber();
    ofstream Fin;
    Fin.open(fileadress);
    Fin << filedata;
    Fin.close();
}
void Account::ChangeAccount() {
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
}