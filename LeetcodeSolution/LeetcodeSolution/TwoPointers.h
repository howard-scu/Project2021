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