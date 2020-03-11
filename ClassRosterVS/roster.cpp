/*See roster.h for class information*/

#include "roster.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include <iostream>
using namespace std;

Roster::Roster()
{
    cout << "Roster default ctor\n";
}

Roster::Roster(int numOfStudentsInArray)
{
    students = new Student*[numOfStudentsInArray];
    numOfStudents = 0;
}

Roster::~Roster()
{
    cout << "\n";
    cout << "Roster has been destructed! Memory is released.\n";
}

void Roster::parseDataInput( const string data[], int numOfStudentsInArray )
{
    
    // This will loop through each element of the data string array
    for( int index = 0; index < numOfStudentsInArray; index++ )
    {
        // This will split the data up into 9 segments based on the ","
        // and populate the arr array
        string *arr;
        arr = new string[9];
        unsigned long beginningLocation = 0;
        int numInputPerStudent = 9;
        for ( int i = 0; i < numInputPerStudent; i++ )
        {
            unsigned long endingLocation = data[index].find( ",", beginningLocation );
            arr[i] = data[index].substr(beginningLocation , endingLocation - beginningLocation);
            beginningLocation = endingLocation + 1;
        }
        add( arr[0], // ID
             arr[1], // first name
             arr[2], // last name
             arr[3], // email address
             atoi( arr[4].c_str() ), // age
             atoi( arr[5].c_str() ), // days 1
             atoi( arr[6].c_str() ), // days 2
             atoi( arr[7].c_str() ), // days 3
             stringToDegree(arr[8]) ); // degree
    }
}

void Roster::add(string studentID,
                 string firstName,
                 string lastName,
                 string emailAddress,
                 int age,
                 int daysInCourse1,
                 int daysInCourse2,
                 int daysInCourse3,
                 Degree dgr)
{
    if (dgr == SECURITY)
    {
        students[numOfStudents] = new SecurityStudent(studentID,
                                                        firstName,
                                                        lastName,
                                                        emailAddress,
                                                        age,
                                                        daysInCourse1,
                                                        daysInCourse2,
                                                        daysInCourse3,
                                                        dgr);
        numOfStudents++;
    }
    else if (dgr == NETWORKING)
    {
        students[numOfStudents] = new NetworkStudent(studentID,
                                                        firstName,
                                                        lastName,
                                                        emailAddress,
                                                        age,
                                                        daysInCourse1,
                                                        daysInCourse2,
                                                        daysInCourse3,
                                                        dgr);
        numOfStudents++;
    }
    else if (dgr == SOFTWARE)
    {
        students[numOfStudents] = new SoftwareStudent(studentID,
                                                        firstName,
                                                        lastName,
                                                        emailAddress,
                                                        age,
                                                        daysInCourse1,
                                                        daysInCourse2,
                                                        daysInCourse3,
                                                        dgr);
        numOfStudents++;
    }
    else
    {
        cout << "No valid degree type found\n";
    }
}

void Roster::printAll()
{
    cout << "\n";
    cout << "PRINTING ALL STUDENTS\n";
    for( int i = 0; i < numOfStudents; i++ )
    {
		if (students[i] != nullptr)
		{
			students[i]->Print();
		}
    }
}

void Roster::printInvalidEmails()
{
    cout << "\n";
    cout << "PRINTING ALL INVALID EMAILS\n";
    for( int i = 0; i < numOfStudents; i++ )
    {
		if (students[i] != nullptr)
		{
			bool valid = true;
			string name = students[i]->getFirstName() + " " + students[i]->getLastName();
			string email = students[i]->getEmailAddress();

			if (email.find('@') == std::string::npos) valid = false; // if @ is not found, valid = false
			if (email.find('.') == std::string::npos) valid = false; // if . is not found, valid = false
			if (email.find(' ') != std::string::npos) valid = false; // if space if found, valid = false

			if (!valid)
			{
				cout << name << "'s email address: " << email << " is invalid\n";
			}
		}
    }
}

void Roster::printAllAverageDays()
{
    cout << "\n";
    cout << "PRINTING ALL AVERAGE DAYS IN COURSE\n";
    for( int i = 0; i < numOfStudents; i++ )
    {
		if (students[i] != nullptr)
		{
			string ID = students[i]->getStudentID();
			printAverageDaysInCourse(ID);
		}
    }
}

void Roster::printAverageDaysInCourse(string ID)
{
    for( int i = 0; i < numOfStudents; i++ )
    {
		if (students[i] != nullptr)
		{
			string studentID = students[i]->getStudentID();

			if (studentID == ID)
			{
				int sum = 0;
				sum += students[i]->getDays(0);
				sum += students[i]->getDays(1);
				sum += students[i]->getDays(2);
				int average = sum / 3;
				string name = students[i]->getFirstName() + " " + students[i]->getLastName();
				cout << name << "'s average days in a course is: " << average << "\n";
			}
		}
    }
}

void Roster::printByDegreeProgram(Degree d)
{
    string inputDegree = degreeToString(d);
    cout << "\n";
    cout << "PRINTING ALL STUDENTS WITH THE DEGREE - " << inputDegree << "\n";
    for( int i = 0; i < numOfStudents; i++ )
    {
		if (students[i] != nullptr)
		{
			string studentDegree = students[i]->getProgramDegree();

			if (studentDegree == inputDegree)
			{
				students[i]->Print();
			}
		}
        
    }
}

void Roster::remove(string ID)
{
    bool studentExists = false;
    
    for( int i = 0; i < numOfStudents; i++ )
    {
        if(students[i] != nullptr)
        {
            string studentID = students[i] -> getStudentID();
            if( studentID == ID )
            {
                studentExists = true;
                string name = students[i] -> getFirstName() + " " + students[i] -> getLastName();
                cout << "\n";
                cout << "Deleted Student - " << name << "\n";
				if (students[i] != nullptr)
				{
					delete students[i];
					students[i] = students[numOfStudents-1];
				}
                numOfStudents--;
                break;
            }
        }
    }
    
	if (!studentExists)
	{
		cout << "\n";
		cout << "No Student Found With ID - " << ID << "\n";
	}
    
}
