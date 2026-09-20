// #include <iostream>
// #include <cstring>

// using namespace std;

// class Array
// {
// public:
//     Array(int capacity = 10) : len(0), capacity(capacity)
//     {
//         arr = new int[capacity];
//     }
//     ~Array()
//     {
//         delete[] arr;
//         arr = nullptr;
//     }
//     void push_back(int value)
//     {
//         if (len == capacity)
//         {
//             expand(2 * capacity);
//         }
//         arr[len++] = value;
//     }
//     void pop_back()
//     {
//         if (len == 0)
//         {
//             return;
//         }
//         len--;
//     }
//     void insert(int index, int value)
//     {
//         if (index < 0 || index > len)
//         {
//             return;
//         }
//         if (len == capacity)
//         {
//             expand(2 * capacity);
//         }
//         for (int i = len - 1; i >= index; i--)
//         {
//             arr[i + 1] = arr[i];
//         }
//         arr[index] = value;
//         len++;
//     }
//     void erase(int index)
//     {
//         if (index < 0 || index >= len)
//         {
//             return;
//         }
//         for (int i = index + 1; i < len; i++)
//         {
//             arr[i] = arr[i + 1];
//         }
//         len--;
//     }
//     bool find(int value)
//     {
//         for (int i = 0; i < len; i++)
//         {
//             if (arr[i] == value)
//             {
//                 cout << "找到了 " << value << " (index=" << i << ")" << endl;
//                 return true;
//             }
//         }
//         cout << "没找到 " << value << endl;
//         return false;
//     }
//     void print()
//     {
//         for (int i = 0; i < len; i++)
//         {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
//     int size() const
//     {
//         return len;
//     }

// private:
//     // 扩容到 newsize，拷贝原有元素后释放旧内存
//     void expand(int newsize)
//     {
//         int *newArr = new int[newsize];
//         memcpy(newArr, arr, sizeof(int) * len);
//         delete[] arr;
//         arr = newArr;
//         capacity = newsize;
//     }
//     int *arr;      // 数组
//     int len;       // 数组当前大小
//     int capacity;  // 数组容量
// };

// int main()
// {
//     Array arr;
//     for (int i = 0; i < 10; i++)
//     {
//         arr.push_back(i);
//     }
//     arr.print();
//     arr.find(5);
//     arr.find(99);
//     arr.insert(5, 100);
//     arr.print();
//     arr.erase(5);
//     arr.print();
//     arr.pop_back();
//     arr.print();
//     arr.push_back(200);
//     arr.print();
//     cout << "size = " << arr.size() << endl;

//     return 0;
// }
