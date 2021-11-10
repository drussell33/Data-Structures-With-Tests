#ifndef list_queue_HPP
#define list_queue_HPP


#include "iqueue.hpp"
#include "linked_list.hpp"

namespace data_structures
{
	template <class T>
	class ListQueue final : public IQueue<T>
	{
	public:
		ListQueue() = default;
		ListQueue(const ListQueue& copy);
		ListQueue& operator=(const ListQueue& rhs);
		ListQueue(ListQueue&& copy) noexcept;
		ListQueue& operator=(ListQueue&& rhs) noexcept;
		~ListQueue() = default;

		void Enqueue(T data) override; 
		T Dequeue() override; 
		T& Front() override; 
		void Clear() noexcept override; 
		size_t Size() const noexcept override; 
		bool Empty() const noexcept override; 
	private:
		LinkedList<T> queue_;
		size_t size_;
	};


	template <class T>
	ListQueue<T>::ListQueue(const ListQueue& copy)
	{
		*this = copy;
	}

	template <class T>
	ListQueue<T>& ListQueue<T>::operator=(const ListQueue& rhs)
	{
		if (this != &rhs)
		{
			queue_ = rhs.queue_;
			size_ = rhs.size_;

			//rhs.stack_ = nullptr;
		}
		return *this;
	}

	template <class T>
	ListQueue<T>::ListQueue(ListQueue&& copy) noexcept
	{
		*this = std::move(copy);
	}

	template <class T>
	ListQueue<T>& ListQueue<T>::operator=(ListQueue&& rhs) noexcept
	{
		if (this != &rhs)
		{
			queue_ = std::move(rhs.stack_);
			size_ = std::move(rhs.size_);

			rhs.stack_ = nullptr;
		}
		return *this;
	}

	template <class T>
	void ListQueue<T>::Enqueue(T data)
	{
		queue_.Append(data);
		++size_;
	}

	template <class T>
	T ListQueue<T>::Dequeue()
	{
		if (Empty()) throw AdtException("Empty!");

		auto popper = queue_.First();
		queue_.RemoveFirst();
		--size_;

		return (popper);
	}

	template <class T>
	T& ListQueue<T>::Front()
	{
		if (Empty()) throw AdtException("Empty!");

		return queue_.First();
	}

	template <class T>
	void ListQueue<T>::Clear() noexcept
	{
		queue_.LinkedList<T>::Clear();
		size_ = 0;
	}

	template <class T>
	size_t ListQueue<T>::Size() const noexcept
	{
		return size_;
	}

	template <class T>
	bool ListQueue<T>::Empty() const noexcept
	{
		return queue_.Head() == nullptr;
	}
}
#endif 
