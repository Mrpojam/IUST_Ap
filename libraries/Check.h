class Check {
    private:
    string CheckNumber;
    long long CheckAmount;
    public:
    string PayPerson;
    string TakePerson;
    bool done = false;
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



