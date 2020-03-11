//
//  securityStudent.cpp
//  ClassRoster
//
//  Created by Macbook on 10/13/19.
//  Copyright © 2019 Matt Pfeiffer. All rights reserved.
//

#include "securityStudent.h"
#include <iostream>

using namespace std;
/*See securityStudent.h for class information*/

SecurityStudent::SecurityStudent()
{
    studentID = "NoStudentID";
    firstName = "NoFirstName";
    lastName = "NoLastName";
    emailAddress = "NoEmail";
    ageYears = -1;
    daysToComplete[0] =  -1;
    daysToComplete[1] =  -1;
    daysToComplete[2] =  -1;
    studentDegree = SECURITY;
}

SecurityStudent::SecurityStudent(string ID, string fN, string lN, string eA, int age, int d1, int d2, int d3, Degree dgr)
{
    studentID = ID;
    firstName = fN;
    lastName = lN;
    emailAddress = eA;
    ageYears = age;
    daysToComplete[0] =  d1;
    daysToComplete[1] =  d2;
    daysToComplete[2] =  d3;
    studentDegree = SECURITY;
}

string SecurityStudent::getProgramDegree()
{
    return degreeToString(studentDegree);
}
