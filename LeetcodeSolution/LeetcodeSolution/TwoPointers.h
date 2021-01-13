#pragma once
#include <vector>
#include <iostream>
#include <algorithm>  
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;


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
			else if(i >= 0 || j >= 0)
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

