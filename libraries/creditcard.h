class Card {
    int Cardnumber;
    short Cvv2;
    string ExpireDate;
    int PassCode1;
    int PassCode2;
    public:
    Card (int num, int cvv, string ex, int p1, int p2) {
        this->Cardnumber = num;
        this->Cvv2 = cvv;
        this->ExpireDate = ex;
        this->PassCode1 = p1;
        this->PassCode2 = p2;
    }

    void SetPassCode1 (int p1) {
        this->PassCode1 = p1;
    }

    void SetPassCode2 (int p2) {
        this->PassCode2 = p2;
    }

}