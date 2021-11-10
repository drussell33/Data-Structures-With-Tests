#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP
#include "avl_node.hpp"
#include "adt_exception.hpp"
#include "itree.hpp"
#include "list_queue.hpp"


namespace data_structures
{
	template <class K, class V>
	class AvlTree final : public ITree<K, V>
	{
	public:
		AvlTree();
		~AvlTree();
		AvlTree(const AvlTree& copy) noexcept(false);
		AvlTree& operator=(const AvlTree& rhs) noexcept(false);
		AvlTree(AvlTree&& copy) noexcept(false);
		auto operator=(AvlTree&& rhs) noexcept(false) -> AvlTree&;
		auto VisitFunction(const std::function<void(const PairNode<K, V>* node)>& visit) noexcept -> void override;
		auto Clear() noexcept -> void override;
		auto Empty() const noexcept -> bool override;
		auto InOrder() const noexcept -> void override;
		auto PreOrder() const noexcept -> void override;
		auto PostOrder() const noexcept -> void override;
		auto BreadthFirst() const noexcept -> void override;
		auto Insert(const K& key, const V& value) noexcept(false) -> void override;
		auto Remove(const K& key) noexcept(false) -> void override;
		auto Search(const K& key) const noexcept(false) -> V override;
		auto Search(const K& key) noexcept(false) -> V& override;

	private:
		AvlNode<K, V>* root_;
		std::function<void(const AvlNode<K, V>* const node)> visit_{ nullptr };


	};

	
}


#endif // AVL_TREE_HPP