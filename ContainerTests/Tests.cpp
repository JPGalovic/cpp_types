#include "Tests.h"

#include <iostream>
#include <Windows.h>

#include "ListNodeTests.h"

/**
 * Tests avalible console handle settings.
 */
void consoleHandleTest()
{
	// Console Handle Settings
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("CLS");

	SetConsoleTextAttribute(hConsole, 10);
	std::cout << "Testing: SetConsoleTextAttribute()." << std::endl << std::endl;

	for (int i = 0; i < 256; i++)
	{
		SetConsoleTextAttribute(hConsole, i);
		std::cout << "Console Atribute #" << i << ". The quick brown fox jumped over the lazy dog." << std::endl;
	}

	SetConsoleTextAttribute(hConsole, 10);
	std::cout << std::endl << std::endl << "Testing: Complete, please check results are as expected." << std::endl;
	system("PAUSE");
}

void testListNodes()
{
	ListNodeTests::testAppend();
	ListNodeTests::testPrepend();


	/*ListNodeTests lTester;

	lTester.testAppend();
	lTester.testPrepend();*/
}
