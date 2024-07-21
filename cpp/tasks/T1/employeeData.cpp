#include <iostream>
#include <string>

using namespace std;

struct Name {
    string firstName;
    string middleName;
    string lastName;
};

struct DateOfBirth {
    int day;
    int month;
    int year;
};

struct Address {
    string street;
    string city;
    string country;
};

struct Contacts {
    string telephoneNumber;
    string mobileNumber;
    string emailAddress;
};

struct Salary {
    double basic;
    double additional;
    double reductions;
    double taxes;
};

// Structure for Employee
struct Employee {
    Name name;
    DateOfBirth dob;
    Address address;
    Contacts contacts;
    string job;
    Salary salary;
};

// prototypes
void inputEmployeeData(Employee &emp);
void printEmployeeData(const Employee &emp);

int main() {
    Employee emp;

    inputEmployeeData(emp);
    printEmployeeData(emp);

    return 0;
}

void inputEmployeeData(Employee &emp) {
    // Input Name
    cout << "Enter First Name: ";
    cin >> emp.name.firstName;
    cout << "Enter Middle Name: ";
    cin >> emp.name.middleName;
    cout << "Enter Last Name: ";
    cin >> emp.name.lastName;

    // Input Date of Birth
    cout << "Enter Date of Birth (day month year): ";
    cin >> emp.dob.day >> emp.dob.month >> emp.dob.year;

    // Input Address
    cout << "Enter Street: ";
    cin >> ws;  //  ws Manipulator discards any leading whitespace before reading the next input
    getline(cin, emp.address.street);
    cout << "Enter City: ";
    getline(cin, emp.address.city);
    cout << "Enter Country: ";
    getline(cin, emp.address.country);

    // Input Contacts
    cout << "Enter Telephone Number: ";
    cin >> emp.contacts.telephoneNumber;
    cout << "Enter Mobile Number: ";
    cin >> emp.contacts.mobileNumber;
    cout << "Enter Email Address: ";
    cin >> emp.contacts.emailAddress;

    // Input Job
    cout << "Enter Job: ";
    cin >> ws;
    getline(cin, emp.job);

    // Input Salary
    cout << "Enter Basic Salary: ";
    cin >> emp.salary.basic;
    cout << "Enter Additional Salary: ";
    cin >> emp.salary.additional;
    cout << "Enter Reductions: ";
    cin >> emp.salary.reductions;
    cout << "Enter Taxes: ";
    cin >> emp.salary.taxes;
}

void printEmployeeData(const Employee &emp) {
    cout << "\nEmployee Information:\n";
    cout << "Name: " << emp.name.firstName << " " << emp.name.middleName << " " << emp.name.lastName << endl;
    cout << "Date of Birth: " << emp.dob.day << "/" << emp.dob.month << "/" << emp.dob.year << endl;
    cout << "Address: " << emp.address.street << ", " << emp.address.city << ", " << emp.address.country << endl;
    cout << "Contacts:\n";
    cout << "  Telephone: " << emp.contacts.telephoneNumber << endl;
    cout << "  Mobile: " << emp.contacts.mobileNumber << endl;
    cout << "  Email: " << emp.contacts.emailAddress << endl;
    cout << "Job: " << emp.job << endl;
    cout << "Salary:\n";
    cout << "  Basic: " << emp.salary.basic << endl;
    cout << "  Additional: " << emp.salary.additional << endl;
    cout << "  Reductions: " << emp.salary.reductions << endl;
    cout << "  Taxes: " << emp.salary.taxes << endl;
}