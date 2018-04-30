#include "DictionaryTests.h"

#include "Dictionary.h"
#include "Misc.h"

#include <iostream>
#include <string>
#include <Windows.h>

void DictionaryTests::testAddElements(bool aClearFlag, bool aPauseFlag)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	TestSuite::BeginTest("Dictionary, Add Elements", aClearFlag);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Build Dictionary:" << std::endl;

	int I1 = 1;
	int I2 = 2;
	int I3 = 3;

	std::string S1 = "One";
	std::string S2 = "Two";
	std::string S3 = "Three";

	Container::Dictionary<int, std::string> lDictionary;

	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "Adding Element: " << "[" << I1 << ", " << S1 << "]" << std::endl;
	lDictionary.addItem(I1, S1);
	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "Adding Element: " << "[" << I2 << ", " << S2 << "]" << std::endl;
	lDictionary.addItem(I2, S2);
	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "Adding Element: " << "[" << I3 << ", " << S3 << "]" << std::endl;
	lDictionary.addItem(I3, S3);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Dictionary Built!" << std::endl << std::endl;

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Display Dictionary:" << std::endl;
	std::cout << lDictionary;

	TestSuite::EndTest(aPauseFlag);
}

void DictionaryTests::testRemoveElements(bool aClearFlag, bool aPauseFlag)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	TestSuite::BeginTest("Dictionary, Remove Elements", aClearFlag);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Build Dictionary:" << std::endl;

	int I1 = 1;
	int I2 = 2;
	int I3 = 3;

	std::string S1 = "One";
	std::string S2 = "Two";
	std::string S3 = "Three";

	Container::Dictionary<int, std::string> lDictionary;

	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "Adding Element: " << "[" << I1 << ", " << S1 << "]" << std::endl;
	lDictionary.addItem(I1, S1);
	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "Adding Element: " << "[" << I2 << ", " << S2 << "]" << std::endl;
	lDictionary.addItem(I2, S2);
	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "Adding Element: " << "[" << I3 << ", " << S3 << "]" << std::endl;
	lDictionary.addItem(I3, S3);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Dictionary Built!" << std::endl << std::endl;

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Display Dictionary:" << std::endl;
	std::cout << lDictionary;

	SetConsoleTextAttribute(hConsole, 2);
	std::cout << std::endl << std::endl << "Removing Element: " << "[" << I2 << ", " << S2 << "]" << std::endl;
	lDictionary.removeValue(I2);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Display Dictionary:" << std::endl;
	std::cout << lDictionary;


	TestSuite::EndTest(aPauseFlag);
}

void DictionaryTests::testGetValue(bool aClearFlag, bool aPauseFlag)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	TestSuite::BeginTest("Dictionary, Fetch Values", aClearFlag);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Build Dictionary:" << std::endl;

	int I1 = 1;
	int I2 = 2;
	int I3 = 3;

	std::string S1 = "One";
	std::string S2 = "Two";
	std::string S3 = "Three";

	Container::Dictionary<int, std::string> lDictionary;

	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "Adding Element: " << "[" << I1 << ", " << S1 << "]" << std::endl;
	lDictionary.addItem(I1, S1);
	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "Adding Element: " << "[" << I2 << ", " << S2 << "]" << std::endl;
	lDictionary.addItem(I2, S2);
	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "Adding Element: " << "[" << I3 << ", " << S3 << "]" << std::endl;
	lDictionary.addItem(I3, S3);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Dictionary Built!" << std::endl << std::endl;

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Display Dictionary Element:" << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Element " << I2 << ": " << lDictionary.getValue(I2);

	TestSuite::EndTest(aPauseFlag);
}
