#include "roster.h"
#include "degree.h"
#include "student.h"
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
	cout << "Hi there!" << "My name is " << userName << " and my WGU Student ID number is " << wGUStudentID << ". " << "\n";
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

	// Data to be parsed, printed, and acted upon
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

	return 0;
}