#ifndef PAIR_HPP
#define PAIR_HPP
#include "adt_exception.hpp"

namespace data_structures
{
	template <class F, class S>
	class Pair
	{
	public:
		Pair() = delete;
		Pair(const F& first, const S& second) noexcept(false);
		Pair(const Pair& copy) noexcept(false);
		Pair& operator=(const Pair& copy) noexcept(false);
		Pair(Pair&& copy) noexcept;
		Pair& operator=(Pair&& copy) noexcept;
		F First() const noexcept;
		S Second() const noexcept;
		void First(const F& first) noexcept;
		void Second(const S& second) noexcept;
		~Pair();

	private:
		F* first_ { nullptr };
		S* second_ { nullptr };
	};

	template<class F, class S>
	Pair<F, S>::Pair(const F& first, const S& second) noexcept(false)
	{
		try
		{
			first_ = new F(first);
			second_ = new S(second);
		}
		catch (std::bad_alloc& exception)
		{
			delete first_;
			throw AdtException(exception.what());
		}
	}

	template<class F, class S>
	Pair<F, S>::Pair(const Pair& copy) noexcept(false)
	{
		*this = copy;
	}

	template<class F, class S>
	Pair<F, S>& Pair<F, S>::operator=(const Pair& copy) noexcept(false)
	{

		if (this != &copy)
		{
			delete first_;
			delete second_;

			try
			{
				first_ = new F(copy.First());
				second_ = new S(copy.Second());
			}
			catch (const std::exception & exception)
			{
				delete first_;
				throw AdtException(exception.what());
			}
		}
		return *this;
	}

	template<class F, class S>
	Pair<F, S>::Pair(Pair&& copy) noexcept
	{
		*this = std::move(copy);
	}

	template<class F, class S>
	Pair<F, S>& Pair<F, S>::operator=(Pair&& copy) noexcept
	{
		if (this != &copy)
		{
			delete first_;
			delete second_;

			first_ = copy.first_;
			second_ = copy.second_;

			copy.first_ = nullptr;
			copy.second_ = nullptr;
		}
		return *this;
	}

	template<class F, class S>
	F Pair<F, S>::First() const noexcept
	{
		return *first_;
	}

	template<class F, class S>
	S Pair<F, S>::Second() const noexcept
	{
		return *second_;
	}

	template<class F, class S>
	void Pair<F, S>::First(const F& first) noexcept
	{
		*first_ = first;
	}

	template<class F, class S>
	void Pair<F, S>::Second(const S& second) noexcept
	{
		*second_ = second;
	}

	template<class F, class S>
	Pair<F, S>::~Pair()
	{
		delete first_;
		delete second_;
	}

}

#endif
