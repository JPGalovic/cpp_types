#pragma once
/**
 * Doubly Linked List Node Iterator, provides a means to transverse lists in an iterive manor.
 * Adapted from code developed for COS30008 - Data Structures and Patters
 * @author  J.P.Galovic
 * @version v1.0.4
 * @date    25-04-2018
 */

#include "ListNode.h"

namespace Container
{
	template<class T>
	class ListNodeIterator
	{
	private:
		enum IterState { BEFORE, DATA, AFTER };

		IterState fState;

		const ListNode<T>* fLeftmost;
		const ListNode<T>* fRightmost;
		const ListNode<T>* fCurrent;

	public:
		// Construction and Destruction
		ListNodeIterator(const ListNode<T>& aList);

		// Getters
		const T& operator*() const;

		ListNodeIterator<T>& operator++();
		ListNodeIterator<T> operator++(int);
		ListNodeIterator<T>& operator--();
		ListNodeIterator<T> operator--(int);

		bool operator==(const ListNodeIterator<T>& aOtherIter) const;
		bool operator!=(const ListNodeIterator<T>& aOtherIter) const;

		ListNodeIterator<T> leftEnd() const;
		ListNodeIterator<T> first() const;
		ListNodeIterator<T> last() const;
		ListNodeIterator<T> rightEnd() const;
	};

	/**
	* Class Constructor.
	*/
	template<class T>
	inline ListNodeIterator<T>::ListNodeIterator(const ListNode<T>& aList)
	{
		fLeftmost = &aList;

		while (&fLeftmost->getPrevious() != nullptr)
			fLeftmost = &fLeftmost->getPrevious();

		fCurrent = fLeftmost;

		if (fCurrent != nullptr)
			fState = DATA;
		else
			fState = AFTER;

		fRightmost = &aList;

		while (&fLeftmost->getNext() != nullptr)
			fRightmost = &fRightmost->getNext();
	}

	/**
	* Derefernces current node.
	*/
	template<class T>
	inline const T & ListNodeIterator<T>::operator*() const
	{
		return fCurrent->getValue();
	}

	/**
	* Prefix Increment.
	*/
	template<class T>
	inline ListNodeIterator<T>& ListNodeIterator<T>::operator++()
	{
		switch (fState)
		{
		case BEFORE:
			fCurrent = fLeftmost;
			if (fCurrent == nullptr)
				fState = AFTER;
			else
				fState = DATA;
			break;
		case DATA:
			fCurrent = &fCurrent->getNext();
			if (fCurrent == nullptr)
				fCurrent = AFTER;
		default:
			break;
		}
		return *this;
	}

	/**
	* Postfix Increment.
	*/
	template<class T>
	inline ListNodeIterator<T> ListNodeIterator<T>::operator++(int)
	{
		ListNodeIterator<T> lTemp = *this;
		++(*this);
		return lTemp;
	}

	/**
	* Prefix Decrement.
	*/
	template<class T>
	inline ListNodeIterator<T>& ListNodeIterator<T>::operator--()
	{
		switch (fState)
		{
		case AFTER:
			fCurrent = fRightmost;
			if (fCurrent == nullptr)
				fState = BEFORE;
			else
				fState = DATA;
			break;
		case DATA:
			fCurrent = &fCurrent->getPrevious();
			if (fCurrent == nullptr)
				fCurrent = BEFORE;
		default:
			break;
		}
		return *this;
	}

	/**
	* Postfix Decrement.
	*/
	template<class T>
	inline ListNodeIterator<T> ListNodeIterator<T>::operator--(int)
	{
		ListNodeIterator<T> lTemp = *this;
		--(*this);
		return lTemp;
	}

	/**
	* Equality Operator.
	*/
	template<class T>
	inline bool ListNodeIterator<T>::operator==(const ListNodeIterator<T>& aOtherIter) const
	{
		return fLeftmost == aOtherIter.fLeftmost &&
			fRightmost == aOtherIter.fRightmost &&
			fCurrent == aOtherIter.fCurrent &&
			fState == aOtherIter.fState;
	}

	/**
	* Not Eqlual Operator.
	*/
	template<class T>
	inline bool ListNodeIterator<T>::operator!=(const ListNodeIterator<T>& aOtherIter) const
	{
		return !(*this == aOtherIter);
	}

	/**
	* Gets before leftmost node.
	* @return Iterator pointing to before leftmost node.
	*/
	template<class T>
	inline ListNodeIterator<T> ListNodeIterator<T>::leftEnd() const
	{
		ListNodeIterator<T> lTemp = *this;

		lTemp.fCurrent == nullptr;
		lTemp.fState == BEFORE;

		return lTemp;
	}

	/**
	* Gets first node.
	* @return Iterator pointing to first node.
	*/
	template<class T>
	inline ListNodeIterator<T> ListNodeIterator<T>::first() const
	{
		return ++(leftEnd());
	}

	/**
	* Gets last node.
	* @return Iterator pointing to last node.
	*/
	template<class T>
	inline ListNodeIterator<T> ListNodeIterator<T>::last() const
	{
		return --(rightEnd());
	}

	/**
	* Gets after rightmost node.
	* @return Iterator pointing to after rightmost node.
	*/
	template<class T>
	inline ListNodeIterator<T> ListNodeIterator<T>::rightEnd() const
	{
		ListNodeIterator<T> lTemp = *this;

		lTemp.fCurrent == nullptr;
		lTemp.fState == AFTER;

		return lTemp;
	}
}
