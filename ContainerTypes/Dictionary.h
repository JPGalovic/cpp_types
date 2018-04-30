#pragma once
/**
 * Dictionary, contains a list of matched pairs, Key and Data.
 * @author  J.P.Galovic
 * @version v0.0.1
 * @date    30-04-2018
 */
#include "List.h"
#include "Pair.h"

#include <iostream>
#include <stdexcept>
#include <Windows.h>

namespace Container
{
	template<class KEY, class DATA>
	class Dictionary
	{
	private:
		List<Pair<KEY, DATA>> fLookup;

		// Getters
		const Pair<KEY, DATA> & getPair(const KEY & aKey) const;

	public:
		// Construction and Destruction
		Dictionary();

		// Getters
		const DATA & getValue(const KEY & aKey) const;

		bool hasKey(const KEY & aKey) const;

		const List<Pair<KEY, DATA>> & getDataList() const;

		// Setters
		void addItem(const KEY & aKey, const ITEM & aValue);
		void removeValue(const KEY & aKey);

		// Misc
		friend std::ostream& operator<<(std::ostream& aOStream, const Dictionary<KEY, DATA> & aList)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			aOStream << aList.getDataList();

			return aOStream;
		}
	};

	/**
	 * Fetches pair from list with a given key.
	 * @param  aKey, key of pair to fetch.
	 * @return Pair if found.
	 * @throw  if no pair found.
	 */
	template<class KEY, class DATA>
	inline const Pair<KEY, DATA>& Dictionary<KEY, DATA>::getPair(const KEY & aKey) const
	{
		for (int i = 0; i < fLookup.size(); i++)
			if (fLookup[i].getA() == aKey)
				return fLookup[i];
		throw std::runtime_error("Key not found.");
	}

	/**
	 * Class Constructor.
	 */
	template<class KEY, class DATA>
	inline Dictionary<KEY, DATA>::Dictionary()
	{
		fLookup = List<Pair<KEY, DATA>>();
	}

	/**
	 * Gets value of a given key.
	 * @param  aKey, key of value to get.
	 * @return Value if key found.
	 * @throw  Passes e if not found.
	 */
	template<class KEY, class DATA>
	inline const DATA & Dictionary<KEY, DATA>::getValue(const KEY & aKey) const
	{
		try
		{
			return getPair(aKey).getB();
		}
		catch (const std::runtime_error& e)
		{
			throw e;
		}
	}

	template<class KEY, class DATA>
	inline bool Dictionary<KEY, DATA>::hasKey(const KEY & aKey) const
	{
		for (int i = 0; i < fLookup.size(); i++)
			if (fLookup[i].getA() == aKey)
				return true;
		return false;
	}

	/**
	 * Gets data list.
	 * @return refernce 
	 */
	template<class KEY, class DATA>
	inline const List<Pair<KEY, DATA>>& Dictionary<KEY, DATA>::getDataList() const
	{
		return fLookup;
	}

	/**
	 * Adds item to dictionary if key does not exist.
	 * @param aKey, key of item to add.
	 * @param aValue, value of item to add.
	 */
	template<class KEY, class DATA>
	inline void Dictionary<KEY, DATA>::addItem(const KEY & aKey, const ITEM & aValue)
	{
		if (hasKey(aKey))
			throw std::runtime_error("Key alredy in dictionary.");
		fLookup.add(Pair<KEY, DATA>(aKey, aItem));
	}

	/**
	 * Removes item from dictionary.
	 * @param aKey, key of item to remove.
	 * @throw Passes e if not found.
	 */
	template<class KEY, class DATA>
	inline void Dictionary<KEY, DATA>::removeValue(const KEY & aKey)
	{
		try
		{
			fLookup.remove(getPair(aKey));
		}
		catch (const std::runtime_error& e)
		{
			throw e;
		}
	}
}