// #include <iostream>
// using namespace std;

// struct Node
// {
//     Node(int data = 0) : data(data), next(nullptr) {}
//     int data;
//     Node *next;
// };
// /**
//  * @brief 循环链表类
//  *
//  * 这个类实现了一个基本的循环链表结构，包含插入、删除和显示等基本操作。
//  */
// class ClinkedList
// {
// public:
//     /**
//      * @brief 构造函数
//      *
//      * 初始化链表，创建头节点
//      */
//     ClinkedList()
//     {
//         head = new Node();
//     }
//     /**
//      * @brief 析构函数
//      *
//      * 释放链表内存，将头节点指针置为nullptr
//      */
//     ~ClinkedList()
//     {
//         Node *p = head;
//         while (p != nullptr)
//         {
//             head = head->next;
//             delete p;
//             p = head;
//         }
//         head = nullptr;
//     }
//     /**
//      * @brief 在链表尾部插入节点
//      *
//      * @param val 要插入的节点的值
//      */
//     void insert(int val)
//     {
//         Node *p = head;
//         while (p->next != nullptr) // 遍历到链表末尾
//         {
//             p = p->next;
//         }
//         Node *node = new Node(val); // 创建新节点
//         p->next = node;             // 将新节点连接到链表末尾
//     }
//     /**
//      * @brief 在链表头部插入节点
//      *
//      * @param val 要插入的节点的值
//      */
//     void insterHead(int val)
//     {
//         Node *node = new Node(val); // 创建新节点
//         node->next = head->next;    // 新节点指向原头节点
//         head->next = node;          // 头节点指向新节点
//     }
//     /**
//      * @brief 删除链表中值为val的节点
//      *
//      * @param val 要删除的节点的值
//      */
//     /**
//      * 从链表中移除指定值的节点
//      * @param val 要移除的节点的值
//      */
//     void Remove(int val)
//     {
//         // 初始化指针q和p，q指向头节点，p指向头节点的下一个节点
//         Node *q = head;
//         Node *p = head->next;
//         // 遍历链表，直到p为空（即到达链表末尾）
//         while (p != nullptr)
//         {
//             // 如果找到值匹配的节点
//             if (p->data == val)
//             {
//                 // 将前一个节点的next指向当前节点的下一个节点，跳过当前节点
//                 q->next = p->next;
//                 // 删除当前节点，释放内存
//                 delete p;
//                 // 找到并删除节点后直接返回
//                 return;
//             }
//             else
//             {

//                 // 如果未找到匹配节点，向前移动指针
//                 q = p;       // q移动到p的位置
//                 p = p->next; // p移动到下一个节点
//             }
//         }
//     }
//     void RemoveAll(int val)
//     {
//         Node *q = head;
//         Node *p = head->next;
//         while (p != nullptr)
//         {
//             if (p->data == val)
//             {
//                 q->next = p->next;
//                 delete p;
//                 p = q->next; // 更新p以继续遍历
//             }
//             else
//             {
//                 q = p;
//                 p = p->next;
//             }
//         }
//     }
//     bool find(int val)
//     {
//         Node *p = head->next;
//         while (p != nullptr)
//         {
//             if (p->data == val)
//             {
//                 return true;
//             }
//             p = p->next;
//         }
//         return false;
//     }
//     /**
//      * @brief 显示链表中的所有元素
//      *
//      * 遍历链表并打印每个节点的值
//      */
//     void show()
//     {
//         Node *p = head->next;
//         while (p != nullptr)
//         {
//             cout << p->data << " "; // 打印当前节点值
//             p = p->next;            // 移动到下一个节点
//         }
//         cout << endl;
//     }

// private:
//     Node *head; // 链表头节点指针
// };

