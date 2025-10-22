#include <iostream>
#include <string>
using namespace std;

class Array {
public:
	Array(int size = 10):size(size),mCur(0) {
		arr = new int[size];
	}
	void push_bak();
	void pop_back();
	void inster();
	void erase();
	void find();
private:
	int* arr; //数组指针
	int size; //大小
	int mCur; //当前元素个数

};


int main() {


	return 0;

}