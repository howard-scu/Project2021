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