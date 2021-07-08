
#include"bank.h"

void ShowUserMenu (Person User);

pair<bool, Person> ShowLoginMenu () {
   
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
                cout << "password does not match." << endl;
                return {false, User};
            }
            else {
                
                return {true, User};
            }
        }
    }
    if (!exists)
        cout << "User does not exists." << endl;
    return {false, User};
}

void ShowRegisterMenu () {
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
    //system("clear");

    cout << "Enter Password:";
    int password;
    cin >> password;
    FileAdress = "Files/Users/Credentials";
    MyFile.open(FileAdress, ios::out | ios::app);
    MyFile << NewAccount.getNcode() << "#" << password << "\n";
    MyFile.close();
    /*
        Set date of memebership
    */

    system("clear");

    ShowUserMenu(NewAccount);

}

void CreateWorker (Bank bank, string type) {
    string GetString;
    vector<string> keys;
    vector<string> values;

    Worker *NewWorker = new Worker("12");

    keys.push_back("bankid");
    values.push_back(bank.getid());

    keys.push_back("type");
    values.push_back(type);

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