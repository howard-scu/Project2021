#include "header.h"


class Solution1370 {
public:
	string sortString(string s)
	{
		int cc[26]{ 0 };
		for (int i = 0; i < s.length(); i++)
			cc[s[i] - 'a']++;

		string answer = "";
		int t = 1;
		int c = 0;
		while (c < s.length())
		{
			for (int i = 0; i < 26; i++)
			{
				if (t == 1)
				{
					if (cc[i] != 0)
					{
						answer += (i + 'a');
						cc[i]--;
						c++;
					}
				}
				else
				{
					if (cc[25 - i] != 0)
					{
						answer += (25 - i + 'a');
						cc[25 - i]--;
						c++;
					}
				}
			}
			t = -t;
		}
		return answer;
	}
};



class Solution1528 {
public:
	string restoreString(string s, vector<int>& indices)
	{
		auto answer = s;
		for (int i = 0; i < s.length(); i++)
		{
			answer[indices[i]] = s[i];
		}
		return answer;
	}
};


class Solution1502 {
public:
	bool canMakeArithmeticProgression(vector<int>& arr)
	{
		sort(arr.begin(), arr.end());

		if (arr.size() <= 1) return false;

		auto delta = arr[1] - arr[0];
		for (int i = 1; i < arr.size(); i++)
		{
			if (arr[i] - arr[i - 1] != delta)
				return false;
		}
		return true;
	}
};


class Solution1636 {
public:
	vector<int> frequencySort(vector<int>& nums)
	{
		// count
		unordered_map<int, int> freq;
		for (auto& x : nums)
			freq[x]++;

		sort(nums.begin(), nums.end(), [&](const int& x, const int& y)
		{
			return (freq[x] < freq[y]) || (freq[x] == freq[y] && x > y);
		});

		return nums;
	}
};


//class Solution922 {
//public:
//	vector<int> sortArrayByParityII(vector<int>& A)
//	{
//		std::partition(A.begin(), A.end(), [&](auto& elem) {
//			auto idx = &elem - &A[0];
//			cout << idx << ", " << A[idx] << endl;
//			return (idx % 2 == 0 && A[idx] % 2 == 0) ||
//				(idx % 2 == 1 && A[idx] % 2 == 1);
//		});
//		return A;
//	}
//};