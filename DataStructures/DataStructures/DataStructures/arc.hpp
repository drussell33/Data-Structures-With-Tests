#ifndef ARC_HPP
#define ARC_HPP

#include <utility>
#include "vertex.hpp"

namespace data_structures
{
	using std::move;

	template <class V, class E>
	class Vertex;

	template <class V, class E>
	class Arc final
	{
	public:
		Arc() = delete;
		Arc(Vertex<V, E>* destination, E data, const int& weight);
		Arc(const Arc<V, E>& copy);
		Arc<V, E>& operator=(const Arc<V, E>& rhs);

		Arc(Arc<V, E>&& copy) noexcept;
		Arc<V, E>& operator=(Arc<V, E>&& rhs) noexcept;

		Vertex<V, E>* Destination() const noexcept;
		void Destination(const Vertex<V, E>* destination);
		int Weight() const noexcept;
		E Data() noexcept;
		bool operator==(const Arc<V, E>& rhs) const noexcept;

		~Arc();
	private:
		Vertex<V, E>* destination_;
		E data_;
		int weight_;
	};

}

#endif