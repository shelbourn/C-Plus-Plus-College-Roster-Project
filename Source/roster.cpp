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
Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];
}

Student* Roster::getStudentRecordAt(int index)
{
	return classRosterArray[index];
}

