#include <iostream>
using namespace std;
#if 0
struct Node
{
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
    int data;
    Node *next;
    Node *prev;
};
class Queuelinked{
private:
    Node *dummy; // 哨兵头节点
    Node *tail;  // 尾指针

public:
    Queuelinked()
    {
        dummy = new Node(0);
        tail = dummy;
    }
    ~Queuelinked(){
        Node *curr =dummy;
        while(curr){
            Node *temp= curr;
            curr =curr->next;
            delete temp;
        }
    }
    void push(int vale){
        Node *node =new Node(vale);
        tail->next = node;
        node->prev=tail;
        tail=node;
    }
    void pop(){
        Node *temp = dummy->next;
        dummy->next=temp->next;
        if(temp->next){
            temp->next->prev=dummy;
        }else{
            tail=dummy;
        }
        delete temp;
    }
    int front() const
    {
        if (empty())
        {
            throw "Queue is empty";
        }
        return dummy->next->data;
    }
    int back() const
    {
        if (empty())
        {
            throw "Queue is empty";
        }
        return tail->data;
    }

    bool empty() const
    {
        return dummy->next == nullptr;
    }
};
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Queuelinked q;
    for (int v : arr)
    {
        q.push(v);
    }
    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;
    q.push(12);
    q.push(13);
    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;
    while (!q.empty())
    {
        cout << q.front() << " " << q.back() << endl;
        q.pop();
    }
    cout << endl;
}

#endif
struct Node
{
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
    int data;
    Node *next;
    Node *prev;
};
class Queuelinked
{
private:
    Node *head;
    Node *tail;

public:
    Queuelinked()
    {
        head = new Node(0);
        tail = head;
    }
    ~Queuelinked()
    {
        Node *curr = head;
        while (curr)
        {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    void push(int value)
    {
        Node *node = new Node(value);
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    void pop()
    {
        if (empty())
        {
            throw "Queue is empty";
        }
        Node *curr = head->next;
        head->next = curr->next;
        if (curr->next)
        {
            curr->next->prev = head;
        }
        else
        {
            tail = head;
        }
        delete curr;
    }
    int front() const
    {
        if (empty())
        {
            throw "Queue is empty";
        }
        return head->next->data;
    }
    int back() const
    {
        if (empty())
        {
            throw "Queue is empty";
        }
        return tail->data;
    }
    bool empty() const
    {
        return head->next == nullptr;
    }
};
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Queuelinked q;
    for (int v : arr)
    {
        q.push(v);
    }
    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;
    q.push(12);
    q.push(13);
    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;
    while (!q.empty())
    {
        cout << q.front() << " " << q.back() << endl;
        q.pop();
    }
    cout << endl;
}