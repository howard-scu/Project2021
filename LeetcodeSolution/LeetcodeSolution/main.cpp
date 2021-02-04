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
	string line;
	while (getline(cin, line)) {
		vector<int> A = stringToIntegerVector(line);

		vector<int> ret = Solution922().sortArrayByParityII(A);

		string out = integerVectorToString(ret);
		cout << out << endl;
	}
	return 0;
}