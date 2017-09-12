#pragma once

#include <memory>
#include <string>

// Simple Binary Tree Implementaion
template <typename T>
class SimpleBinarySearchTree
{

private:
	// Inner class for the TreeNode object
	struct TreeNode {

		// The Data this TreeNode holds
		T data;

		// The left child of the TreeNode
		std::shared_ptr<TreeNode> left;

		// The right child of the TreeNode
		std::shared_ptr<TreeNode> right;

		TreeNode(T data) : TreeNode(data, nullptr, nullptr)
		{
		};

		TreeNode(T data, const std::shared_ptr<TreeNode>& left, const std::shared_ptr<TreeNode>& right) : data(data), left(left), right(right)
		{
		};

		~TreeNode()
		{
		};

	};

	// Gets the minimum value from the given tree
	T getMin(std::shared_ptr<TreeNode>& root)
	{
		if (root->left == nullptr)
			return root->data;
		else
			return getMin(root->left);
	};

	// The overall root of the tree
	std::shared_ptr<TreeNode> overallRoot;

	// Recursive function to add a value to the BST
	std::shared_ptr<typename SimpleBinarySearchTree<T>::TreeNode> add(std::shared_ptr<TreeNode>& root, T value)
	{
		if (!root)
			root = std::make_shared<TreeNode>(value);
		else if (root->data > value)
			root->left = add(root->left, value);
		else if (root->data < value)
			root->right = add(root->right, value);

		return root;
	};

	// Recursive function to remove a value from the BST
	std::shared_ptr<TreeNode> remove(std::shared_ptr<TreeNode>& root, T value)
	{
		if (!root)
			return nullptr;
		else if (root->data > value)
			root->left = remove(root->left, value);
		else if (root->data < value)
			root->right = remove(root->right, value);
		else {
			if (!root->right)
				// No right child, return left
				// If left is null, case of no children handled
				return root->left;
			else if (!root->left)
				// No left child, return right
				return root->right;
			else {
				// Both children; replace w/ min from right
				root->data = getMin(root->right);
				root->right = remove(root->right, root->data);
			}
		}

		return root;
	};

	// Recursive function to find a value from the BST
	bool contains(std::shared_ptr<TreeNode>& root, T value)
	{
		if (!root)
			return false;
		else if (root->data == value)
			return true;
		else if (root->data > value)
			return contains(root->left, value);
		else
			return contains(root->right, value);
	};

	// Recursive function to find the in order traversal of the BST
	void inOrderTraversal(std::shared_ptr<TreeNode>& root)
	{
		if (root) {
			inOrderTraversal(root->left);
			std::cout << root->data << " " << std::flush;
			inOrderTraversal(root->right);
		}

	};

public:
	SimpleBinarySearchTree()
	{
		overallRoot = nullptr;
	};

	SimpleBinarySearchTree(T rootData)
	{
		overallRoot = std::make_shared<TreeNode>(rootData);
	};

	~SimpleBinarySearchTree()
	{
		while (overallRoot)
			SimpleBinarySearchTree::remove(overallRoot->data);
	};

	// Adds a value to the Binary Tree if it is not a duplicate
	void add(T value)
	{
		overallRoot = add(overallRoot, value);
	};

	// Removes a value from the Binary Tree if it exists and then returns it
	void remove(T value)
	{
		overallRoot = remove(overallRoot, value);
	};

	// Determines if the given value is in the BST
	bool contains(T value)
	{
		return contains(overallRoot, value);
	};

	// Prints an in order traversal of the BST to the console without a new line
	void inOrderTraversal()
	{
		inOrderTraversal(overallRoot);
	};

};
