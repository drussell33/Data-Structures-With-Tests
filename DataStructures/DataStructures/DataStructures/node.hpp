#ifndef NODE_HPP
#define NODE_HPP

#include <algorithm>

namespace data_structures
{
	template <class T>
	class Node
	{
	public:
		explicit Node() = delete;
		Node(const Node& copy);
		explicit Node(const T& data);

		Node<T>& operator=(const Node& copy);

		Node(Node&& copy) noexcept;
		Node<T>& operator=(Node&& copy) noexcept;

		virtual ~Node() = default;

		T& Value() noexcept;
		T Value() const noexcept;
		void Value(const T& data);
	private:
		T value_;
	};

	
}
#endif
