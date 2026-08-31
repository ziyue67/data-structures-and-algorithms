#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node
{
    Node(int data = 0) : data(data), next(nullptr) {}
    int data;
    Node *next;
};

class SingleLinkedList
{
public:
    SingleLinkedList()
    {
        head = new Node();
    }
    ~SingleLinkedList()
    {
        Node *p = head;
        while (p != nullptr)
        {
            Node *q = p->next;
            delete p;
            p = q;
        }
        head = nullptr;
    }
    void insertTail(int data)
    {
        Node *node = new Node(data);
        Node *p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = node;
    }
    void insertHead(int data)
    {
        Node *node = new Node(data);
        node->next = head->next;
        head->next = node;
    }
    void erase(int value)
    {
        Node *q = head;
        Node *p = head->next;
        while (p != nullptr)
        {
            if (p->data == value)
            {
                q->next = p->next;
                delete p;
                return;
            }
            q = p;
            p = p->next;
        }
    }
    void removeAll(int value)
    {
        Node *q = head;
        Node *p = head->next;
        while (p != nullptr)
        {
            if (p->data == value)
            {
                q->next = p->next;
                delete p;
                p = q->next;
            }
            else
            {
                q = p;
                p = p->next;
            }
        }
    }
    bool find(int value)
    {
        Node *p = head->next;
        while (p != nullptr)
        {
            if (p->data == value)
            {
                cout << "find " << value << endl;
                return true;
            }
            p = p->next;
        }
        cout << "not find " << value << endl;
        return false;
    }
    void show()
    {
        Node *p = head->next;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    // 判断 value 是否存在：存在返回 true，不存在返回 false
    bool exists(int value)
    {
        Node *p = head->next;
        while (p != nullptr)
        {
            if (p->data == value)
            {
                cout << "exists " << value << endl;
                return true;
            }
            p = p->next;
        }
        cout << "not exists " << value << endl;
        return false;
    }
    bool isEmpty()
    {
        return head->next == nullptr;
    }

private:
    Node *head;
};

int main()
{
    srand(time(0));
    SingleLinkedList list;
    for (int i = 0; i < 10; i++)
    {
        list.insertTail(rand() % 100);
    }
    list.show();
    list.insertHead(100);
    list.show();
    list.erase(100);
    list.show();
    list.insertTail(200);
    list.insertTail(200);
    list.show();
    list.removeAll(200);
    list.show();
    list.insertTail(300);
    list.show();
    list.find(300);
    list.exists(300);
    list.exists(9999);
    cout << "isEmpty: " << list.isEmpty() << endl;

    return 0;
}
