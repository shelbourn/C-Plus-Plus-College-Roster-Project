#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
using std::cout;
using std::cerr;
using namespace std;

// Defining main program operations
// Supplying data, calling functions/methods, demonstrating functionality, releasing allocated memory with destructor

int main()
{
	// Setting the number of student records
	int numStudentRecords = 5;

	// Setting user data variables to print info relating to the user of program
	const string courseTitle = "C867: Scripting & Programming - Applications";
	const string programmingLanguage = "C++";
	const string wGUStudentID = "001059665";
	const string userName = "Matthew Shelbourn";

	// Welcome message
	cout << "Hi there! " << "My name is " << userName << " and my WGU Student ID number is " << wGUStudentID << ". " << "\n";
	cout << "This program is the finished product of a course project for " << courseTitle << "." << "\n";
	cout << "This program was built using the tried and true programming language " << programmingLanguage << "." << "\n";
	cout << "It will demonstrate how several C++ components can be implemented to create a console program.\n";
	cout << "These components include, but are not limited to:\n";
	cout << "Setters\n";
	cout << "Getters\n";
	cout << "Methods\n";
	cout << "Functions\n";
	cout << "Loops\n";
	cout << "Pointers\n";
	cout << "Console Printing\n";
	cout << "Use of Enumerated Data Types\n";
	cout << "Classes\n";
	cout << "Scoping\n";
	cout << "Error Handling\n";
	cout << "And Much More!!!\n";
	cout << "\n";
	cout << "ENJOY! =)\n";

	// Data to be parsed and utilized in program
	const string studentData[5] =
	{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Matthew,Shelbourn,mshelbo@wgu.edu,39, 47,13,26,SOFTWARE"
	};

	// Creating an instance of the roster named classRoster
	Roster* classRoster = new Roster(numStudentRecords);

	// Parsing and adding student records to classRoster
	cout << "Now parsing student data and adding records to the student roster:\t";
	for (int i = 0; i < numStudentRecords; i++)
	{
		classRoster->parseString(studentData[i]);
	}
	cout << "...PROCESS COMPLETE!\n";

	// Printing all students in classRoster
	cout << "List of all students currently in the student roster:\n\n";
	classRoster->printAll();

	// Printing any invalid emails in classRoster
	cout << "List of all student records with invalid email addresses:\n\n";
	classRoster->printInvalidEmails();

	// Printing average days a student spends in a course using a loop
	cout << "Now printing the average number of days each student spends in a course:\n\n";
	for (int i = 0; i < numStudentRecords; i++)
	{
		classRoster->printAverageDaysInCourse(classRoster->getStudentRecordAt(i)->getStudentID());
	}

	// Printing student records by DegreeProgram
	for (int i = 0; i < 3; i++) classRoster->printByDegreeProgram((DegreeProgram)i);

	// Removing a student record by studentID and printing the resulting classRoster
	cout << "Now removing student record associated with Student ID - A3:\n\n";
	if (classRoster->remove("A3"))
	{
		classRoster->printAll();
		numStudentRecords--;
	}
	else cout << "A student with this ID was not found!\n\n";

	// Removing the student record with the same studentID as above to test error message
	cout << "Now attempting to remove student record A3 agein:\n\n";
	if (classRoster->remove("A3"))
	{
		classRoster->printAll(); 
		numStudentRecords--;
	}
	else cout << "A student with this ID was not found!\n\n";

	// Pausing the program to keep console window showing until 'ENTER' is pressed
	system("pause");

	// Printing confirmation of program execution complete!
	cout << "PROGRAM EXECUTION IS NOW COMPLETE!\n\n";
	cout << "HAVE A FANTABULOUS DAY!!! ;-)\n";
	
	// End of program. Yay!
	return 0;
}