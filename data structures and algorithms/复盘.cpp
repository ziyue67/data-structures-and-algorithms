#include <iostream>
#include <string>
#include <cstring> // memcpy需要包含此头文件（避免编译器警告）
using namespace std;
#include <time.h>
//#if 0
//class Array {
//public:
//	Array(int size = 10) :size(size), mcur(0) {
//		arr = new int[size];
//	}
//	~Array()
//	{
//		delete[]arr;
//		arr = nullptr;
//	}
//	void push_back(int val) {
//		if (mcur == size) {
//			expand(2 * size);
//		}
//		arr[mcur++] = val;
//	}
//	void pop_back() {
//		if (mcur == 0) {
//			return;
//		}
//		mcur--;
//
//	}
//	void insert(int pos, int val) {
//		if (pos < 0 || pos > mcur) {  // 位置合法性检查
//			return;
//		}
//		if (mcur == size) {  // 容量不足则扩容
//			expand(2 * size);
//		}
//		for (int i = mcur; i > pos; i--) {
//			arr[i] = arr[i - 1];
//		}
//		arr[pos++] = val;
//		mcur++;
//	}
//	void erase(int pos) {
//		if (pos < 0 || pos >= mcur) {
//			return;
//		}
//		for (int i = pos; i < mcur - 1; i++) {
//			arr[i] = arr[i + 1];
//		}
//		mcur--;
//
//	}
//	int find(int val) {
//		for (int i = 0; i < mcur; i++) {
//			if (arr[i] == val) {
//				return i;
//			}
//		}
//		return -1;
//	}
//	void show() {
//		for (int i = 0; i < mcur; i++) {
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//
//
//private:
//	void expand(int newsize) {
//		int* p = new int[newsize];
//		memcpy(p, arr, sizeof(int) * mcur);
//
//		delete[]arr;
//		arr = p;
//		size = newsize;
//	}
//private:
//	int* arr;
//	int size;
//	int mcur;
//};
//#endif
//#if 0
//void Revase(char  arr[], int size) {
//
//	char* p = arr;
//	char* q = arr + size - 1;
//
//	while (p < q)
//	{
//		char* ch = *p;
//		*p = *q;
//		*q = *ch;
//		p++;
//		q--;
//	}
//
//}
//
//
//
//
//int main() {
//
//	char arr[] = "abcdefg";
//	Revase(arr, strlen(arr));
//	cout << arr << endl;
//
//
//#if 0
//	Array arr;
//	srand(time(0));
//
//	for (int i = 0; i < 10; i++) {
//		arr.push_back(rand() % 100);
//	}
//
//	arr.show();
//	arr.push_back(100);
//	arr.show();
//	arr.pop_back();
//	arr.show();
//	arr.insert(10, 200);
//	arr.show();
//	int pos = arr.find(200);
//	if (pos != -1) {
//		arr.erase(pos);
//		arr.show();
//	}
//#endif
//
//	return 0;
//
//}
//#endif

//class Array {
//public:
//	Array(int size = 10) :size(size), mcap(0) {
//		arr = new int[size];
//	}
//	~Array()
//	{
//		delete[]arr;
//		arr = nullptr;
//	};
//	void push_back(int val) {
//		if (mcap == size) {  // 容量不足时扩容
//			expan(2 * size);
//		}
//		arr[mcap++] = val;  // 直接在尾部插入，修正原循环覆盖和重复递增问题
//	}
//	void pop_back() {
//		if (mcap == 0) {
//			return;
//		}
//		mcap--;
//	}
//	void intsert(int pos, int val) {
//		if (mcap == size) {
//			expan(2 * size);
//		}
//		for (int i = mcap-1; i > pos; i--) {
//			arr[i] = arr[i + 1];
//		}
//		arr[pos] = val;
//		mcap++;
//	}
//	void  erase(int pos) {
//		if(pos < 0 || pos >= mcap) {
// 			return;}
//
//		for (int i = pos+1; i < mcap; i++) {
//			arr[i] = arr[i - 1];
//		}
//		mcap--;
//	}
//	int find(int val) {
//		if (mcap == 0) {
//			return -1;
//		}
//		for (int i = 0; i < mcap; i++) {
//			if (arr[i] == val) {
//				return i;
//			}
//		}
//		return -1;
//	};
//	void show() {
//		for (int i = 0; i < mcap; i++) {
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//private:
//	void expan(int newsize) {
//		int* p = new int[newsize];
//		memcpy(p, arr, sizeof(int) * mcap);
//		delete[]arr;
//		arr = p;
//		size = newsize;
//	}
//private:
//	int* arr;
//	int size;
//	int mcap;
//
//
//};
//
//
//
//
//
//int main() {
//	Array arr;
//	srand(time(0));
//
//	for (int i = 0; i < 10; i++) {
//		arr.push_back(rand() % 100);
//	}
//	arr.show();
//	arr.push_back(100);
//	arr.show();
//	arr.pop_back();
//	arr.show();
//	arr.intsert(10, 200);
//	arr.show();
//	int pos = arr.find(200);
//	if (pos != -1) {
//		arr.erase(pos);
//		arr.show();
//	}
//
//
//	return 0;
//}