#include "SlidingWindow.h"
#include "TwoPointers.h"
#include "Stack.h"


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
		string S = stringToString(line);

		string ret = Solution1047().removeDuplicates(S);

		string out = (ret);
		cout << out << endl;
	}
	return 0;
}