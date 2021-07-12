#include"account.h"
#include"bank.h"
class Loan {
    private:
    int situation;
    long long loanamount;
    public:
    void situationprocess(int stn);
    void setcodebranch(string codebranch);
    void setaccountnum(string accountnum);
    void setloanamount(long long loanamt);
    void varizvam(longlong lamount);
    long long getloanamount();
    string getcodebranch();
    string getaccountnum();

    Loan() {
        return;
    }

    varizvam();
    getloanamount();
    getcodebranch();
    getaccountnum();
};

void Loan::situationprocess(int stn) {
    situation = stn;
    if (situation == 0) {
        cout<< "Montazer Sabt tavasot Masoul Bajeh!" <<endl;
    }
    else if (situation == 1) {
        cout<< "Sabt Shode Tavasot Masoul Bajeh va Montazer Ghaboul Raeis Shoebeh!" <<endl;
    }
    else if (situation == 2) {
        Cout<< "Ghaboul Shode tavasot Raeis Shoebeh!" <<endl;
        varizvam();
    }
    else if (situation != 0 || situation != 1 || situation != 2) {
        cout<< "Error!!!" <<endl;
    }
}

void Loan::varizvam(Bank bank, Account dist) {

    bank.Self.Depostit(loanamount);
    dist.Withdraw(loanamount);
    cout<< "Vam Variz Shod!" <<endl;
     
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

/*Loan loan;
ifstream LoanFile;
LoanFile.open("Files/Loans/" + codebranch + accountnum);
string GetString;
LoanFile >> GetString;
cout << GetString << endl;
loan.setcodebranch(ExtractData("codebranch", GetString));
loan.setaccountnum(ExtractData("accountnum", GetString));
loan.setloanamount(stol(ExtractData("loanamount", GetString), nullptr, 10));
loan.situationprocess(stoi(ExtractData("stn", GetString), nullptr, 10));
LoanFile.close();*/

void CreateLoan() {
    Loan NewLoan;
    string GetString;
    long long Getlonglong;
    int Getint;
    vector<string> keys;
    vector<string> values;

    cout << "Branch Id:";
    cin >> GetString;
    keys.push_back("codebranch");
    values.push_back(GetString);
    NewLoan.setcodebranch(GetString);

    cout << "Account Number:";
    cin >> GetString;
    keys.push_back("accountnum");
    values.push_back(GetString);
    NewLoan.setaccountnum(GetString);

    cout << "Loan Amount:";
    cin >> Getlonglong;
    keys.push_back("loanamount");
    values.push_back(to_string(Getlonglong));
    NewLoan.setloanamount(Getlonglong);

    keys.push_back("0");
    values.push_back(Getint);
    NewLoan.situationprocess(Getint);

    string FileData = CreateData(keys, values);

    string FileAdress = "Files/Loans/" + NewLoan.getcodebranch() + NewLoan.getaccountnum();
    
    ofstream MyLoan;
    MyLoan.open(FileAdress);
    MyLoan << FileData;
    MyLoan.close();
}
