#include "Misc.h"

#include <iostream>
#include <Windows.h>

/**
 * Method for preparing Test to run, dependant on flags, screen will be cleared and test identifiers displayed
 * @param aTestName, name of test beign run
 * @param aClearFlag, flag indicating weather to clear screen.
 */
void TestSuite::BeginTest(std::string aTestName, bool aClearFlag)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (aClearFlag)
		system("CLS");

	SetConsoleTextAttribute(hConsole, 10);
	std::cout << "Begining Test: " << aTestName << "." << std::endl << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
}

void TestSuite::EndTest(bool aPauseFlag)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 10);
	std::cout << std::endl << std::endl << "Test Completed: Please review to confirm correct functionality." << std::endl << std::endl;
	SetConsoleTextAttribute(hConsole, 15);

	if (aPauseFlag)
		system("PAUSE");
}
