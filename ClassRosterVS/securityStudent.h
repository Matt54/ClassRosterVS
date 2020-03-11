/*
SecurityStudent inherits from student and sets the StudentDegree value to "SECURITY"
*/

#ifndef securityStudent_h
#define securityStudent_h

#pragma once
#include "student.h"

using namespace std;

class SecurityStudent : public Student
{
public:
    SecurityStudent();
    SecurityStudent(string ID, string fN, string lN, string eA, int age, int d1, int d2, int d3, Degree dgr);
    virtual ~SecurityStudent(){};
    virtual string getProgramDegree() override;
};

#endif /* securityStudent_h */
