vector<Bank> branches;
vector<Loan> loans;


void UpdateBanks () {

    branches.clear();

    ifstream BankList;
    BankList.open("Files/Banks/BankList");

    string BankId;
    while (BankList >> BankId) {
        ifstream bank;
        bank.open("Files/Banks/" + BankId);
        string data;
        Bank newBank ("CreateNULL");
        bank >> data;
        newBank.setid(ExtractData("id", data));
        newBank.setfoundDate(ExtractData("id", data));
        newBank.setbankaddress(ExtractData("Add", data));
        branches.push_back(newBank);
    }
    BankList.close();
  
}

void UpdateLoans() {

    loans.clear();

    ifstream LoanList;
    LoanList.open("Files/Loans/All");

    string loan;
    while (LoanList >> loan) {
        Loan newLoan;
        ifstream loanfile;
        loanfile.open("Files/Loans/" + loan);
        string data;
        loanfile >> data;
        
        newLoan.setcodebranch(ExtractData("codebranch", data));
        newLoan.setaccountnum(ExtractData("accountnum", data));
        newLoan.setloanamount(stol(ExtractData("loanamount", data), nullptr, 10));
        newLoan.setsit(stoi(ExtractData("sit", data)));
        loans.push_back(newLoan);
        loanfile.close();
    }

    LoanList.close();
}