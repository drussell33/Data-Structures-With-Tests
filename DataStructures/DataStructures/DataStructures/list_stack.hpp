#ifndef LIST_STACK_HPP
#define LIST_STACK_HPP

#include "istack.hpp"
#include "linked_list.hpp"
#include "adt_exception.hpp"

namespace data_structures
{
	template <class T>
	class ListStack final : public IStack<T>
	{
	public:
		ListStack();
		ListStack(const ListStack& copy);
		ListStack& operator=(const ListStack& rhs);
		ListStack(ListStack&& copy) noexcept;
		ListStack& operator=(ListStack&& rhs) noexcept;
		~ListStack() = default;

		T Pop() override;
		T Peek() override;
		void Push(T data) override;
		void Clear() noexcept override;
		bool Empty() const noexcept override;
		size_t Size() const noexcept override;
	private:
		LinkedList<T> stack_;
		size_t size_{ 0 };
	};

	
}
#endif // list_stack_HPP
