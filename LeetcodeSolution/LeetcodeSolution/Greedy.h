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

class Solution944 {
public:
	int minDeletionSize(vector<string>& A)
	{
		int answer = 0;
		for (int j = 0; j < A[0].size(); j++)
		{
			for (int i = 0; i < A.size() - 1; i++)
			{
				if (A[i + 1][j] < A[i][j])
				{
					answer++;
					break;
				}
			}
		}
		return answer;
	}
};

class Solution1403 {
public:
	vector<int> minSubsequence(vector<int>& nums)
	{
		// sort
		sort(nums.begin(), nums.end(), [](const int& l, const int& r) {return l > r; });

		// sum
		int sum = accumulate(nums.cbegin(), nums.cend(), 0);

		vector<int> result;
		int seq_sum = 0;
		for (auto& x : nums)
		{
			seq_sum += x;
			result.push_back(x);
			if (seq_sum > sum - seq_sum)
				break;
		}
		return result;
	}
};

class Solution1217 {
public:
	int minCostToMoveChips(vector<int>& position)
	{
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < position.size(); i++)
		{
			if (position[i] % 2 == 0) sum1++;
			else sum2++;
		}
		return sum1 < sum2 ? sum1 : sum2;
	}
};

class Solution1518 {
public:
	int numWaterBottles(int numBottles, int numExchange)
	{
		int answer = numBottles;
		int t, s;
		do
		{
			t = numBottles / numExchange;
			s = numBottles % numExchange;
			numBottles = t + s;
			answer += t;
		} while (numBottles / numExchange);

		return answer;
	}
};

class Solution122 {
public:
	int maxProfit(vector<int>& prices)
	{
		int answer = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			auto profit = std::max(0, prices[i] - prices[i - 1]);
			answer += profit;
		}
		return answer;
	}
};