#ifndef FORWARDITERATOR_HPP
#define FORWARDITERATOR_HPP
#include "list_iterator.hpp"

namespace data_structures
{
	template <class T>
	class ForwardIterator final : public ListIterator<T>
	{
	public:
		ForwardIterator();
		~ForwardIterator();
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


}
#endif