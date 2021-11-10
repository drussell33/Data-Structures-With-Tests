#ifndef array_queue_HPP
#define array_queue_HPP

#include "iqueue.hpp"
#include "array.hpp"

namespace data_structures
{
	template <class T>
	class ArrayQueue final : public IQueue<T>
	{
	public:
		ArrayQueue();
		explicit ArrayQueue(size_t size);
		ArrayQueue(const ArrayQueue& copy);
		ArrayQueue& operator=(const ArrayQueue& rhs);
		ArrayQueue(ArrayQueue&& copy) noexcept;
		ArrayQueue& operator=(ArrayQueue&& rhs) noexcept;

		void Enqueue(T data) override;
		T Dequeue() override;
		T& Front() override;
		bool Full() const noexcept;
		void Clear() noexcept override;
		
		~ArrayQueue() = default;
		size_t Size() const noexcept override;
		bool Empty() const noexcept override;
	private:
		Array<T> queue_;
		size_t size_;
		int index_;
	};

	
}
#endif // array_queue_HPP
