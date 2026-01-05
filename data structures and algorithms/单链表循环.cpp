#include <iostream>
using namespace std;

#if 0
class CircleList {
public:
	CircleList() {
		head = new Node();
		tail = head;
		head->next = tail;
	}
	~CircleList()
	{
		//		Node* dummy = head;
		//		while (dummy != head) {
		//			dummy->next = head;
		//			delete dummy;
		//			dummy = dummy->next;
		//		}
		//		delete head;
		Node* dummy = head;
		while (dummy != head) {
			Node* temp = dummy;
			dummy = dummy->next;
			delete temp;
		}
		delete head;
	}
	void InsertTial(int val) {
		Node* node = new Node(val);
		node->next = head;
		tail->next = node;
		tail = node;
	}
	void InsertHead(int val) {
		Node* node = new Node(val);
		node->next = head->next;
		head->next = node;
		if (tail == head) {
			tail = node;
		}
	};

	void Remove(int val) {
		Node* prev = head;
		Node* curr = head->next;
		while (curr != head) {
			if (curr->data == val) {
				prev->next = curr->next;
				if (tail = curr) {
					tail = prev;
				}
				delete curr;
				return;
			}
			prev = curr;
			curr = curr->next;
		}
	}
	void RemoveAll(int val) {
		Node* prev = head;
		Node* curr = head->next;
		while (curr != head) {
			if (curr->data == val) {
				prev->next = curr->next;
				Node* temp = curr;
				curr = curr->next;
				if (tail == curr) {
					tail = prev;
				}
				delete temp;

			}
			else {
				prev = curr;
				curr = curr->next;
			}
		}
	}
	bool Find(int val) {
		Node* curr = head->next;
		while (curr != head) {
			if (curr->data == val) {
				return true;
			}
			curr = curr->next;
		}
		return false;
	}


	void show() {
		Node* curr = head->next;
		while (curr != head) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}


private:
	struct Node {
		Node(int data = 0) :data(data), next(nullptr) {}
		int data;
		Node* next;
	};
	Node* head;
	Node* tail;
};



int main() {
	CircleList list;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		list.InsertTial(rand() % 100);
	}
	list.show();
	list.InsertTial(100);
	list.show();
	list.InsertTial(100);
	list.show();
	bool flag = list.Find(100);
	if (flag) {
		cout << "find" << endl;
		list.RemoveAll(100);
	}
	list.show();
	CircleList list1;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		list1.InsertHead(rand() % 100);
	}
	list1.show();
	list1.InsertHead(100);
	list1.show();
	list1.Remove(100);
	list1.show();
	return 0;
}
#endif