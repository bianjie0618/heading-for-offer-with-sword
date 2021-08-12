// 23. 合并K个升序链表

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <vector>
using namespace std;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return recursion(lists, 0, lists.size() - 1);
    }

private:

    ListNode* recursion( vector<ListNode*>& lists, int left, int right ) {
        if (left > right) {
            return nullptr;
        }
        if (left == right) {
            return lists[left];
        }
        int mid = left + (right - left) / 2;
        ListNode* l1 =  recursion(lists, left, mid);
        ListNode* l2 = recursion(lists, mid + 1, right);
        return mergeTwoLists(l1, l2);;
        
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        // 在创建 head 时 栽了跟头，这是需要创建一个新的节点，保证 &head 不是 nullptr
        ListNode head;
        ListNode* curPtr = &head;
        while ( l1 != nullptr && l2 != nullptr ) {
            if ( l1->val < l2->val ) {
                curPtr->next = l1;
                l1 = l1->next;
            }
            else {
                curPtr->next = l2;
                l2 = l2->next;
            }
            curPtr = curPtr->next;
        }
        if (l1 != nullptr ) {
            curPtr->next = l1;
        }
        else {
            curPtr->next = l2;
        }
        return head.next;
    }
};