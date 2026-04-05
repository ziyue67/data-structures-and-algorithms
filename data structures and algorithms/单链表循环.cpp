#include <iostream>
using namespace std;

class CircleList
{
private:
	struct Node
	{
		int data; // 将data成员移到next之前
		Node *next;
		Node(int data = 0) : data(data), next(nullptr) {}
	};

	Node *head;
	Node *tail;

public:
	CircleList()
	{
		head = new Node;
		head->next = head;
		tail = head;
	}

	~CircleList()
	{
		if (head == nullptr)
			return;

		Node *curr = head->next;
		while (curr != head)
		{
			Node *temp = curr;
			curr = curr->next;
			delete temp;
		}
		delete head;
	}

	void InsertTial(int val)
	{
		Node *node = new Node(val);
		node->next = head;
		tail->next = node;
		tail = node;
	}

	void InsertHead(int val)
	{
		Node *node = new Node(val);
		node->next = head->next;
		head->next = node;
		if (tail == head)
		{
			tail = node;
		}
	}

	void Remove(int val)
	{
		Node *prev = head;
		Node *curr = head->next;
		while (curr != head)
		{
			if (curr->data == val)
			{
				prev->next = curr->next;
				if (tail == curr)
				{
					tail = prev;
				}
				delete curr;
				return;
			}
			prev = curr;
			curr = curr->next;
		}
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
	void Joseph(int m, int k)
	{
		if (head == nullptr || head->next == head)
			return;
		Node *curr = head->next;
		Node *prev = head;
		// 先移动到第k个节点
		for (int i = 1; i < k; i++)
		{
			prev = curr;
			curr = curr->next;
		}
		// 从第k个节点开始报数，数到m删除
		while (head->next != head) // 循环直到只剩哨兵节点
		{
			// 数m-1步
			for (int i = 1; i < m; i++)
			{
				prev = curr;
				curr = curr->next;
				if (curr == head) // 跳过哨兵
				{
					prev = curr;
					curr = curr->next;
				}
			}
			// 删除curr节点
			cout << curr->data << " ";
			prev->next = curr->next;
			Node *toDelete = curr;
			if (curr == tail) tail = prev;
			curr = prev->next;
			delete toDelete;
			if (curr == head) // 确保curr不停留在head
				curr = head->next;
		}
		cout << endl;
	}
};

int main()
{
	CircleList list;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		list.InsertTial(rand() % 100);
	}

	list.Joseph(3, 1);

	return 0;
}
