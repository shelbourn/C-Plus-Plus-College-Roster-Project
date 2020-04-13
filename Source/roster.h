/***** REQUIREMENT B */
/***** REQUIREMENT E */
#pragma once
#include <string>
#include <iostream>
#include "degree.h"
#include "student.h"
using std::cout;

// Setting the Roster class, which holds a database of student records
class Roster
{
private:
	int lastIndex; // Index of last student record in the roster (how many entries are in the roster)
	int capacity; // Max size of the roster (Number of pointers in array. How many records allowed)

	/***** REQUIREMENT E.1 */
	Student** classRosterArray; // classRosterArray is an array of pointers to the data in the student roster

	/***** REQUIREMENT E.3 */
public:
	Roster(); // Empty constructor to set the Roster to default values
	Roster(int capacity); // Sets the max size (number of records) for the Roster

	Student* getStudentRecordAt(int index);

	void parseString(string studentRecord); // Parses string, creates Student object, adds record to roster
	void add(string stuID, string fName, string lName, string email, int ageTemp, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeTemp);
	bool remove(string studentID); // Removes a student record based on studentID
	void printAll(); // Prints all student records in the roster
	void printAverageDaysInCourse(string studentID); // Prints a certain student's average time to complete a course
	void printInvalidEmails(); // Will locate and print student records with invalid email addresses
	void printByDegreeProgram(string degree); // Prints all student records by a certain DegreeProgram value

	// Destructor for Roster
	~Roster();
};