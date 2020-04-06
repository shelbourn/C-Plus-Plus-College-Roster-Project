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
		DegreeProgram degree;
		if (record.find("SECURITY") != string::npos) degree = DegreeProgram::SECURITY;
		else if (record.find("NETWORK") != string::npos) degree = DegreeProgram::NETWORK;
		else if (record.find("SOFTWARE") != string::npos) degree = DegreeProgram::SOFTWARE;
		else
		{
			cerr << "INVALID DEGREE PROGRAM ENTERED! EXITING PROGRAM!\n";
			exit(-1);
		}

		// Parse through each roster record (string)
		// Extract each substring (separated by commas) and store them in temporary variables

		// Extracting the Student ID
		int rightSubStringEnd = record.find(",");
		string studentID = record.substr(0, rightSubStringEnd);

		// Extracting First Name
		int leftSubStringEnd = rightSubStringEnd + 1;
		rightSubStringEnd = record.find(",", leftSubStringEnd);
		string firstName = record.substr(leftSubStringEnd, rightSubStringEnd - leftSubStringEnd);



	}
}
