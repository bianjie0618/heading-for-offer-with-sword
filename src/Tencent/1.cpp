

#include <vector>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param m int整型 
     * @param a ListNode类 指向彩带的起点，val表示当前节点的val，next指向下一个节点
     * @return ListNode类vector
     */
    vector<ListNode*> solve(int m, ListNode* a) {
        // write code here
        vector<vector<ListNode*>> vecRes(m, vector<ListNode*>());
        vector<ListNode*> res;
        while (a != nullptr) {
            vecRes[(a->val % m)].push_back(a);
            a = a->next;
        }
        for (int i = 0; i < m; ++i) {
            ListNode* curHead = new ListNode(0);
            ListNode* curPtr = curHead;
            for (int j = 0; j < vecRes[i].size(); j++) {
                curPtr->next = vecRes[i][j];
                curPtr = curPtr->next;
            }
            curPtr->next = nullptr;
            res.push_back(curHead->next);
        }
        return res;
    }
};