#include "roster.h"
#include "degree.h"
#include "student.h"
using std::cout;
using std::cerr;
using namespace std;

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
int ageTemp = stoi(record.substr(leftSubStringEnd, rightSubStringEnd - leftSubStringEnd));

// Extracting each value for daysInCourse
// daysInCourse1
leftSubStringEnd = rightSubStringEnd + 1;
rightSubStringEnd = record.find(",", leftSubStringEnd);
int daysInCourse1 = stoi(record.substr(leftSubStringEnd, rightSubStringEnd - leftSubStringEnd));

// daysInCourse2
leftSubStringEnd = rightSubStringEnd + 1;
rightSubStringEnd = record.find(",", leftSubStringEnd);
int daysInCourse2 = stoi(record.substr(leftSubStringEnd, rightSubStringEnd - leftSubStringEnd));

// daysInCourse3
leftSubStringEnd = rightSubStringEnd + 1;
rightSubStringEnd = record.find(",", leftSubStringEnd);
int daysInCourse3 = stoi(record.substr(leftSubStringEnd, rightSubStringEnd - leftSubStringEnd));

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

// Defining remove() method to remove student record by studentID
bool Roster::remove(string studentID)
{
	bool found = false; // Initializes found variable to false
	for (int i = 0; i <= lastIndex; i++)
	{
		// Checks whether the Student ID exists in roster
		if (this->classRosterArray[i]->getStudentID() == studentID)
		{
			// If Student ID exists in roster then remove (delete) it
			found = true;
			delete this->classRosterArray[i];

			// Replaces record at deleted index with record at last index
			this->classRosterArray[i] = this->classRosterArray[lastIndex];

			// Shrinks the roster by one record
			lastIndex--;
		}
		else
		{
			cerr << "ERROR! A STUDENT WITH THIS ID DOES NOT EXIST IN THE ROSTER!" << "\n";
		}
	}
	return found;
}

// Defining printAll() method using for loop
void Roster::printAll()
{
	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

// Defining the printAverageDaysInCourse() method
void Roster::printAverageDaysInCourse(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		// Validates studentID exists in roster
		if (this->classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			int* days = classRosterArray[i]->getDaysToCompleteCourse();
			cout << "The average number of days to complete a course for student with ID " << studentID << " is " << days[0] + days[1] + days[2] / 3 << "/n";
		}
	}
	if (!found) cout << "Student with ID " << studentID << " not found!" << "\n";
}

// Defining printInvalidEmails() method
void Roster::printInvalidEmails()
{
	cout << "Students with invalid email addresses in roster:\n";
	bool any = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		// Not sure why the line below throws an error
		// Initializing a string pointer probably isn't necessary this function only has 1 loop scope

		//string* email = classRosterArray[i]->getEmailAddress();

		// *** Check to see if the line below works or not
		// Searches each email address string for "." or "@"
		if (this->classRosterArray[i]->getEmailAddress().find(".") == string::npos 
			|| this->classRosterArray[i]->getEmailAddress().find("@") == string::npos 
			|| this->classRosterArray[i]->getEmailAddress().find(" ") != string::npos)
		{
			any = true;
			cout << "Student ID: " << classRosterArray[i]->getStudentID();
			cout << " -- " << "Email Address: " << classRosterArray[i]->getEmailAddress();
		}
		if (any) cout << "\n";
	}
	if (!any) cout << "No students with invalid email addresses in roster.";
}

// Defining printByDegreeProgram() method
void Roster::printByDegreeProgram(DegreeProgram degree)
{
	// ****Hopefully the casting performed in main.cpp will fix this
	cout << "Printing all student records for the " << degreeProgramArray[degree] << " degree program:" << "\n";
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getDegreeProgram() == degree) this->classRosterArray[i]->print();
	}
}

// Defining destructor for Roster -- THIS DESTROYS ALL STUDENT RECORDS!!!
Roster::~Roster()
{
	// Deletes each student record one-by-one with loop
	for (int i = 0; i <= lastIndex; i++)
	{
		delete this->classRosterArray[i];
	}

	// Deletes the array of pointers to the student records
	delete classRosterArray;
}