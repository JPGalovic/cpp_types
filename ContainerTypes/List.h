#pragma once
/**
 * Doubly Linked List, defines the template for lists.
 * Adapted from code developed for COS30008 - Data Structures and Patters
 * @author  J.P.Galovic
 * @version v1.0.4
 * @date    26-04-2018
 */

#include "ListNodeIterator.h"

#include <stdexcept>

namespace Container
{
	template<class T>
	class List
	{
	private:
		ListNode<T>* fTop;
		ListNode<T>* fLast;

		int fCount;

	public:
		// Construction and Destruction
		List();
		List(const List<T>& aOtherList);

		~List();

		// Getters
		List<T>& operator=(const List<T>& aOtherList);

		bool isEmpty() const;
		int size() const;

		const T& getAt(unsigned int aIndex) const;
		const T& operator[](unsigned int aIndex) const;

		ListNodeIterator<T> getIterator() const;

		// Setters
		void pushFront(const T& aElement);
		void pushBack(const T& aElement);
		void add(const T& aElement);

		void remove(const T& aElement);
		void removeAt(unsigned int aIndex);
	};

	/**
	 * Class Constructor.
	 */
	template<class T>
	inline List<T>::List()
	{
		fTop = nullptr;
		fLast = nullptr;
		fCount = 0;
	}

	/**
	 * Copy Constructor.
	 * @param aOtherList, refernce to list to be copied.
	 */
	template<class T>
	inline List<T>::List(const List<T>& aOtherList)
	{
		fTop = nullptr;
		fLast = nullptr;
		fCount = 0;

		for (ListNodeIterator<T> iter = aOtherList.getIterator().first(); iter != iter.rightEnd(); iter++)
			pushBack(*iter);
	}

	/**
	 * Class Destructor.
	 */
	template<class T>
	inline List<T>::~List()
	{
		while (fTop != nullptr)
		{
			ListNode<T>* lTemp = (ListNode<T>*) &fTop->getNext();
			fTop->remove();
			delete fTop;
			fTop = lTemp;
		}
	}

	/**
	 * Assignment Operator, works in a simmilar way to the copy constructor.
	 * @param aOtherList, refernce to list to be copied.
	 */
	template<class T>
	inline List<T>& List<T>::operator=(const List<T>& aOtherList)
	{
		if (&aOtherList != this)
		{
			while (fTop != nullptr)
			{
				ListNode<T>* lTemp = (ListNode<T>*) &fTop->getNext();
				fTop->remove();
				delete fTop;
				fTop = lTemp;
			}

			fTop = nullptr;
			fLast = nullptr;
			fCount = 0;

			for (ListNodeIterator<T> iter = aOtherList.getIterator().first(); iter != iter.rightEnd(); iter++)
				pushBack(*iter);
		}
		return *this;
	}
	template<class T>

	/**
	 * Determines if list is empty.
	 * @return true if list is empty.
	 */
	inline bool List<T>::isEmpty() const
	{
		return fTop == nullptr;
	}

	/**
	 * Gets number of elements in list.
	 * @return Size of list.
	 */
	template<class T>
	inline int List<T>::size() const
	{
		return fCount;
	}

	/**
	 * Gets value of element at a specific index.
	 * @param aIndex, index of element to return.
	 * @return value of element found.
	 * @throw out_of_range error if aIndex is greater than count.
	 */
	template<class T>
	inline const T & List<T>::getAt(unsigned int aIndex) const
	{
		if (!(aIndex < fCount))
			throw std::range_error("Index out of bounds.");

		ListNode<T>* lNode = fTop;

		while (aIndex)
		{
			aIndex--;
			lNode = (ListNode<T>*) lNode->getNext();
		}

		return lNode->getValue();
	}

	/**
	 * Bracket operator, gets value of element at a specific index.
	 * @param aIndex, index of element to return.
	 * @return value of elemen found.
	 * @throw out_of_range error if aIndex is greter than count.
	 */
	template<class T>
	inline const T & List<T>::operator[](unsigned int aIndex) const
	{
		try
		{
			return getAt(aIndex);
		}
		catch (const std::range_error& e)
		{
			throw e;
		}
	}

	/**
	 * Gets list iterator.
	 * return list iterator.
	 */
	template<class T>
	inline ListNodeIterator<T> List<T>::getIterator() const
	{
		return ListNodeIterator<T>(*fTop);
	}

	/**
	 * Pushes element to front of list.
	 * @param aElement, refernce to element to add.
	 */
	template<class T>
	inline void List<T>::pushFront(const T & aElement)
	{
		ListNode<T>* lNewElement = new ListNode<T>(aElement);

		if (fTop == nullptr)
		{
			fTop = lNewElement;
			fLast = lNewElement;
		} 
		else
		{
			fTop->prepend(*lNewElement);
			fTop = lNewElement;
		}

		fCount++;
	}

	/**
	 * Pushes element to back of list.
	 * @param aElement, refernce to element to add.
	 */
	template<class T>
	inline void List<T>::pushBack(const T & aElement)
	{
		ListNode<T>* lNewElement = new ListNode<T>(aElement);

		if (fTop == nullptr)
		{
			fTop = lNewElement;
			fLast = lNewElement;
		}
		else
		{
			fLast->append(*lNewElement);
			fLast = lNewElement;
		}

		fCount++;
	}

	/**
	 * Adds elemet to back of list.
	 * @param aElement, refernce to element to add.
	 */
	template<class T>
	inline void List<T>::add(const T & aElement)
	{
		pushBack(aElement);
	}

	/**
	 * Removes a specified elemet from the list.
	 * @param aElement, refernce to element to remove.
	 */
	template<class T>
	inline void List<T>::remove(const T & aElement)
	{
		ListNode<T>* lNode = fTop;

		while (lNode != nullptr)
		{
			if (lNode->getValue() == aElement)
				break;
			lNode = (ListNode<T>*)
		}

		if (lNode != nullptr)
		{
			if (lNode == fTop)
				fTop = (ListNode<T>*)&lNode->getNext();
			if (lNode == fLast)
				fLast = (ListNode<T>*)&lNode->getPrevious();

			lNode->remove();
			delete lNode;
			fCount--;
		}
	}

	/**
	 * Removes element from a given index.
	 * @param aIndex, index of element to remove.
	 */
	template<class T>
	inline void List<T>::removeAt(unsigned int aIndex)
	{
		try
		{
			remove(getAt(aIndex));
		}
		catch (const std::range_error& e)
		{
			throw e;
		}
	}
}
