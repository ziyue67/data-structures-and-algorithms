// #include <iostream>
// using namespace std;

// // 单链表逆序

// struct ListNode
// {
// ListNode(int x) : val(x), next(nullptr) {}
// int val;
// ListNode *next;
// };
// class Solution
// {
// public:
// ListNode *reverseList(ListNode *head)
// {
// ListNode *prev = nullptr;
// ListNode *cur = head;
// while (cur != nullptr)
// {
// ListNode *next = cur->next;
// cur->next = prev;
// prev = cur;
// cur = next;
// }
// return prev;
// }
// }
//
// class Solution
// {
// public:
//     ListNode *reverseList(ListNode *head)
//     {
//         ListNode *prev = nullptr;
//         ListNode *cur = head;
//         while (cur != nullptr)
//         {
//             ListNode *next = cur->next;
//             cur->next = prev;
//             prev = cur;
//             cur = next;
//         }
//         return prev;
//     }
//     void printList(ListNode *head)
//     {
//         while (head != nullptr)
//         {
//             cout << head->val << " ";
//             head = head->next;
//         }
//         cout << endl;
//     }
// };

// int main()
// {
//     ListNode *head = new ListNode(1);
//     ListNode *node2 = new ListNode(2);
//     ListNode *node3 = new ListNode(3);
//     ListNode *node4 = new ListNode(4);
//     ListNode *node5 = new ListNode(5);
//     head->next = node2;
//     node2->next = node3;
//     node3->next = node4;
//     node4->next = node5;
//     Solution s;
//     s.printList(head);
//     s.printList(s.reverseList(head));
// }