class Card {
    string Cardnumber;
    int Cvv2;
    string ExpireDate;
    int PassCode1;
    int PassCode2;
    public:
    Card (string num, int cvv, string ex, int p1, int p2) {
        this->Cardnumber = num;
        this->Cvv2 = cvv;
        this->ExpireDate = ex;
        this->PassCode1 = p1;
        this->PassCode2 = p2;
    }
    void setCardN(string cardn);
    void setCVV2(int cvv2);
    void setExpireD(string expired);
    void setPass1(int pass1);
    void setPass2(int pass2);
    Card( string cardn = "" , int cvv2 = 0 , string expired = "" , int pass1 = 0 , int pass2 = 0) {
    setCardN(cardn);
    setCVV2(cvv2);
    setExpireD(expired);
    setPass1(pass1);
    setPass2(pass2);
    }
    string getCardN();
    int getCVV2();
    string getExpireD();
    int getPass1();
    int getPass2();

    void SetPassCode1 (int p1) {
        this->PassCode1 = p1;
    }

    void SetPassCode2 (int p2) {
        this->PassCode2 = p2;
    }
};
void Card::setCardN(string cardn) {
    Cardnumber = cardn;
}
void Card::setCVV2(int cvv2) {
    Cvv2 = cvv2;
}
void Card::setExpireD(string expired) {
    ExpireDate = expired;
}
void Card::setPass1(string pass1) {
    PassCode1 = pass1;
}
void Card::setPass2(string pass2) {
    PassCode2 = pass2;
}
string Account::getCardN() {
    return Cardnumber;
}
int Account::getCVV2() {
    return Cvv2;
}
string Account::getExpireD() {
    return ExpireDate;
}
int Account::getPass1() {
    return PassCode1;
}
int Account::getPass2() {
    return PassCode2;
}