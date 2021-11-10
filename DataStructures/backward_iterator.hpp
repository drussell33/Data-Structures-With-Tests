#ifndef BACKWARDITERATOR_HPP
#define BACKWARDITERATOR_HPP
#include "list_iterator.hpp"

namespace data_structures
{
	template <class T>
	class BackwardIterator : public ListIterator<T>
	{
	public:
		BackwardIterator() = default;
		~BackwardIterator() = default;
		BackwardIterator(const BackwardIterator& copy) noexcept;
		explicit BackwardIterator(ListNode<T>* const copy) noexcept;
		BackwardIterator(BackwardIterator&& copy) noexcept;
		BackwardIterator& operator=(const BackwardIterator& rhs) noexcept;
		BackwardIterator& operator=(ListNode<T>* const rhs) noexcept override;
		BackwardIterator& operator=(BackwardIterator&& rhs) noexcept;

		bool operator==(const BackwardIterator<T>& rhs) const noexcept;

		void MoveNext() override;
		void Reset() noexcept override;
		BackwardIterator& operator++();
		const BackwardIterator operator++(int);
	};


	template <class T>
	BackwardIterator<T>::BackwardIterator(const BackwardIterator& copy) noexcept
	{
		*this = copy;
	}

	template <class T>
	BackwardIterator<T>::BackwardIterator(ListNode<T>* const copy) noexcept
	{
		*this = BackwardIterator<T>::operator=(copy);
	}

	template <class T>
	BackwardIterator<T>::BackwardIterator(BackwardIterator&& copy) noexcept
	{
		*this = std::move(copy);
	}

	template <class T>
	BackwardIterator<T>& BackwardIterator<T>::operator=(const BackwardIterator& rhs) noexcept
	{
		if (this != &rhs)
		{
			ListIterator<T>::node_ = rhs.ListIterator<T>::node_;
			ListIterator<T>::done_ = rhs.ListIterator<T>::done_;
		}
		return *this;
	}

	template <class T>
	BackwardIterator<T>& BackwardIterator<T>::operator=(ListNode<T>* const rhs) noexcept
	{
		ListIterator<T>::node_ = rhs;
		if (rhs->Previous() == nullptr) 
		{
			ListIterator<T>::done_ = true;
		}
		return *this;
	}

	template <class T>
	BackwardIterator<T>& BackwardIterator<T>::operator=(BackwardIterator&& rhs) noexcept
	{
		ListIterator<T>::operator=(std::move(rhs));
		return *this;
	}

	template <class T>
	bool BackwardIterator<T>::operator==(const BackwardIterator<T>& rhs) const noexcept
	{
		return ListIterator<T>::node_ == rhs.node_ && ListIterator<T>::done_ == rhs.done_;
	}

	template <class T>
	void BackwardIterator<T>::MoveNext()
	{
		if(ListIterator<T>::node_->Previous() != nullptr)
		{
			ListIterator<T>::node_ = ListIterator<T>::node_->Previous();
		}
		else
			ListIterator<T>::done_ = true;
	}

	template <class T>
	void BackwardIterator<T>::Reset() noexcept
	{
		auto node = ListIterator<T>::node_;
		while (node->Next() != nullptr)
		{
			node = node->Next();
		}
		ListIterator<T>::node_ = node;
	}

	template <class T>
	BackwardIterator<T>& BackwardIterator<T>::operator++()
	{
		MoveNext();
		return *this;
	}

	template <class T>
	const BackwardIterator<T> BackwardIterator<T>::operator++(int)
	{
		auto temp = BackwardIterator<T>(*this);
		MoveNext();
		return temp;
	}
}
#endif // BACKWARDITERATOR_HPP
