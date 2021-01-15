#pragma once
#include"header.h"



class Solution763
{
public:
	vector<int> partitionLabels(string S)
	{
		int last[26];
		for (int i = 0; i < S.length(); i++)
			last[S[i] - 'a'] = i;

		vector<int> partition;
		int start = 0, end = 0;
		for (int i = 0; i < S.length(); i++)
		{
			end = std::max(end, last[S[i] - 'a']);
			if (i == end)
			{
				partition.push_back(end - start + 1);
				start = end + 1;
			}
		}
		return partition;
	}
};

class Solution167 {
public:
	vector<int> twoSum(vector<int>& numbers, int target)
	{
		vector<int> result;
		int l = 0;
		int r = numbers.size() - 1;

		while (l < r)
		{
			auto sum = numbers[l] + numbers[r];
			if (sum > target) r--;
			else if (sum < target) l++;
			else return vector<int>{l + 1, r + 1};
		}
	}
};


class Solution350 {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
	{
		// ≈≈–Ú
		std::sort(nums1.begin(), nums1.end());
		std::sort(nums2.begin(), nums2.end());

		// ΩªºØ
		std::vector<int> intersection;
		std::set_intersection(
			nums1.begin(), nums1.end(),
			nums2.begin(), nums2.end(),
			std::back_inserter(intersection));
		return intersection;
	}
};


class Solution26 {
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.size() <= 1) return nums.size();

		int fast = 0;
		int slow = 1;

		for (; fast < nums.size(); fast++)
		{
			if (nums[fast] != nums[slow])
			{
				slow++;
				nums[slow] = nums[fast];
			}
		}
		return slow + 1;
	}
};


class Solution844 {
public:
	bool backspaceCompare(string S, string T)
	{
		int i = S.length() - 1;
		int j = T.length() - 1;
		int skipS = 0;
		int skipT = 0;
		while (i >= 0 && j >= 0)
		{
			while (i >= 0)
			{
				if (S[i] == '#')
				{
					skipS++, i--;
				}
				else if (skipS > 0)
				{
					skipS--, i--;
				}
				else
					break;
			}
			while (j >= 0)
			{
				if (T[j] == '#')
				{
					skipT++, j--;
				}
				else if (skipT > 0)
				{
					skipT--, j--;
				}
				else
					break;
			}
			if (i >= 0 && j >= 0)
			{
				if (S[i] != T[j])
					return false;
			}
			else if (i >= 0 || j >= 0)
				return false;

			i--, j--;
		}
		while (i >= 0)
		{
			if (S[i] == '#')
			{
				skipS++, i--;
			}
			else if (skipS > 0)
			{
				skipS--, i--;
			}
			else
				break;
		}
		while (j >= 0)
		{
			if (T[j] == '#')
			{
				skipT++, j--;
			}
			else if (skipT > 0)
			{
				skipT--, j--;
			}
			else
				break;
		}
		if (i >= 0 || j >= 0)
			return false;
		else
			return true;
	}
};

class Solution88 {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int id = m + n - 1;
		for (int i = m - 1, j = n - 1; id >= 0 && j >= 0; )
		{
			if (i < 0)
			{
				nums1[id--] = nums2[j--];
			}
			else
			{
				if (nums2[j] >= nums1[i])
				{
					nums1[id] = nums2[j];
					j--, id--;
				}
				else
				{
					nums1[id] = nums1[i];
					i--, id--;
				}
			}

		}
	}
};


class Solution125
{
public:
	bool isPalindrome(string s)
	{
		int l = 0;
		int r = s.length() - 1;

		while (l < r)
		{
			while (l < s.length() && !isalnum(s[l]))l++;
			while (r >= 0 && !isalnum(s[r]))r--;

			if (l < r)
			{
				//if (s[l] != s[r] && !(isalpha(s[l]) && isalpha(s[r]) && tolower(s[l]) == tolower(s[r])))
				if (tolower(s[l]) != tolower(s[r]))
					return false;
				else
				{
					l++, r--;
				}
			}
		}
		return true;
	}
};


class Solution234
{
public:
	ListNode* reverseNodes(ListNode* head)
	{
		if (head == nullptr) return nullptr;
		ListNode* p = head;
		head = new ListNode(0);
		while (p != nullptr)
		{
			auto q = head->next;
			auto t = p->next;

			head->next = p;
			p->next = q;
			p = t;
		}
		auto tmp = head;
		head = head->next;
		delete tmp;
		return head;
	}

	bool isPalindrome(ListNode* head)
	{
		if (head == nullptr) return true;

		ListNode* fast = head;
		ListNode* slow = head;

		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		ListNode* p;
		if (fast) p = slow->next;
		else p = slow;
		p = reverseNodes(p);

		for (auto q = head;
			p != nullptr&& q != nullptr;
			p = p->next, q = q->next)
			if (p->val != q->val)
			{
				return false;
			}
		return true;
	}
};

