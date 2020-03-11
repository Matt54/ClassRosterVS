/*See student.h for class information*/

#include "student.h"
#include "degree.h"
#include <iostream>

Student::Student(){
    
    studentID = "NoStudentID";
    firstName = "NoFirstName";
    lastName = "NoLastName";
    emailAddress = "NoEmail";
    ageYears = -1;
    daysToComplete[0] =  -1;
    daysToComplete[1] =  -1;
    daysToComplete[2] =  -1;
}

void Student::setStudentID(string _studentID) {
    studentID = _studentID;
}

void Student::setFirstName(string _firstName) {
    firstName = _firstName;
}

void Student::setLastName(string _lastName) {
    lastName = _lastName;
}

void Student::setEmailAddress(string _emailAddress) {
    emailAddress = _emailAddress;
}

void Student::setAge(int _ageYears) {
    ageYears = _ageYears;
}

void Student::setDays(int _days[]) {
    for( int i = 1; i < numOfClasses; i++ )
    {
        daysToComplete[i] = _days[i];
    }
}

string Student::getStudentID() {
    return studentID;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getEmailAddress() {
    return emailAddress;
}

int Student::getAge() {
    return ageYears;
}

int Student::getDays(int i) {
    return daysToComplete[i];
}

Degree Student::stringToDegree(string s)
{
    if (s == "SECURITY") return SECURITY;
    else if (s == "NETWORKING") return NETWORKING;
    else if (s == "SOFTWARE") return SOFTWARE;
    else
    {
        cerr << "INVALID DEGREE STRING!";
        exit(-1);
    }
}

void Student::Print()
{
    cout << "Student ID: " << getStudentID() << '\t';
    cout << "First Name: " << getFirstName() << '\t';
    cout << "Last Name: " << getLastName() << '\t';
    cout << "Email Address: " << getEmailAddress() << '\t';
    cout << "Age: " << getAge() << '\t';
    cout << "Days To Complete: " << getDays(0) << "," << getDays(1) << "," << getDays(2) << " ";
    cout << "Degree Program: " << getProgramDegree() << endl;
}


