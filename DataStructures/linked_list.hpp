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
		LinkedList() = default;
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
		ListNode<T>* head_{nullptr};
		ListNode<T>* tail_{nullptr};
		size_t size_{0};

	};

	template <class T>
	LinkedList<T>::LinkedList(const LinkedList& copy)
	{
		*this = copy; 
	}

	template <class T>
	LinkedList<T>::LinkedList(LinkedList&& copy) noexcept
	{
		*this = copy;
	}

	template <class T>
	LinkedList<T>::~LinkedList()
	{
		Clear();
	}

	template <class T>
	LinkedList<T>& LinkedList<T>::operator=(const LinkedList& rhs)
	{
		if(this != &rhs)
		{
			for(auto node = rhs.head_; node != nullptr; node = node->Next())
			{
				Append(node->Value());
			}
		}
		return *this;
	}

	template <class T>
	LinkedList<T>& LinkedList<T>::operator=(LinkedList&& rhs) noexcept
	{
		if (this != &rhs)
		{
			Clear();
			
			head_ = rhs.head_;
			tail_ = rhs.tail_;
			size_ = rhs.size_;

			rhs.head_ = nullptr;
			rhs.tail_ = nullptr;
		}
		return *this;
	}

	template <class T>
	LinkedList<T>::operator bool() const
	{
		return !Empty();
	}

	template <class T>
	void LinkedList<T>::Append(const T& data)
	{
		auto new_node = new ListNode<T>(data, nullptr, nullptr); // could also make a function that news up a node on its own. 
		if(Empty())
		{
			head_ = tail_ = new_node;
		}
		else
		{
			tail_->Next(new_node);
			new_node->Previous(tail_);
			tail_ = new_node;
		}
		++size_;
	}

	template <class T>
	void LinkedList<T>::Prepend(const T& data)
	{
		auto new_node = new ListNode<T>(data, nullptr, nullptr); 
		if (Empty())
		{
			head_ = tail_ = new_node;
		}
		else
		{
			head_->Previous(new_node);
			new_node->Next(head_);
			head_ = new_node;
		}
		++size_;
	}

	template <class T>
	void LinkedList<T>::RemoveLast()
	{
		if (Empty()) throw AdtException("List was Empty");

		if(size_ == 1)
		{
			Clear();
		}
		else
		{
			tail_ = tail_->Previous();
		}
		--size_;
	}

	template <class T>
	void LinkedList<T>::RemoveFirst()
	{
		if (Empty()) throw AdtException("List was Empty");

		if (size_ == 1)
		{
			Clear();
		}
		else
		{
			ListNode<T>* temp = head_;
			head_ = temp->Next();
			delete temp;
		}
		--size_;
	}

	template <class T>
	void LinkedList<T>::Extract(const T& data)
	{
		ListNode<T>* node_to_drop = head_;

		while (node_to_drop != nullptr)
		{
			if (node_to_drop->Value() == data)
			{
				break;
			}
			node_to_drop = node_to_drop->Next();
		}
		if (size_ == 1)
		{
			Clear();
		}
		else if (node_to_drop == head_) RemoveFirst();
		else if (node_to_drop == tail_) RemoveLast();
		else
		{
			node_to_drop->Previous()->Next(node_to_drop->Next());
			node_to_drop->Next()->Previous(node_to_drop->Previous());

			delete node_to_drop;

			--size_;
		}	
	}

	template <class T>
	void LinkedList<T>::InsertAfter(const T& data, const T& after)
	{
		ListNode<T>* node_before = head_;

		while (node_before != nullptr)
		{
			if (node_before->Value() == after)
			{
				break;
			}
			node_before = node_before->Next();
		}
		if (node_before == nullptr)
		{
			throw AdtException("Before not found");
		}
		if (node_before == tail_) Append(data);
		else
		{
			ListNode<T>* new_node = new ListNode<T>(data, node_before->Next(), node_before);


			new_node->Previous()->Next(new_node);
			node_before->Next()->Previous(node_before);
			++size_;
		}
	}

	template <class T>
	void LinkedList<T>::InsertBefore(const T& data, const T& before)
	{
		ListNode<T>* node_before = head_;

		while(node_before != nullptr)
		{
			if (node_before->Value() == before)
			{
				break;
			}
			node_before = node_before->Next();
		}
		if(node_before == nullptr)
		{
			throw AdtException("Before not found");
		}
		if (node_before == head_) Prepend(data);
		else
		{
			ListNode<T>* new_node = new ListNode<T>(data,node_before, node_before->Previous());
			node_before->Previous()->Next(new_node);
			new_node->Next()->Previous(new_node);
			++size_;
		}
	}

	template <class T>
	void LinkedList<T>::Clear() noexcept
	{
		auto node = head_;

		while (node != nullptr)
		{
			auto temp = node->Next();
			delete node;
			node = temp;
		}

		head_ = tail_ = nullptr;

	}

	template <class T>
	T& LinkedList<T>::Last() 
	{
		if (Empty()) throw AdtException("List was Empty");
		return tail_->Value();
	}

	template <class T>
	T LinkedList<T>::Last() const
	{
		if (Empty()) throw AdtException("List was Empty");
		return tail_->Value();
	}

	template <class T>
	T& LinkedList<T>::First()
	{
		if (Empty()) throw AdtException("List was Empty");
		return head_->Value();
	}

	template <class T>
	T LinkedList<T>::First() const
	{
		if (Empty()) throw AdtException("List was Empty");
		return head_->Value();
	}

	template <class T>
	ListNode<T>* LinkedList<T>::Head() const noexcept
	{
		return head_;
	}

	template <class T>
	ListNode<T>* LinkedList<T>::Tail() const noexcept
	{
		return tail_;
	}

	template <class T>
	bool LinkedList<T>::Empty() const noexcept
	{
		return head_ == nullptr;
	}

	template <class T>
	size_t LinkedList<T>::Size() const noexcept
	{
		return size_;
	}

	template <class T>
	bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const noexcept
	{
		ListNode<T>* lhs_node = head_;
		ListNode<T>* rhs_node = rhs.head_;

		if(size_ != rhs.size_ )
		{
			return false;
		}

		while (lhs_node != nullptr || rhs_node != nullptr)
		{
			if (lhs_node->Value() != rhs_node->Value())
			{
				return false;
			}
			
			lhs_node = lhs_node->Next();
			rhs_node = rhs_node->Next();
		}
		return true;
	}

	template <class T>
	ForwardIterator<T> LinkedList<T>::ForwardBegin()
	{
		if (Empty()) throw AdtException("List was Empty");
		ForwardIterator<T> it;
		it = head_;
		return it;
	}

	template <class T>
	ForwardIterator<T> LinkedList<T>::ForwardEnd()
	{
		if (Empty()) throw AdtException("List was Empty");
		ForwardIterator<T> it;
		it = tail_;
		return it;
	}

	template <class T>
	BackwardIterator<T> LinkedList<T>::BackwardBegin()
	{
		if (Empty()) throw AdtException("List was Empty");
		return BackwardIterator<T>(tail_);
	}

	template <class T>
	BackwardIterator<T> LinkedList<T>::BackwardEnd()
	{
		if (Empty()) throw AdtException("List was Empty");
		return BackwardIterator<T>(head_); 
	}
}
#endif