vector<string> FindAccountsByCard(string cardnum) {
    vector<srting> accounts;
    ifstream faccbycard;
    faccbycard.open("Files/Cards/All");
    string abbasbouazar;
    while ( faccbycard >> abbasbouazar ) {
        ifstream facc;
        facc.open("Files/Cards/" + abbasbouazar);
        string data;
        facc >> data;
        string accountnumber = ExtractData("account", data); 
        accounts.push_back(accountnumber);  
        facc.close();
    }
    return accounts;
}

vector<string> FindCardsByAccount (string accnum) {
    vector<srting> cards;
    ifstream faccbycard;
    faccbycard.open("Files/Cards/All");
    string abbasbouazar;
    while (faccbycard >> abbasbouazar) {
        ifstream facc;
        facc.open("Files/Cards/" + abbasbouazar);
        string data;
        facc >> data;
        string accountnumber = ExtractData("account", data); 
        if (accountnumber == accnum)
            cards.push_back(ExtractData("cardn", data));  
        facc.close();
    }
    return cards;
}