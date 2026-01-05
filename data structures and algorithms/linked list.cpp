#if 0
#include <iostream>
using namespace std;

struct Node // 定义链表节点
{
	Node(int data = 0) : data(data), next(nullptr) {} // 构造函数，初始化节点值和指针
	int data;										  // 节点值
	Node *next;										  // 指向下一个节点的指针
};
class ClinkedList
{
public:
	// 构造函数，初始化链表头节点
	ClinkedList()
	{
		head = new Node();
	}
	// 析构函数，释放链表头节点内存并将头指针置空
	~ClinkedList()
	{
		// 先检查是否有环，有环的话不析构以避免死循环
		int temp;
		if (IsLinkHasCircle(*this, temp))
		{
			head = nullptr; // 有环时只置空头指针，避免内存泄漏警告
			return;
		}

		Node *p = head;		 // 定义一个指针指向头节点
		while (p != nullptr) // 遍历链表
		{
			head = head->next; // 头指针指向下一个节点
			delete p;		   // 释放当前节点内存
			p = head;		   // 指针后移
		}
		head = nullptr; // 将头指针置空
	}
	// 插入函数，在链表末尾插入一个新节点
	// 参数 val: 要插入的节点的值
	/**
	 * 在链表末尾插入一个新节点
	 * @param val 要插入的节点的值
	 */
	void insertTail(int val)
	{ // 链表尾插入 O(n)
		Node *p = head;
		// 遍历链表直到找到最后一个节点
		while (p->next != nullptr)
		{
			p = p->next; // 指针后移
		}
		// 创建新节点并将其链接到链表末尾
		Node *node = new Node(val); // 创建新节点
		p->next = node;				// 将新节点链接到链表末尾
	}
	void insertHead(int val)
	{								// 链表头插入 O(1)
		Node *node = new Node(val); // 创建新 节点
		node->next = head->next;	// 新节点指向原头节点的下一个节点
		head->next = node;			// 头节点指向新节点
	}
	void Remove(int val)
	{
		Node *q = head;		  // 前驱节点
		Node *p = head->next; // 从头节点的下一个节点开始遍历
		while (p != nullptr)  // 遍历链表
		{
			if (p->data == val) // 找到要删除的节点
			{
				q->next = p->next; // 前驱节点指向要删除节点的下一个节点
				delete p;		   // 释放要删除节点的内存
				return;			   // 退出函数
			}
			else
			{
				q = p;		 // 前移 q->next=p->next;
				p = p->next; // 指针后移
			}
		}
	}
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
				// 继续删除下一个节点
				p = q->next;
			}
			else
			{
				q = p;
				p = p->next;
			}
		}
	}
	void reverseList()
	{
		Node *head = this->head;
		Node *p = head->next;
		while (p == nullptr)
		{
			return;
		}
		head->next = nullptr;
		while (p != nullptr)
		{
			Node *q = p->next;
			p->next = head->next;
			head->next = p;
			p = q;
		}
	}

	// 搜索 函数，查找链表中是否存在值为 val 的节点 O(n)
	bool find(int val)
	{
		Node *p = head->next; // 从头节点的下一个节点开始遍历
		while (p != nullptr)  // 遍历链表
		{
			if (p->data == val) // 找到节点
			{
				return true; // 返回 true
			}
			p = p->next; // 指针后移
		}
		return false; // 未找到节点，返回 false
	};

	// 打印链表中的所有节点值
	void show()
	{
		Node *p = head->next; // 从头节点的下一个节点开始遍历
		while (p != nullptr)
		{
			cout << p->data << " "; // 输出节点值
			p = p->next;			// 指针后移
		}
		cout << endl;
	}
	Node *getHead() const { return head; }
	void setHead(Node *newHead) { head = newHead; }

