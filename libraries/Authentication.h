#include"bank.h"
void ShowUserMenu (Person User);

pair<bool, Person> ShowLoginMenu () {
   system("cls");
    cout << "User National Code : ";
    string UserName;
    cin >> UserName;
    cout << "User Password : ";
    string UserPass;
    cin >> UserPass;
    ifstream Myfile;
    Myfile.open("Files/Users/Credentials");
    string credentials;
    bool exists = false;
    Person User;
    while (Myfile >> credentials) {
        string username = "";
        int i = 0;
        for (; i < credentials.size(); i++) {
            if (credentials[i] == '#') break;
            username += credentials[i];
        }
        i++;
        if (username == UserName) {
            exists = true;
            string password = "";
            for (; i < credentials.size(); i++)
                password += credentials[i];
            if (password != UserPass) {
                cout << "Password does not match." << endl;
                cout << "Enter Something to continue:";
                string c;
                cin >> c;
                return {false, User};
            }
            else {
                ifstream UserFile;
                UserFile.open("Files/Users/" + UserName);
                string GetString;
                UserFile >> GetString;
                cout << GetString << endl;
                User.setNcode(ExtractData("nCode", GetString));
                User.setFname(ExtractData("fName", GetString));
                User.setLname(ExtractData("lName", GetString));
                User.setBCnum(ExtractData("BirthCerNum", GetString));
                User.setWaddress(ExtractData("workAddrr", GetString));
                User.setHaddress(ExtractData("homeAddrr", GetString));
                User.setMnum(ExtractData("mobile", GetString));
                User.setPnum(ExtractData("phone", GetString));
                User.setFathname(ExtractData("father", GetString));
                User.setBD(ExtractData("birth", GetString));
                User.setEmail(ExtractData("email", GetString));
                UserFile.close();

                return {true, User};
            }
        }
    }
    if (!exists)
        cout << "User does not exists." << endl;
    return {false, User};
}

void ShowRegisterMenu () {
    system("cls");
    Person NewAccount;
    string GetString;
    vector<string> keys;
    vector<string> values;

    cout << "First Name:";
    cin >> GetString;
    keys.push_back("fName");
    values.push_back(GetString);
    NewAccount.setFname(GetString);

    cout << "Last Name:";
    cin >> GetString;
    keys.push_back("lName");
    values.push_back(GetString);
    NewAccount.setLname(GetString);

    cout << "National Code:";
    cin >> GetString;
    keys.push_back("nCode");
    values.push_back(GetString);
    NewAccount.setNcode(GetString);

    cout << "Birth Certificate Number:";
    cin >> GetString;
    keys.push_back("BirthCerNum");
    values.push_back(GetString);
    NewAccount.setBCnum(GetString);

    cout << "Work Address:";
    cin >> GetString;
    keys.push_back("workAddrr");
    values.push_back(GetString);
    NewAccount.setWaddress(GetString);

    cout << "Home Adress:";
    cin >> GetString;
    keys.push_back("homeAddrr");
    values.push_back(GetString);
    NewAccount.setHaddress(GetString);

    cout << "Mobile Number:";
    cin >> GetString;
    keys.push_back("mobile");
    values.push_back(GetString);
    NewAccount.setMnum(GetString);

    cout << "Phone Number:";
    cin >> GetString;
    keys.push_back("phone");
    values.push_back(GetString);
    NewAccount.setMnum(GetString);

    cout << "Father\'s Name:";
    cin >> GetString;
    keys.push_back("father");
    values.push_back(GetString);
    NewAccount.setFathname(GetString);

    cout << "Date Of Birth:";
    cin >> GetString;
    keys.push_back("birth");
    values.push_back(GetString);
    NewAccount.setBD(GetString);

    cout << "Email:";
    cin >> GetString;
    keys.push_back("email");
    values.push_back(GetString);
    NewAccount.setEmail(GetString);

    string FileData = CreateData(keys, values);

    string FileAdress = "Files/Users/" + NewAccount.getNcode();
    
    ofstream MyFile;
    MyFile.open(FileAdress);
    MyFile << FileData;
    MyFile.close();

    cout << "Enter Password:";
    int password;
    cin >> password;
    FileAdress = "Files/Users/Credentials";
    MyFile.open(FileAdress, ios::out | ios::app);
    MyFile << NewAccount.getNcode() << "#" << password << "\n";
    MyFile.close();
    system("cls");
    ShowUserMenu(NewAccount);
}

