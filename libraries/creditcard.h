class Card {
    string Cardnumber;
    string Cvv2;
    string ExpireDate;
    string PassCode1;
    string PassCode2;
    public:
    Card (string num, string cvv, string ex, string p1, string p2) {
        this->Cardnumber = num;
        this->Cvv2 = cvv;
        this->ExpireDate = ex;
        this->PassCode1 = p1;
        this->PassCode2 = p2;
    }
    Card() {
        return;
    };
    void setCardN(string cardn);
    void setCVV2(string cvv2);
    void setExpireD(string expired);
    void setPass1(string pass1);
    void setPass2(string pass2);
   
    string getCardN();
    string getCVV2();
    string getExpireD();
    string getPass1();
    string getPass2();

 
};


void Card::setCardN(string cardn) {
    Cardnumber = cardn;
}
void Card::setCVV2(string cvv2) {
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
string Card::getCardN() {
    return Cardnumber;
}
string Card::getCVV2() {
    return Cvv2;
}
string Card::getExpireD() {
    return ExpireDate;
}
string Card::getPass1() {
    return PassCode1;
}
string Card::getPass2() {
    return PassCode2;
}



void ShowCardMenu () {
    Card NewCard;
    string GetString;
    vector<string> JsonKeys;
    vector<string> JsonValues;

    cout << "Card Number:";
    cin >> GetString;
    JsonKeys.push_back("cardn");
    JsonValues.push_back(GetString);
    NewCard.setCardN(GetString);

    cout << "CVV2:";
    cin >> GetString;
    JsonKeys.push_back("cvv2");
    JsonValues.push_back(GetString);
    NewCard.setCVV2(GetString);

    cout << "Expire Date:";
    cin >> GetString;
    JsonKeys.push_back("expired");
    JsonValues.push_back(GetString);
    NewCard.setExpireD(GetString);

     cout << "Pass Code 1 :";
    cin >> GetString;
    JsonKeys.push_back("pass1");
    JsonValues.push_back(GetString);
    NewCard.setPass1(GetString);

     cout << "Pass Code 2 :";
    cin >> GetString;
    JsonKeys.push_back("pass2");
    JsonValues.push_back(GetString);
    NewCard.setPass2(GetString);

    string file_d = CreateData(JsonKeys, JsonValues);
    string file_a = "Files/Users/" + NewCard.getCardN();
    ofstream fin;
    fin.open(file_a);
    fin << file_d;
    fin.close();
}