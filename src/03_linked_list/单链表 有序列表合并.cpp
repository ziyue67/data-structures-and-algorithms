#include <iostream>
using namespace std;
 
#if 0;
struct ListNode
{
    ListNode(int x) : val(x), next(nullptr) {}
    int val;
    ListNode *next;
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode dummy(0);
    ListNode *cur = &dummy;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next; // cur=cur->next;cur指向下一个节点
    }
    cur->next = l1 ? l1 : l2; // 如果l1不为空，则cur->next指向l1，否则指向l2
    return dummy.next;        // 返回合并后的链表的头节点
}
int main()
{
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);

    // 链表2: 2 -> 4 -> 6
    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);

    ListNode *merged = mergeTwoLists(l1, l2); // 合并两个有序链表
    while (merged){
        cout << merged->val << " "; // 输出合并后的链表
        merged = merged->next;

    }
    cout << endl;
    return 0;
}
#endif

// struct ListNode
// {
//     ListNode(int x) : val(x), next(nullptr) {}
//     int val;
//     ListNode *next;
// };
// ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
//     ListNode dummy(0);
//     ListNode *cur = &dummy;
//     while(l1 && l2){
//         if(l1->val  <l2->val){
//             cur->next =l1;
//             l1=l1->next;
//         }else{
//             cur->next=l2;
//             l2=l2->next;
//         }
//         cur=cur->next;
//     }
//     cur->next=l1?l1:l2;
//     return dummy.next;
// }