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