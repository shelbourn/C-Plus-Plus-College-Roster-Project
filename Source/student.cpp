#include <iostream>
#include <iomanip>
#include "student.h"
#include "degree.h"
using std::cout;
using std::left;
using std::setw;

//Empty constructor to set fields to default values
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < numDaysArraySize; i++) this->daysToCompleteCourse[i] = 0;
	this->degree; /*Sub-Class??? Or Enum Array???*/

	/********
	NOTE: I might need to create a sub-class for the enum DegreeProgram or need
	to use the degreeProgramArray to fix the setters, getters, and constructors
	for the degree program
	*/
}

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

// Defining the print() function to print all fields to the console
void Student::print()
{
	cout << left << setw(5) << studentID;
	cout << left << setw(15) << firstName;
	cout << left << setw(15) << lastName;
	cout << left << setw(35) << emailAddress;
	cout << left << setw(3) << age;
	cout << left << setw(4) << daysToCompleteCourse[0];
	cout << left << setw(4) << daysToCompleteCourse[1];
	cout << left << setw(4) << daysToCompleteCourse[2];
	cout << left << setw(12) << degreeProgramArray[degree]; // Need to fix this
}

// Defining the destructor function for Student
Student::~Student()
{

}