void ShowRegisterMenuWorker (Bank bank, string type) {
    system("cls");
    string GetString;
    vector<string> keys;
    vector<string> values;

    Worker *NewWorker = new Worker();

    keys.push_back("bankid");
    values.push_back(bank.getid());
    NewWorker->bank = bank.getid();
    keys.push_back("type");
    values.push_back(type);
    NewWorker->type = type; 
    cout << "First Name:";
    cin >> GetString;
    keys.push_back("fName");
    values.push_back(GetString);
    NewWorker->setFname(GetString);

    cout << "Last Name:";
    cin >> GetString;
    keys.push_back("lName");
    values.push_back(GetString);
    NewWorker->setLname(GetString);

    cout << "National Code:";
    cin >> GetString;
    keys.push_back("nCode");
    values.push_back(GetString);
    NewWorker->setNcode(GetString);

    cout << "Birth Certificate Number:";
    cin >> GetString;
    keys.push_back("BirthCerNum");
    values.push_back(GetString);
    NewWorker->setBCnum(GetString);

    cout << "Work Address:";
    cin >> GetString;
    keys.push_back("workAddrr");
    values.push_back(GetString);
    NewWorker->setWaddress(GetString);

    cout << "Home Adress:";
    cin >> GetString;
    keys.push_back("homeAddrr");
    values.push_back(GetString);
    NewWorker->setHaddress(GetString);

    cout << "Mobile Number:";
    cin >> GetString;
    keys.push_back("mobile");
    values.push_back(GetString);
    NewWorker->setMnum(GetString);

    cout << "Phone Number:";
    cin >> GetString;
    keys.push_back("phone");
    values.push_back(GetString);
    NewWorker->setMnum(GetString);

    cout << "Father\'s Name:";
    cin >> GetString;
    keys.push_back("father");
    values.push_back(GetString);
    NewWorker->setFathname(GetString);

    cout << "Date Of Birth:";
    cin >> GetString;
    keys.push_back("birth");
    values.push_back(GetString);
    NewWorker->setBD(GetString);

    cout << "Email:";
    cin >> GetString;
    keys.push_back("email");
    values.push_back(GetString);
    NewWorker->setEmail(GetString);

    cout << "Worker ID:";
    cin >> GetString;
    keys.push_back("id");
    values.push_back(GetString);
    NewWorker->setEID(GetString);
    
    cout << "Date of Employment:";
    cin >> GetString;
    keys.push_back("empdate");
    values.push_back(GetString);
    NewWorker->setDempl(GetString);

    cout << "Salary:";
    cin >> GetString;
    keys.push_back("salary");
    values.push_back(GetString);
    NewWorker->setSal(GetString);

    string FileData = CreateData(keys, values);

    string FileAddress = "Files/Workers/" + NewWorker->getNcode();
  
    ofstream MyFile;
    MyFile.open(FileAddress);
    MyFile << FileData;
    MyFile.close();

    cout << "Enter Password:";
    int password;
    cin >> password;
    FileAddress = "Files/Users/Credentials";
    MyFile.open(FileAddress, ios::out | ios::app);
    MyFile << NewWorker->getNcode() << "#" << password << "\n";
    MyFile.close();
}

pair<bool, Worker> ShowLoginMenuWorker () {
   system("cls");
    cout << "AccountNumber : ";
    string UserName;
    cin >> UserName;
    cout << "AccountPassword : ";
    string UserPass;
    cin >> UserPass;

    ifstream Myfile;
    Myfile.open("Files/Users/Credentials");
    string credentials;
    bool exists = false;
    Worker User;
    while (Myfile >> credentials) {
        string username = "";
        int i = 0;
        for (; i < credentials.size(); i++) {
            if (credentials[i] == '#') break;
            username += credentials[i];
        }
        i++;
        if (username == UserName) {
            exists = true;
            string password = "";
            for (; i < credentials.size(); i++)
                password += credentials[i];
            if (password != UserPass) {
                cout << "password does not match." << endl;
                return {false, User};
            }
            else {
                
                ifstream UserFile;
                UserFile.open("Files/Workers/" + UserName);
                string GetString;
                UserFile >> GetString;
                User.setNcode(ExtractData("nnum", GetString));
                User.setFname(ExtractData("fname", GetString));
                User.setLname(ExtractData("lname", GetString));
                User.setBCnum(ExtractData("BirthCerNum", GetString));
                User.setWaddress(ExtractData("workAddrr", GetString));
                User.setHaddress(ExtractData("homeAddrr", GetString));
                User.setMnum(ExtractData("mobile", GetString));
                User.setPnum(ExtractData("phone", GetString));
                User.setFathname(ExtractData("father", GetString));
                User.setBD(ExtractData("birth", GetString));
                User.setEmail(ExtractData("email", GetString));
                User.setEID(ExtractData("id", GetString));
                User.setDempl(ExtractData("empdate", GetString));
                User.setSal(ExtractData("salary", GetString));
                
                UserFile.close();
                return {true, User};
            }
        }
    }
    if (!exists)
        cout << "User does not exists." << endl;
    return {false, User};
}