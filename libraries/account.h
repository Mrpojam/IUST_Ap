#include"person.h"

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
     void setAccountNumber(string accn);
     void setAccountAmount(long long accam);
     void setFoundDate(string fdt);
    Account( string accn = "" , long long accam = 0 , string fdt = "") {
        setAccountNumber(string accn);
        setAccountAmount(long long accam);
        setFoundDate(string fdt);
    }
    string getAccountNumber();
    long long getAccountAmount();
    string getFoundDate();

    static int Counter;

    string GetShaba () {
        return "IR"+ Id + AccountNumber;
    }

    void SetAccountNumber(string _Number) {
        this->AccountAmount = _Number;
    }

    void SetAccountAmount(long long _Amount) {
        this->AccountAmount = _Amount;
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
void Account::SetAccountAmount(long long accam) {
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