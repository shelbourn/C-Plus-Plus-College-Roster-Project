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
	this->degree = degree; /*Sub-Class??? Or Enum Array???*/
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
		this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
}

void Student::setDegreeProgram(DegreeProgram degree)
{
	this->degree = degree;
}

// Function specifically linked to printing DegreeProgram to console
void Student::degreeProgramPrint(DegreeProgram degree)
{
	// Converting the DegreeProgram value to a string for printing
	string degreeResult;
	switch (degree) {

	case DegreeProgram::SECURITY:
		degreeResult = "SECURITY";
		break;

	case DegreeProgram::NETWORK:
		degreeResult = "NETWORK";
		break;

	case DegreeProgram::SOFTWARE:
		degreeResult = "SOFTWARE";
		break;

	default:
		degreeResult = "NONE SPECIFIED";
		break;
	}
	this->degreePrint = degreeResult;
}

/***** REQUIREMENT D.2.e */
// Defining the print() function to print all fields to the console
void Student::print()
{
	degreeProgramPrint(degree);

	cout << left << "ID: " << setw(6) << studentID;
	cout << left << "First Name: " << setw(12) << firstName;
	cout << left << "Last Name: " << setw(14) << lastName;
	cout << left << "Email: " << setw(27) << emailAddress;
	cout << left << "Age: " << setw(6) << age;
	cout << left << "Days in Course: " << daysToCompleteCourse[0] << ", "; // *** Make sure that commas separate values here
	cout << left << daysToCompleteCourse[1] << ", ";
	cout << left << setw(6) << daysToCompleteCourse[2];
	cout << left << "Degree Program: " << setw(15) << degreePrint << "\n";
}

// Defining the destructor function for Student
Student::~Student()
{

}