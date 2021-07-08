#include"person.h"
#include"account.h"
#include"creditcard.h"
#include"Authentication.h"
#include"WriteData.h"

#include <filesystem>

class Bank {
    private:
    string BankName;
    string FoundDate;
    string Id;
    string BankAddress;
    vector<Account> BankAccounts;
    vector<Card> BankCards;
    vector<Person> BankPersons;
    vector<Worker> BankWorkers;
    Worker Boss;

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
        this->Id = Getstring;

        cout << "Found date: ";   
        cin >> GetString;
        keys.push_back("date");
        values.push_back(GetString);
        this->FoundDate = Getstring;
        
        cout << "Address: ";   
        cin >> GetString;
        keys.push_back("Add");
        values.push_back(GetString);
        this->BankAddress = Getstring;

        Worker *Boss = new Worker("Boss");
        this-> BankBoss = *Boss;

        fs::create_directories("./Files/Banks/" + this->id);

        string FileData = CreateData(keys, values);

        ofstream Myfile;
        Myfile.open("./Files/Banks" + this->id);
        Myfile << FileData;

        Account *Self = new Account();
        this->BankAccounts.push_back(*Self);
    }   
};