private:
	// 链表头节点指针
	Node *head;
	friend void mergeList(ClinkedList &list1, ClinkedList &list2);
	friend void mergeList1(ClinkedList &list1, ClinkedList &list2);
	friend void reverseList(ClinkedList &list);
	friend bool linkedList(ClinkedList &list, int k, int &val);
	friend bool IsLinkHasCircle(ClinkedList &list, int &val);
	friend bool IsLinkHasCircle(Node *head, int &val);
};
// 单链表逆序
void reverseList(ClinkedList &list)
{
	Node *head = list.head; // 获取链表头节点指针
	Node *p = head->next;	// 定义一个指针指向头节点的下一个节点
	while (p == nullptr)	// 遍历链表
	{
		return; // 链表为空，直接返回
	}
	head->next = nullptr; // 将头节点的下一个节点置空
	while (p != nullptr)  // 遍历链表
	{
		Node *q = p->next;	  // 定义一个指针指向当前节点的下一个节点
		p->next = head->next; // 将当前节点的下一个节点指向头节点的下一个节点
		head->next = p;		  // 将头节点的下一个节点指向当前节点

		p = q; // 指针后移
	}
}
// 查找链表中倒数第k个节点
bool linkedList(ClinkedList &list, int k, int &val)
{
	Node *head = list.head;
	Node *per = head;
	Node *p = head;

	if (k <= 0)
		return false;
	// 先移动p指针k步
	for (int i = 0; i < k; i++)
	{
		if (p == nullptr)
			return false;
		p = p->next;
	}

	// 同时移动per和p直到p到达末尾
	while (p != nullptr)
	{
		per = per->next;
		p = p->next;
	}

	val = per->data; // 将倒数第k个节点的值赋给val
	return true;	 // 返回true表示找到了倒数第k个节点
}
// 合并二个有序链表的单链表 从小到大
void mergeList(ClinkedList &list1, ClinkedList &list2)
{
	Node *p = list1.head->next;
	Node *q = list2.head->next;
	Node *last = list1.head;
	list2.head->next = nullptr;

	while (p != nullptr && q != nullptr)
	{
		if (p->data < q->data)
		{ // 修改比较条件：从 > 改为 <
			last->next = p;
			p = p->next;
			last = last->next;
		}
		else
		{
			last->next = q;
			q = q->next;
			last = last->next;
		}
	}
	if (p != nullptr)
	{
		last->next = p;
	}
	else
	{
		last->next = q;
	}
}
// 合并二个有序链表的单链表 从大到小
void mergeList1(ClinkedList &list1, ClinkedList &list2)
{
	// Node* p = list1.head->next;
	// Node* q = list2.head->next;
	// Node* last = list1.head;
	// list2.head->next = nullptr;

	// while (p != nullptr && q != nullptr)
	// {
	// 	if (p->data > q->data) {  // 修改比较条件：从 < 改为 >
	// 		last->next = p;
	// 		p = p->next;
	// 		last = last->next;
	// 	}
	// 	else
	// 	{
	// 		last->next = q;
	// 		q = q->next;
	// 		last = last->next;
	// 	}
	// }
	// if (p != nullptr) {
	// 	last->next = p;
	// }
	// else
	// {
	// 	last->next = q;
	// }
	Node *p = list1.head->next;
	Node *q = list2.head->next;

	list1.head->next = nullptr; // 断开头节点
	list2.head->next = nullptr; // 断开第二个链表

	while (p != nullptr && q != nullptr)
	{
		Node *temp;
		if (p->data > q->data)
		{ // 取较大的
			temp = p;
			p = p->next;
		}
		else
		{
			temp = q;
			q = q->next;
		}

		// 头插法：大的放在前面
		temp->next = list1.head->next;
		list1.head->next = temp;
	}

	// 处理剩余节点
	while (p != nullptr)
	{
		Node *temp = p;
		p = p->next;
		temp->next = list1.head->next;
		list1.head->next = temp;
	}

	while (q != nullptr)
	{
		Node *temp = q;
		q = q->next;
		temp->next = list1.head->next;
		list1.head->next = temp;
	}
}
// 单链表是否存在环,找出环的入口 (ClinkedList版本)
bool IsLinkHasCircle(ClinkedList &list, int &val)
{
	Node *fast = list.getHead(); // 快指针，使用getHead()访问私有成员
	Node *slow = list.getHead(); // 慢指针，使用getHead()访问私有成员

	while (fast != nullptr && fast->next != nullptr) // 快指针每次走两步，慢指针每次走一步，如果存在环，快指针会追上慢指针
	{
		slow = slow->next;		 // 慢指针走一步
		fast = fast->next->next; // 快指针走两步
		if (slow == fast)		 // 快慢指针相遇，说明存在环
		{
			slow = list.getHead(); // 将慢指针重新指向链表头节点
			while (slow != fast)
			{					   // 快慢指针同时走一步，直到相遇，相遇点即为环的入口
				slow = slow->next; // 慢指针走一步
				fast = fast->next; // 快指针走一步
			}
			val = slow->data; // 环的入口节点值赋值给val
			// 快慢指针再次遇见链表存在环
			return true; // 返回true表示存在环
		}
	}
	return false; // 返回false表示不存在环
}
#if 0

