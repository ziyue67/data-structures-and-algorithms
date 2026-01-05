#include <iostream>
using namespace std;

class CircleList
{
public:
    CircleList()
    {
        head = new Node();
        tail = head;
        head->next = tail;
    }
    ~CircleList()
    {
        Node *dummy = head;
        while (dummy != head)
        {
            Node *temp = dummy;
            dummy = dummy->next;
            delete temp;
        }
        delete head;
    }
    void InertTail(int val)
    {
        Node *node = new Node(val);
        node->next = head;
        tail->next = node;
        tail = node;
    }
    void InsertHead(int val)
    {
        Node *node = new Node(val);
        node->next = head->next;
        head->next = node;
        if (tail == head)
        {
            tail = node;
        }
    }
    void Rmove(int val)
    {
        Node *prev = head;
        Node *curr = head->next;
        while (curr != head)
        {
            if (curr->data == val)
            {
                prev->next = curr->next;
                if (tail == curr)
                {
                    curr = prev;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    void RemoveAll(int val)
    {
        Node *prev = head;
        Node *curr = head->next;
        while (curr != head)
        {
            if (curr->data == val)
            {
                prev->next = curr->next;
                Node *temp = curr;
                curr = curr->next;
                if (tail == curr)
                {
                    tail = prev;
                }
                delete temp;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    bool Find(int val)
    {
        Node *curr = head->next;
        while (curr != head)
        {
            if (curr->data == val)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
    void show()
    {
        Node *curr = head->next;
        while (curr != head)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    void Reverse()
    {
        if (head == nullptr || head->next == head)
        {
            return;
        }
        Node *prev = head;
        Node *curr = head->next;
        Node *next = nullptr;
        while (curr != head)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = prev;
        tail = head->next;
    }
    bool LinkList(int k, int &val)
    {
        if (k <= 0)
            return false;

        Node *prev = head;
        Node *curr = head;
        for (int i = 0; i < k; i++)
        {
            if (curr == head)
                return false;
            curr = curr->next;
        }
        while (curr != head)
        {
            prev = prev->next;
            curr = curr->next;
        }
        val = prev->data;
        return true;
    }
    void mergeList(CircleList &list1, CircleList &list2)
    {
        // 获取 list1 的头节点和尾节点
        Node *list1Head = list1.head->next;
        Node *list1Tail = list1.tail;

        // 获取 list2 的头节点和尾节点
        Node *list2Head = list2.head->next;
        Node *list2Tail = list2.tail;

        // 如果 list1 不为空，将其插入到当前链表的尾部
        if (list1Head != list1.head)
        {
            tail->next = list1Head;
            list1Tail->next = head;
            tail = list1Tail;
        }

        // 如果 list2 不为空，将其插入到当前链表的尾部
        if (list2Head != list2.head)
        {
            tail->next = list2Head;
            list2Tail->next = head;
            tail = list2Tail;
        }
    }

private:
    struct Node
    {
        Node(int data = 0) : data(data), next(nullptr) {}
        int data;
        Node *next;
    };
    Node *head;
    Node *tail;
};
#if 0
int main()
{
    CircleList list;

    // 插入一些元素到循环链表
    list.InertTail(10);
    list.InertTail(20);
    list.InertTail(30);
    list.InertTail(40);

    cout << "原始链表: ";
    list.show(); // 输出：10 20 30 40

    int k = 2;
    int val;
    if (list.LinkList(k, val))
    {
        cout << "链表中倒数第 " << k << " 个元素是: " << val << endl;
    }
    else
    {
        cout << "无法找到倒数第 " << k << " 个元素。" << endl;
    }

    return 0;
}
#endif
#if 0
int main()
{
    CircleList list;

    // 插入一些元素到循环链表
    list.InertTail(1);
    list.InertTail(2);
    list.InertTail(3);
    list.InertTail(4);

    cout << "原始链表: ";
    list.show(); // 输出：1 2 3 4

    // 反转链表
    list.Reverse();

    cout << "反转后的链表: ";
    list.show(); // 输出：4 3 2 1

    return 0;
}
#endif
#if 0
int main()
{
    CircleList list1, list2, mergedList;

    list1.InertTail(1);
    list1.InertTail(2);
    list1.InertTail(3);

    list2.InertTail(4);
    list2.InertTail(5);
    list2.InertTail(6);

    mergedList.mergeList(list1, list2);
    mergedList.show(); // 输出：1 2 3 4 5 6

    return 0;
}
#endif