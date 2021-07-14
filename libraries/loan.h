class Loan {
    private:
    int situation;
    long long loanamount;
    string AccountNumber;
    string Id;
    public:
    void varizvam();
    void setcodebranch(string codebranch);
    void setaccountnum(string accountnum);
    void setloanamount(long long loanamt);
    long long getloanamount();
    string getcodebranch();
    string getaccountnum();
    void update();
    Loan() {
        situation = 0;
        return;
    }

    int getSit() {
        return situation;
    }
    void setsit (int sit) {
        situation = sit;
    }
};

void Loan::update() {
    if (situation < 2) situation++;
    if (situation == 2) varizvam();
    ofstream LoanFile;
    LoanFile.open("Files/Loans/" + (this->getcodebranch() + this->getaccountnum()));
    vector<string> keys;
    vector<string> values;

    keys.push_back("codebranch");
    values.push_back(this->getcodebranch());
    
    keys.push_back("accountnum");
    values.push_back(this->getaccountnum());
    
    keys.push_back("loanamount");
    values.push_back(to_string(this->getloanamount()));
    
     keys.push_back("sit");
    values.push_back(to_string(situation));
   
    string FileData = CreateData(keys, values);
    LoanFile << FileData;
    LoanFile.close();
}

void Loan::varizvam() {
    Account bank;
    Account dist;

    ifstream BankFile;
    BankFile.open("Files/Accounts/" + ("1000" + this->getcodebranch()));
    string GetString;
    BankFile >> GetString;
    bank.setAccountNumber(ExtractData("accn", GetString));
    string am = ExtractData("accam", GetString);
    bank.setAccountAmount(stol(am, nullptr, 10));
    bank.setFoundDate(ExtractData("fdt", GetString));
    BankFile.close();

    bank.Deposit(loanamount);
    bank.UpdateFile(ExtractData("nnum", GetString));

    ifstream DtisFile;
    DtisFile.open("Files/Accounts/"  + this->getaccountnum());
    DtisFile >> GetString;
    dist.setAccountNumber(ExtractData("accn", GetString));
    cout << "DEBUG" << endl;
    dist.setAccountAmount(stol(ExtractData("accam", GetString), nullptr, 10));
    dist.setFoundDate(ExtractData("fdt", GetString));
    DtisFile.close();

    dist.Withdraw(loanamount);

    dist.UpdateFile(ExtractData("nnum", GetString));

}
void Loan::setcodebranch(string codebranch) {
    Id = codebranch;
}
void Loan::setaccountnum(string accountnum) {
    AccountNumber = accountnum;
}
void Loan::setloanamount(long long loanamt) {
    loanamount = loanamt;
}
long long Loan::getloanamount() {
    return loanamount;
}
string Loan::getcodebranch() {
    return Id;
}
string Loan::getaccountnum() {
    return AccountNumber;
}

void CreateLoan(string BankID, string AccountNum) {
    Loan NewLoan;
    string GetString;
    long long Getlonglong;
    int Getint;
    vector<string> keys;
    vector<string> values;

    keys.push_back("codebranch");
    values.push_back(BankID);
    NewLoan.setcodebranch(BankID);

    keys.push_back("accountnum");
    values.push_back(AccountNum);
    NewLoan.setaccountnum(AccountNum);

    cout << "Loan Amount:";
    cin >> Getlonglong;
    keys.push_back("loanamount");
    values.push_back(to_string(Getlonglong));
    NewLoan.setloanamount(Getlonglong);

     keys.push_back("sit");
    values.push_back("0");
   
    string FileData = CreateData(keys, values);

    string FileAdress = "Files/Loans/" + NewLoan.getcodebranch() + NewLoan.getaccountnum();
    ofstream MyLoan;
    MyLoan.open(FileAdress);
    MyLoan << FileData;
    MyLoan.close();

    ofstream AllLoans;
    AllLoans.open("Files/Loans/All", ios::app);
    AllLoans << NewLoan.getcodebranch() + NewLoan.getaccountnum() << endl;
    AllLoans.close();
}
