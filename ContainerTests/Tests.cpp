#include "Tests.h"

#include <iostream>
#include <Windows.h>

#include "ListNodeTests.h"
#include "ListTests.h"
#include "Misc.h"

/**
 * Tests avalible console handle settings.
 */
void consoleHandleTest(bool aClearFlag, bool aPauseFlag)
{
	// Console Handle Settings
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	TestSuite::BeginTest("Console Text Attribute", aClearFlag);

	for (int i = 0; i < 256; i++)
	{
		SetConsoleTextAttribute(hConsole, i);
		std::cout << "Console Atribute #" << i << ". The quick brown fox jumped over the lazy dog." << std::endl;
	}

	TestSuite::EndTest(aPauseFlag);
}

void testListNodes(bool aClearFlag, bool aPauseFlag)
{
	ListNodeTests::testAppend(aClearFlag, aPauseFlag);
	ListNodeTests::testPrepend(aClearFlag, aPauseFlag);
}

void testLists(bool aClearFlag, bool aPauseFlag)
{
	ListTests::testPushFront(aClearFlag, aPauseFlag);
	ListTests::testPushBack(aClearFlag, aPauseFlag);
	ListTests::testRemove(aClearFlag, aPauseFlag);
	ListTests::testArraySubscriptOperator(aClearFlag, aPauseFlag);
}
