#include <iostream>
using namespace std;

struct Node
{
    Node(int data = 0)
        : data(data), next(nullptr), prev(nullptr)
    {
    }
    int data;
    Node *next; // 后继指针
    Node *prev; // 前驱指针
};

class DoublyCircularLinkedList
{
public:
    DoublyCircularLinkedList()
    {
        head = new Node();
        head->next = head;
        head->prev = head;
    }
    ~DoublyCircularLinkedList()
    {
        Node *curr = head->next;
        while (curr != head)
        {
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
        delete head;
    }
    void InsertHead(int val)
    {
        Node *node = new Node(val);
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void InsertTail(int val)
    {
        Node *node = new Node(val);
        Node *curr = head->prev;
        curr->next = node;
        node->prev = curr;
        node->next = head;
        head->prev = node;
    }
    void Remove(int val)
    {
        Node *curr = head->next;
        while (curr != head)
        {
            if (curr->data == val)
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
                return;
            }
            else
            {
                curr = curr->next;
            }
        }
    }
    void RemoveAll(int val)
    {
        Node *curr = head->next;
        while (curr != head)
        {
            if (curr->data == val)
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                Node *temp = curr;
                curr = curr->next;
                delete temp;
            }
            else
            {
                curr = curr->next;
            }
        }
    }
    void Print()
    {
        Node *curr = head->next;
        while (curr != head)
        {

            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    bool IsEmpty()
    {
        return head->next == head;
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

private:
    Node *head; // 头节点
    Node *tail; // 尾节点
    Node *curr; // 当前节点
};

int main()
{
    DoublyCircularLinkedList dlink;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        dlink.InsertHead(rand() % 100);
    }
    dlink.Print();
    dlink.InsertHead(200);
    dlink.Print();
    dlink.InsertTail(300);
    dlink.InsertTail(300);
    dlink.Print();
    dlink.Remove(200);
    dlink.Print();
    dlink.RemoveAll(300);
    dlink.Print();
    // cout << dlink.Find(200) << endl;
    // cout << dlink.Find(300) << endl;

    return 0;
}