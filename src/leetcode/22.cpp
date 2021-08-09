// 剑指 Offer 22. 链表中倒数第 k 个节点

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;
        while (k > 0 && second != nullptr ) {
            second = second->next;
            k--;
        }
        while (second != nullptr) {
            first = first->next;
            second = second->next;
        }

        return first;
    }
};