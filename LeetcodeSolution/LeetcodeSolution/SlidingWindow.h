#pragma once
#include <vector>
#include <iostream>
#include <algorithm>  
#include <unordered_map>
#include <map>
#include <queue>
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
			(stones[n - 1] - stones[1] + 1)/* 所有点 */ - (n - 1)/* 占用点 */,
			(stones[n - 2] - stones[0] + 1)/* 所有点 */ - (n - 1)/* 占用点 */
		);
		int minMoves = n;
		for (int i = 0, j = 0; j < n; ++j)
		{
			//当前窗口的大小大于n
			while (stones[j] - stones[i] + 1 > n)i++;
			//当前窗口的石子个数
			int already_stone = (j - i + 1);
			//前n-1个石子的顺序连续，最后一个石子不连续，需要移动2步。
			//比如3 4 5 6 10，我们不能直接将10变为2，而是将3变为8，然后10变为7来移动
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

class Solution424
{
public:
	int characterReplacement(string s, int k)
	{
		int maxch = 0;
		int cmap[26]{ 0 };
		int left = 0;

		for (int right = 0; right < s.length(); right++)
		{
			cmap[s[right] - 'A']++;
			maxch = std::max(maxch, cmap[s[right] - 'A']);

			if (right - left + 1 > maxch + k)
			{
				cmap[s[left] - 'A']--;
				left++;
			}
		}
		return s.length() - left;
	}
};


class Solution1456
{
public:
	int maxVowels(string s, int k)
	{
		int result = 0;

		for (int left = 0, right = 0, cnt = 0; right < s.length(); right++)
		{
			if (s[right] == 'a' ||
				s[right] == 'e' ||
				s[right] == 'i' ||
				s[right] == 'o' ||
				s[right] == 'u')
				cnt++;

			if (right - left + 1 > k)
			{
				if (s[left] == 'a' ||
					s[left] == 'e' ||
					s[left] == 'i' ||
					s[left] == 'o' ||
					s[left] == 'u')
					cnt--;
				left++;
			}

			result = std::max(result, cnt);
		}
		return result;
	}
};


class Solution1423
{
public:
	int maxScore(vector<int>& cardPoints, int k)
	{
		// 前n-k个值和
		int kSum = 0;
		int n = cardPoints.size();
		for (int i = 0; i < k && i < n; i++)
		{
			kSum += cardPoints[i];
		}

		int maxSum = kSum;
		for (int i = 1; i <= k && i < n; i++)
		{
			// k=4 => 0,1,2,3,
			// ...
			// k=4 => n-4,n-3,n-2,n-1,
			kSum = kSum - cardPoints[k - i] + cardPoints[n - i];
			maxSum = std::max(maxSum, kSum);
		}

		return maxSum;
	}
};


class Solution978
{
public:
	int maxTurbulenceSize(vector<int>& arr)
	{
		if (arr.size() <= 1) return arr.size();
		int result = 1;

		for (int l = 0, r = 1, flag = 0; r < arr.size(); r++)
		{
			if (flag == 0)
			{
				if (arr[r] - arr[r - 1] > 0) flag = 1;
				else if (arr[r] - arr[r - 1] < 0) flag = -1;
				else
				{
					flag = 0;
					l = r;
					r = std::min(l + 1, (int)arr.size() - 1);
				}
			}
			else if (flag == 1)
			{
				if (arr[r] - arr[r - 1] < 0) flag = -1;
				else if (arr[r] - arr[r - 1] > 0)
				{
					flag = 1;
					l = r - 1;
				}
				else
				{
					flag = 0;
					l = r;
					r = std::min(l + 1, (int)arr.size() - 1);
				}
			}
			else if (flag == -1)
			{
				if (arr[r] - arr[r - 1] > 0) flag = 1;
				else if (arr[r] - arr[r - 1] < 0)
				{
					flag = -1;
					l = r - 1;
				}
				else
				{
					flag = 0;
					l = r;
					r = std::min(l + 1, (int)arr.size() - 1);
				}
			}
			cout << "R:" << r << ", L:" << l << "\t" << flag << endl;
			result = std::max(r - l + 1, result);
		}
		return result;
	}
};



class Solution1208
{
public:
	int equalSubstring(string s, string t, int maxCost)
	{
		int result = 0;
		int current = 0;
		for (int l = 0, r = 0; r < s.length(); r++)
		{
			current += abs(s[r] - t[r]);

			if (current > maxCost)
			{
				current -= abs(s[l] - t[l]);
				l++;
			}

			result = std::max(r - l + 1, result);
		}
		return result;
	}
};



class Solution1438
{
public:
	int longestSubarray(vector<int>& nums, int limit)
	{
		int result = 0;
		std::map<int, int> vmap;
		for (int l = 0, r = 0; r < nums.size(); r++)
		{
			vmap[nums[r]]++;
			if (vmap.rbegin()->first - vmap.begin()->first > limit)
			{
				auto it = vmap.find(nums[l++]);
				it->second--;
				if (it->second == 0)
					vmap.erase(it);
			}
			result = std::max(r - l + 1, result);
		}
		return result;
	}
};



class Solution1498
{
public:
	int numSubseq(vector<int>& nums, int target)
	{
		int result = 0;
		std::map<int, int> vmap;

		for (int l = 0, r = 0; r < nums.size(); r++)
		{
			vmap[nums[r]]++;

			if (vmap.begin()->first + vmap.rbegin()->first > target)
			{
				auto it = vmap.find(vmap[l++]);
				if (--(it->second) == 0)
				{
					vmap.erase(it);
				}
			}
			result = std::max(r - l + 1, result);
		}
		return result % (1000000000 + 7);
	}
};

