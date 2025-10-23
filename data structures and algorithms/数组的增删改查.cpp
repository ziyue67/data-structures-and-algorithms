#include <iostream>
#include <string>
using namespace std;
#include <time.h>
class Array {
public:
	Array(int size = 10) :size(size), mCur(0) {
		arr = new int[size];
	}
	~Array()
	{
		delete[]arr;
		arr = nullptr;
	}
	void push_back(int val) {
		if (mCur == size) {
			expand(2 * size);
		}
		arr[mCur++] = val;

	}
	void pop_back() {
		if (mCur == 0) {
			return;
		}
		mCur--;
	}
	void insert(int pos, int val) { //先索引 后值
		if (pos < 0 || pos > mCur) {
			return;
		}
		if (mCur == size) {
			expand(2 * size);
		}
		for (int i = mCur; i > pos; i--) {
			arr[i] = arr[i - 1];
		}
		arr[pos] = val;
		mCur++;
	}
	void erase(int pos) {
		if (pos <0 || pos>mCur) {
			return;
		}
		for (int i = pos; i < mCur; i++) {
			arr[i] = arr[i + 1];
		}
		mCur--;
	}
	int  find(int val) {
		for (int i = 0; i < mCur; i++) {
			if (arr[i] == val) {
				return i;
			}
		}
		return -1;
	}
	void show() {
		for (int i = 0; i < mCur; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	};

private:
	void expand(int size) {
		int* p = new int[size];
		memcpy(p, arr, sizeof(int) * mCur);

		delete[]arr;
		arr = p;  //指针指向新数组
		size = size;

	}
private:
	int* arr; //数组指针
	int size; //数组大小
	int mCur; //当前元素个数

};


int main() {
	Array arr;
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		arr.push_back(rand() % 100);
	}
	arr.show();

	arr.push_back(100);
	arr.show();
	arr.pop_back();
	arr.show();

	arr.insert(10, 200);
	arr.show();

	//arr.erase(10);
	//arr.show();
	int pos = arr.find(200);
	if (pos != -1) {
		arr.erase(pos);
		arr.show();
	}


	return 0;

}