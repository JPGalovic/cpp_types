#pragma once
/**
 * Dynamic Queue, Elements are Enqueued then Dequeued.
 * Adapted from code developed for COS30008 - Data Structures and Patters
 * @author  J.P.Galovic
 * @version v1.1.0
 * @date    04-05-2018
 */
#include "List.h"

namespace Container
{
	template<class T>
	class Queue
	{
	private:
		List<T> fElements;
	public:
		// Construction & Destruction

		// Getters
		bool isEmpty() const;
		bool empty() const;

		int size() const;
		int count() const;
		int length() const;

		const T& top() const;

		// Setters
		void enqueue(const T& aElement);
		void dequeue();

		// Misc
		friend std::ostream& operator<<(std::ostream & aOstream, const Queue<T> & aQueue)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 2);
			aOstream << "Queue contains " << aQueue.size() << " Elements." << std::endl;

			

			SetConsoleTextAttribute(hConsole, 15);
			return aOstream;
		}
	};

	/**
	 * Determines if Queue is empty.
	 * @return true if Queue is empty.
	 */
	template<class T>
	inline bool Queue<T>::isEmpty() const
	{
		return fElements.isEmpty();
	}

	/**
	 * Determines if Queue is empty.
	 * @return true if Queue is empty.
	 */
	template<class T>
	inline bool Queue<T>::empty() const
	{
		return isEmpty();
	}

	/**
	 * Gets number of elements in Queue.
	 * @return Size of Queue.
	 */
	template<class T>
	inline int Queue<T>::size() const
	{
		return fElements.size();
	}

	/**
	 * Gets number of elements in Queue.
	 * @return Size of Queue.
	 */
	template<class T>
	inline int Queue<T>::count() const
	{
		return size();
	}

	/**
	 * Gets number of elements in Queue.
	 * @return Size of Queue.
	 */
	template<class T>
	inline int Queue<T>::length() const
	{
		return size();
	}

	/**
	 * Gets element at top of Queue.
	 * @return value of element at top of Queue.
	 */
	template<class T>
	inline const T & Queue<T>::top() const
	{
		if(isEmpty())
			throw std::underflow_error("Queue Empty");
		return fElements[0];
	}

	/**
	 * Adds element to Queue.
	 * @param aElement, element to add to queue.
	 */
	template<class T>
	inline void Queue<T>::enqueue(const T & aElement)
	{
		fElements.pushBack(aElement);
	}

	/**
	 * Removes element from top of Queue.
	 */
	template<class T>
	inline void Queue<T>::dequeue()
	{
		if (isEmpty())
			throw std::underflow_error("Queue Empty");
		return fElements.removeAt(0);
	}



}
