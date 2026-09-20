#include <iostream>
using namespace std;

// struct Node
// {
//     Node(int val) : data(val), next(nullptr), prev(nullptr) {}
//     int data;
//     Node *next;
//     Node *prev;
// };
// class DoublyLinkedList
// {
// public:
//     DoublyLinkedList()
//     {
//         head = new Node(0);
//         tail = head;
//     }
//     ~DoublyLinkedList()
//     {
//         Node *curr = head;
//         while (curr)
//         {
//             Node *temp = curr;
//             curr = curr->next;
//             delete temp;
//         }
//     }
//     void insertTail(int val)
//     {
//         Node *curr = new Node(val);
//         tail->next = curr;
//         curr->prev = tail;
//         tail = curr;
//     }
//     void insertHead(int val)
//     {
//         Node *curr = new Node(val);
//         curr->prev = head;
//         curr->next = head->next;
//         if (head->next)
//         {
//             head->next->prev = curr;
//         }
//         head->next = curr;
//         if (tail == head)
//         {
//             tail = curr;
//         }
//     }
//     void Reverse(int value)
//     {
//         Node *curr = head->next;
//         while (curr)
//         {
//             if (curr->data == value)
//             {
//                 if (curr == tail)
//                     tail = curr->prev;
//                 curr->prev->next = curr->next;
//                 if (curr->next)
//                     curr->next->prev = curr->prev;
//                 delete curr;
//                 return;
//             }
//             curr = curr->next;
//         }
//     }
//     void Reverseall(int value)
//     {
//         Node *curr = head->next;
//         while (curr)
//         {
//             if (curr->data == value)
//             {
//                 Node *temp = curr->next;
//                 curr->prev->next = curr->next;
//                 if (curr->next)
//                 {
//                     curr->next->prev = curr->prev;
//                 }
//                 if (curr == tail)
//                 {
//                     tail = curr->prev;
//                 }
//                 delete curr;
//                 curr = temp;
//             }
//             else
//             {
//                 curr = curr->next;
//             }
//         }
//     }
//     void printList()
//     {
//         Node *curr = head->next;
//         while (curr)
//         {
//             cout << curr->data << " ";
//             curr = curr->next;
//         }
//         cout << endl;
//     }

// private:
//     Node *head;
//     Node *tail;
// };
// int main()
// {
//     DoublyLinkedList list;
//     for (int i = 0; i < 10; i++)
//     {
//         list.insertTail(i);
//     }
//     list.printList();
//     for (int i = 10; i < 20; i++)
//     {
//         list.insertHead(i);
//     }
//     list.printList();
//     list.insertTail(15);
//     list.printList();
//     list.Reverseall(15);
//     list.printList();
//     list.Reverse(5);
//     list.printList();
//     return 0;
// }

struct Node
{
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    int data;
    Node *next;
    Node *prev;
};

class DoublyLinkedList
{
public:
    DoublyLinkedList()
    {
        head->next = head;
        head->prev = head;
    }
    ~DoublyLinkedList()
    {
        Node *curr = head->next;
        while (curr != head)
        {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete head;
        head = nullptr;
    }
    void insertTail(int val)
    {
        Node *curr = new Node(val);
        curr->prev = head->prev;
        curr->next = head;
        head->prev->next = curr;
        head->prev = curr;
    }
    void insertHead(int val)
    {
        Node *curr = new Node(val);
        curr->next = head->next;
        head->next->prev = curr;
        head->next = curr;
        curr->prev = head;
    }

private:
    Node *head;
    Node *tail;
};