#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>
#include <iterator>
#include <queue>
#include <stack>
#include <functional>
#include "vertex.hpp"
#include "adt_exception.hpp"

namespace data_structures
{
	template <class V, class E>
	class Graph final
	{
	public:
		Graph();
		~Graph();

		Graph(const Graph& other);
		Graph<V, E>& operator=(const Graph& rhs);
		Graph(Graph&& other) noexcept;
		Graph<V, E>& operator=(Graph&& rhs) noexcept;

		void ResetVertices() noexcept;
		void InsertVertex(const V& data);
		void RemoveVertex(const V& data);
		void InsertArc(const V& from, const V& to, const E& data, const int& weight);
		void RemoveArc(const V& from, const V& to, const E& data);

		void DepthFirst(const V& start_data) noexcept(false);
		void BreadthFirst(const V& start_data) noexcept(false);

		Vertex<V, E>* GetVertex(const V& data);

		bool Empty() const noexcept;
		size_t Vertices() const noexcept;
		typename list<Vertex<V, E>>::iterator MapBeginIterator();
		typename list<Vertex<V, E>>::iterator MapEndIterator();
		void VisitFunction(const std::function<void(const V& data)>& visit);

	private:
		std::function<void(const V& data)> visit_;
		std::list<Vertex<V, E>> vertices_;
	};


}

#endif
