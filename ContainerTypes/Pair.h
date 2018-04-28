#pragma once
/**
 * Paird Elements, used for Dictionary Lookup Tables.
 * @author  J.P.Galovic
 * @version v0.0.1
 * @date    28-04-2018
 */

namespace Container
{
	template<class A, class B>
	class Pair
	{
	private:
		A fA;
		B fB;

	public:
		// Construction and Destrucion
		Pair();
		Pair(const A& aA, const B& aB);

		// Getters
		const A & getA() const;
		const B & getB() const;

		bool operator==(const Pair<A, B> & aOther) const;
		bool operator!=(const Pair<A, B> & aOther) const;

		// Setters
		void setA(const A & aA);
		void setB(const B & aB);
	};

	/**
	 * Default Class Constructor.
	 */
	template<class A, class B>
	inline Pair<A, B>::Pair()
	{
		fA = A();
		fB = B();
	}

	/**
	 * Class Constructor.
	 * @param aA, value to set A.
	 * @param aB, value to set B.
	 */
	template<class A, class B>
	inline Pair<A, B>::Pair(const A & aA, const B & aB)
	{
		fA = aA;
		fB = aB;
	}

	/**
	 * Gets value of A.
	 * @return value stored in A.
	 */
	template<class A, class B>
	inline const A & Pair<A, B>::getA() const
	{
		return fA;
	}

	/**
	 * Gets value of B.
	 * @return value stored in B.
	 */
	template<class A, class B>
	inline const B & Pair<A, B>::getB() const
	{
		return fB;
	}

	/**
	 * Equality Operator.
	 * @return true if equal.
	 */
	template<class A, class B>
	inline bool Pair<A, B>::operator==(const Pair<A, B>& aOther) const
	{
		return fA == aOther.fA && fB == aOther.fB;
	}

	/**
	 * Inequality Operator.
	 * @return true if not equal.
	 */
	template<class A, class B>
	inline bool Pair<A, B>::operator!=(const Pair<A, B>& aOther) const
	{
		return !(*this == aOther);
	}

	/**
	 * Sets value of A.
	 * @param aA, value to set A.
	 */
	template<class A, class B>
	inline void Pair<A, B>::setA(const A & aA)
	{
		fA = aA;
	}

	/**
	 * Sets value of B.
	 * @param aB, value to set B.
	 */
	template<class A, class B>
	inline void Pair<A, B>::setB(const B & aB)
	{
		fB = aB;
	}
}