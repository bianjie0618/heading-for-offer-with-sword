
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* currentPtr = head;
        while (l1 != nullptr && l2 != nullptr) {
            carry = l1->val + l2->val + carry;
            ListNode* newNode = new ListNode(carry % 10);
            currentPtr->next = newNode;
            currentPtr = currentPtr->next;
            carry /= 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != nullptr) {
            carry = l1->val + carry;
            ListNode* newNode = new ListNode(carry % 10);
            currentPtr->next = newNode;
            currentPtr = currentPtr->next;
            carry /= 10;
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            carry = l2->val + carry;
            ListNode* newNode = new ListNode(carry % 10);
            currentPtr->next = newNode;
            currentPtr = currentPtr->next;
            carry /= 10;
            l2 = l2->next;
        }

        if (carry != 0) {
            currentPtr->next = new ListNode(carry);
        }

        return head->next;
    }
};