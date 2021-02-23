#include "header.h"

class Solution897 {
public:
	vector<int> nodes;

	void traversal(TreeNode* root)
	{
		if (root == nullptr) return;
		traversal(root->left);
		nodes.push_back(root->val);
		traversal(root->right);
	}

	TreeNode* increasingBST(TreeNode* root)
	{
		traversal(root);
		if (nodes.size() == 0) return nullptr;
		TreeNode* ans_root = new TreeNode(nodes[0]);
		TreeNode* p = ans_root;
		for (int i = 1; i < nodes.size(); i++)
		{
			auto t = new TreeNode(nodes[i]);
			p->right = t;
			p = t;
		}
		return ans_root;
	}
};


class Solution21 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode* result = new ListNode(0);
		ListNode* p = result;
		ListNode* q = p->next;

		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				p->next = l1;
				l1 = l1->next;
				p = p->next;
				p->next = q;
				q = p->next;
			}
			else
			{
				p->next = l2;
				l2 = l2->next;
				p = p->next;
				p->next = q;
				q = p->next;
			}
		}
		while (l1)
		{

			p->next = l1;
			l1 = l1->next;
			p = p->next;
			p->next = q;
			q = p->next;

		}
		while (l2)
		{

			p->next = l2;
			l2 = l2->next;
			p = p->next;
			p->next = q;
			q = p->next;
		}
		return result->next;
	}
};


class Solution563 {
public:
	int traversal(TreeNode* root)
	{
		if (root == nullptr) return 0;
		return traversal(root->left) + traversal(root->right) + root->val;
	}
	int findTilt(TreeNode* root)
	{
		if (root == nullptr) return 0;
		return abs(traversal(root->left) - traversal(root->right)) + findTilt(root->left) + findTilt(root->right);
	}
};

class Solution783 {
public:
	int prev;
	int	ans;

	int minDiffInBST(TreeNode* root)
	{
		prev = -1;
		ans = 1000;
		dfs(root);
		return ans;
	}

	void dfs(TreeNode* node)
	{
		if (node == nullptr) return;
		dfs(node->left);
		if (prev != -1)
			ans = min(ans, node->val - prev);
		prev = node->val;
		dfs(node->right);
	}
};

class Solution110 {
public:
	int height(TreeNode* root)
	{
		if (root == nullptr) return 0;
		return max(height(root->left), height(root->right)) + 1;
	}

	bool isBalanced(TreeNode* root)
	{
		if (root == nullptr) return true;
		return (abs(height(root->left) - height(root->right)) <= 1) &&
			isBalanced(root->left) && isBalanced(root->right);
	}
};


class Solution1137 {
public:
	int tribonacci(int n)
	{
		if (n == 0) return 0;
		else if (n == 1) return 1;
		else if (n == 2) return 1;
		else
			return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
	}
};



class Solution1379 {
public:
	TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
	{
		if (original == nullptr) return nullptr;

		if (original == target) return cloned;
		else {
			auto left = getTargetCopy(original->left, cloned->left, target);
			auto right = getTargetCopy(original->right, cloned->right, target);
			return left != nullptr ? left : right;
		}
	}
};


class Solution1038 {
public:
	int sum = 0;
	TreeNode* bstToGst(TreeNode* root)
	{
		if (root != nullptr) {
			bstToGst(root->right);
			sum = sum + root->val;
			root->val = sum;
			bstToGst(root->left);
		}
		return root;

	}
};