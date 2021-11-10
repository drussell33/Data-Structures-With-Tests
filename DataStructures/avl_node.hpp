#ifndef AVL_NODE_HPP
#define AVL_NODE_HPP
#include "pair_node.hpp"


namespace data_structures
{
	enum class AvlNodeBalanceFactor : int8_t
	{
		LeftHeavy = -1,
		Equal = 0,
		RightHeavy = 1,
	};

	template <class K, class V>
	class AvlNode final : public PairNode<K, V>
	{
	public:
		AvlNode(const K& key, const V& value, AvlNode<K, V>* left = nullptr, AvlNode<K, V>* right = nullptr);
		~AvlNode();

		AvlNode(const AvlNode& copy) noexcept (false);
		AvlNode& operator=(const AvlNode& rhs) noexcept(false);
		AvlNode(AvlNode&& copy) noexcept;
		AvlNode& operator=(AvlNode&& rhs) noexcept;

		AvlNode*& Left() noexcept;
		AvlNode*& Right() noexcept;
		AvlNode* Left() const noexcept;
		AvlNode* Right() const noexcept;
		void Left(AvlNode* const left) noexcept;
		void Right(AvlNode* const right) noexcept;

		AvlNodeBalanceFactor BalanceFactor() const noexcept;
		void BalanceFactor(const AvlNodeBalanceFactor& balance_factor) noexcept;

	private:
		AvlNode* left_;
		AvlNode* right_;
		AvlNodeBalanceFactor balance_factor_;
	};

	
}

#endif // AVL_NODE_HPP