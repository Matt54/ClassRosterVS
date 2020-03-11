/*
Roster holds an array of students.
This roster can:
- parse an input array of student data and use that information to create students and add them to the roster
- add a student
- remove a student
- print a students information
- print all students' information
- determine if any of the student have an invalid email
- print all students' average days per course
- print a particular student's average days per course
- print all students that have a certain degree
*/

#ifndef roster_h
#define roster_h

#pragma once
#include <string>
#include "student.h"

using namespace std;

class Roster {
    public:
    
    Roster();
    Roster(int numOfStudentsInArray);
    ~Roster();
    
    void parseDataInput( const string data[], int numOfStudentInArray );
    void add(string studentID,
             string firstName,
             string lastName,
             string emailAddress,
             int age,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             Degree dgr);
    void remove(string ID);
    void printAll();
    void printInvalidEmails();
    void printAllAverageDays();
    void printAverageDaysInCourse(string ID);
    void printByDegreeProgram(Degree d);
    
    
    const int elementsInArray = 7;
    
    private:
    Student** students;
    int numOfStudents;
    
};


#endif /* roster_h */