// int main()
// {
//     ClinkedList cl;
//     srand((unsigned)time(NULL));
//     for (int i = 0; i < 10; i++)
//     {
//         int val = rand() % 100;
//         cl.insert(val);
//     }
//     cl.show();
//     cl.insert(100);
//     cl.show();
//     cl.Remove(100);
//     cl.show();
//     cl.insterHead(50);
//     cl.insterHead(50);
//     cl.insterHead(50);
//     cl.insterHead(50);
//     cl.show();
//     cl.RemoveAll(50);
//     cl.show();
//     cl.insert(25);
//     cl.show();
//     cl.find(25) ? cout << "Found 25" << endl : cout << "25 Not Found" << endl;

//     return 0;
// }
#if 0
#include <iostream>
using namespace std;
struct Node
{
    Node(int data = 0) : data(data), next(nullptr) {}
    int data;
    Node *next;
};
/**
 * @brief ClinkedList 类，表示一个循环链表
 *
 * 这个类实现了一个基本的循环链表数据结构，包含构造函数和析构函数
 */
class ClinkedList
{
public:
    ClinkedList()
    {
        head = new Node();
    }
    ~ClinkedList()
    {
        Node *p = head;
        while (p != nullptr)
        {
            head = head->next;
            delete p;
            p = head;
        }
        head = nullptr;
    }
    void insertTail(int val)
    {
        Node *p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        Node *node = new Node(val);
        p->next = node;
    }
    void insertHead(int val)
    {
        Node *node = new Node(val);
        node->next = head->next;
        head->next = node;
    };
    void Remove(int val)
    {
        Node *q = head;
        Node *p = head->next;
    };
    void RemoveAll(int val)
    {
        Node *q = head;
        Node *p = head->next;
        while (p != nullptr)
        {
            if (p->data == val)
            {
                q->next = p->next;
                delete p;
                p = q->next; // 更新p以继续遍历
            }
            else
            {
                q = p;
                p = p->next;
            }
            }
        }
        void find(int val){
            Node *p = head->next;
            while (p != nullptr){
                if (p->data == val){
                    cout << "Found " << val << endl;
                    return;
                }
                p = p->next;
            }
            cout << val << " Not Found" << endl;
        }

    private:
        Node *head; // 链表头节点指针
    };
#endif

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int data = 0) : data(data), next(nullptr) {}
};

class ClinkedList
{
public:
    ClinkedList()
    {
        head = new Node();
    }
    ~ClinkedList()
    {
        Node *p = head;
        while (p != nullptr)
        {
            head = p->next;
            delete p;
            p = head;
        }
        head = nullptr;
    }
    void insertTail(int val)
    {
        Node *p = head;
        while (p->next!= nullptr)
        {
            p = p->next;
        }
        Node *node = new Node(val);
        p->next = node;
    }
    void insertHead(int val)
    {
        Node *node = new Node(val);
        node->next = head->next;
        head->next = node;
    }
    void Remove(int val)
    {
        Node *p = head;
        Node *q = head->next;
        while (p != nullptr)
        {
            if (q->data == val)
            {
                p->next = q->next;
                delete q;
                return;
            }
            p = q;
            q = q->next;
        }
    }
    void RemoveAll(int val)
    {
        Node *p = head;
        Node *q = head->next;
        while (p != nullptr)
        {
            if (q->data == val)
            {
                p->next = q->next;
                delete q;
                q = p->next;
            }
            else
            {
                p = q;
                q = p->next;
            }
        }
    }
    void find(int val)
    {
        Node *p = head->next;
        while (p != nullptr)
        {
            if (p->data == val)
            {
                cout << "Found " << val << endl;
                return;
            }
            p = p->next;
        }
        cout << val << " Not Found" << endl;
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

    friend void verserList(ClinkedList &list);

private:
    Node *head;
};
void verserList(ClinkedList &list)
{
    Node *head=list.head;
    Node *p=head->next;
    if(p==nullptr)
    {
        return;
    }
    head->next=nullptr;
    while (p!=nullptr)
    {
        Node *q=p->next;
        p->next=head->next;
        head->next=p;
        p=q;
    }

    
}

int main()
{
    ClinkedList cl;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        cl.insertTail(rand() % 100);
    }
    cl.show();
    verserList(cl);
    cl.show();
    return 0;
}