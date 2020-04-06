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

	void parseString(string studentRecord); // Parses string, creates Student object, adds record to roster
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degree);
	bool remove(string studentID); // Removes a student record based on studentID
	void printAll(); // Prints all student records in the roster
	void printAverageDaysInCourse(string studentID); // Prints a certain student's average time to complete a course
	void printInvalidEmails(); // Will locate and print student records with invalid email addresses
	void printByDegreeProgram(DegreeProgram degree); // Prints all student records by a certain DegreeProgram value

	~Roster(); // Destructor

private:
	int lastIndex; // Index of last student record in the roster (how many entries are in the roster)
	int capacity; // Max size of the roster (how many records allowed)
	Student** classRosterArray; // An array of pointers to the data in the student roster
};