class Person {
    private :
    string first_name;
    string last_name;
    string national_code;
    string birth_certificate_number;
    string work_address;
    string home_address;
    string mobile_number;
    string phone_number;
    string fathers_name;
    string date_of_birth;
    string date_of_membership;
    string email_address;
    public :
     void setFname(string fname);
     void setLname(string lname);
     void setNcode(string ncode);
     void setBCnum(string bcnum);
     void setWaddress(string waddress);
     void setHaddress(string haddress);
     void setMnum(string mnum);
     void setPnum(string pnum);
     void setFathname(string fatname);
     void setBD(string bd);
     void setDM(string dm);
     void setEmail(string email);
     void PersonAddToFile ();
     void ChangeProfile ();

     Person(string fname = "",string lname ="",string ncode = "",string bcnum = "",string waddress = "",string haddress = "",string mnum = "",string pnum = "",string fathname = "",string bd = "",string dm = "",string email = "") {

        setFname(fname);
        setLname(lname);
        setNcode(ncode);
        setBCnum(bcnum);
        setWaddress(waddress);
        setHaddress(haddress);
        setMnum(mnum);
        setPnum(pnum);
        setFathname(fathname);
        setBD(bd);
        setDM(dm);
        setEmail(email);

     }
     string getFname();   
     string getLname();
     string getNcode();
     string getBCnum();
     string getWaddress();
     string getHaddress();
     string getMnum();
     string getPnum();
     string getFathname();
     string getBD();
     string getDM();
     string getEmail();
     void UpdateFile();
    
};

class Worker : public Person {
    private :
    string employment_ID;
    string date_of_employment;
    string salary;
    public :
    void setEID (string eid);
    void setDempl(string dempl);
    void setSal(string sal);
    void Change_Worker_Profile ();
        Worker (string eid = "",string dempl = "",string sal = "") {
        setEID (eid);
        setDempl(dempl);
        setSal(sal);
    }
    string getEID ();
    string getDempl();
    string getSal();
    void UpdateFile();
};

void Person::setFname(string fname) {
    first_name = fname;
}
void Person::setLname(string lname) {
    last_name = lname;
}
void Person::setNcode(string ncode) {
    national_code = ncode;
}
void Person::setBCnum(string bcnum) {
    birth_certificate_number = bcnum;
}
void Person::setWaddress(string waddress) {
    work_address = waddress;
}
void Person::setHaddress(string haddress) {
    home_address = haddress;
}
void Person::setMnum(string mnum) {
    mobile_number = mnum;
}
void Person::setPnum(string pnum) {
    phone_number = pnum;
}
void Person::setFathname(string fathname) {
    fathers_name = fathname;
}
void Person::setBD(string bd) {
    date_of_birth = bd;
}
void Person::setDM(string dm) {
    date_of_membership = dm;
}
void Person::setEmail(string email) {
    email_address = email;
}

string Person::getFname() {
    return first_name;
}
string Person::getLname() {
    return last_name;
}
string Person::getNcode() {
    return national_code;
}
string Person::getBCnum() {
    return birth_certificate_number;
}
string Person::getWaddress() {
    return work_address;
}
string Person::getHaddress() {
    return home_address;
}
string Person::getMnum() {
    return mobile_number;
}
string Person::getPnum() {
    return phone_number;
}
string Person::getFathname() {
    return fathers_name;
}
string Person::getBD() {
    return date_of_birth;
}
string Person::getDM() {
    return date_of_membership;
}
string Person::getEmail() {
    return email_address;
}
void Worker::setEID(string eid) {
    employment_ID = eid;
}
void Worker::setDempl(string dempl) {
    date_of_employment = dempl;
}
void Worker::setSal(string sal) {
    salary = sal;
}
string Worker::getEID() {
    return employment_ID;
}
string Worker::getDempl() {
    return date_of_employment;
}
string Worker::getSal() {
    return salary;
}

void Person::ChangeProfile() {
    cout<<"Please select to change each section."<<endl;
    int aq ;
    cout<<"1.Change Work Address."<<endl<<"2.Change Home Address."<<endl<<"3.Change Mobile Number"<<endl<<"4.Change Phone Number"<<endl<<"5.Change Email."<<endl<<"6.Back."<<endl;
    cin>>aq;
    string  GetString;
    if (aq==1) {
        cout << "Work Address:";
        cin >> GetString;
        setWaddress(GetString);
        cout<<"Updated Successfully!!"<<endl;
    }
    if (aq==2) {
        cout << "Home Adress:";
        cin >> GetString;
        setHaddress(GetString);
        cout<<"Updated Successfully!!"<<endl;
    }
    if (aq==3) {
        cout << "Mobile Number:";
        cin >> GetString;
        setMnum(GetString);
        cout<<"Updated Successfully!!"<<endl;
    }
    if (aq==4) {
        cout << "Phone Number:";
        cin >> GetString;
        setPnum(GetString);
        cout<<"Updated Successfully!!"<<endl;
    }
    if (aq==5) {
        cout << "Email:";
        cin >>GetString;
        setEmail(GetString);
        cout<<"Updated Successfully!!"<<endl;
    }
    if (aq==6) {
        return;
    }
    else {
        cout<<"Error!!!"<<endl;
    }
    UpdateFile();
}

