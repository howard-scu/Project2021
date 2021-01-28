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


class Solution973 {
public:
	//vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
	//	sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
	//		return u[0] * u[0] + u[1] * u[1] < v[0] * v[0] + v[1] * v[1];
	//	});
	//	return { points.begin(), points.begin() + K };
	//}

	vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
	{
		vector<vector<int>>			results;
		vector<pair<int, double>>	dist_map;
		for (int i = 0; i < points.size(); i++)
		{
			dist_map.push_back(make_pair(i, sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1])));
		}

		auto cmp = [](const pair<int, double>& x, const pair<int, double>& y)->bool
		{
			return x.second > y.second;
		};

		sort(dist_map.begin(), dist_map.end(), cmp);

		for (int i = 0; i < K; i++)
		{
			results.push_back(points[dist_map[i].first]);
		}
		return results;
	}
};


class Solution692 {
public:
	vector<string> topKFrequent(vector<string>& words, int k)
	{
		map<string, int> word_count;
		for (auto w : words)
			word_count[w]++;

		vector<pair<string, int>> wc_vec(word_count.begin(), word_count.end());
		sort(wc_vec.begin(), wc_vec.end(), [](const pair<string, int>& x, const pair<string, int>& y)
		{
			return (x.second > y.second) || (x.second == y.second && x.first < y.first);
		});

		vector<string> results;
		auto it = wc_vec.begin();

		for (int i = 0; i < k; i++)
		{
			results.push_back(it->first);
			++it;
		}
		return results;
	}
};