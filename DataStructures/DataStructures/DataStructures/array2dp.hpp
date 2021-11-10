#ifndef ARRAY2DP_HPP
#define ARRAY2DP_HPP

#include "iarray2d.hpp"

namespace data_structures
{
	template <class T>
	class Array2DP final : public IArray2D<T>
	{

	public:
		Array2DP();
		~Array2DP();
		explicit Array2DP(const size_t& rows, const size_t& columns) noexcept(false);
		explicit Array2DP(const T** storage, const size_t& rows, const size_t& columns) noexcept(false);
		Array2DP(const Array2DP& copy) noexcept(false);
		Array2DP& operator=(const Array2DP& copy) noexcept(false);
		Array2DP(Array2DP&& copy) noexcept;
		Array2DP& operator=(Array2DP&& copy) noexcept;
		T Select(const int& row, const int& column) const override;
		T& Select(const int& row, const int& column) override;
		Row<T> operator[](const int& row_index) const noexcept(false) override;
		Row<T> operator[](const int& row_index) noexcept(false) override;
		explicit operator bool() const noexcept override;
		size_t Rows() const noexcept override;
		size_t Columns() const noexcept override;
		void Rows(const size_t& rows) noexcept(false) override;
		void Columns(const size_t& columns) noexcept(false) override;

		bool operator==(const Array2DP<T>& rhs) const noexcept;

	private:
		T** storage_;
		size_t rows_;
		size_t columns_;
	};

}
#endif // array_2d_p_H