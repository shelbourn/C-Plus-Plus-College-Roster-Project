/***** REQUIREMENT B */
#pragma once
#include "degree.h"
#include <string>
using std::string;

/***** REQUIREMENT C.1 */
// Definining the Student class
class Student
{
public:
	// Initializing Days in Course array with size of 3
	const static int numDaysArraySize = 3;

private:
	/***** REQUIREMENT C.1 */
	// Declaring private variables
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToCompleteCourse[numDaysArraySize];
	DegreeProgram degree;
	string degreePrint;
	string degreeResult;

public:
	/***** REQUIREMENT C.2.d */
	// Constructors
	Student(); // Will set an empty roster with default values for all fields
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse[], DegreeProgram degree);

	/***** REQUIREMENT D.2.a */
	// Accessor Funtions (Getters)
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysToCompleteCourse();
	DegreeProgram getDegreeProgram();
	string getDegreeProgramPrint();

	/***** REQUIREMENT D.2.b */
	// Mutator Functions (Setters)
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysToCompleteCourse(int inputDaysToCompleteCourse[]);
	void setDegreeProgram(DegreeProgram degree);
	void setDegreeProgramPrint(string degreePrint);

	/***** REQUIREMENT D.2.e */
	// Print function to print specific student data to console
	void print();

	// Destructor
	~Student();
};
