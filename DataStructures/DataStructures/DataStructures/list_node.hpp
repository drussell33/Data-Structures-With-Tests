#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

#include "node.hpp"

namespace data_structures
{
	template <class T>
	class ListNode : public Node<T>
	{
	public:
		ListNode() = delete;
		explicit ListNode(const T& data, ListNode<T>* next = nullptr, ListNode<T>* previous = nullptr);
		ListNode(const ListNode<T>& copy);
		ListNode<T>& operator=(const ListNode<T>& rhs);

		ListNode(ListNode<T>&& copy) noexcept;
		ListNode<T>& operator=(ListNode<T>&& rhs) noexcept;

		ListNode<T>* Next() noexcept;
		ListNode<T>* Next() const noexcept;
		ListNode<T>* Previous() noexcept;
		ListNode<T>* Previous() const noexcept;

		void Next(ListNode<T>* const next) noexcept;
		void Previous(ListNode<T>* const previous) noexcept;

		~ListNode() = default;
	private:
		ListNode<T>* next_;
		ListNode<T>* previous_;
	};

}
#endif
