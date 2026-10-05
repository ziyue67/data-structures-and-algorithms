#include <iostream>
using namespace std;
#include <cstring>
#include <random>

void siftDown(int arr[], int size, int i)
{
    int val = arr[i];
    while (i < size / 2)
    {
        int child = i * 2 + 1;
        if (child + 1 < size && arr[child] < arr[child + 1])
        {
            child = child + 1;
        }
        if (arr[child] > val)
        {
            arr[i] = arr[child];
            i = child;
        }
        else
        {
            break;
        }
    }
}

void HeapSort(int arr[], int size)
{
    int n = size - 1;
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        siftDown(arr, i, size);
    }
    for (int i = n; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        siftDown(arr, 0, i);
    }
}

int main()
{
    srand(time(NULL));
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i]=rand()%100+1;
    }
    for (int v:arr)
    {
        cout << v << " ";
    }
    cout << endl;
    HeapSort(arr, 10);
    for (int v:arr){
        cout << v << " ";
    }
    cout << endl;   

    return 0;
}