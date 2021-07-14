#include<bits/stdc++.h>

using namespace std;

#include"WriteData.h"
#include"account.h"
#include"creditcard.h"
#include"report.h"
#include"Check.h"
class Bank {
    private:
    string BankName;
    string FoundDate;
    string Id;
    string BankAddress;
    vector<Account> BankAccounts;
    Worker Boss();
    Account Self;
    public:
    Bank(string type) {
        if (type == "CreateNULL");
            return;
    }
    Bank();
    void setfoundDate(string fd);
    void setid(string idnum);
    void setbankaddress(string baddress);

    Bank(string fd  ,string idnum  ,string baddress ) {
        setfoundDate(fd);
        setid(idnum);
        setbankaddress(baddress);
    }
    string getbankname();
    string getfoundDate();
    string getid();
    string getbankaddress();
  
};

void ShowRegisterMenuWorker (Bank bank, string type);

Bank::Bank() {
        
        vector<string> keys;
        vector<string> values;
        string GetString;
        
        this->BankName = "Sazandegan";
        
        cout << "Enter Branch Code: ";   
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
        Myfile.open("./Files/Banks/" + this->Id);
        Myfile << FileData;

        long long Getlonglong;
        vector<string> JsonKeys;
        vector<string> JsonValues;


        JsonKeys.push_back("nnum");
        JsonValues.push_back("Bank"+this->getid());



        JsonKeys.push_back("accn");
        JsonValues.push_back("1000" + this->getid());
        Self.setAccountNumber("1000" + this->getid());


        JsonKeys.push_back("accam");
        JsonValues.push_back("1000000000");
        Self.setAccountAmount(1000000000);


        JsonKeys.push_back("fdt");
        JsonValues.push_back(this->FoundDate);
        Self.setFoundDate(this->FoundDate);


        string filedata = CreateData(JsonKeys, JsonValues);
        string fileadress = "Files/Accounts/" + ("1000" + this->getid());
        ofstream Fin;
        Fin.open(fileadress);
        Fin << filedata;
        Fin.close();
        vector<string> acckeys;
        vector<string> accvalues;


        acckeys.push_back("num");
        acckeys.push_back("amount");
        acckeys.push_back("date");


        accvalues.push_back(Self.getAccountNumber());
        accvalues.push_back(to_string(Self.getAccountAmount()));
        accvalues.push_back(Self.getFoundDate());

        system("cls");

        cout << "Register Boss:" << endl;

        ShowRegisterMenuWorker(*this, "boss");

        ofstream BankList;
        BankList.open("Files/Banks/BankList", ios::app);
        BankList << this->getid() << endl;
        BankList.close();
    }

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