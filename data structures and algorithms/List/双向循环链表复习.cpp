#include <iostream>
using namespace std;

struct Node
{
    Node(int data = 0) : data(data), next(nullptr), prev(nullptr) {}
    int data;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
public:
    DoubleLinkedList()
    {
        head = new Node();
        head->next = head;
        head->prev = head;
    }
    ~DoubleLinkedList()
    {
        Node *curr = head->next;
        while (curr != head)
        {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete head;
    }
    void insertHead(int val)
    {
        Node *curr = new Node(val);
        curr->next = head->next;
        curr->prev = head;
        head->next->prev = curr;
        head->next = curr;
    }
    void insertTail(int val)
    {
        Node *node = new Node(val);
        Node *curr = head->prev;
        curr->next = node;
        node->prev = curr;
        node->next = head;
        head->prev = node;
    };
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
            curr = curr->next;
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
    void print()
    {
        Node *curr = head->next;
        while (curr != head)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    bool empty()
    {
        return head->next == head;
    }
    bool find(int val)
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
    Node *head;
};

int main()
{
    DoubleLinkedList dlink;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        dlink.insertHead(rand() % 100);
    }
    dlink.print();
    dlink.insertHead(200);
    dlink.print();
    dlink.insertTail(300);
    dlink.insertTail(300);
    dlink.print();
    dlink.Remove(200);
    dlink.print();
    dlink.RemoveAll(300);
    dlink.print();
}