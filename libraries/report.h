void FindAccountsByCard(string cardnum) {
    vector<string> accounts;
    ifstream faccbycard;
    faccbycard.open("Files/Cards/" + cardnum);
    string card;
    faccbycard >> card;
    string account = ExtractData("account", card);
    ofstream report;

    report.open("Files/Reports", ios::app);
    cout << account << endl;
    report << account << endl;
    report << "---------" << endl;
    report.close();
}

void FindCardsByAccount (string accnum) {
    ifstream faccbycard;
    faccbycard.open("Files/Cards/All");
    string cardN;
    int cnt = 1;

    ofstream report;
    report.open("Files/Reports", ios::app);

    while (faccbycard >> cardN) {
        ifstream facc;
        facc.open("Files/Cards/" + cardN);
        string data;
        facc >> data;
        string accountnumber = ExtractData("account", data); 
        if (accountnumber == accnum) {
            cout << cnt++ << ")" << cardN << endl;
            report << cnt++ << ")" << cardN << endl; 
            report << "---------" << endl;
        }
        facc.close();
    }
    report.close();
        
}


void ShowUserInfo (Person User) {
    cout << "First Name: " << User.getFname() << endl;
    cout << "Last Name: " << User.getLname() << endl;
    cout << "National Code: " << User.getNcode() << endl;
    cout << "Home Address: " << User.getHaddress() << endl;
    cout << "Birthday: " << User.getBD() << endl;
    cout << "Email: " << User.getEmail() << endl;
}

void FindCardsByPerson (string ncode) {
    ifstream accounts;
        ofstream report;

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
        ofstream report;

    all.open("Files/Users/Credentials");
    string person;


    report.open("Files/Reports", ios::app);

    while (all >> person) {
         string username = "";
        int i = 0;
        for (; i < person.size(); i++) {
            if (person[i] == '#') break;
            username += person[i];
        }
        ifstream user;
        user.open("Files/Users/" + username);
        string data;
        user >> data;
        if (ExtractData("fname", data) == fname) {        
            cout << "First Name: " << ExtractData("fname", data) << endl;
            cout << "Last Name: " << ExtractData("lname", data) << endl;
            cout << "National Code: " << ExtractData("nCode", data) << endl;
            cout << "Home Address: " << ExtractData("homeAddrr", data) << endl;
            cout << "Birthday: " << ExtractData("birth", data) << endl;
            cout << "Email: " << ExtractData("email", data) << endl;
            

            report << "First Name: " << ExtractData("fname", data) << endl;
            report << "Last Name: " << ExtractData("lname", data) << endl;
            report << "National Code: " << ExtractData("nCode", data) << endl;
            report << "Home Address: " << ExtractData("homeAddrr", data) << endl;
            report << "Birthday: " << ExtractData("birth", data) << endl;
            report << "Email: " << ExtractData("email", data) << endl;
                        report << "--------------" << endl;

        }
    }
    report.close();
}

void FindPersonByMobile (string mob) {
    ifstream all;
    ofstream report;

    report.open("Files/Reports", ios::app);

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
        user.open("Files/Users/" + username);
        string data;
        user >> data;
        if (ExtractData("mobile", data) == mob) {        
            cout << "First Name: " << ExtractData("fname", data) << endl;
            cout << "Last Name: " << ExtractData("lname", data) << endl;
            cout << "National Code: " << ExtractData("nCode", data) << endl;
            cout << "Home Address: " << ExtractData("homeAddrr", data) << endl;
            cout << "Birthday: " << ExtractData("birth", data) << endl;
            cout << "Email: " << ExtractData("email", data) << endl;


            report << "First Name: " << ExtractData("fname", data) << endl;
            report << "Last Name: " << ExtractData("lname", data) << endl;
            report << "National Code: " << ExtractData("nCode", data) << endl;
            report << "Home Address: " << ExtractData("homeAddrr", data) << endl;
            report << "Birthday: " << ExtractData("birth", data) << endl;
            report << "Email: " << ExtractData("email", data) << endl;
            report << "--------------" << endl;

        }
    report.close();
    }
}

void FindPersonByAccount (string acc) {
    ifstream accfile;
    ofstream report;

    report.open("Files/Reports", ios::app);

    accfile.open("File/Accounts/" + acc);
    string accdata;
    accfile >> accdata;
    string ncode = ExtractData("nnum", accdata);
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


    report << "First Name: " << ExtractData("fname", data) << endl;
    report << "Last Name: " << ExtractData("lname", data) << endl;
    report << "National Code: " << ExtractData("nCode", data) << endl;
    report << "Home Address: " << ExtractData("homeAddrr", data) << endl;
    report << "Birthday: " << ExtractData("birth", data) << endl;
    report << "Email: " << ExtractData("email", data) << endl;
    report << "--------------" << endl;

    report.close();
}

void ShowTodaysBirthDay() {
    string year, month, day;
    cout << "Enter Year:";
    cin >> year;
    cout << "Enter Month:";
    cin >> month;
    cout << "Enter Day";
    cin >> day;
        ofstream report;

report.open("Files/Reports", ios::app);

    ifstream allUsers;
    allUsers.open("Files/Users/Credentials");
    string user;
    while (allUsers >> user) {
        string username = "";
        int i = 0;
        for (; i < user.size(); i++) {
            if (user[i] == '#') break;
            username += user[i];
        }
        ifstream userFile;
        userFile.open("Files/Users/" + username);
        string data;
        string birth = ExtractData("birth", data); 
        if (year + '-' + month + '-' + day == birth) {
            cout << "Firstname " << ExtractData("fname", data) << endl;
            cout << "Lastname " << ExtractData("lname", data) << endl;
            cout << "National Code " << ExtractData("nCode", data) << endl;
            cout << "--------------" << endl;
            report << "Firstname " << ExtractData("fname", data) << endl;
            report << "Lastname " << ExtractData("lname", data) << endl;
            report << "National Code " << ExtractData("nCode", data) << endl;
            report << "--------------" << endl;
        }  
    }
}

void ShowUsersWithHigherAmount (long long amount) {
    ifstream creds;
    ofstream report;
    report.open("Files/Reports", ios::app);

    creds.open("Files/Users/Credentials");
    string user;
    while (creds >> user) {
        long long allamount = 0;
        string username = "";
        int i = 0;
        for (; i < user.size(); i++) {
            if (user[i] == '#') break;
            username += user[i];
        }
        ifstream allacc;
        allacc.open("Files/Accounts/All");
        string acc;
        while (allacc >> acc) {
                string ncode = "";
            int i = 0;
            for (; i < acc.size(); i++) {
                if (acc[i] == '#') break;
                ncode += acc[i];
            }
            i++;
            if (ncode == username) {
                string accnum = acc.substr(i, acc.size());
                ifstream accfile;
                accfile.open("Files/Accounts/" + accnum);
                string data;
                accfile >> data;
                allamount += stol(ExtractData("amount", data), nullptr, 10);
                accfile.close();
            }   
        }
        if (allamount >= amount) {
            cout << "National Code : " << username << endl;
            report << "National Code : " << username << endl;
            report << "--------------" << endl;

        }
        allacc.close();
    }
    creds.close();
    report.close();
}