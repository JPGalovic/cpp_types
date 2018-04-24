#pragma once
/**
 * Doubly Linked List Node, defines the template for nodes used in lists.
 * Adapted from code developed for COS30008 - Data Structures and Patters
 * @author  J.P.Galovic
 * @version v1.0.4
 * @date    24-04-2018
 */

template<class T>
class ListNode
{
private:
	T fValue;
	ListNode<T>* fNext;
	ListNode<T>* fPrevious;

public:
	// Construction and Destruction
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
};

/**
 * Class Constructor, Sets node with no next or previous connections
 * @param aValue, value to set node with.
 */
template<class T>
inline ListNode<T>::ListNode(const T & aValue)
{
	fNext = nullptr;
	fPrevious = nullptr;

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

	if (fPrevious != nullptr) // If not start of list, insert on previous.
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

	if (fNext != nullptr)
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
	if (fPrevious != nullptr)
		fPrevious->fNext = fNext;
	if (fNext != nullptr)
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
