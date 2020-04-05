#include <iostream>
#include <iomanip>
#include "student.h"
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
	this->DegreeProgram = 0; /*Sub-Class??? Or Enum Array???*/

}