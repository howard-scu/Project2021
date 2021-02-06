#include "header.h"


class Solution938 {
public:
	void InOrderTraversal(TreeNode* root, int& low, int& high, int& sum)
	{
		if (root == nullptr) return;
		if (root->val >= low && root->val <= high)
			sum += root->val;
		InOrderTraversal(root->left, low, high, sum);
		InOrderTraversal(root->right, low, high, sum);
	}
	int rangeSumBST(TreeNode* root, int low, int high)
	{
		int sum = 0;
		InOrderTraversal(root, low, high, sum);
		return sum;
	}
};


class Solution226 {
public:
	TreeNode* invertTree(TreeNode* root)
	{
		if (root == nullptr) return nullptr;

		auto left = invertTree(root->left);
		auto right = invertTree(root->right);

		root->left = right;
		root->right = left;

		return root;
	}
};


class Solution104 {
public:
	int maxDepth(TreeNode* root)
	{
		if (root == nullptr) return 0;

		auto l = maxDepth(root->left) + 1;
		auto r = maxDepth(root->right) + 1;

		return max(l, r);
	}
};


class Solution590 {
public:
	vector<int> postorder(Node* root) {
		vector<int> result;
		postorder(root, result);
		return result;
	}

	void postorder(Node* root, vector<int>& result) {
		if (root == nullptr)
			return;
		for (auto node : root->children)
			postorder(node, result);
		result.push_back(root->val);
	}
};


class Solution700 {
public:
	TreeNode* searchBST(TreeNode* root, int val)
	{
		if (root == nullptr) return nullptr;

		if (root->val < val) return searchBST(root->right, val);
		else if (root->val < val) return searchBST(root->left, val);
		else return root;
	}
};