#include "SlidingWindow.h"
#include "TwoPointers.h"
#include "Stack.h"
#include "Heap.h"
#include "Greedy.h"
#include "Sort.h"


//int main() {
//	string line;
//	while (getline(cin, line)) {
//		string S = stringToString(line);
//
//		string ret = Solution1021().removeOuterParentheses(S);
//
//		string out = (ret);
//		cout << out << endl;
//	}
//	return 0;
//}


int main() {
	auto ret = Solution1640().canFormArray(vector<int>{91, 4, 64, 78}, 
		vector<vector<int>>{ {78}, { 4, 64 }, { 91 }});
	return 0;
}