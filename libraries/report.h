void FindAccountsByCard(string cardnum) {
    vector<srting> accounts;
    ifstream faccbycard;
    faccbycard.open("Files/Cards/" + cardnum);
    string card;
    faccbycard >> card;
    string account = ExtractData("account", card);
    cout << account << endl;
    
}

void FindCardsByAccount (string accnum) {
    ifstream faccbycard;
    faccbycard.open("Files/Cards/All");
    string abbasbouazar;
    int cnt = 1;
    while (faccbycard >> abbasbouazar) {
        ifstream facc;
        facc.open("Files/Cards/" + abbasbouazar);
        string data;
        facc >> data;
        string accountnumber = ExtractData("account", data); 
        if (accountnumber == accnum)
            cout << cnt++ << ")" << abbasbouazar;
        facc.close();
    }
}

void ShowUserInfo (Person User) {
    cout << "First Name: " << User.getFname() << endl;
    cout << "Last Name: " << User.getLname() << endl;
    cout << "National Code: " << User.Ncode() << endl;
    cout << "Home Address: " << User.Haddress() << endl;
    cout << "Birthday: " << User.getBD() << endl;
    cout << "Email: " << User.getEmail() << endl;
}

void FindCardsByPerson (string ncode) {
    ifstream accounts;
    accounts.open("Files/Accounts/All");
    string acc;
    while (accounts >> acc) {
         string num = "";
        int i = 0;
        for (; i < acc.size(); i++) {
            if (acc[i] == '#') break;
            num += acc[i];
        }
        FindCardsByAccount(num);
    }
}

void FindPersonByName (string fname) {
    ifstream all;
    all.open("Files/Users/Credentials");
    string person;
    while (all >> person) {
         string username = "";
        int i = 0;
        for (; i < person.size(); i++) {
            if (person[i] == '#') break;
            username += person[i];
        }
        ifstream user;
        user.open("Files/Users/" + user);
        string data;
        user >> data;
        if (ExtractData("fname", data) == fname) {        
            cout << "First Name: " << ExtractData("fname", data) << endl;
            cout << "Last Name: " << ExtractData("lname", data) << endl;
            cout << "National Code: " << ExtractData("nCode", data) << endl;
            cout << "Home Address: " << ExtractData("homeAddrr", data) << endl;
            cout << "Birthday: " << ExtractData("birth", data) << endl;
            cout << "Email: " << ExtractData("email", data) << endl;
        }
    }
}

void FindPersonByMobile (string mob) {
    ifstream all;
    all.open("Files/Users/Credentials");
    string person;
    while (all >> person) {
         string username = "";
        int i = 0;
        for (; i < person.size(); i++) {
            if (person[i] == '#') break;
            username += person[i];
        }
        ifstream user;
        user.open("Files/Users/" + user);
        string data;
        user >> data;
        if (ExtractData("mobile", data) == mob) {        
            cout << "First Name: " << ExtractData("fname", data) << endl;
            cout << "Last Name: " << ExtractData("lname", data) << endl;
            cout << "National Code: " << ExtractData("nCode", data) << endl;
            cout << "Home Address: " << ExtractData("homeAddrr", data) << endl;
            cout << "Birthday: " << ExtractData("birth", data) << endl;
            cout << "Email: " << ExtractData("email", data) << endl;
        }
    
}

void FindPersonByAccount (string acc) {
    ifstream accfile;
    accfile.open("File/Accounts/" + acc);
    string accdata;
    accfile >> accdata;
    string ncode = ExtreactData("nnum", accdata);
    accfile.close();
    ifstream user;
    user.open("Files/Users/" + ncode);
    string data;
    user >> data;

    cout << "First Name: " << ExtractData("fname", data) << endl;
    cout << "Last Name: " << ExtractData("lname", data) << endl;
    cout << "National Code: " << ExtractData("nCode", data) << endl;
    cout << "Home Address: " << ExtractData("homeAddrr", data) << endl;
    cout << "Birthday: " << ExtractData("birth", data) << endl;
    cout << "Email: " << ExtractData("email", data) << endl;
}

ShowTodaysBirthDay() {
    string year, month, day;
    cout << "Enter Year:";
    cin >> year;
    cout << "Enter Month:";
    cin >> month;
    cout << "Enter Day";
    cin >> day;
    ifstream allUsers;
    allUsers.open("Files/Users/Credentials");
    string user;
    while (allUsers >> user) {
        string username = "";
        int i = 0;
        for (; i < person.size(); i++) {
            if (person[i] == '#') break;
            username += person[i];
        }
        ifstream userFile
        userFile.open("Files/Users/" + username);
        string data;
        string birth = ExtractData("birth", data);   
    }
}