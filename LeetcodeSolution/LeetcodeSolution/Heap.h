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
		mk = k;
		for (int i = 0; i < nums.size(); i++)
			pq.push(nums[i]);
	}

	int add(int val) 
	{
		pq.push(val);
		for (int i = 0; i < mk; i++)
		{
			auto v = pq.top();
			sta.push(v);
			pq.pop();
		}
		auto result = sta.top();
		while (!sta.empty())
		{
			auto v = sta.top();
			sta.pop();
			pq.push(v);
		}
		return result;
	}
private:
	priority_queue<int> pq;
	stack<int>			sta;
	int mk;
};
