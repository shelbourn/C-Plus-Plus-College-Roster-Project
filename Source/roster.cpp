#include "roster.h"
using std::cout;
using std::cerr;

// Defining the empty roster constructor -- sets fields to default values
Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1; // Arrays are 0-indexed so -1 will set it to no value
	this->classRosterArray = nullptr;
}

// Defining the non-empty roster constructor -- sets the max size for the roster
// Allocates appropriate memory for roster size
Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];
}

// Return student record at specified record number (index)
Student* Roster::getStudentRecordAt(int index)
{
	return classRosterArray[index];
}

// Parse string data and add it to roster
void Roster::parseString(string record)
{
	if (lastIndex < capacity) {
		lastIndex++;

		// Validates DegreeProgram in submitted string
		DegreeProgram degreeTemp;
		if (record.find("SECURITY") != string::npos) degreeTemp = DegreeProgram::SECURITY;
		else if (record.find("NETWORK") != string::npos) degreeTemp = DegreeProgram::NETWORK;
		else if (record.find("SOFTWARE") != string::npos) degreeTemp = DegreeProgram::SOFTWARE;
		else
		{
			cerr << "INVALID DEGREE PROGRAM ENTERED! PROGRAM TERMINATED!\n";
			exit(-1);
		}

		// Parse through each roster record (string)
		// Extract each substring (separated by commas) and store them in temporary variables

		// Extracting the Student ID
		int rightSubStringEnd = record.find(",");
		string stuID = record.substr(0, rightSubStringEnd);

		// Extracting First Name
		int leftSubStringEnd = rightSubStringEnd + 1;
		rightSubStringEnd = record.find(",", leftSubStringEnd);
		string fName = record.substr(leftSubStringEnd, rightSubStringEnd - leftSubStringEnd);

		// Extracting Last Name
		leftSubStringEnd = rightSubStringEnd + 1;
		rightSubStringEnd = record.find(",", leftSubStringEnd);
		string lName = record.substr(leftSubStringEnd, rightSubStringEnd - leftSubStringEnd);

		// Extracting Email Address
		leftSubStringEnd = rightSubStringEnd + 1;
		rightSubStringEnd = record.find(",", leftSubStringEnd);
		string email = record.substr(leftSubStringEnd, rightSubStringEnd - leftSubStringEnd);

		// Extracting Age
		leftSubStringEnd = rightSubStringEnd + 1;
		rightSubStringEnd = record.find(",", leftSubStringEnd);
		int ageTemp = stod(record.substr(leftSubStringEnd, rightSubStringEnd - leftSubStringEnd));

		// Extracting each value for daysInCourse
		// daysInCourse1
		leftSubStringEnd = rightSubStringEnd + 1;
		rightSubStringEnd = record.find(",", leftSubStringEnd);
		int daysInCourse1 = stod(record.substr(leftSubStringEnd, rightSubStringEnd - leftSubStringEnd));

		// daysInCourse2
		leftSubStringEnd = rightSubStringEnd + 1;
		rightSubStringEnd = record.find(",", leftSubStringEnd);
		int daysInCourse2 = stod(record.substr(leftSubStringEnd, rightSubStringEnd - leftSubStringEnd));

		// daysInCourse3
		leftSubStringEnd = rightSubStringEnd + 1;
		rightSubStringEnd = record.find(",", leftSubStringEnd);
		int daysInCourse3 = stod(record.substr(leftSubStringEnd, rightSubStringEnd - leftSubStringEnd));

		// Adding all the parsed student data as a record in the roster
		add(stuID, fName, lName, email, ageTemp, daysInCourse1, daysInCourse2, daysInCourse3, degreeTemp);
	}

	// Exit program if roster capacity is exceeded
	else
	{
		cerr << "ERROR!! THE STUDENT ROSTER HAS EXCEEDED ITS MAXIMUM CAPACITY!\n PROGRAM TERMINATED!";
		exit(-1);
	}
}

// Defining the add() method
void Roster::add(string stuID, string fName, string lName, string email, int ageTemp, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeTemp)
{
	// Creating an array for the number of days in course
	int daysInCourseArray[Student::numDaysArraySize];
	daysInCourseArray[0] = daysInCourse1;
	daysInCourseArray[1] = daysInCourse2;
	daysInCourseArray[2] = daysInCourse3;
}

// Defining printAll() method
void Roster::printAll()
{
	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}
