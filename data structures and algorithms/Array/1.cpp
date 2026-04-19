#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
#include <time.h>

//class Array {
//public:
//	// 构造函数
//	Array(int size = 10) : size(size), mcap(0) {
//		arr = new int[size];
//	}
//
//	// 拷贝构造函数
//	Array(const Array& other) : size(other.size), mcap(other.mcap) {
//		arr = new int[size];
//		memcpy(arr, other.arr, sizeof(int) * mcap);
//	}
//
//	// 赋值运算符
//	Array& operator=(const Array& other) {
//		if (this != &other) {
//			delete[] arr;
//			size = other.size;
//			mcap = other.mcap;
//			arr = new int[size];
//			memcpy(arr, other.arr, sizeof(int) * mcap);
//		}
//		return *this;
//	}
//
//	// 析构函数
//	~Array()
//	{
//		delete[] arr;
//		arr = nullptr;
//	}
//	void push_back(int val) {
//		if (size == mcap) {
//			expand(2 * size);
//		}
//		arr[mcap] = val;
//		mcap++;  // 缺少这一行，元素没有被正确添加
//	}
//	void pop_back() {
//		if (mcap == 0) {
//			return;
//		}
//		mcap--;
//	}
//	void insert(int pos, int val) {
//		if (pos < 0 || pos > mcap) {  // 位置合法性检查
//			return;
//		}
//		if (mcap == size) {  // 容量不足则扩容
//			expand(2 * size);
//		}
//		for (int i = mcap; i > pos; i--) {
//			arr[i] = arr[i - 1];
//		}
//		arr[pos++] = val;
//		mcap++;
//	}
//	void erase(int pos) {
//		if (pos < 0 || pos >= mcap) {
//			return;
//		}
//		for (int i = pos; i < mcap - 1; i++) {
//			arr[i] = arr[i + 1];
//		}
//		mcap--;
//	}
//	int find(int val) {
//		for (int i = 0; i < mcap; i++) {
//			if (arr[i] == val) {
//				return i;
//			}
//		}
//		return -1;
//	}
//	void show() {
//		for (int i = 0; i < mcap; i++) {
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//
//private:
//	void expand(int newsize) {
//		int* newarr = new int[newsize];
//		memcpy(newarr, arr, sizeof(int) * mcap);
//		delete[] arr;
//		arr = newarr;
//		size = newsize;
//	}
//private:
//	int* arr;
//	int size;
//	int mcap;
//};
//
//
//
//int main() {
//	Array arr;
//	srand(time(0));
//	for (int i = 0; i < 10; i++) {
//		arr.push_back(rand() % 100);
//	}
//	arr.show();
//	arr.erase(2);
//	arr.show();
//	arr.insert(2, 100);
//	arr.show();
//
//	int pos = arr.find(100);
//	if (pos != -1) {
//		arr.erase(pos);
//	}
//	arr.show();
//
//	return 0;
//}

#if 0
template <typename T>
class Array {
public:
	Array(int size = 10) :size(size), capacity(0) {
		arr = new T[size];
	}
	Array(const Array& other) :capacity(other.capacity), size(other.size) {
		arr = new T[capacity];
		memcpy(arr, other.arr, sizeof(T) * size);
	}
	Array& operator=(const Array& other) {
		if (this != &other) {
			delete[] arr;
			capacity = other.capacity;
			size = other.size;
			arr = new T[capacity];
			other.arr = nullptr;
			other.m_capacity = 0;
			other.m_size = 0;
			memcpy(arr, other.arr, sizeof(T) * size);
		}
		return *this;
	}
	~Array()
	{
		delete[]arr;
		arr = nullptr;
	}
	void push_back(const T& val) {
		if (capacity >= size) {
			expand(2 * size);
		}
		arr[capacity++] = val;
	}
	void pop_back() {
		if (capacity == 0) {
			return;
		}
		capacity--;
	}
	void insert(int pos, const T& val) {
		if (pos < 0 || pos > capacity) {
			return;
		}
		if (capacity >= size) {
			expand(2 * size);
		}
		for (int i = capacity; i > pos; i--) {
			arr[i] = arr[i - 1];
		}
		arr[pos++] = val;
		capacity++;
	}
	void erase(int pos) {
		if (pos < 0 || pos >= capacity) {
			return;
		}
		for (int i = pos; i < capacity - 1; i++) {
			arr[i] = arr[i + 1];
		}
		capacity--;
	}
	int find(const T& val)const {
		for (int i = 0; i < capacity; i++) {
			if (arr[i] == val) {
				return i;
			}
		}
		return -1;
	}
	void show() const {
		for (int i = 0; i < capacity; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
private:
	void expand(int newsize) {
		T* newarr = new T[newsize];
		memcpy(newarr, arr, sizeof(T) * size);
		delete[] arr;
		arr = newarr;
		size = newsize;
	}
private:
	T* arr;
	int size;
	int capacity;
};

int main() {
	Array<int> arr;
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		arr.push_back(rand() % 100);
	}
	arr.show();
	arr.erase(2);
	arr.show();
	arr.insert(2, 100);
	arr.show();
	int pos = arr.find(100);
	if (pos != -1) {
		arr.erase(pos);
	}
	arr.show();
	Array<double> arr2;
	arr2.push_back(1.1);
	arr2.push_back(2.2);
	cout << "double数组：";
	arr2.show();

	// 5. 测试拷贝构造
	Array<int> arr3 = arr;
	arr3.push_back(4);
	cout << "arr3（拷贝后添加4）：";
	arr3.show();
	cout << "arr（原数组不变）：";
	arr.show();

	Array<string> arr4;
	arr4.push_back("hello");
	arr4.push_back("world");
	cout << "string数组：";
	arr4.show();

	return 0;
}
#endif