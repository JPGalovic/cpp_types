#pragma once
/**
 * Dynamic Queue Iterator.
 * Adapted from code developed for COS30008 - Data Structures and Patters
 * @author  J.P.Galovic
 * @version v1.2.0
 * @date    10-05-2018
 */
#include "Queue.h"


namespace Container
{
	template<class T>
	class QueueIterator
	{
	private:
		Queue<T> fQueue;
	public:
		// Construction and Destruction
		QueueIterator(const Queue<T> & aQueue);

		// Getters
		const T & operator*();

		QueueIterator<T>& operator++();
		QueueIterator<T> operator++(int);

		bool operator==(const QueueIterator& aOtherIter) const;
		bool operator!=(const QueueIterator& aOtherIter) const;

		QueueIterator<T> end() const;

		// Setters

		// Misc
	};

	/**
	 * Class Constructor;
	 * @param aQueue, refence to queue.
	 */
	template<class T>
	inline QueueIterator<T>::QueueIterator(const Queue<T>& aQueue)
	{
		fQueue = aQueue;
	}

	/**
	 * Derefernce Operator
	 * @reutrn top element
	 */
	template<class T>
	inline const T & QueueIterator<T>::operator*()
	{
		return fQueue.top();
	}

	/**
	 * Prefix increment operator.
	 * @return Iterator post increment.
	 */
	template<class T>
	inline QueueIterator & QueueIterator<T>::operator++()
	{
		fQueue.dequeue();
		return *this;
	}

	/**
	 * Postfix increment operator.
	 * @return Iterator pre increment.
	 */
	template<class T>
	inline QueueIterator QueueIterator<T>::operator++(int)
	{
		QueueIterator<T> lTemp = *this;
		++(*this);
		return lTemp;
	}

	/**
	 * Determines if iterators are eqivilant.
	 * @param aOtherIter, refernce to other iterator.
	 * @return true if eqivilant.
	 */
	template<class T>
	inline bool QueueIterator<T>::operator==(const QueueIterator & aOtherIter) const
	{
		return fQueue.size() == aOtherIter.fQueue.size();
	}

	/**
	 * Determines if iterators are eqivilant.
	 * @param aOtherIter, refernce to other iterator.
	 * @return true if eqivilant.
	 */
	template<class T>
	inline bool QueueIterator<T>::operator!=(const QueueIterator & aOtherIter) const
	{
		return !(*this == aOtherIter);
	}

	/**
	 * Returns Iterator after last element. (empty?);
	 */
	template<class T>
	inline QueueIterator<T> QueueIterator<T>::end() const
	{
		return QueueIterator<T>();
	}

}