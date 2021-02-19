#include "header.h"

class Solution20
{
public:
	bool isValid(string s)
	{
		stack<char> st;
		for (auto c : s)
		{
			if (c == '(' || c == '[' || c == '{')
			{
				st.push(c);
			}
			else
			{
				if (!st.empty() && (
					(c == ')' && st.top() == '(') ||
					(c == ']' && st.top() == '[') ||
					(c == '}' && st.top() == '{')))
					st.pop();
				else
					return false;
			}
		}
		if (st.empty()) return true;
		else return false;
	}
};

class Solution1021
{
public:
	string removeOuterParentheses(string S)
	{
		stack<char> st;
		string result = "";
		for (auto c : S)
		{
			if (c == ')')
				st.pop();
			if (!st.empty())
				result += c;
			if (c == '(')
				st.push('(');
		}
		return result;
	}
};

class Solution1047 {
public:
	string removeDuplicates(string S)
	{
		stack<char> st;
		for (int i = 0; i < S.length(); i++)
		{
			if (st.empty() || st.top() != S[i])
			{
				st.push(S[i]);
			}
			else
			{
				st.pop();
			}
		}
		string result;
		result.resize(st.size());
		int c = 0;
		int n = st.size() - 1;
		while (!st.empty())
		{
			result[n - c++] = st.top();
			st.pop();
		}
		return result;
	}
};

class Solution682 {
public:
	int calPoints(vector<string> ops)
	{
		stack<int> st;
		for (int i = 0; i < ops.size(); i++)
		{
			if (ops[i].length() == 1)
			{
				if (ops[i][0] == 'C')
				{
					st.pop();
				}
				else if (ops[i][0] == 'D')
				{
					auto n1 = st.top();
					st.push(n1 * 2);
				}
				else if (ops[i][0] == '+')
				{
					auto n1 = st.top();
					st.pop();
					auto n2 = st.top();
					st.pop();
					st.push(n2);
					st.push(n1);
					st.push(n1 + n2);
				}
				else
					st.push(atoi(ops[i].c_str()));
			}
			else
				st.push(atoi(ops[i].c_str()));
		}
		int sum = 0;
		while (!st.empty())
		{
			sum += st.top();
			st.pop();
		}
		return sum;
	}
};

class Solution1598 {
public:
	int minOperations(vector<string>& logs)
	{
		stack<string> st;
		int result = 0;
		for (int i = 0; i < logs.size(); i++)
		{
			if (logs[i] == "../")
			{
				if (st.size() > 0)
					st.pop();
			}
			else if (logs[i] == "./")
			{
				;
			}
			else
			{
				st.push(logs[i]);
			}
		}
		return st.size();
	}
};

//class Solution496
//{
//public:
//	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
//	{
//		unordered_map<int,int>  umap;
//		stack<int>				st;
//
//		for (int i = 0; i < nums2.size(); i++)
//		{
//			if (st.empty()) st.push(nums2[i]);
//			else if (nums2[i] > st.top())
//			{
//				st.push(nums2[i]);
//			}
//			else
//			{
//				while (!st.empty())
//				{
//					umap[st.top()] = nums2[i];
//					st.pop();
//				}
//			}
//		}
//		vector<int> results;
//		for (int i = 0; i < nums1.size(); i++)
//			if (umap.find(nums1[i]) != umap.end())
//				results.push_back(umap[nums1[i]]);
//			else
//				results.push_back(-1);
//		return results;
//	}
//};