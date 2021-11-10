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
		ListIterator();
		ListIterator(const ListIterator& copy) noexcept;
		explicit ListIterator(ListNode<T>* const copy) noexcept;
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

	
}

#endif // LISTITERATOR_HPP