void Person::UpdateFile() {
    vector<string> keys;
    vector<string> values;

    keys.push_back("fName");
    values.push_back(this->first_name);
    
    keys.push_back("lName");
    
    values.push_back(this->last_name);

    keys.push_back("nCode");
    values.push_back(this->national_code);

    keys.push_back("BirthCerNum");
    values.push_back(this->birth_certificate_number);
    
    keys.push_back("workAddrr");
    values.push_back(this->work_address);

    keys.push_back("homeAddrr");
    values.push_back(this->work_address);

    keys.push_back("mobile");
    values.push_back(this->home_address);

    keys.push_back("phone");
    values.push_back(this->phone_number);

    keys.push_back("father");
    values.push_back(this->fathers_name);

    keys.push_back("birth");
    values.push_back(this->date_of_birth);

    keys.push_back("email");
    values.push_back(this->email_address);

    string FileData = CreateData(keys, values);

    string FileAdress = "Files/Users/" + this->getNcode();
    
    ofstream MyFile;
    MyFile.open(FileAdress);
    MyFile << FileData;
    MyFile.close();
}

void Worker::Change_Worker_Profile() {

    cout<<"Please select to change each section."<<endl;
    int Account ;
    cout<<"1.Change Work Address."<<endl<<"2.Change Home Address."<<endl<<"3.Change Mobile Number"<<endl<<"4.Change Phone Number"<<endl<<"5.Change Email"<<endl<<"6.Change Salary"<<endl<<"7.Back."<<endl;
    int al;
    cin>>al;
    string  GetString;
    if (al==1) {
        cout << "Work Address:";
        cin >> GetString;
        setWaddress(GetString);
        cout<<"Updated Successfully!!"<<endl;
    }
    if (al==2) {
        cout << "Home Adress:";
        cin >> GetString;
        setHaddress(GetString);
        cout<<"Updated Successfully!!"<<endl;
    }
    if (al==3) {
        cout << "Mobile Number:";
        cin >> GetString;
        setMnum(GetString);
        cout<<"Updated Successfully!!"<<endl;
    }
    if (al==4) {
        cout << "Phone Number:";
        cin >> GetString;
        setPnum(GetString);
        cout<<"Updated Successfully!!"<<endl;
    }
    if (al==5) {
        cout << "Email:";
        cin >>GetString;
        setEmail(GetString);
        cout<<"Updated Successfully!!"<<endl;
    }
    if (al==6) {
        cout<<"Salary:";
        cin>>GetString;
        setSal(GetString);
        cout<<"Salary Updated Successfully!!"<<endl;
    }
    if (al==7) {
        return;
    }
    else {
        cout<<"Error!!!"<<endl;
    }
    UpdateFile();
}

void Worker::UpdateFile() {

    vector<string> keys;
    vector<string> values;

    keys.push_back("fName");
    values.push_back(this->getFname());
    
    keys.push_back("lName");
    
    values.push_back(this->getLname());

    keys.push_back("nCode");
    values.push_back(this->getNcode());

    keys.push_back("BirthCerNum");
    values.push_back(this->getBCnum());
    
    keys.push_back("workAddrr");
    values.push_back(this->getWaddress());

    keys.push_back("homeAddrr");
    values.push_back(this->getHaddress());

    keys.push_back("mobile");
    values.push_back(this->getMnum());

    keys.push_back("phone");
    values.push_back(this->getPnum());

    keys.push_back("father");
    values.push_back(this->getFathname());

    keys.push_back("birth");
    values.push_back(this->getBD());

    keys.push_back("email");
    values.push_back(this->getEmail());

    keys.push_back("id");
    values.push_back(this->getEID());
  
    keys.push_back("empdate");
    values.push_back(this->getDempl());

    keys.push_back("salary");
    values.push_back(this->getSal());

    string FileData = CreateData(keys, values);

    string FileAddress = "/Files/Workers/" + this->getNcode();
  
    ofstream MyFile;
    MyFile.open(FileAddress);
    MyFile << FileData;
    MyFile.close();
}
