// #include <iostream>
// using namespace std;

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
//         Node *curr = head;
//         while (curr->next != nullptr)
//         {
//             curr = curr->next;
//         }
//         Node *node = new Node(val);
//         node->prev = curr;
//         curr->next = node;
//     }
//     void insertHead(int val)
//     {
//         Node *curr = new Node(val);
//         curr->next = head->next;
//         curr->prev = head;
//         if (head->next)
//         {
//             head->next->prev = curr;
//         }
//         head->next = curr;
//     }
//     void Reverse(int value)
//     {
//         Node *curr = head->next;
//         while (curr)
//         {
//             if (curr->data == value)
//             {
//                 curr->prev->next = curr->next;
//                 if (curr->next)
//                 {
//                     curr->next->prev = curr->prev;
//                 }
//                 delete curr;
//                 return;
//             }
//             else
//             {
//                 curr = curr->next;
//             }
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
//                 delete curr;
//                 curr = temp;
//             }
//             else
//             {
//                 curr = curr->next;
//             }
//         }
//     }
//     bool Find(int value)
//     {
//         Node *curr = head->next;
//         while (curr)
//         {
//             if (curr->data == value)
//             {
//                 return true;
//             }
//             curr = curr->next;
//         }
//         return false;
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