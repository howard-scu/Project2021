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