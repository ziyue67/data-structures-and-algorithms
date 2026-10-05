// #include <iostream>
// using namespace std;

// int BrySerch(int arr[],int size,int valvue){
//     int first= 0;
//     int last= size-1;
//     while(first<=last){
//         int mid=(first +last/2);
//         if(arr[mid]==valvue){
//             return mid;
//         }else  if(arr[mid]>valvue){
//             last=mid-1;
//         }
//         else{
//             first=mid +1;
//         }
//     }
//     return -1;
// }
// int main(){
//     int arr[]={1,2,3,4,5,6,7,8,9};
//     int size=sizeof(arr)/sizeof(arr[0]);
//     int valvue;
//     cout<<"请输入要查找的值：";
//     cin>>valvue;
//     int index=BrySerch(arr,size,valvue);
//     if(index!=-1){
//         cout<<"值"<<valvue<<"在数组中的索引为："<<index<<endl;
//     }else{
//         cout<<"值"<<valvue<<"不在数组中"<<endl;
//     }
//     return 0;
// }

// 递归 二分搜索
//  #include <iostream>
//  using namespace std;

// int BinarySearch(int arr[], int i, int j, int value)
// {
//     if (i > j)
//     {
//         return -1;
//     }
//     int mid = (i + j) / 2;
//     if (arr[mid] == value)
//     {
//         return mid;
//     }
//     else if (arr[mid] > value)
//     {
//         return BinarySearch(arr, i, mid - 1, value);
//     }
//     else
//     {
//         return BinarySearch(arr, mid + 1, j, value);
//     }
// }

// 重新写二分搜索
#include <iostream>
using namespace std;

// int BinarySearch(int arr[], int szie, int value)
// {
//     int first = 0;
//     int last = szie - 1;
//     while (first < last)
//     {
//         int mid = first - (first - last) / 2;
//         if (arr[mid] == value)
//         {
//             return mid;
//         }
//         else if (arr[mid] > value)
//         {
//             last = mid - 1;
//         }
//         else
//         {
//             first = mid + 1;
//         }
//     }
//     return -1;
// }

int BinarySearch(int arr[], int j, int i, int value)
{
    if (j > i)
    {
        return -1;
    }
    int mid = j + (i - j) / 2;
    if (arr[mid] == value)
    {
        return mid;
    }
    else if (arr[mid] > value)
    {
        return BinarySearch(arr, j, mid - 1, value);
    }
    else
    {
        return BinarySearch(arr, mid + 1, i, value);
    }
};
int main()
{
    int arr[] = {12, 25, 34, 39, 45, 57, 63, 78, 82, 96, 100};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << BinarySearch(arr, 0, size - 1, 39) << endl; // 输出 3
    cout << BinarySearch(arr, 0, size - 1, 45) << endl; // 输出 4
    cout << BinarySearch(arr, 0, size - 1, 12) << endl; // 输出 0
    cout << BinarySearch(arr, 0, size - 1, 64) << endl; // 输出 -1（未找到）
    // cout << BinarySearch(arr, size, 39) << endl; // 输出 3
    // cout << BinarySearch(arr, size, 45) << endl; // 输出 4
    // cout << BinarySearch(arr, size, 12) << endl; // 输出 0
    // cout << BinarySearch(arr, size, 64) << endl; // 输出 -1（未找到）

    return 0;
}