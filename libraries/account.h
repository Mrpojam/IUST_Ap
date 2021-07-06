#include"person.h"

class Account {
    private:
    string AccountNumber;
    int AccountAmount;
    string FoundDate;
    public:
    Account(string _Number, int _Amount, string _Date) {
        this->AccountNumber = _Number;
        this->AccountAmount = _Amount;
        this->FoundDate = _Date;
    }
    
    static int Counter;

    string GetShaba () {
        return "IR"+ Id + AccountNumber;
    }

    void SetAccountNumber(int _Number) {
        this->AccountAmount = _Number;
    }

    void SetAccountAmount(int _Amount) {
        this->AccountAmount = _Amount;
    }

    void Deposit (int _Amount) {
        if (this->AccountAmount - _Amount < 0) {
            cout << "Not enough money!" << endl;
            return;
        }
        this->AccountAmount -= _Amount;
    }

    void Withdraw (int _Amount) {
        this->AccountAmount += _Amount;
    }
};

void CreateAcoount(Person person, int ammount) {
    string AccNum = "1000" + person.getNcode();
    // string DoundDate = ""
    Account NewAccount(AccNum, ammount, "");
    
}