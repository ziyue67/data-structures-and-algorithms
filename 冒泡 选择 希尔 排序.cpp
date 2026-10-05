#include <iostream>
using namespace std;
#include <cstring>
#include <random>
// 冒泡排序
int swap(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        bool flag = false;
        for (int j = i + 1; j < size - 1; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                flag = true;
            }
        }
        if (!flag)
        {
            return 0;
        }
    }
    return 0;
};

// 选择排序
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
// 插入排序
// void insertionSort(int arr[], int size)
// {
//     for (int i = 1; i < size; i++)
//     {
//         int val = arr[i];
//         int j;
//         for (j = i - 1; j >= 0; j--)
//         {
//             if (arr[j] < val)
//             {
//                 break;
//             }
//             arr[j + 1] = arr[j];
//         }
//         arr[j + 1] = val;
//     }
// }
void insertionSort(int arr[],int size){
    for(int i=1;i<size;i++){
        int val=arr[i];
        int j;
        for(j=i-1;j>=0;j--){
            if(arr[j]<val){
                break;
            }
            arr[j+1]=arr[j];
        }
        arr[j+1]=val;
    }
}
// 希尔排序
// void shellSort(int arr[], int size)
// {
//     for (int gap = size / 2; gap > 0; gap /= 2)
//     {
//         for (int i = gap; i < size; i++)
//         {
//             int val = arr[i];
//             int j;
//             for (j = i - gap; j >= 0; j -= gap)
//             {
//                 if (arr[j] < val)
//                 {
//                     break;
//                 }
//                 arr[j + gap] = arr[j];
//             }
//             arr[j + gap] = val;
//         }
//     }
// }
void shellSort(int arr[],int size){
    for(int gap=size/2;gap>0;gap/2){
        for(int i=gap;i<size;i++){
            int val=arr[i];
            int j;
            for(j=i-gap;j>=0;j-gap){
                if(arr[j]<val){
                    break;
                }
                if(arr[j]>=val){
                    arr[j+gap]=arr[j];
                }
            }
            arr[j+gap]=val;
        }

    }
}
// int partion(int arr[],int l,int r){
//     int val=arr[l];   // 取第一个元素作为基准值
//     while(l<r){
//         // O(n) 复杂度  O(log n)=O(nlog)  空间O(logn) -O(n)
//         while (l < r && arr[r] >= val)
//         {        // 从右向左找第一个小于基准值的元素
//             r--; // 右指针左移
//         }
//         if (l < r)
//         {
//             arr[l] = arr[r]; // 将小于基准值的元素放到左边
//             l++;              // 左指针右移
//         }

//         val = arr[l]; // 取第一个元素作为基准值
//         return l;     // 返回基准值的位置
//     }
// }
// void quicksort(int arr[],int begin,int end){
//     if(begin>=end){ // 递归终止条件
//         return;
//     }
//     int pos=partion(arr,begin,end); // 获取基准值的位置
//     quicksort(arr,begin,pos-1); // 对左半部分进行快速排序
//     quicksort(arr,pos+1,end);// 对右半部分进行快速排序

// }
// //快速排序递归接口
// void quickSort(int arr[], int size)
// {
//     quicksort(arr, 0, size - 1);
// }

// 快速排序
//  优化快速 排序  "三数取中" arr[l] arr[r] arr[(l+r)/2] 取中间值作为基准值
// 记录 基准数
//  优化在中间插入 插入排序
int  partion(int arr[], int l, int r){
    int mid=l+(r-l)/2;
    int val=arr[l];
    while(l<r){
        while(l<r &&arr[r]>=val){
            r--;
        }
        if(l<r){
            arr[l]=arr[r];
            l++;
        }

    }
    arr[l]=val;
    return l;

}
void quicksort(int arr[], int l, int r){
    if(l>=r){
        return;
    }
    int pos=partion(arr,l,r);
    quicksort(arr,l,pos-1);
    quicksort(arr,pos+1,r);
}

    // 递归快速排序
    // void quickSort(int arr[], int size)
    // {
    //     if (size <= 1)
    //         return;

    //     int pos = partition(arr, size);           // 分区
    //     quickSort(arr, pos);                      // 排左半部分 [0, pos-1]
    //     quickSort(arr + pos + 1, size - pos - 1); // 排右半部分 [pos+1, size-1]
    // }

    // // void merger(int arr[], int l, int r, int mid)
    // {
    //     int *p=new int[r-l+1];
    //     int dix=0;
    //     int i=l;
    //     int j=mid+1;
    //     while(i<=mid &&j<=r){
    //         if(arr[i]<=arr[j]){
    //             p[dix++]=arr[i++];
    //         }
    //         else{
    //             p[dix++]=arr[j++];
    //         }
    //     }
    //     while(i<=mid){
    //         p[dix++]=arr[i++];
    //     }
    //     while (j<=r)
    //     {
    //         p[dix++]=arr[j++];
    //     }
    //     memcpy(arr + l, p, (r - l + 1) * sizeof(int));
    //     delete[] p;

    // }

    // void mergeSort(int arr[], int begin, int end)
    // {
    //     if (begin >= end)
    //         return;

    //     int mid = begin + (end - begin) / 2; // 防止溢出

    //     mergeSort(arr, begin, mid);   // 排左半部分
    //     mergeSort(arr, mid + 1, end); // 排右半部分
    //     merger(arr, begin, end, mid); // 合并
    // }
    void merge(int arr[], int l, int mid, int r)
{
    int *p=new int[r-l+1];
    int dix=0;
    int i=l;
    int j=mid+1;
    while(i<=mid &&j<=r){
        if(arr[i]<=arr[j]){
            p[dix++]=arr[i++];
        }
        else{
            p[dix++]=arr[j++];
        }
    }
    while(i<=mid){
        p[dix++]=arr[i++];
    }
    while(j<=r){
        p[dix++]=arr[j++];
    }
    memcpy(arr+l,p,(r-l+1)*sizeof(int));
    delete[] p;
}
void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = l + (r - l) / 2;
    merge(arr, l, mid, r);
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
}

// 归并排序
void mergeSort(int arr[], int size)
{
    mergeSort(arr, 0, size - 1);
}
int main()
{
    srand(time(0));

    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
    }
    mergeSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}