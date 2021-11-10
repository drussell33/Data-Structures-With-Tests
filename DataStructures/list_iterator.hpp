#ifndef LISTITERATOR_HPP
#define LISTITERATOR_HPP

#include "iiterator.hpp"
#include "adt_exception.hpp"
#include "list_node.hpp"

namespace data_structures
{
	template <class T>
	class ListIterator : public IIterator<T>
	{
	public:
		ListIterator() = default;
		ListIterator(const ListIterator& copy) noexcept;
		explicit ListIterator(ListNode<T>* const copy) noexcept; //
		ListIterator(ListIterator&& copy) noexcept;
		ListIterator& operator=(const ListIterator& rhs) noexcept;
		virtual ListIterator& operator=(ListNode<T>* const rhs) noexcept;
		ListIterator& operator=(ListIterator&& rhs) noexcept;

		T& operator*();
		T operator*() const;
		T& Current() override;
		T Current() const override;
		T* operator->();
		T* operator->() const;
		bool Done() const noexcept override;
		operator void* () const noexcept override;

		virtual ~ListIterator() = default;


	protected:
		ListNode<T>* node_;
		bool done_;
	};


	template <class T>
	ListIterator<T>::ListIterator(const ListIterator& copy) noexcept
	{
		*this = copy;
	}

	template <class T>
	ListIterator<T>::ListIterator(ListNode<T>* const copy) noexcept
	{
		*this = ListIterator<T>::operator=(copy);
	}

	template <class T>
	ListIterator<T>::ListIterator(ListIterator&& copy) noexcept
	{
		*this = std::move(copy);
	}

	template <class T>
	ListIterator<T>& ListIterator<T>::operator=(const ListIterator& rhs) noexcept 
	{
		if (this != &rhs)
		{
			node_ = rhs.node_;
			done_ = rhs.done_;

			rhs.node_ = nullptr;
		}
		return *this;
	}

	template <class T>
	ListIterator<T>& ListIterator<T>::operator=(ListNode<T>* const rhs) noexcept
	{
		node_ = rhs;
		if (rhs->Next() == nullptr) // how can I make this better?
		{
			done_ = true;
		}
		return *this;
	}

	template <class T>
	ListIterator<T>& ListIterator<T>::operator=(ListIterator&& rhs) noexcept
	{
		if (this != &rhs)
		{
			node_ = rhs.node_;
			done_ = rhs.done_;

			rhs.node_ = nullptr;
		}
		return *this;
	}

	template <class T>
	T& ListIterator<T>::operator*()
	{
		return Current();
	}

	template <class T>
	T ListIterator<T>::operator*() const
	{
		return Current();
	}

	template <class T>
	T& ListIterator<T>::Current()
	{
		return node_->Value(); 
	}

	template <class T>
	T ListIterator<T>::Current() const
	{
		return node_->Value(); 
	}

	template <class T>
	T* ListIterator<T>::operator->()
	{
		return &node_->Value();
	}

	template <class T>
	T* ListIterator<T>::operator->() const
	{
		return &node_->Value();
	}

	template <class T>
	bool ListIterator<T>::Done() const noexcept
	{
		return done_;
	}

	template <class T>
	ListIterator<T>::operator void*() const noexcept
	{
		return node_; 
	}
}

#endif // LISTITERATOR_HPP