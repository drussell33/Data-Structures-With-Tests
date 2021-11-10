#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#include "adt_exception.hpp"
#include "list_node.hpp"
#include "forward_iterator.hpp"
#include "backward_iterator.hpp"

namespace data_structures
{
	template <class T>
	class LinkedList final
	{
	public:
		LinkedList();
		LinkedList(const LinkedList& copy);
		LinkedList(LinkedList&& copy) noexcept;
		~LinkedList();

		LinkedList& operator=(const LinkedList& rhs);
		LinkedList& operator=(LinkedList&& rhs) noexcept;

		explicit operator bool() const;

		void Append(const T& data);
		void Prepend(const T& data);
		void RemoveLast();
		void RemoveFirst();
		void Extract(const T& data);
		void InsertAfter(const T& data, const T& after);
		void InsertBefore(const T& data, const T& before);
		void Clear() noexcept;
		T& Last();
		T Last() const;
		T& First();
		T First() const;
		ListNode<T>* Head() const noexcept;
		ListNode<T>* Tail() const noexcept;
		bool Empty() const noexcept;
		size_t Size() const noexcept;

		bool operator==(const LinkedList<T>& rhs) const noexcept;

		ForwardIterator<T> ForwardBegin();
		ForwardIterator<T> ForwardEnd();
		BackwardIterator<T> BackwardBegin();
		BackwardIterator<T> BackwardEnd();

	private:
		ListNode<T>* head_;
		ListNode<T>* tail_;
		size_t size_;

	};

}
#endif