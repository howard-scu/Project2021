#include "SlidingWindow.h"
#include "TwoPointers.h"


int main() {
	string line;
	while (getline(cin, line)) {
		ListNode* head = stringToListNode(line);

		bool ret = Solution234().isPalindrome(head);

		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}

