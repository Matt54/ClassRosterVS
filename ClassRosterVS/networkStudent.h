/*
NetworkStudent inherits from student and sets the StudentDegree value to "NETWORK"
*/

#ifndef networkStudent_h
#define networkStudent_h

#pragma once
#include "student.h"

using namespace std;

class NetworkStudent : public Student
{
public:
    NetworkStudent();
    NetworkStudent(string ID, string fN, string lN, string eA, int age, int d1, int d2, int d3, Degree dgr);
    virtual ~NetworkStudent(){};
    virtual string getProgramDegree() override;
};

#endif /* networkStudent_h */
