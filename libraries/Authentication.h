
#include"Json.h"

void ShowLoginMenu () {
    cout << "AccountNumber : ";
    string UserName;
    cin >> UserName;
    cout << "AccountPassword : ";
    string UserPass;
    cin >> UserPass;
   // Login (UserName, UserPass);
}

void ShowRegisterMenu () {
    Person NewAccount;
    string GetString;
    vector<string> JsonKeys;
    vector<string> JsonValues;

    cout << "First Name:";
    cin >> GetString;
    JsonKeys.push_back("fName");
    JsonValues.push_back(GetString);
    NewAccount.setFname(GetString);

    cout << "Last Name:";
    cin >> GetString;
    JsonKeys.push_back("lName");
    JsonValues.push_back(GetString);
    NewAccount.setLname(GetString);

    cout << "National Code:";
    cin >> GetString;
    JsonKeys.push_back("nCode");
    JsonValues.push_back(GetString);
    NewAccount.setNcode(GetString);

    cout << "Birth Certificate Number:";
    cin >> GetString;
    JsonKeys.push_back("BirthCerNum");
    JsonValues.push_back(GetString);
    NewAccount.setBCnum(GetString);

    cout << "Work Address:";
    cin >> GetString;
    JsonKeys.push_back("workAddrr");
    JsonValues.push_back(GetString);
    NewAccount.setWaddress(GetString);

    cout << "Home Adress:";
    cin >> GetString;
    JsonKeys.push_back("homeAddrr");
    JsonValues.push_back(GetString);
    NewAccount.setHaddress(GetString);

    cout << "Mobile Number:";
    cin >> GetString;
    JsonKeys.push_back("mobile");
    JsonValues.push_back(GetString);
    NewAccount.setMnum(GetString);

    cout << "Phone Number:";
    cin >> GetString;
    JsonKeys.push_back("phone");
    JsonValues.push_back(GetString);
    NewAccount.setMnum(GetString);

    cout << "Father\'s Name:";
    cin >> GetString;
    JsonKeys.push_back("father");
    JsonValues.push_back(GetString);
    NewAccount.setFathname(GetString);

    cout << "Date Of Birth:";
    cin >> GetString;
    JsonKeys.push_back("birth");
    JsonValues.push_back(GetString);
    NewAccount.setBD(GetString);

    cout << "Email:";
    cin >> GetString;
    JsonKeys.push_back("email");
    JsonValues.push_back(GetString);
    NewAccount.setEmail(GetString);

    string FileData = CreatePersonData(JsonKeys, JsonValues);

    string FileAdress = "Files/Users/" + NewAccount.getNcode();
    cout << FileAdress << endl;
    ofstream MyFile;
    MyFile.open(FileAdress);
    MyFile << FileData;
    MyFile.close();
    //system("clear");

    cout << "Enter Password:";
    int password;
    cin >> password;
    FileAdress = "Files/Users/Credentials" + NewAccount.getNcode();
    MyFile.open(FileAdress);
    MyFile << password;

    /*
        Set date of memebership
    */

}