#ifndef array_queue_HPP
#define array_queue_HPP

#include "iqueue.hpp"
#include "array.hpp"
#include "adt_exception.hpp"

namespace data_structures
{
	template <class T>
	class ArrayQueue final : public IQueue<T>
	{
	public:
		ArrayQueue() = default;// done +++
		explicit ArrayQueue(int size);// done +++
		ArrayQueue(const ArrayQueue& copy);// done +++
		ArrayQueue& operator=(const ArrayQueue& rhs);// done +++
		ArrayQueue(ArrayQueue&& copy) noexcept;// done +++
		ArrayQueue& operator=(ArrayQueue&& rhs) noexcept;// done +++

		void Enqueue(T data) override; // put in the back, look at the slides.
		T Dequeue() override; //pull from the front
		T& Front() override; // pull from the front but dont take
		bool Full() const noexcept; // done +++
		void Clear() noexcept override; // done +++
		
		~ArrayQueue() = default; // done +++
		size_t Size() const noexcept override; // done +++
		bool Empty() const noexcept override; // done +++
	private:
		Array<T> queue_;
		int size_{0};
		int front_{-1};
		int back_{-1};
	};



	template <class T>
	ArrayQueue<T>::ArrayQueue(int size)
		:queue_(size)
	{
	}

	template <class T>
	ArrayQueue<T>::ArrayQueue(const ArrayQueue& copy)
	{
		*this = copy;
	}

	template <class T>
	ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue& rhs)
	{
		if(this != &rhs)
		{
			queue_ = rhs.queue_;
			size_ = rhs.size_;
			front_ = rhs.front_;
			back_ = rhs.back_;
		}
		return *this;
	}

	template <class T>
	ArrayQueue<T>::ArrayQueue(ArrayQueue&& copy) noexcept
	{
		*this = copy;
	}

	template <class T>
	ArrayQueue<T>& ArrayQueue<T>::operator=(ArrayQueue&& rhs) noexcept
	{
		if (this != &rhs)
		{
			queue_ = rhs.queue_;
			size_ = rhs.size_;
			front_ = rhs.front_;
			back_ = rhs.back_;
		}
		return *this;
	}

	template <class T>
	void ArrayQueue<T>::Enqueue(T data)
	{
		if (Full()) throw AdtException("Full!");

			if (front_ == -1) 
			{
				front_ = 0;
				back_ = 0;
			}
			queue_[back_] = data;
			back_ = (back_ + 1) % queue_.Length();
			++size_;
		
		}
	
	template <class T>
	T ArrayQueue<T>::Dequeue()
	{
		if (Empty()) throw AdtException("Empty!");
		T return_data = queue_[front_];
		
		front_ = (front_ + 1) % queue_.Length();
		--size_;

		return return_data;
	}

	template <class T>
	T& ArrayQueue<T>::Front()
	{
		if (Empty()) throw AdtException("Empty!");
		return queue_[front_];
	}

	template <class T>
	bool ArrayQueue<T>::Full() const noexcept
	{
		return size_ == queue_.Length();
	}

	template <class T>
	void ArrayQueue<T>::Clear() noexcept
	{
		front_ = -1;
		back_ = -1;
		size_ = 0;
	}

	template <class T>
	size_t ArrayQueue<T>::Size() const noexcept
	{
		return size_;
	}

	template <class T>
	bool ArrayQueue<T>::Empty() const noexcept
	{
		return front_ == back_ && size_ == 0;
	}
}
#endif // array_queue_HPP
