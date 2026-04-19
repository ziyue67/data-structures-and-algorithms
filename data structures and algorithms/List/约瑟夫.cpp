#include <iostream>
using namespace std;

class CircleList
{
public:
    struct Node
    {
        int data;
        Node *next;
        Node(int data = 0) : data(data), next(nullptr) {}
    };
    Node *head;
    Node *tail;

public:
    CircleList(int n)
    {
        head = new Node(1);
        tail = head;
        for (int i = 2; i <= n; i++)
        {
            tail->next = new Node(i);
            tail = tail->next;
        }
        tail->next = head;
    }
    ~CircleList()
    {
        Node *p = head;
        while (p != tail)
        {
            Node *q = p;
            p = p->next;
            delete q;
        }
        delete tail;
    }
    // 从头节点开始，删除第m个节点
    // k从第k个节点开始计数
    // m 每次报m个时 出列
    void josephus(int m, int k)
    {
        if (head == nullptr) return;
        Node *perv = tail;
        Node *curr = head;

        for (int i = 1; i < k; i++) {
            perv = curr;
            curr = curr->next;
        }

        while (curr->next != curr) {
            for (int i = 1; i < m; i++) {
                perv = curr;
                curr = curr->next;
            }
            perv->next = curr->next;
            if (curr == tail) tail = perv;
            cout << curr->data << " ";
            delete curr;
            curr = perv->next;
        }
        cout << curr->data << endl;
        delete curr;
    }

     
    void print()
    {
        Node *p = head;
        while (p != tail)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << tail->data << endl;
    }

};

int main()
{
    CircleList cl(8); // 1 2 3 4 5 6 7 8
    cl.josephus(5, 1);  
    return 0;
}
