#pragma once

#include <string>


/**
 * Test Suite Misc Functions
 */

class TestSuite
{
public:
	static bool ClearFlag;
	static bool PauseFlag;

	static void BeginTest(std::string aTestName, bool aClearFlag);
	static void EndTest(bool aPauseFlag);
};