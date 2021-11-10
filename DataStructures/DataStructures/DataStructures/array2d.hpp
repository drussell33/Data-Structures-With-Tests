#ifndef array_2d_HPP
#define array_2d_HPP


#include "array.hpp"
#include "iarray2d.hpp"

namespace data_structures
{
	template <class T>
	class Array2D final : public IArray2D<T>
	{
	public:
		Array2D();
		~Array2D();
		explicit Array2D(const size_t& rows, const size_t& columns) noexcept(false);
		Array2D(const Array2D& copy) noexcept(false);
		Array2D& operator=(const Array2D& copy) noexcept(false);
		Array2D(Array2D&& copy) noexcept;
		Array2D& operator=(Array2D&& copy) noexcept;
		T Select(const int& row, const int& column) const override;
		T& Select(const int& row, const int& column) override;
		Row<T> operator[](const int& row_index) const noexcept(false) override;
		Row<T> operator[](const int& row_index) noexcept(false) override;
		explicit operator bool() const noexcept override;
		size_t Rows() const noexcept override;
		size_t Columns() const noexcept override;
		void Rows(const size_t& rows) noexcept(false) override;
		void Columns(const size_t& columns) noexcept(false) override;

		bool operator==(const Array2D<T>& rhs) const noexcept;
	private:
		Array<T> storage_;
		size_t rows_;
		size_t columns_;
	};

	
}
#endif // array_2d_H