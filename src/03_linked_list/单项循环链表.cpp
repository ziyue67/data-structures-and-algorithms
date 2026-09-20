#include <iostream>
using namespace std;
#if 0
struct Node
{
    Node(int d) : data(d), next(nullptr) {}
    int data;
    Node *next;
};

class SingleLinkedList
{
public:
    SingleLinkedList() : head(nullptr), tail(nullptr) {
        Node *node = new Node(0);
        head = node;
        tail = node;
    }
    ~SingleLinkedList() {
        Node *node = head;
        while (node != nullptr) {
            Node *next = node->next;
            delete node;        // 这条链走到最后就会删掉 tail
            node = next;
        }
        // 注意：不能再 delete tail，否则重复释放同一块内存
    }
    void insertTail(int data) {
        Node *node = new Node(data);
        tail->next = node;
        tail = node;
    }
    void inserHead(int val){
        Node *node = new Node(val);
        node->next =head->next;
        head->next=node;
    }
    void printList() {
        Node *node = head->next; // 跳过头结点
        while (node != nullptr) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }
    void Remove(int val){
        Node *node = head;
        Node *prev =head->next;
        while (prev != nullptr) {
            if(prev->data==val){
                node->next=prev->next;
                delete prev;
                if(node->next==nullptr){
                    tail=node;
                }
                return;
            }
            node = prev;
            prev = prev->next;
        }
    }
    void RemoveAll(int val)
    {
        Node *node = head;          // 前驱
        Node *prev = head->next;    // 当前
        while (prev != nullptr)
        {
            if (prev->data == val)
            {
                node->next = prev->next;
                delete prev;
                prev = node->next;  // 只前移"当前"，前驱不动
                                    // 所以这个分支不能再去执行 node = prev
            }
            else
            {
                node = prev;        // 没命中才两个指针一起前移
                prev = prev->next;
            }
        }
        tail = node;                // 循环结束时 node 正好停在最后一个节点
    }

    bool Find(int val){
        Node *node = head->next;
        while (node != nullptr) {
            if(node->data==val){
                return true;
            }
            node = node->next;
        }
        return false;
    }
private:
    Node* head;
    Node *tail;
};   
    
int main(){
    SingleLinkedList clinkedList;
    srand(time(nullptr));
    for (int i = 1; i <= 5; ++i) {
        clinkedList.insertTail(rand() % 100);
    }
    clinkedList.printList();
    clinkedList.inserHead(100);
    clinkedList.printList();
    clinkedList.insertTail(200);
    clinkedList.printList();
    clinkedList.Remove(100);
    clinkedList.printList();
    clinkedList.insertTail(200);
    clinkedList.insertTail(200);
    clinkedList.printList();
    clinkedList.RemoveAll(200);
    clinkedList.printList();
    clinkedList.insertTail(200);
    clinkedList.printList();
    clinkedList.Find(200) ? cout << "Found 200" << endl : cout << "Not Found 200" << endl;
    return 0;
}
#endif