int main()
{
	ClinkedList list;
	Node *n1 = new Node(25);
	Node *n2 = new Node(67);
	Node *n3 = new Node(32);
	Node *n4 = new Node(18);
	list.getHead()->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n2; // 创建环

	int val;
	if (IsLinkHasCircle(list, val))
	{
		cout << "链表存在环，环的入口节点值为：" << val << endl;
	}
	else
	{
		cout << "链表不存在环" << endl;
	}

	return 0;
}
#endif // 0
// 单链表是否存在环,找出环的入口 (Node*版本，支持直接传入头节点)
bool IsLinkHasCircle(Node* head, int& val)
{
	Node* fast = head; //快指针
	Node* slow = head; //慢指针

	while (fast != nullptr && fast->next != nullptr) //快指针每次走两步，慢指针每次走一步，如果存在环，快指针会追上慢指针
	{
		slow = slow->next; //慢指针走一步
		fast = fast->next->next; //快指针走两步
		if (slow == fast) //快慢指针相遇，说明存在环
		{
			slow = head; //将慢指针重新指向链表头节点
			while (slow != fast) { //快慢指针同时走一步，直到相遇，相遇点即为环的入口
				slow = slow->next;  //慢指针走一步
				fast = fast->next;  //快指针走一步
			}
			val = slow->data; //环的入口节点值赋值给val
			//快慢指针再次遇见链表存在环
			return true;//返回true表示存在环
		}
	}
	return false;//返回false表示不存在环
}

int main() {
	Node head;
	Node n1(25), n2(67), n3(32), n4(18);
	head.next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n2;
	int val;
	if (IsLinkHasCircle(&head, val)) {
		cout << "链表存在环，环的入口节点值为：" << val << endl;
	}
	else {
		cout << "链表不存在环" << endl;
	}

	return 0;
}

#if 0
int main() {
	// 测试从小到大合并
	int arr[] = { 25,37,52,78,88,92,98,108 };
	int brr[] = { 12,23,40 ,56,62,77,109 };

	ClinkedList list;
	ClinkedList list2;

	for (int v : arr) {
		list.insertTail(v);
	}
	for (int v : brr) {
		list2.insertTail(v);
	}

	cout << "原始链表1: ";
	list.show();
	cout << "原始链表2: ";
	list2.show();

	// 从小到大合并
	mergeList(list, list2);
	cout << "从小到大合并后: ";
	list.show();

	// 重新创建数据测试从大到小合并
	int arr2[] = { 25,37,52,78,88,92,98,108 };
	int brr2[] = { 12,23,40 ,56,62,77,109 };

	ClinkedList list3;
	ClinkedList list4;

	for (int v : arr2) {
		list3.insertTail(v);
	}
	for (int v : brr2) {
		list4.insertTail(v);
	}

	// 从大到小合并
	mergeList1(list3, list4);
	cout << "从大到小合并后: ";
	list3.show();
}
#endif

#if 0
int main() {
	ClinkedList list;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++) {
		int val = rand() % 100;
		list.insertTail(val);
	}d

		cout << "原始链表：";
	list.show();

	reverseList(list);
	cout << "逆序后链表：";
	list.show();

	int kavl;
	int k = 3;
	if (linkedList(list, k, kavl)) {
		cout << "倒数第" << k << "个节点的值为" << kavl << endl;
	}
	else {
		cout << "链表长度不足" << k << "个节点" << endl;
	}

	return 0;
}
#endif

#if 0
int main() {
	ClinkedList list; //创建链表对象
	srand((unsigned)time(NULL)); //设置随机数种子
	for (int i = 0; i < 10; i++) {
		int val = rand() % 100; //生成0-99之间的随机数
		list.insert(val); //在链表末尾插入新节点
	}
	list.show(); //打印链表内容
	list.insert(50);
	list.show();

	list.Remove(50);
	list.show();
	list.insertHead(23);
	list.insertHead(23);
	list.insertHead(23);
	list.insert(23);
	list.show();
	list.RemoveAll(23);
	list.show();
	list.insert(100);
	cout << list.find(100) << endl;
	return 0;
}
#endif
#endif
