// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include <algorithm>

// using namespace std;

// // 双指针：把奇数全部排到前面，偶数全部排到后面（不保证相对顺序）
// void rearrangeOddEven(int arr[], int n)
// {
//     int p = 0;
//     int q = n - 1;
//     while (p < q)
//     {
//         // p 向右找第一个偶数
//         while (p < q && arr[p] % 2 != 0)
//         {
//             p++;
//         }
//         // q 向左找第一个奇数
//         while (p < q && arr[q] % 2 == 0)
//         {
//             q--;
//         }
//         if (p < q)
//         {
//             swap(arr[p], arr[q]);
//             p++;
//             q--;
//         }
//     }
// }

// int main()
// {
//     int arr[10];
//     srand((unsigned int)time(0));
//     for (int i = 0; i < 10; i++)
//     {
//         arr[i] = rand() % 100;
//     }

//     cout << "处理之前：";
//     for (int i = 0; i < 10; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     rearrangeOddEven(arr, 10);

//     cout << "处理之后：";
//     for (int i = 0; i < 10; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }
