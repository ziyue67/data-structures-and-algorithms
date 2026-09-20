// #include <iostream>
// #include <cstring>

// using namespace std;

// // 原地反转字符串（按引用传递，直接修改传入的串）
// void reverseString(string &str)
// {
//     int p = 0;
//     int q = str.size() - 1;
//     while (p < q)
//     {
//         swap(str[p], str[q]);
//         p++;
//         q--;
//     }
// }

// // 原地反转字符数组
// void reverseCharArray(char arr[], int size)
// {
//     char *p = arr;
//     char *q = arr + size - 1;
//     while (p < q)
//     {
//         char ch = *p;
//         *p = *q;
//         *q = ch;
//         p++;
//         q--;
//     }
// }

// int main()
// {
//     // --- 方式一：std::string ---
//     string s = "Hello, World!";
//     cout << "Original: " << s << endl;
//     reverseString(s);
//     cout << "Reversed: " << s << endl;
//     cout << endl;

//     // --- 方式二：char[] ---
//     char arr[] = "Hello, World!";
//     cout << "Original: " << arr << endl;
//     reverseCharArray(arr, strlen(arr));
//     cout << "Reversed: " << arr << endl;

//     return 0;
// }
