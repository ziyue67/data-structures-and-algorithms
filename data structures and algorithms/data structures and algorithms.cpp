#include <iostream>
#include <string>
using namespace std;
#include <time.h>

//整形 数据 把偶数调整到数组的左边 ，奇数调整到数组的右边
#if 0
void Adjust(int arr[], int size) {
	int* p = arr;
	int* q = arr + size - 1;

	while (p < q)
	{
		//#if 0
		//		while (*p % 2 == 0) { // 找到偶数
		//			p++;
		//		}
		//		while (*q % 2 == 1)
		//		{
		//			q--; // 找到奇数
		//		}
		//#endif
		while (p < q && (*p & 0x1) == 0) {
			p++;
			continue;
		}
		// q向左找偶数（直到找到偶数或p>=q）
		while (p < q && (*q & 0x1) == 1) {
			q--;
			continue;
		}
		/*while (p<q)
		{
			if (*p & 0x1) {
				break;
			}
			p++;
		}
		while (p < q) {
			if ((*q & 0x1) == 0) {
				break;
			}
			q--;
		}*/

		//if (p < q) {
		//	swap(*p, *q); // 交换两个元素
		//	p++;
		//	q--;
		//}
		if (p < q) {
			int temp = *p;
			*p = *q;
			*q = temp;
			p++;
			q--;
		}
	}
}

//逆序字符串
void Reverse(char arr[], int size) {
	char* p = arr;
	char* q = arr + size - 1; // 指向最后一个元素

	while (p < q)  // 交换前后两个元素
	{
		char ch = *p;
		*p = *q;
		*q = ch;
		p++;
		q--;
	}
}

class Array {
public:
	Array(int size = 10) :mCap_(size), mCur(0) { // 构造函数
		mpArr = new int[size]; // 动态分配数组
	}
	~Array() {
		delete[] mpArr; // 释放内存
		mpArr = nullptr; // 防止悬空指针
	}

	void push_back(int val) { // 在数组末尾插入一个元素
		if (mCur == mCap_) { // 数组已满，需要扩容
			// 扩容
			expand(2 * mCap_); // 扩容为原来的2倍 O(n)
		}
		mpArr[mCur++] = val; // 插入新元素 O(1)
	}
	void pop_back() // 删除数组末尾的元素
	{
		if (mCur == 0) {
			return;
		}
		mCur--; // 更新有效元素个数 O(1)
	}
	void insert(int pos, int val)// 在pos位置插入一个元素
	{
		if (pos <0 || pos >mCur) { // 索引越界
			return;  // 不做处理
		}
		if (mCur == mCap_) {
			expand(2 * mCap_);
		}
		// 从最后一个元素开始，依次往后挪一位（腾出位置）
		for (int i = mCur - 1; i > pos; i--) { // 从后往前，i > pos 避免越界
			mpArr[i] = mpArr[i + 1]; // 每个元素往后挪一位
		}

		mpArr[pos] = val; // 插入新元素
		mCur++; // 更新有效元素个数 O(n)
	}
	void erase(int pos) // 删除pos位置的元素
	{
		if (pos < 0 || pos >= mCur) {
			return;
		}
		for (int i = pos + 1; i < mCur; i++) { // 从前往后
			mpArr[i] = mpArr[i - 1]; // 每个元素往前挪一位
		}
		mCur--; // 更新有效元素个数 O(n)
	}
	int find(int val) // 查找值为val的元素，返回其索引
	{
		for (int i = 0; i < mCur; i++) { // 线性查找 O(n)
			if (mpArr[i] == val) {  // 找到
				return i;
			}
		}
		return -1;
	}
	void show() // 打印数组
	{
		for (int i = 0; i < mCur; i++) {
			cout << mpArr[i] << " ";
		}
		cout << endl;
	}
private:
	void expand(int size)// 内部数组扩容接口
	{
		int* p = new int[size]; // 分配新内存
		memcpy(p, mpArr, sizeof(int) * mCap_); // 复制旧数组到新数组 按字节复制
		delete[] mpArr; // 释放旧数组内存

		mpArr = p; // 指向新数组
		mCap_ = size; // 更新容量
	}
private:
	int* mpArr; // 指向动态分配的数组
	int mCap_; // 容量
	int mCur; // 数组有效元素个数
};

int main()
{
	int arr[10] = { 0 };
	srand(time(0));
	//int arr []= { 12,23,45,31,56,82,62 };
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 100;
		//cout << arr[i] << " ";
	}

	for (int v : arr) {
		cout << v << " ";
	}
	cout << endl;

	Adjust(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	//
	//	char arr[] = { "hello world" };
	//	Reverse(arr, strlen(arr));
	//	cout << arr << endl;

		/*Array arr;
		srand(time(0));
		for (int i = 0; i < 10; i++) {
			arr.push_back(rand() % 100);
		}
		arr.show();
		arr.pop_back();
		arr.show();
		arr.insert(0, 100);
		arr.show();

		arr.insert(10, 200);
		arr.show();

		int pos = arr.find(100);
		if (pos != -1) {
			arr.erase(pos);
			arr.show();
		}*/

		//*int arr[10] = { 12,23,45,31,56,82,62 };

		//for (int i = 0; i < 10; i++) {
		//	cout << arr[i] << " ";*/

		//}
		//cout << endl;

		//int valid_len = 7; // 已有7个元素
		//int insert_pos = 3; // 要插在索引3的位置

		//// 从最后一个元素开始，依次往后挪一位（腾出位置）
		//for (int i = valid_len - 1; i >= insert_pos; i--) {
		//	arr[i + 1] = arr[i];
		//}

		//arr[insert_pos] = 77; // 插入77

		//int pop_pos = 5; // 要删除索引5的元素
		//for (int i = pop_pos; i < valid_len - 1; i++) {
		//	arr[i] = arr[i + 1];
		//	valid_len--;
		//}

		//int pos = -1;
		//for (int i = 0; i < valid_len; i++) {
		//	if (arr[i] == 77) {
		//		pos = i;
		//		break;
		//	}
		//}
		//if (pos != -1) {
		//	for (int i = pos; i < valid_len - 1; i++) {
		//		arr[i] = arr[i + 1];
		//		valid_len--;
		//	}
		//}

		/*for (int i = 0; i < 10; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;*/

		/* int* ptr = &arr[6];
		 for (int i = 0; i < 7; i++) {
			 cout << *ptr << " ";
			 ptr--;
		 }
		 cout << endl;*/

	return 0;
}
#endif