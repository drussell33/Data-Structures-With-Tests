#ifndef array_stack_HPP
#define array_stack_HPP

#include "istack.hpp"
#include "array.hpp"
#include "adt_exception.hpp"
namespace data_structures
{

	template <class T>
	class ArrayStack final : public IStack<T>
	{
	public:
		ArrayStack();
		explicit ArrayStack(const size_t& max_size);
		ArrayStack(const ArrayStack& copy);
		ArrayStack& operator=(const ArrayStack& rhs);
		ArrayStack(ArrayStack&& copy) noexcept;
		ArrayStack& operator=(ArrayStack&& rhs) noexcept;
		~ArrayStack() = default;

		T Pop() override;
		T Peek() override;
		void Push(T data) override;
		bool Full() const noexcept;
		void Clear() noexcept override;
		bool Empty() const noexcept override;
		size_t Size() const noexcept override;
	private:
		Array<T> stack_;
		size_t size_;
	};

	
}
#endif // array_stack_HPP
