/*
ClassRosterVS program flow:
	- parses array of comma delimited student data
	- creates a roster of students (seperating them based on their degree program)
	- prints out all students in the roster
	- prints out any students with invalid emails
	- prints out each students average days per course
	- prints out all students with a software degree
	- removed a student by their studentID (unique identifier)
	- attempts to remove the same student again (prints error message)
	- deletes the roster from memory
*/


#include <iostream>
#include "student.h"
#include "softwareStudent.h"
#include "roster.h"


using namespace std;

int main() {
    
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Matt,Pfeiffer,mattpfeiffer54@gmail.com,28,1,2,3,SOFTWARE"
    };
    
    int numOfStudents = sizeof( studentData ) / sizeof( studentData[ 0 ] );
    
    Roster* classRoster = new Roster(numOfStudents);
    classRoster -> parseDataInput( studentData, numOfStudents );
    classRoster -> printAll();
    classRoster -> printInvalidEmails();
    classRoster -> printAllAverageDays();
    classRoster -> printByDegreeProgram(SOFTWARE);
    classRoster -> remove("A3");
    classRoster -> remove("A3");
    delete classRoster;
    
}
