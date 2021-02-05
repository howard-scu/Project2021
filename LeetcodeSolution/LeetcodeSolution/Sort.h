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


class Solution1030 {
public:
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
	{
		vector<vector<int>> result;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				result.push_back(vector<int>{i, j});
			}
		}

		sort(result.begin(), result.end(),
			[&](const vector<int>& x, const vector<int>& y)
		{
			return abs(x[0] - r0) + abs(x[1] - c0) <
				abs(y[0] - r0) + abs(y[1] - c0);
		});

		return result;
	}
};

class Solution1122 {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
	{
		unordered_map<int, int> rank;
		for (int i = 0; i < arr2.size(); i++)
		{
			rank[arr2[i]] = i;
		}

		sort(arr1.begin(), arr1.end(),
			[&](auto& x, auto& y) {
			if (rank.count(x)) {
				return rank.count(y) ? rank[x] < rank[y] : true;
			}
			else {
				return rank.count(y) ? false : x < y;
			}
		});

		return arr1;
	}
};


class Solution1640 {
public:
	bool canFormArray(vector<int> arr, vector<vector<int>> pieces)
	{
		unordered_map<int, int> rank;
		for (int i = 0; i < arr.size(); i++)
			rank[arr[i]] = i;

		for (int i = 0; i < pieces.size(); i++)
		{
			for (int j = 0; j < pieces[i].size(); j++)
			{
				if (!rank.count(pieces[i][j])) return false;
				else {
					if (j >= 1 && (rank[pieces[i][j]] - rank[pieces[i][j - 1]] != 1))
						return false;
				}
			}
		}
		return true;
	}
};


class Solution1491 {
public:
	double average(vector<int>& salary)
	{
		double max = 0;
		double min = 1e10;
		double sum = 0;
		for (int i = 0; i < salary.size(); i++)
		{
			sum += salary[i];
			if (max < salary[i]) max = salary[i];
			if (min > salary[i]) min = salary[i];
		}
		return (sum - min - max) / (salary.size() - 2);
	}
};


class Solution976 {
public:
	int largestPerimeter(vector<int>& A)
	{
		sort(A.begin(), A.end(), [](auto& x, auto& y) {return x > y; });

		vector<int> answer;
		for (int i = 0; i < A.size() - 2; i++)
		{
			if (A[i + 2] + A[i + 1] > A[i])
				return A[i] + A[i + 1] + A[i + 2];
		}
		return 0;
	}
};


class Solution922 {
public:
	vector<int> sortArrayByParityII(vector<int>& A)
	{
		std::partition(A.begin(), A.end(), [&](auto& elem) {
			auto idx = &elem - &A[0];
			cout << idx << ", " << A[idx] << endl;
			return (idx % 2 == 0 && A[idx] % 2 == 0) ||
				(idx % 2 == 1 && A[idx] % 2 == 1);
		});
		return A;
	}
};