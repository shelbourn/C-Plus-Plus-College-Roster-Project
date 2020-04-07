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

	// Setting user data variables to be used in first line of output
	const string courseTitle = "C867: Scripting & Programming - Applications";
	const string programmingLanguage = "C++";
	const string wGUStudentID = "001059665";
	const string userName = "Matthew Shelbourn";

	// Data to be parsed, printed, and acted upon
	const string studentData[5] =
	{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Matthew,Shelbourn,mshelbo@wgu.edu,39, 47,13,26,SOFTWARE"
	};


}