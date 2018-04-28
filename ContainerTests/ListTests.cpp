#include "ListTests.h"

#include <string>
#include <iostream>
#include <Windows.h>

#include "List.h"

void ListTests::testPushFront()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("CLS");

	SetConsoleTextAttribute(hConsole, 10);
	std::cout << "Testing: List.PushFront()." << std::endl << std::endl;

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Build List:" << std::endl;
	std::string S1("AAAA");
	std::string S2("BBBB");
	std::string S3("CCCC");
	std::string S4("DDDD");

	Container::List<std::string> lList;

	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "Pushing S4 to Front of List." << std::endl;
	lList.pushFront(S4);
	std::cout << "Pushing S3 to Front of List." << std::endl;
	lList.pushFront(S3);
	std::cout << "Pushing S2 to Front of List." << std::endl;
	lList.pushFront(S2);
	std::cout << "Pushing S1 to Front of List." << std::endl;
	lList.pushFront(S1);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "List Built!" << std::endl << std::endl;

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Display List:" << std::endl;

	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "Top to bottom: " << lList.size() << " elements." << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
	for (Container::ListNodeIterator<std::string> iter = lList.getIterator(); iter != iter.rightEnd(); iter++)
		std::cout << *iter << std::endl;

	SetConsoleTextAttribute(hConsole, 10);
	std::cout << std::endl << std::endl << "Testing: Complete, please check results are as expected." << std::endl;
	system("PAUSE");
}

void ListTests::testPushBack()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("CLS");

	SetConsoleTextAttribute(hConsole, 10);
	std::cout << "Testing: List.PushBack()." << std::endl << std::endl;

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Build List:" << std::endl;
	std::string S1("AAAA");
	std::string S2("BBBB");
	std::string S3("CCCC");
	std::string S4("DDDD");

	Container::List<std::string> lList;

	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "Pushing S4 to Back of List." << std::endl;
	lList.pushBack(S4);
	std::cout << "Pushing S3 to Back of List." << std::endl;
	lList.pushBack(S3);
	std::cout << "Pushing S2 to Back of List." << std::endl;
	lList.pushBack(S2);
	std::cout << "Pushing S1 to Back of List." << std::endl;
	lList.pushBack(S1);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "List Built!" << std::endl << std::endl;

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Display List:" << std::endl;

	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "Top to bottom: " << lList.size() << " elements." << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
	for (Container::ListNodeIterator<std::string> iter = lList.getIterator(); iter != iter.rightEnd(); iter++)
		std::cout << *iter << std::endl;

	SetConsoleTextAttribute(hConsole, 10);
	std::cout << std::endl << std::endl << "Testing: Complete, please check results are as expected." << std::endl;
	system("PAUSE");
}

void ListTests::testRemove()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("CLS");

	SetConsoleTextAttribute(hConsole, 10);
	std::cout << "Testing: List.Remove()." << std::endl << std::endl;

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Build List:" << std::endl;
	std::string S1("AAAA");
	std::string S2("BBBB");
	std::string S3("CCCC");
	std::string S4("DDDD");

	Container::List<std::string> lList;

	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "Pushing S4 to Front of List." << std::endl;
	lList.pushFront(S4);
	std::cout << "Pushing S3 to Front of List." << std::endl;
	lList.pushFront(S3);
	std::cout << "Pushing S2 to Front of List." << std::endl;
	lList.pushFront(S2);
	std::cout << "Pushing S1 to Front of List." << std::endl;
	lList.pushFront(S1);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "List Built!" << std::endl << std::endl;

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Display List:" << std::endl;

	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "Top to bottom: " << lList.size() << " elements." << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
	for (Container::ListNodeIterator<std::string> iter = lList.getIterator(); iter != iter.rightEnd(); iter++)
		std::cout << *iter << std::endl;

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << std::endl << std::endl << "Remove Element from List:" << std::endl;

	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "Removing S3 from List." << std::endl << std::endl;
	lList.remove(S3);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Element Removed." << std::endl;

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Display List:" << std::endl;

	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "Top to bottom: " << lList.size() << " elements." << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
	for (Container::ListNodeIterator<std::string> iter = lList.getIterator(); iter != iter.rightEnd(); iter++)
		std::cout << *iter << std::endl;

	SetConsoleTextAttribute(hConsole, 10);
	std::cout << std::endl << std::endl << "Testing: Complete, please check results are as expected." << std::endl;
	system("PAUSE");
}

void ListTests::testArraySubscriptOperator()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("CLS");

	SetConsoleTextAttribute(hConsole, 10);
	std::cout << "Testing: List.Operator[]." << std::endl << std::endl;

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Build List:" << std::endl;
	std::string S1("AAAA");
	std::string S2("BBBB");
	std::string S3("CCCC");
	std::string S4("DDDD");

	Container::List<std::string> lList;

	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "Pushing S4 to Front of List." << std::endl;
	lList.pushFront(S4);
	std::cout << "Pushing S3 to Front of List." << std::endl;
	lList.pushFront(S3);
	std::cout << "Pushing S2 to Front of List." << std::endl;
	lList.pushFront(S2);
	std::cout << "Pushing S1 to Front of List." << std::endl;
	lList.pushFront(S1);

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "List Built!" << std::endl << std::endl;

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Display Element from List at Index:" << std::endl;

	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "Index 0 to N: " << lList.size() << " elements." << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
	for (int i = 0; i < lList.size(); i++)
	{
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "Element " << i << ": ";
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << lList[i] << std::endl;
	}
		

	SetConsoleTextAttribute(hConsole, 10);
	std::cout << std::endl << std::endl << "Testing: Complete, please check results are as expected." << std::endl;
	system("PAUSE");
}
