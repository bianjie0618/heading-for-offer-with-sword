// 剑指 Offer 52. 两个链表的第一个公共节点 - 解决方案

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 本质：长短不齐，最总走的进度会一致

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        while(l1 != l2) {
            l1 = l1 == nullptr ? headB : l1->next;
            l2 = l2 == nullptr ? headA : l2->next;
        }
        return l1;
    }
};