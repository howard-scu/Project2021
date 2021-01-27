#include "header.h"

class Solution1046 {
public:
	int lastStoneWeight(vector<int>& stones)
	{
		priority_queue<int> pq;
		for (int i = 0; i < stones.size(); i++)
			pq.push(stones[i]);

		while (pq.size() != 1)
		{
			auto v1 = pq.top();
			pq.pop();
			auto v2 = pq.top();
			pq.pop();
			pq.push(v1 - v2);
		}
		return pq.top();
	}
};


class KthLargest {
public:
	KthLargest(int k, vector<int>& nums)
	{
		K = k;
		for (int i = 0; i < nums.size(); i++)
		{
			st.insert(nums[i]);
			if (st.size() > k) st.erase(st.begin());
		}
	}

	int add(int val)
	{
		st.insert(val);
		if (st.size() > K) st.erase(st.begin());
		return *st.begin();
	}
private:
	int K;
	multiset<int> st;
};


class Solution451 {
public:

	//std::priority_queue< freq_pair, std::vector<freq_pair>, auto(*)(const freq_pair&, const freq_pair&)->bool > pq
	//{
	//	[](const freq_pair& x, const freq_pair& y)->bool
	//	{
	//		return x.second < y.second;
	//	}
	//};
	string frequencySort(string s)
	{
		unordered_map<char, int> mp;
		for (const auto& ch : s)
		{
			mp[ch]++;
		}

		auto cmp = [&](const auto& a, const auto& b)
		{
			return mp[a] > mp[b] || (mp[a] == mp[b] && a < b);
		};

		sort(s.begin(), s.end(), cmp);
		return s;
	}
};


class Solution215
{
public:
	int findKthLargest(vector<int>& nums, int k)
	{
		std::priority_queue<int, vector<int>, greater<int>> pq;
		for (auto v : nums)
		{
			if (pq.size() < k) pq.push(v);
			else {
				pq.push(v);
				pq.pop();
			}
		}
		return pq.top();
	}
};


class Solution264 {
public:
	int nthUglyNumber(int n)
	{
		set<int> iset;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					auto val = pow(5, i)*pow(3, j)*pow(2, k);
					if (iset.size() == 0 || val < *(iset.rbegin()))
						iset.insert(val);
				}
			}
		}
		return *(iset.rbegin());
	}
};