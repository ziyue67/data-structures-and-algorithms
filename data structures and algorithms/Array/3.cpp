#include <iostream>
using namespace std;

#if 0
struct Node
{
	Node(int data = 0) :data(data), next(nullptr) {}
	int data;
	Node* next;
};
class ClinkedList {
public:
	ClinkedList() {
		head = new Node();
	}
	~ClinkedList()
	{
		Node* p = head;
		while (p != nullptr)
		{
			head = head->next;
			delete p;
			p = head;
		}
	}
	void insertTail(int val) {
		Node* p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		Node* node = new Node(val);
		p->next = node;
	}
	void intsertHead(int val) {
		Node* node = new Node(val);
		node->next = head->next;
		head->next = node;
	}
	void Remove(int val) {
		Node* q = head;
		Node* p = head->next;
		while (p != nullptr)
		{
			if (p->data == val) {
				q->next = p->next;
				delete p;
				return;
			}
			else
			{
				q = p;
				p = p->next;
			}
		}
	}
	void RemoveAll(int val) {
		Node* q = head;
		Node* p = head->next;
		while (p != nullptr) {
			if (p->data == val) {
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
	bool find(int val) {
		Node* p = head->next;
		while (p != nullptr) {
			if (p->data == val) {
				return true;
			}
			p = p->next;
		}
		return false;
	}
	void show() {
		Node* p = head->next;
		while (p != nullptr) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
private:
	Node* head;
	friend void verserList(ClinkedList& list);
};
void verserList(ClinkedList& list) {
	Node* head = list.head;
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

int main() {
	ClinkedList list;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++) {
		list.insertTail(rand() % 100);
	}
	list.show();
	list.intsertHead(100);
	list.show();
	list.Remove(100);
	list.show();
	list.insertTail(200);
	list.insertTail(200);
	list.insertTail(200);
	list.show();
	list.RemoveAll(200);
	list.show();
	list.insertTail(100);
	cout << list.find(100) << endl;
	verserList(list);
	list.show();

	return 0;
}
#endif