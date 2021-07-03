class Account {
    private:
    int AccountNumber;
    int AccountAmount;
    string FoundDate;
    private:
    Account(int _Number, int _Amount, string _Date) {
        this->AccountNumber = _Number;
        this->AccountAmount = _Amount;
        this->FoundDate = _Date;
    }
    
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
}