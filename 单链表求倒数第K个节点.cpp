#include <iostream>
using namespace std;
#if 0
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution
{
public:
    // ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    // {
    //     if (pListHead == nullptr || k == 0)
    //     {
    //         return nullptr;
    //     }
    //     ListNode *p1 = pListHead;
    //     ListNode *p2 = pListHead;
    //     for (int i = 0; i < k - 1; i++)
    //     {
    //         if (p1->next !=nullptr)
    //         {
    //             p1 = p1->next;
    //         }
    //         else
    //         {
    //             return nullptr;
    //         }
    //     }
    //     while(p1->next!=nullptr){
    //         p1=p1->next;
    //         p2=p2->next;
    //     }
    //     return p2;
    // }
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        if (pListHead == nullptr || k == 0)
            return nullptr;
        ListNode *p1 = pListHead;
        ListNode *p2 = pListHead;
        for (unsigned int i = 0; i < k; ++i)
        {
            if (p2 == nullptr)
                return nullptr;
            p2 = p2->next;
        }
        while (p2 != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode *p = s.FindKthToTail(head, 1);
    cout << p->val << endl;
    p = s.FindKthToTail(head, 2);
    cout << p->val << endl;
    p = s.FindKthToTail(head, 3);
    cout << p->val << endl;
    p = s.FindKthToTail(head, 4);
    cout << p->val << endl;
    p = s.FindKthToTail(head, 5);
    cout << p->val << endl;
    return 0;
}
#endif



struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
