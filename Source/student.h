#pragma once
#include <degree.h>
#include <string>
using std::string;


// Definining the Student class
class Student
{
public:

	// Initializing Days in Course array with size of 3
	const static int numDaysArraySize = 3;

	// Constructors
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse[], DegreeProgram degree);

	// Accessor Funtions (Getters)
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysToCompleteCourse();
	DegreeProgram getDegreeProgram();

	// Mutator Functions (Setters)
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysToCompleteCourse(int daysToCompleteCourse[]);
	void setDegreeProgram(DegreeProgram degree);

	// Print function to print specific student data to console
	void print();

private:
	// Declaring private variables
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToCompleteCourse[numDaysArraySize];
	DegreeProgram degree;
};
