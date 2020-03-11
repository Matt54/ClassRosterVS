/*
Abstract Student class holds information about a student including:
	studentID (int) - unique identifier for the student
	firstName (string) - first name of student
	lastName (string) - last name of student
	emailAddress (string) - email address of student
	ageYears (int) - age of student
	daysToComplete (int[3]) - number of days it took for student to complete 3 classes
*/

#ifndef student_h
#define student_h

#pragma once
#include "degree.h"
#include <string>
#include <stdio.h>
#include <array>

using namespace std;

class Student {
public:
    
    Student();
    virtual ~Student(){};
    
    static const int numOfClasses = 3;
    
    void   setStudentID(string studentID);
    void   setFirstName(string firstName);
    void   setLastName(string lastName);
    void   setEmailAddress(string emailAddress);
    void   setAge(int ageYears);
    void   setDays(int daysToComplete[]);
    
    string   getStudentID();
    string   getFirstName();
    string   getLastName();
    string   getEmailAddress();
    int      getAge();
    int      getDays(int i);
    
    void Print();
    
    virtual string getProgramDegree() = 0; // a pure virtual function

    Degree stringToDegree(string s);
    
protected:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int    ageYears;
    int    daysToComplete[numOfClasses];
    Degree studentDegree;
};


#endif /* Student_h */
