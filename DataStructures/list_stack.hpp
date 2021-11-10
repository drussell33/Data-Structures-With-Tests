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
		ListStack() = default;
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


	template <class T>
	ListStack<T>::ListStack(const ListStack& copy)
	{
		*this = copy;
	}

	template <class T>
	ListStack<T>& ListStack<T>::operator=(const ListStack& rhs)
	{
		if (this != &rhs)
		{
			stack_ = rhs.stack_;
			size_ = rhs.size_;
		}
		return *this;
	}

	template <class T>
	ListStack<T>::ListStack(ListStack&& copy) noexcept
	{
		*this = std::move(copy);
	}

	template <class T>
	ListStack<T>& ListStack<T>::operator=(ListStack&& rhs) noexcept
	{
		if (this != &rhs)
		{
			stack_ = std::move(rhs.stack_);
			size_ = std::move(rhs.size_);

			rhs.stack_ = nullptr;
		}
		return *this;
	}

	template <class T>
	T ListStack<T>::Pop()
	{
		if (Empty()) throw AdtException("Empty!");

		auto popper = stack_.Last();
		stack_.RemoveLast();
		--size_;

		return (popper);
	}

	template <class T>
	T ListStack<T>::Peek()
	{
		if (Empty()) throw AdtException("Empty!");

		return stack_.Last();
	}

	template <class T>
	void ListStack<T>::Push(T data)
	{
		stack_.Append(data);
		++size_;
	}

	template <class T>
	void ListStack<T>::Clear() noexcept
	{
		stack_.LinkedList<T>::Clear();
		size_ = 0;
	}

	template <class T>
	bool ListStack<T>::Empty() const noexcept
	{
		return stack_.Head() == nullptr;
	}

	template <class T>
	size_t ListStack<T>::Size() const noexcept
	{
		return size_;
	}
}
#endif // list_stack_HPP
