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


class Solution1716 {
public:
	int totalMoney(int n)
	{
		int total = 0, week = 0, offset = 0;
		for (int i = 0; i < n; i++)
		{
			week = i / 7;
			offset = i % 7 + 1;
			total += week + offset;
		}
		return total;
	}
};


class Solution1710 {
public:
	int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
	{
		sort(boxTypes.begin(), boxTypes.end(),
			[](const vector<int>& x, const vector<int>& y) {return x[1] > y[1]; });

		int answer = 0;
		for (int i = 0; i < boxTypes.size(); i++)
		{
			for (int j = 0; j < boxTypes[i][0]; i++)
			{
				answer += boxTypes[i][1];
				truckSize--;
				if (truckSize == 0)
					break;
			}
		}
		return answer;
	}
};