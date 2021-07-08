#include<bits/stdc++.h>

using namespace std;

#include"WriteData.h"
// #include"person.h"
#include"account.h"
#include"creditcard.h"
// #include"Authentication.h"


class Bank {
    private:
    string BankName;
    string FoundDate;
    string Id;
    string BankAddress;
    vector<Account> BankAccounts;
    // vector<Card> BankCards;
    // vector<Person> BankPersons;
    // vector<Worker> BankWorkers;
    Worker Boss();
    // Account Self;
    public:
    Bank() {
        
        vector<string> keys;
        vector<string> values;
        string GetString;
        
        this->BankName = "Sazandegan";
        
        cout << "Enter Branch code: ";   
        cin >> GetString;
        keys.push_back("id");
        values.push_back(GetString);
        this->Id = GetString;

        cout << "Found date: ";   
        cin >> GetString;
        keys.push_back("date");
        values.push_back(GetString);
        this->FoundDate = GetString;
        
        cout << "Address: ";   
        cin >> GetString;
        keys.push_back("Add");
        values.push_back(GetString);
        this->BankAddress = GetString;

       
        string FileData = CreateData(keys, values);

        ofstream Myfile;
        Myfile.open("./Files/Banks" + this->Id);
        Myfile << FileData;

        Account *Self = new Account();

        Self->setAccountAmount(1000000000);
        Self->setAccountNumber("100" + this->Id);
        Self->setFoundDate(this->FoundDate);

        vector<string> acckeys;
        vector<string> accvalues;

        acckeys.push_back("num");
        acckeys.push_back("amount");
        acckeys.push_back("date");

        accvalues.push_back(Self->getAccountNumber());
        accvalues.push_back(to_string(Self->getAccountAmount()));
        accvalues.push_back(Self->getFoundDate());

        this->BankAccounts.push_back(*Self);

        
    }
    void setfoundDate(string fd);
    void setid(string idnum);
    void setbankaddress(string baddress);

    Bank(string fd = "" ,string idnum = "" ,string baddress = "") {
        setfoundDate(fd);
        setid(idnum);
        setbankaddress(baddress);
    }
    string getbankname();
    string getfoundDate();
    string getid();
    string getbankaddress();
  
};

void Bank::setfoundDate(string fd) {
    FoundDate = fd;
}
void Bank::setid(string idnum) {
    Id = idnum;
}
void Bank::setbankaddress(string baddress) {
    BankAddress = baddress;
}
string Bank::getbankname() {
    return BankName;
}
string Bank::getfoundDate() {
    return FoundDate;
}
string Bank::getid() {
    return Id;
}
string Bank::getbankaddress() {
    return BankAddress;
}