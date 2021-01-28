#include "SlidingWindow.h"
#include "TwoPointers.h"
#include "Stack.h"
#include "Heap.h"
#include "Greedy.h"


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
	string line;
	while (getline(cin, line)) {
		vector<int> stones = stringToIntegerVector(line);

		int ret = Solution1046().lastStoneWeight(stones);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}