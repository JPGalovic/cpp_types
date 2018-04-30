/**
 * Conatiner Types Testing Methods
 * Main Entry Point
 * @author  J.P.Galovic
 * @version v1.0.0
 * @date    27-04-2018
 */

#include "Tests.h"
#include <iostream>

int main(int argc, char ** argv)
{
	bool lClearFlag = false;
	bool lPauseFlag = false;
	consoleHandleTest(lClearFlag, lPauseFlag);

	// List Tests
	testListNodes(lClearFlag, lPauseFlag);
	testLists(lClearFlag, lPauseFlag);

	// Dictionary Tests
	testPairs(lClearFlag, lPauseFlag);
	testDictionaries(lClearFlag, lPauseFlag);

	if (!lPauseFlag)
		system("PAUSE");
	return 0;
}