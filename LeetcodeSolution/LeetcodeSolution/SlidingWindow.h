#pragma once
#include <vector>
#include <iostream>
#include <algorithm>  

using namespace std;

class Solution1004
{
public:
	// https://leetcode-cn.com/problems/max-consecutive-ones-iii/solution/zhong-gui-zhong-ju-hua-chuang-ji-zhi-duo-5w0a/
	int longestOnes(vector<int>& A, int K)
	{
		int result = 0;

		for (int left = 0, right = 0, zeros = 0; right < A.size(); right++)
		{
			if (A[right] == 0) zeros++;
			while (zeros > K)
			{
				if (A[left++] == 0) zeros--;
			}
			result = std::max(result, right - left + 1);
		}
		return result;
	}
};


class Solution1052
{
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X)
	{
		int total = 0;
		for (int i = 0; i < grumpy.size(); i++)
			if (grumpy[i] == 0) total += customers[i];

		int sum = 0;
		int maxSum = 0;
		for (int i = 0; i < X; i++)
		{
			if (grumpy[i] == 1)
				sum += customers[i];
		}

		//cout << sum << endl;
		maxSum = max(sum, maxSum);

		for (int l = 0, r = X; r < grumpy.size(); r++, l++)
		{
			if (grumpy[r] == 1) sum += customers[r];
			if (grumpy[l] == 1) sum -= customers[l];
			//cout << "[" << l << "," << r << "] : " << sum << endl;
			maxSum = max(sum, maxSum);
		}
		return total + maxSum;
	}
};


class Solution1040
{
public:
	vector<int> numMovesStonesII(vector<int>& stones)
	{
		sort(stones.begin(), stones.end());
		int n = stones.size();
		int maxMoves = std::max(
			(stones[n - 1] - stones[1] + 1)/* ���е� */ - (n - 1)/* ռ�õ� */,
			(stones[n - 2] - stones[0] + 1)/* ���е� */ - (n - 1)/* ռ�õ� */
		);
		int minMoves = n;
		for (int i = 0, j = 0; j < n; ++j)
		{
			//��ǰ���ڵĴ�С����n
			while (stones[j] - stones[i] + 1 > n)i++;
			//��ǰ���ڵ�ʯ�Ӹ���
			int already_stone = (j - i + 1);
			//ǰn-1��ʯ�ӵ�˳�����������һ��ʯ�Ӳ���������Ҫ�ƶ�2����
			//����3 4 5 6 10�����ǲ���ֱ�ӽ�10��Ϊ2�����ǽ�3��Ϊ8��Ȼ��10��Ϊ7���ƶ�
			if (already_stone == n - 1 && stones[j] - stones[i] + 1 == n - 1)
				minMoves = std::min(maxMoves, 2);
			else
				minMoves = std::min(maxMoves, n - already_stone);
		}
		return { minMoves, maxMoves };
	}
};

class Solution830
{
public:
	vector<vector<int>> largeGroupPositions(string s)
	{
		vector<vector<int>> result;
		int i = 0, j = 0;
		for (; j < s.length();)
		{
			if (s[i] == s[j]) j++;
			else
			{
				if (j - i >= 3)
				{
					result.push_back({ i,j - 1 });
				}
				i = j;
			}
		}
		int a = s.length();
		if (a - i >= 3)
		{
			result.push_back({ i,a - 1 });
		}
		return result;
	}
};

