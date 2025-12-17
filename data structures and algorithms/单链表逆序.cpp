#include <iostream>
using namespace std;


struct Node //定义链表节点
{
	Node(int data = 0) :data(data), next(nullptr) {} //构造函数，初始化节点值和指针
	int data; //节点值
	Node* next; //指向下一个节点的指针
};
class ClinkedList {
public:
	// 构造函数，初始化链表头节点
	ClinkedList() {
		head = new Node();
	}
	// 析构函数，释放链表头节点内存并将头指针置空
	~ClinkedList()
	{
		Node* p = head; //定义一个指针指向头节点
		while (p != nullptr) //遍历链表
		{
			head = head->next; //头指针指向下一个节点
			delete p; //释放当前节点内存
			p = head; //指针后移

		}
		head = nullptr; //将头指针置空
	}
	// 插入函数，在链表末尾插入一个新节点
	// 参数 val: 要插入的节点的值
/**
 * 在链表末尾插入一个新节点
 * @param val 要插入的节点的值
 */
	void insertTail(int val) { //链表尾插入 O(n)
		Node* p = head;
		// 遍历链表直到找到最后一个节点
		while (p->next != nullptr)
		{
			p = p->next; //指针后移
		}
		// 创建新节点并将其链接到链表末尾
		Node* node = new Node(val); //创建新节点
		p->next = node; //将新节点链接到链表末尾
	}
	void insertHead(int val) { //链表头插入 O(1)
		Node* node = new Node(val); //创建新 节点
		node->next = head->next; //新节点指向原头节点的下一个节点
		head->next = node; //头节点指向新节点





	}
	void Remove(int val)
	{
		Node* q = head;//前驱节点
		Node* p = head->next; //从头节点的下一个节点开始遍历
		while (p != nullptr) //遍历链表
		{
			if (p->data == val) //找到要删除的节点
			{
				q->next = p->next; //前驱节点指向要删除节点的下一个节点
				delete p; //释放要删除节点的内存
				return; //退出函数
			}
			else
			{
				q = p; //前移 q->next=p->next;
				p = p->next; //指针后移
			}
		}

	}
	void RemoveAll(int val)
	{
		Node* q = head;
		Node* p = head->next;
		while (p != nullptr)
		{
			if (p->data == val) {
				q->next = p->next;
				delete p;
				//继续删除下一个节点
				p = q->next;
			}
			else
			{
				q = p;
				p = p->next;
			}
		}
	}
	void VeverseList() {
		Node* head = this->head;
		Node* p = head->next;
		while (p == nullptr)
		{
			return;
		}
		head->next = nullptr;
		while (p != nullptr)
		{
			Node* q = p->next;
			p->next = head->next;
			head->next = p;
			p = q;
		}
	}

	//搜索 函数，查找链表中是否存在值为 val 的节点 O(n)
	bool  find(int val) {
		Node* p = head->next; //从头节点的下一个节点开始遍历
		while (p != nullptr) //遍历链表
		{
			if (p->data == val) //找到节点
			{
				return true; //返回 true
			}
			p = p->next; //指针后移
		}
		return false; //未找到节点，返回 false
	};



	// 打印链表中的所有节点值
	void show()
	{
		Node* p = head->next; //从头节点的下一个节点开始遍历
		while (p != nullptr)
		{
			cout << p->data << " "; //输出节点值
			p = p->next; //指针后移
		}
		cout << endl;
	}
private:
	// 链表头节点指针
	Node* head;
	friend	void reverseList(ClinkedList& list);
	friend bool linkedList(ClinkedList& list, int k, int& val);
};
void reverseList(ClinkedList& list) {
	Node* head = list.head; //获取链表头节点指针
	Node* p = head->next; //定义一个指针指向头节点的下一个节点
	while (p == nullptr) //遍历链表
	{
		return; //链表为空，直接返回
	}
	head->next = nullptr; //将头节点的下一个节点置空
	while (p != nullptr) //遍历链表
	{
		Node* q = p->next; //定义一个指针指向当前节点的下一个节点
		p->next = head->next; //将当前节点的下一个节点指向头节点的下一个节点
		head->next = p; //将头节点的下一个节点指向当前节点

		p = q; //指针后移
	}

}
bool linkedList(ClinkedList& list, int k, int& val) {
	Node* head = list.head;
	Node* per = head;
	Node* p = head;


	if (k <= 0) return false;
	// 先移动p指针k步
	for (int i = 0; i < k; i++) {
		if (p == nullptr) return false;
		p = p->next;
	}

	// 同时移动per和p直到p到达末尾
	while (p != nullptr) {
		per = per->next;
		p = p->next;
	}


	val = per->data;
	return true;
}

int main() {
	ClinkedList list;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++) {
		int val = rand() % 100;
		list.insertTail(val);
	}

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
