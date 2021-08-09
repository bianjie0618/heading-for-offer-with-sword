//剑指 Offer 18. 删除链表的节点

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* vir = new ListNode(0);
        vir->next = head;
        ListNode* pre = vir;
        ListNode* cur = head;
        ListNode* next = nullptr;
        while ( cur != nullptr ) {
            next = cur->next;
            if ( cur->val == val ) {
                pre->next = next;
                break;
            }
            pre = cur;
            cur = next;
        }
        return vir->next;
    }
};