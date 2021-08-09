// 剑指 Offer 25. 合并两个排序的链表
#include <iostream>
using namespace std;
// struct ListNode
// {
//     int val;
//     ListNode* next;
//     ListNode(int x): val(x), next(nullptr) {}
// };


// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         ListNode* fakeHead = new ListNode(0);
//         ListNode* movingPtr = fakeHead;
//         while (l1 != nullptr && l2 != nullptr) {
//             if (l1->val < l2->val) {
//                 movingPtr->next = l1;
//                 l1 = l1->next;
//             }
//             else {
//                 movingPtr->next = l2;
//                 l2 = l2->next;
//             }
//             movingPtr = movingPtr->next;
//         }
//         while (l1 != nullptr) {
//             movingPtr->next = l1;
//             l1 = l1->next;
//             movingPtr = movingPtr->next;
//         }
//         while (l2 != nullptr) {
//             movingPtr->next = l2;
//             l2 = l2->next;
//             movingPtr = movingPtr->next;
//         }

//         return fakeHead->next;
//     }
// };

int main(int argc, char* argv[]) {
    cout << "相等？ " << (nullptr == nullptr) << endl;
    return 0;
}