#include "ListNodeTests.h"

#include <iostream>
#include <string>
#include <Windows.h>

#include "ListNode.h"
#include "Misc.h"

/** 
 * Tests Append List Item
 */
void ListNodeTests::testAppend(bool aClearFlag, bool aPauseFlag)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	TestSuite::BeginTest("ListNode, Append", aClearFlag);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Build List (From Nodes):" << std::endl;
	std::string S1 = std::string("One");
	std::string S2 = std::string("Two");
	std::string S3 = std::string("Three");
	std::string S4 = std::string("Four");

	typedef Container::ListNode<std::string> StringNode;

	StringNode N1(S1);
	StringNode N2(S2);
	StringNode N3(S3);
	StringNode N4(S4);

	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "Appending N1 with N4." << std::endl;
	N1.append(N4);
	std::cout << "Appending N1 with N3." << std::endl;
	N1.append(N3);
	std::cout << "Appending N1 with N2." << std::endl;
	N1.append(N2);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "List Built!" << std::endl << std::endl;

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Display Nodes:" << std::endl;

	for (const StringNode* PN = &N1; PN != nullptr; PN = &PN->getNext())
	{
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "(";

		if (&PN->getPrevious() == nullptr)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "<NULL>";
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 15);
			std::cout << PN->getPrevious().getValue();
		}

		SetConsoleTextAttribute(hConsole, 14);
		std::cout << ", ";
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << PN->getValue();
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << ", ";

		if (&PN->getNext() == nullptr)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "<NULL>";
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 15);
			std::cout << PN->getNext().getValue();
		}

		SetConsoleTextAttribute(hConsole, 14);
		std::cout << ")" << std::endl;
	}

	TestSuite::EndTest(aPauseFlag);
}

void ListNodeTests::testPrepend(bool aClearFlag, bool aPauseFlag)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	TestSuite::BeginTest("ListNode, Prepend", aClearFlag);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Build List (From Nodes):" << std::endl;
	std::string S1 = std::string("One");
	std::string S2 = std::string("Two");
	std::string S3 = std::string("Three");
	std::string S4 = std::string("Four");

	typedef Container::ListNode<std::string> StringNode;

	StringNode N1(S1);
	StringNode N2(S2);
	StringNode N3(S3);
	StringNode N4(S4);

	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "Prepending N4 with N1." << std::endl;
	N4.prepend(N1);
	std::cout << "Prepending N4 with N2." << std::endl;
	N4.prepend(N2);
	std::cout << "Prepending N4 with N3." << std::endl;
	N4.prepend(N3);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "List Built!" << std::endl << std::endl;

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Display Nodes:" << std::endl;

	for (const StringNode* PN = &N1; PN != nullptr; PN = &PN->getNext())
	{
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "(";

		if (&PN->getPrevious() == nullptr)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "<NULL>";
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 15);
			std::cout << PN->getPrevious().getValue();
		}

		SetConsoleTextAttribute(hConsole, 14);
		std::cout << ", ";
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << PN->getValue();
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << ", ";

		if (&PN->getNext() == nullptr)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "<NULL>";
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 15);
			std::cout << PN->getNext().getValue();
		}

		SetConsoleTextAttribute(hConsole, 14);
		std::cout << ")" << std::endl;
	}

	TestSuite::EndTest(aPauseFlag);
}
