#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "adt_exception.hpp"
#include <random>
#include <ctime>

namespace data_structures
{
	template <class T>
	class Array final
	{
	public:
		explicit Array();
		~Array();
		explicit Array(const size_t& length, const int& start_index = 0) noexcept(false);
		explicit Array(const T* storage, const size_t& length, const int& start_index = 0) noexcept(false);

		Array(const Array& copy) noexcept(false);
		Array& operator=(const Array& rhs) noexcept(false);
		Array(Array&& copy) noexcept;
		Array& operator=(Array&& rhs) noexcept;

		T& operator[](const int& index) noexcept(false);
		T operator[](const int& index) const noexcept(false);
		explicit operator bool() const noexcept;

		bool operator==(const Array<T>& rhs) noexcept;

		int StartIndex() const noexcept;
		size_t Length() const noexcept;

		void StartIndex(const int& start_index) noexcept;
		void Length(const size_t& length) noexcept(false);

		void Shuffle() noexcept;
		void Merge(const Array& rhs) noexcept(false);

	private:
		T* storage_;
		size_t length_;
		int start_index_;

	};

	

}

#endif
