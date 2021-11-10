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
		ArrayStack() = delete; // done +++
		explicit ArrayStack(const size_t& max_size) // done +++
			:stack_(max_size){};
		ArrayStack(const ArrayStack& copy); //done +++
		ArrayStack& operator=(const ArrayStack& rhs); //done +++
		ArrayStack(ArrayStack&& copy) noexcept; // done +++
		ArrayStack& operator=(ArrayStack&& rhs) noexcept;  
		~ArrayStack() = default; //done +++

		T Pop() override; // done +++
		T Peek() override; // done +++
		void Push(T data) override; // done +++
		bool Full() const noexcept; // done +++
		void Clear() noexcept override; // done +++
		bool Empty() const noexcept override; // done +++
		size_t Size() const noexcept override; // done +++
	private:
		Array<T> stack_;
		size_t size_ {0};
	};


	template <class T>
	ArrayStack<T>::ArrayStack(const ArrayStack& copy)
	{
		*this = copy;
	}

	template <class T>
	ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack& rhs)
	{
		if(this != &rhs)
		{
			stack_ = rhs.stack_;
			size_ = rhs.size_;
		}
		return *this;
	}

	template <class T>
	ArrayStack<T>::ArrayStack(ArrayStack&& copy) noexcept
	{
		*this = copy;
	}

	template <class T>
	ArrayStack<T>& ArrayStack<T>::operator=(ArrayStack&& rhs) noexcept
	{
		if (this != &rhs)
		{
			stack_ = rhs.stack_;
			size_ = rhs.size_;
		}
		return *this;
	}

	template <class T>
	T ArrayStack<T>::Pop()
	{
		if (Empty()) throw AdtException("Empty!");
		else
		{
			return stack_[--size_];
		}
	}

	template <class T>
	T ArrayStack<T>::Peek()
	{	
		if (Empty()) throw AdtException("Empty!");
		return stack_[size_ - 1];
	}

	template <class T>
	void ArrayStack<T>::Push(T data)
	{
		if (Full()) throw AdtException("Full!");
		stack_[size_++] = data;
	
	}

	template <class T>
	bool ArrayStack<T>::Full() const noexcept
	{
		return size_ == stack_.Length();
	}

	template <class T>
	void ArrayStack<T>::Clear() noexcept
	{
		size_ = 0; 
	}

	template <class T>
	bool ArrayStack<T>::Empty() const noexcept
	{
		return size_ == 0;
	}

	template <class T>
	size_t ArrayStack<T>::Size() const noexcept
	{
		return size_;
	}
}
#endif // array_stack_HPP
 