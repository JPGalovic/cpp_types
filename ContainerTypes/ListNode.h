#pragma once
/**
 * Doubly Linked List Node, defines the template for nodes used in lists.
 * Adapted from code developed for COS30008 - Data Structures and Patters
 * @author  J.P.Galovic
 * @version v1.2.0
 * @date    10-05-2018
 */

#include <iostream>
#include <Windows.h>

namespace Container
{
	template<class T>
	class ListNode
	{
	private:
		T fValue;
		ListNode<T>* fNext;
		ListNode<T>* fPrevious;

		ListNode()
		{
			fNext = &NIL;
			fPrevious = &NIL;

			fValue = T();
		}
	public:
		// Construction and Destruction
		static ListNode<T> NIL;
		ListNode(const T& aValue);

		// Getters
		const T& getValue() const;
		const ListNode<T>& getNext() const;
		const ListNode<T>& getPrevious() const;

		// Setters
		void prepend(ListNode<T>& aNode);
		void append(ListNode<T>& aNode);
		void remove();

		void setValue(const T& aValue);

		friend std::ostream& operator<<(std::ostream& aOStream, const ListNode<T>& aListNode)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 14);
			aOStream << "(";

			if (&aListNode.getPrevious() == &NIL)
			{
				SetConsoleTextAttribute(hConsole, 12);
				aOStream << "<NULL>";
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 15);
				aOStream << aListNode.getPrevious().getValue();
			}

			SetConsoleTextAttribute(hConsole, 14);
			aOStream << ", ";
			SetConsoleTextAttribute(hConsole, 15);
			aOStream << aListNode.getValue();
			SetConsoleTextAttribute(hConsole, 14);
			aOStream << ", ";

			if (&aListNode.getNext() == &NIL)
			{
				SetConsoleTextAttribute(hConsole, 12);
				aOStream << "<NULL>";
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 15);
				aOStream << aListNode.getNext().getValue();
			}

			SetConsoleTextAttribute(hConsole, 14);
			aOStream << ")";
			SetConsoleTextAttribute(hConsole, 15);
			return aOStream;
		}
	};

	/**
	 * Null Sentinal Definition
	 */
	template<class T>
	ListNode<T> ListNode<T>::NIL;

	/**
	 * Class Constructor, Sets node with no next or previous connections
	 * @param aValue, value to set node with.
	 */
	template<class T>
	inline ListNode<T>::ListNode(const T & aValue)
	{
		fNext = &NIL;
		fPrevious = &NIL;

		fValue = aValue;
	}

	/**
	* Gets value of node.
	* @return refernce to value of node.
	*/
	template<class T>
	inline const T & ListNode<T>::getValue() const
	{
		return fValue;
	}

	/**
	* Gets refernce to next connected node.
	* @return refernce to next node.
	*/
	template<class T>
	inline const ListNode<T>& ListNode<T>::getNext() const
	{
		return *fNext;
	}
	/**
	* Gets refernce to previous connected node.
	* @return refernce to previous node.
	*/
	template<class T>
	inline const ListNode<T>& ListNode<T>::getPrevious() const
	{
		return *fPrevious;
	}

	/**
	* Prepends node with a given node, in the case that this is not the begining of the list, node is inserted prepend.
	* @param aNode, refernce to node.
	*/
	template<class T>
	inline void ListNode<T>::prepend(ListNode<T>& aNode)
	{
		aNode.fNext = this;

		if (fPrevious != &NIL) // If not start of list, insert on previous.
		{
			aNode.fPrevious = fPrevious;
			fPrevious->fNext = &aNode;
		}

		fPrevious = &aNode;
	}

	/**
	* Appends node with a given node, in the case that this is not the begining of the list, node is inserted append.
	* @param aNode, refernce to node.
	*/
	template<class T>
	inline void ListNode<T>::append(ListNode<T>& aNode)
	{
		aNode.fPrevious = this;

		if (fNext != &NIL)
		{
			aNode.fNext = fNext;
			fNext->fPrevious = &aNode;
		}

		fNext = &aNode;
	}

	/**
	* Removes this node from list, does note delete.
	*/
	template<class T>
	inline void ListNode<T>::remove()
	{
		if (fPrevious != &NIL)
			fPrevious->fNext = fNext;
		if (fNext != &NIL)
			fNext->fPrevious = fPrevious;
	}

	/**
	* Sets value of node.
	* @param aValue, value to set.
	*/
	template<class T>
	inline void ListNode<T>::setValue(const T & aValue)
	{
		fValue = aValue;
	}
}
