class Check {
    private:
    string CheckNumber;
    long long CheckAmount;
    public:
     Account PayPerson;
    Account TakePerson;
   
    void acceptcheck();
    void setchecknumber(string checknum);
    string getchecknumber();
    void setcheckamount(long long checkamnt);
    long long getcheckamount();
   
};
void Check::setchecknumber(string checknum) {
    CheckNumber = checknum;
}
string Check::getchecknumber() {
    return CheckNumber;
}
void Check::setcheckamount(long long checkamnt) {
    CheckAmount = checkamnt;
}
long long Check::getcheckamount() {
    return CheckAmount; 
}
void Check::acceptcheck() {
    if ( PayPerson.getAccountAmount() < CheckAmount ) {
        cout<< " Dont Have Enough Money!!" <<endl<< "Check Shoma Bargasht Khahad Khord!!! -_-" <<endl;
    }
    else {
        PayPerson.Deposit(CheckAmount);
        TakePerson.Withdraw(CheckAmount);
        cout<< " Check Ba Movafaghiyat Beh Hesab Khabandeh Shod! +_+" <<endl;
    }
}

/*Check check;
ifstream CheckFile;
CheckFile.open("Files/Checks/" + checknum);
string GetString;
CheckFile >> GetString;
cout << GetString << endl;
check.setchecknumber(ExtractData("checknum", GetString));
check.setcheckamount(stol(ExtractData("checkamnt", GetString), nullptr, 10));
check.PayPerson.setAccountNumber(ExtractData("accn", GetString));
check.TakePerson.setAccountNumber(ExtractData("accn", GetString));
CheckFile.close();*/

void CreateCheck () {
    Check NewCheck;
    string GetString;
    long long Getlonglong;
    vector<string> keys;
    vector<string> values;

    cout << "Check Number:";
    cin >> GetString;
    keys.push_back("checknum");
    values.push_back(GetString);
    NewCheck.setchecknumber(GetString);

    cout << "Check Amount:";
    cin >> Getlonglong;
    keys.push_back("checkamnt");
    values.push_back(to_string(Getlonglong));
    NewCheck.setcheckamount(Getlonglong);

    cout << "Pay Person Account Number:";
    cin >> GetString;
    keys.push_back("accn");
    values.push_back(GetString);
    NewCheck.PayPerson.setAccountNumber(GetString);

    cout << "Take Person Account Number:";
    cin >> GetString;
    keys.push_back("accn");
    values.push_back(GetString);
    NewCheck.TakePerson.setAccountNumber(GetString);

     string FileData = CreateData(keys, values);

    string FileAdress = "Files/Checks/" + NewCheck.getchecknumber();
    
    ofstream MyCheck;
    MyCheck.open(FileAdress);
    MyCheck << FileData;
    MyCheck.close();
}


