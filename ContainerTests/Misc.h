#pragma once

#include <string>
#include <iostream>

#include <Windows.h>

class TestSuite
{
public:
	static void BeginTest(std::string aTestName, bool aClearFlag);
	static void EndTest(bool aPauseFlag);

	class Assert
	{
	public:
		template<class T>
		static bool AreEqual(const T & aExpected, const T & aActual, const std::string aFailureMessage);

		template<class T>
		static bool AreNotEqual(const T & aExpected, const T & aActual, const std::string aFailureMessage);
	};
};

template<class T>
inline bool TestSuite::Assert::AreEqual(const T & aExpected, const T & aActual, const std::string aFailureMessage)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (aExpected == aActual)
	{
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "Assert::AreEqual: PASS" << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
		return true;
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "Assert::AreEqual: FAIL ";
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << aFailureMessage << std::endl;
		return false;
	}
}

template<class T>
inline bool TestSuite::Assert::AreNotEqual(const T & aExpected, const T & aActual, const std::string aFailureMessage)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (aExpected != aActual)
	{
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "Assert::AreNotEqual: PASS" << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
		return true;
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "Assert::AreNotEqual: FAIL ";
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << aFailureMessage << std::endl;
		return false;
	}
}
