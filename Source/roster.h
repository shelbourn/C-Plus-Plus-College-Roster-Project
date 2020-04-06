#pragma once
#include <string>
#include <iostream>
#include "degree.h"
#include "student.h"

// Setting the Roster class, which holds a database of student records
class Roster
{
public:
	Roster(); // Empty constructor to set the Roster to default values
	Roster(int capacity); // Sets the max size (number of records) for the Roster

	Student* getStudentRecordAt(int index);

	void parseStringAdd(string studentRecord); // Parses string, creates Student object, adds record to roster
	void addStudentRecord(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degree);
	void printAllRecords(); // Prints all student records in the roster
	bool removeStudentRecord(string studentID); // Removes a student record based on studentID


private:

};