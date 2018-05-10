/**
 * Conatiner Types Testing Methods
 * Main Entry Point
 * @author  J.P.Galovic
 * @version v1.0.0
 * @date    27-04-2018
 */

#include "Tests.h"
#include "Misc.h"

#include <iostream>

int main(int argc, char ** argv)
{
	bool lClearFlag = true;
	bool lPauseFlag = true;
	consoleHandleTest(lClearFlag, lPauseFlag);

	// List Tests
	testListNodes(lClearFlag, lPauseFlag);
	testLists(lClearFlag, lPauseFlag);

	// Dictionary Tests
	testPairs(lClearFlag, lPauseFlag);
	testDictionaries(lClearFlag, lPauseFlag);

	TestSuite::Assert::AreEqual(true, true, "T T");
	TestSuite::Assert::AreEqual(true, false, "T F");

	TestSuite::Assert::AreNotEqual(true, true, "T T");
	TestSuite::Assert::AreNotEqual(true, false, "T F");

	if (!lPauseFlag)
		system("PAUSE");
	return 0;
}