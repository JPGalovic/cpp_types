#pragma once

#include <string>

class TestSuite
{
public:
	static void BeginTest(std::string aTestName, bool aClearFlag);
	static void EndTest(bool aPauseFlag);
};