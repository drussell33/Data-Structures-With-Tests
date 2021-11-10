#ifndef FORWARDITERATOR_HPP
#define FORWARDITERATOR_HPP
#include "list_iterator.hpp"

namespace data_structures
{
	template <class T>
	class ForwardIterator final : public ListIterator<T>
	{
	public:
		ForwardIterator() = default;
		~ForwardIterator() = default;
		ForwardIterator(const ForwardIterator& copy) noexcept;
		explicit ForwardIterator(ListNode<T>* const copy) noexcept;
		ForwardIterator(ForwardIterator&& copy) noexcept;
		ForwardIterator& operator=(const ForwardIterator& rhs) noexcept;
		ForwardIterator& operator=(ListNode<T>* const rhs) noexcept override;
		ForwardIterator& operator=(ForwardIterator&& rhs) noexcept;

		bool operator==(const ForwardIterator& rhs) const noexcept;

		void MoveNext() override;
		void Reset() noexcept override;
		ForwardIterator& operator++();
		const ForwardIterator operator++(int);
	};

	template <class T>
	ForwardIterator<T>::ForwardIterator(const ForwardIterator& copy) noexcept
	{
		*this = copy;
	}

	template <class T>
	ForwardIterator<T>::ForwardIterator(ListNode<T>* const copy) noexcept
	{
		*this = ForwardIterator<T>::operator=(copy);
	}

	template <class T>
	ForwardIterator<T>::ForwardIterator(ForwardIterator&& copy) noexcept
	{
		*this = std::move(copy);
	}

	template <class T>
	ForwardIterator<T>& ForwardIterator<T>::operator=(const ForwardIterator& rhs) noexcept
	{
		if (this != &rhs)
		{
			ListIterator<T>::node_ = rhs.node_;
			ListIterator<T>::done_ = rhs.done_;
		}
		return *this;
	}

	template <class T>
	ForwardIterator<T>& ForwardIterator<T>::operator=(ListNode<T>* const rhs) noexcept
	{
		ListIterator<T>::node_ = rhs;
		if (rhs->Next() == nullptr) 
		{
			ListIterator<T>::done_ = true;
		}
		return *this;
	}

	template <class T>
	ForwardIterator<T>& ForwardIterator<T>::operator=(ForwardIterator&& rhs) noexcept
	{
		ListIterator<T>::operator=(std::move(rhs));
		return *this;
	}

	template <class T>
	bool ForwardIterator<T>::operator==(const ForwardIterator& rhs) const noexcept
	{
		return ListIterator<T>::node_ == rhs.node_ && ListIterator<T>::done_ == rhs.done_;
	}

	template <class T>
	void ForwardIterator<T>::MoveNext()
	{
		if(ListIterator<T>::node_->Next() != nullptr)
		{
			ListIterator<T>::node_ = ListIterator<T>::node_->Next();
		}
		else
			ListIterator<T>::done_ = true;
	}

	template <class T>
	void ForwardIterator<T>::Reset() noexcept
	{
		auto node = ListIterator<T>::node_;
		while(node->Previous() != nullptr)
		{
			node = node->Previous();
		}
		ListIterator<T>::node_ = node;
	}

	template <class T>
	ForwardIterator<T>& ForwardIterator<T>::operator++()
	{
		MoveNext();
		return *this;
	}

	template <class T>
	const ForwardIterator<T> ForwardIterator<T>::operator++(int)
	{
		auto temp = ForwardIterator<T>(*this);
		MoveNext();
		return temp;
	}
}
#endif