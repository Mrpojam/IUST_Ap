//Ahmadreza Rahnama 99441164
#include<iostream>
#include<iomanip>
#include<string>
// #include<conio.h>
using namespace std;
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

        PersonAddToFile();

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
        Worker (string eid = "",string dempl = "",string sal = "") {
        setEID (eid);
        setDempl(dempl);
        setSal(sal);
    }
    string getEID ();
    string getDempl();
    string getSal();
    ~Worker();
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

void Person::PersonAddToFile() {
    
}
