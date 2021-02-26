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

class Solution108 {
public:
	TreeNode* constructBST(vector<int>& nums, int i, int j)
	{
		if (i > j) return nullptr;
		else
		{
			int t = (i + j) / 2;
			auto root = new TreeNode(nums[t]);
			root->left = constructBST(nums, i, t - 1);
			root->right = constructBST(nums, t + 1, j);
			return root;
		}
	}

	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		return constructBST(nums, 0, nums.size() - 1);
	}
};

class Solution589 {
public:
	vector<int> preorder(Node* root)
	{
		stack<Node*> sta;
		if (root != nullptr)
			sta.push(root);

		vector<int> results;
		while (!sta.empty())
		{
			auto t = sta.top();
			sta.pop();
			results.push_back(t->val);

			for (int i = t->children.size() - 1; i >= 0; i--)
			{
				sta.push(t->children[i]);
			}
		}
		return results;
	}
};

class Solution559 {
public:

	int maxDepth(Node* root)
	{
		if (root == nullptr) return 0;

		int depth = 0;
		for (auto node : root->children)
		{
			depth = max(depth, maxDepth(node));
		}

		return depth + 1;
	}
};


class Solution1022 {
public:
	int  sum = 0;

	void dfs(TreeNode *root, int num)
	{
		if (root == nullptr) return;
		num = num * 2 + root->val;
		if (root->left == nullptr && root->right == nullptr) sum += num;
		dfs(root->left, num);
		dfs(root->right, num);
		return;
	}

	int sumRootToLeaf(TreeNode* root)
	{
		dfs(root, 0);
		return sum;
	}
};


class Solution637 {
public:
	vector<double> averageOfLevels(TreeNode* root)
	{
		vector<double> result;
		std::queue<TreeNode*> que;
		que.push(root);

		while (!que.empty())
		{
			int num = que.size();
			double sum = 0;

			for (int i = 0; i < num; i++)
			{
				auto node = que.front();
				sum += node->val;
				que.pop();

				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
			result.push_back(sum / num);
		}
		return result;
	}
};


class Solution965 {
public:
	bool dfs(TreeNode* root, int val)
	{
		if (root == nullptr) return true;
		else
		{
			if (root->val != val) return false;
			else
			{
				return dfs(root->left, val) && dfs(root->right, val);
			}
		}
	}

	bool isUnivalTree(TreeNode* root)
	{
		return dfs(root, root->val);
	}
};


class Solution257 {
public:
	vector<string> result;

	void traversal(TreeNode* root, string path)
	{
		if (root == nullptr) return;
		path += ("->" + std::to_string(root->val));
		if (!root->left && !root->right)
			result.push_back(path.substr(2, path.length()));
		traversal(root->left, path);
		traversal(root->right, path);
	}

	vector<string> binaryTreePaths(TreeNode* root)
	{
		traversal(root, "");
		return result;
	}
};


class Solution235 {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (root == nullptr || root == p || root == q)
			return root;

		TreeNode* left  = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		//如果left为空，说明这两个节点在cur结点的右子树上，我们只需要返回右子树查找的结果即可
		if (left == nullptr)
			return right;
		//同上
		if (right == nullptr)
			return left;
		//如果left和right都不为空，说明这两个节点一个在cur的左子树上一个在cur的右子树上，
		//我们只需要返回cur结点即可。
		return root;
	}
};


class Solution872 {
public:
	void traversal(TreeNode* root, vector<int>& leaves)
	{
		if (root == nullptr) return;
		if (!root->left && !root->right)leaves.push_back(root->val);
		traversal(root->left,leaves);
		traversal(root->right, leaves);
	}

	bool leafSimilar(TreeNode* root1, TreeNode* root2) 
	{
		vector<int> leaves1;
		vector<int> leaves2;

		traversal(root1, leaves1);
		traversal(root2, leaves2);

		return leaves1 == leaves2;
	}
};