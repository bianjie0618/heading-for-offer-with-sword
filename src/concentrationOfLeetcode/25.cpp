// k个一组翻转列表

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1. 找区间
// 2. 翻转
// 3. 链接
// 以此类推

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* fakeHead = new ListNode(0, head);
        ListNode* leftBound = fakeHead;
        ListNode* rightBound = fakeHead;
        while(rightBound != nullptr) {
            int num = k;
            while (rightBound != nullptr && num > 0) {
                rightBound = rightBound->next;
                num--;
            }
            if (rightBound == nullptr) {
                break;
            }
            rightBound = rightBound->next;
            ListNode* lastNodeInNewList = leftBound->next;
            ListNode* firstNodeInNewList = reverseList(leftBound->next, rightBound);
            lastNodeInNewList->next = rightBound;
            leftBound->next = firstNodeInNewList;
            leftBound = lastNodeInNewList;
            rightBound = leftBound;
        }
        return fakeHead->next;
    }

    ListNode* reverseList(ListNode* start, ListNode* end) {
        ListNode* pre = nullptr;
        ListNode* current = start;
        ListNode* next = nullptr;
        while (current != end) {
            next = current->next;
            current->next = pre;
            pre = current;
            current = next;
        }
        return pre;
    }
};