#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#if 0
class Array {
public:
	Array(int size = 10) :size(size), mcur(0) {
		arr = new int[size];
	}
	~Array()
	{
		delete[]arr;
		arr = nullptr;
	}
	void push_back(int val) {
		if (mcur == size) {
			expand(2 * size);
		}
		arr[mcur++] = val;
	}
	void pop_back() {
		if (mcur == 0) {
			return;
		}
		mcur--;

	}
	void insert(int pos, int val) {
		if (pos < 0 || pos > mcur) {  // 位置合法性检查
			return;
		}
		if (mcur == size) {  // 容量不足则扩容
			expand(2 * size);
		}
		for (int i = mcur; i > pos; i--) {
			arr[i] = arr[i - 1];
		}
		arr[pos++] = val;
		mcur++;
	}
	void erase(int pos) {
		if (pos < 0 || pos >= mcur) {
			return;
		}
		for (int i = pos; i < mcur - 1; i++) {
			arr[i] = arr[i + 1];
		}
		mcur--;

	}
	int find(int val) {
		for (int i = 0; i < mcur; i++) {
			if (arr[i] == val) {
				return i;
			}
		}
		return -1;
	}
	void show() {
		for (int i = 0; i < mcur; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}


private:
	void expand(int newsize) {
		int* p = new int[newsize];
		memcpy(p, arr, sizeof(int) * mcur);

		delete[]arr;
		arr = p;
		size = newsize;
	}
private:
	int* arr;
	int size;
	int mcur;
};
#endif
#if 0
void Revase(char  arr[], int size) {

	char* p = arr;
	char* q = arr + size - 1;

	while (p < q)
	{
		char* ch =  *p;
		*p = *q;
		*q = *ch;
		p++;
		q--;
	}

}




int main() {

	char arr[] = "abcdefg";
	Revase(arr, strlen(arr));
	cout << arr << endl;


#if 0
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
	int pos = arr.find(200);
	if (pos != -1) {
		arr.erase(pos);
		arr.show();
	}
#endif

	return 0;

}
#endif

