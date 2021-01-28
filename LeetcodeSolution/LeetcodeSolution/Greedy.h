#include "header.h"

class Solution1221 {
public:
	int balancedStringSplit(string s)
	{
		int answer = 0;
		int l = 0;
		int r = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'L') l++;
			if (s[i] == 'R') r++;
			if (l == r) answer++;
		}
		return answer;
	}
};

class Solution1725 {
public:
	int countGoodRectangles(vector<vector<int>>& rectangles)
	{
		int n_max = 0;
		int n_count = 0;
		for (auto it : rectangles)
		{
			auto minor = min(it[0], it[1]);
			if (minor > n_max)
			{
				n_max = minor;
				n_count = 1;
			}
			else if (minor == n_max)n_count++;
		}
		return n_count;
	}
};
