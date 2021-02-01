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



class Solution1528{
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