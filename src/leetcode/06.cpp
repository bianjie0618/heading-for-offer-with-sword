#include <vector>
#include <iostream>
#include <stack>
using namespace std;

// 剑指 Offer 06. 从尾到头打印链表

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};



// 解法一：链表反转
class Solution {
public:
    // 链表反转
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        if (head == nullptr) {
            return result;
        }
        head = reverseLinkedList(head);
        while(head != nullptr) {
            result.push_back(head->val);
            head = head->next;
        }
        return result;
    }

    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        // 链表通常考虑当前节点
        while(cur != nullptr) {
            next = cur->next;

            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

// 解法二：栈的使用——先进后出
// 这种解法的空间复杂度是 O(n)，而链表的空间复杂度是O(1)
class Solution1 {
public:
    // 链表反转
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        if (head == nullptr) {
            return result;
        }

        stack<int> stack;
        while(head != nullptr) {
            stack.push(head->val);
            head = head->next;
        }

        while( !stack.empty() ) {
            result.push_back(stack.top());
            stack.pop();
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);

    Solution1 solution;
    vector<int> final_result = solution.reversePrint(head);
    for(int ele : final_result) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}