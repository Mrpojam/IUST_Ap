//Ahmadreza Rahnama 99441164
#include<iostream>
#include<iomanip>
#include<string>
#include<conio.h>
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
     Person(string fname = "",string lname ="",string ncode = "",string bcnum = "",string waddress = "",string haddress = "",string mnum = "",string pnum = "",string fatname = "",string bd = "",string dm = "",string email = "") {

     setFname(string fname);
     setLname(string lname);
     setNcode(string ncode);
     setBCnum(string bcnum);
     setWaddress(string waddress);
     setHaddress(string haddress);
     setMnum(string mnum);
     setPnum(string pnum);
     setFathname(string fathname);
     setBD(string bd);
     setDM(string dm);
     setEmail(string email);
     }
     string getFname(string fname);   
     string getLname(string lname);
     string getNcode(string ncode);
     string getBCnum(string bcnum);
     string getWaddress(string waddress);
     string getHaddress(string haddress);
     string getMnum(string mnum);
     string getPnum(string pnum);
     string getFathname(string fathname);
     string getBD(string bd);
     string getDM(string dm);
     string getEmail(string email);
     ~Person();
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
    setEID (string eid);
    setDempl(string dempl);
    setSal(string sal);
    }
    string getEID (string eid);
    string getDempl(string dempl);
    string getSal(string sal);
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
