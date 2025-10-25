//#include <iostream>
//#include <string>
//#include <cstring> // memcpy需要包含此头文件（避免编译器警告）
//using namespace std;
//#include <time.h>
//
//class Array {
//public:
//	Array(int size = 10) : size(size), mCur(0) {
//		arr = new int[size];
//	}
//	~Array() {
//		delete[] arr;
//		arr = nullptr; // 置空指针，避免野指针
//	}
//	void push_front(int val) {
//		if (mCur == size) {
//			expand(2 * size);
//		}
//		for (int i = mCur - 1; i >= 0; i--) {
//			arr[i + 1] = arr[i];
//		}
//		arr[0] = val;
//		mCur++;
//	}
//	// 尾插元素（正确）
//	void push_back(int val) {
//		if (mCur == size) {
//			expand(2 * size);
//		}
//		arr[mCur++] = val;
//	}
//
//	// 尾删元素（正确）
//	void pop_back() {
//		if (mCur == 0) {
//			return;
//		}
//		mCur--;
//	}
//
//	// 修正：插入函数（元素向后移动）
//	void insert(int pos, int val) {
//		if (pos < 0 || pos > mCur) { // pos=mCur等价于尾插，合法
//			return;
//		}
//		if (mCur == size) {
//			expand(2 * size);
//		}
//		// 关键修正：从最后一个有效元素（mCur-1）向前遍历，元素向后移动1位
//		for (int i = mCur - 1; i >= pos; i--) {
//			arr[i + 1] = arr[i];
//		}
//		arr[pos] = val;
//		mCur++; // 有效元素数+1
//	}
//	void erase_front(int pos) {
//		if (pos < 0 || pos >= mCur) { // pos必须在有效索引范围内（0~mCur-1）
//			return;
//		}
//		// 关键修正：从pos开始向后遍历，元素向前移动1位（覆盖被删除元素）
//		for (int i = pos; i < mCur - 1; i++) {
//			arr[i] = arr[i + 1];
//		}
//		--mCur; // 有效元素数-1
//	}
//	
//
//	// 修正：删除函数（元素向前移动）
//	void erase(int pos) {
//		if (pos < 0 || pos >= mCur) { // pos必须在有效索引范围内（0~mCur-1）
//			return;
//		}
//		// 关键修正：从pos开始向后遍历，元素向前移动1位（覆盖被删除元素）
//		for (int i = pos; i < mCur - 1; i++) {
//			arr[i] = arr[i + 1];
//		}
//		mCur--; // 有效元素数-1
//	}
//
//	// 查找元素（正确）
//	int find(int val) {
//		for (int i = 0; i < mCur; i++) {
//			if (arr[i] == val) {
//				return i;
//			}
//		}
//		return -1;
//	}
//
//	// 打印有效元素（正确）
//	void show() {
//		for (int i = 0; i < mCur; i++) {
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//
//private:
//	// 扩容函数（正确，已修正size赋值问题）
//	void expand(int newSize) {
//		int* newArr = new int[newSize];
//		memcpy(newArr, arr, sizeof(int) * mCur); // 仅拷贝有效元素
//		delete[] arr; // 释放旧内存
//		arr = newArr;
//		size = newSize; // 更新总容量
//	}
//
//private:
//	int* arr;    // 动态数组指针
//	int size;    // 数组总容量
//	int mCur;    // 当前有效元素个数
//};
//
//int main() {
//	Array arr;
//	srand(time(0)); // 初始化随机数种子
//
//	// 1. 尾插10个随机数（0~99）
//	for (int i = 0; i < 10; i++) {
//		arr.push_back(rand() % 100);
//	}
//	cout << "1. 初始10个随机数：";
//	arr.show();
//
//	arr.push_front(100);
//	cout << "1. 头插100后：";
//	arr.show();
//
//	//arr.erase(0);
//	arr.erase_front(0);
//	cout << "1. 删除第一个元素后：";
//	arr.show();
//
//	// 2. 尾插100（触发扩容：容量从10→20）
//	arr.push_back(100);
//	cout << "2. 尾插100后：";
//	arr.show();
//
//	// 3. 尾删（删除100）
//	arr.pop_back();
//	cout << "3. 尾删后：";
//	arr.show();
//
//	// 4. 在pos=10插入200（此时mCur=10，pos=10等价于尾插）
//	arr.insert(10, 200);
//	cout << "4. 插入200后：";
//	arr.show();
//
//	// 5. 查找200并删除
//	int pos = arr.find(200);
//	if (pos != -1) {
//		arr.erase(pos);
//		cout << "5. 删除200后：";
//		arr.show();
//	}
//
//	return 0;
//}