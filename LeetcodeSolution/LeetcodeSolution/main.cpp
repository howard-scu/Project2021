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

int main()
{
	int result = Solution682().calPoints(vector<string>{"5", "2", "C", "D", "+"});
	cout << result << endl;
	return 0;
}