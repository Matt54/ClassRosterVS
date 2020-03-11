/*
SoftwareStudent inherits from student and sets the StudentDegree value to "SOFTWARE"
*/


#ifndef softwareStudent_h
#define softwareStudent_h

#pragma once
#include "student.h"

using namespace std;

class SoftwareStudent : public Student
{
public:
    SoftwareStudent();
    SoftwareStudent(string ID, string fN, string lN, string eA, int age, int d1, int d2, int d3, Degree dgr);
    virtual ~SoftwareStudent(){};
    virtual string getProgramDegree() override;
};

#endif /* SoftwareStudent_h */
