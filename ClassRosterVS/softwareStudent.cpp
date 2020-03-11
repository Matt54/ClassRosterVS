/*See softwareStudent.h for class information*/

#include "softwareStudent.h"
#include <iostream>

using namespace std;

SoftwareStudent::SoftwareStudent()
{
    studentID = "NoStudentID";
    firstName = "NoFirstName";
    lastName = "NoLastName";
    emailAddress = "NoEmail";
    ageYears = -1;
    daysToComplete[0] =  -1;
    daysToComplete[1] =  -1;
    daysToComplete[2] =  -1;
    studentDegree = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string ID, string fN, string lN, string eA, int age, int d1, int d2, int d3, Degree dgr)
{
    studentID = ID;
    firstName = fN;
    lastName = lN;
    emailAddress = eA;
    ageYears = age;
    daysToComplete[0] =  d1;
    daysToComplete[1] =  d2;
    daysToComplete[2] =  d3;
    studentDegree = SOFTWARE;
}

string SoftwareStudent::getProgramDegree() 
{
    return degreeToString(studentDegree);
}
