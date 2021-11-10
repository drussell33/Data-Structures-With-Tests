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
		F* first_;
		S* second_;
	};

}

#endif