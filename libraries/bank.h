class Bank {
    private:
    string BankName;
    string FoundDate;
    int Id;
    string BankAddress;
    vector<Account> BankAccounts;
    vector<Cards> BankCards;
    vector<Person> BankPersons;
    vector<Worker> BankWorkers;

    public:
    Bank(string _Name, string _Date, int _Id, string _Address) {
        this->BankName = _Name;
        this->FoundDate = _Date;
        this->Id = _id;
        this->BankAdress = _Adress;
        Account *Self = new Account();
        this->BankAccounts.push_back(*Self);
    }
}