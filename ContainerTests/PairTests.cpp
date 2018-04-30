#include "PairTests.h"

#include "Pair.h"
#include "Misc.h"

#include <iostream>
#include <string>
#include <Windows.h>

void PairTests::testBasicValues(bool aClearFlag, bool aPauseFlag)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	TestSuite::BeginTest("Pair, Basic Values", aClearFlag);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Build Pair:" << std::endl;
	int I1 = 1;
	std::string S1 = "One";

	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "[" << I1 << ", " << S1 << "]" << std::endl;
	Container::Pair<int, std::string> P1(I1, S1);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Pair Built!" << std::endl << std::endl;

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Display Pair:" << std::endl;
	std::cout << P1;

	TestSuite::EndTest(aPauseFlag);
}
