/***** REQUIREMENT B */
#include <iostream>
#include <iomanip>
#include "student.h"
#include "degree.h"
using std::cout;
using std::left;
using std::setw;

/***** REQUIREMENT D.2.d */
//Empty constructor to set fields to default values
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < numDaysArraySize; i++) this->daysToCompleteCourse[i] = 0;
	this->degree;
}

/***** REQUIREMENT D.2.d */
// Full constructor to build out student roster line entry
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse[], DegreeProgram degree)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < numDaysArraySize; i++) this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
	this->degree = degree;
}

/***** REQUIREMENT D.2.a */
// Defining Getter Functions
string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

int* Student::getDaysToCompleteCourse()
{
	return daysToCompleteCourse;
}

DegreeProgram Student::getDegreeProgram()
{
	return degree;
}

string Student::getDegreeProgramPrint()
{
	// Converting the DegreeProgram enum value to a string for printing
	string degreePrint;
	switch (degree) {

	case DegreeProgram::SECURITY:
		degreePrint = "SECURITY";
		break;

	case DegreeProgram::NETWORK:
		degreePrint = "NETWORK";
		break;

	case DegreeProgram::SOFTWARE:
		degreePrint = "SOFTWARE";
		break;

	default:
		degreePrint = "NONE SPECIFIED";
		break;
	}
	return degreePrint;
}

/***** REQUIREMENT D.2.b */
// Defining Setter Functions
void Student::setStudentID(string studentID)
{
	this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setDaysToCompleteCourse(int daysToCompleteCourse[])
{
	for (int i = 0; i < numDaysArraySize; i++)
	{
		this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degree)
{
	this->degree = degree;
}

void Student::setDegreeProgramPrint(string degreePrint)
{
	this->degreePrint = degreePrint;
}

/***** REQUIREMENT D.2.e */
// Defining the print() function to print all fields to the console
void Student::print()
{
	cout << left << "ID: " << setw(6) << getStudentID();
	cout << left << "First Name: " << setw(12) << getFirstName();
	cout << left << "Last Name: " << setw(14) << getLastName();
	cout << left << "Email: " << setw(27) << getEmailAddress();
	cout << left << "Age: " << setw(6) << getAge();
	cout << left << "Days in Course: " << getDaysToCompleteCourse()[0] << ", ";// *** Make sure that commas separate values here
	cout << left << getDaysToCompleteCourse()[1] << ", ";
	cout << left << setw(6) << getDaysToCompleteCourse()[2];
	cout << left << "Degree Program: " << setw(15) << getDegreeProgramPrint() << "\n";
}

// Defining the destructor function for Student
Student::~Student()
{

}