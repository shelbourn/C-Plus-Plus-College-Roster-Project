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
