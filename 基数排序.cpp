#include <iostream>
using namespace std;
#include <vector>


// 时间复杂度 O(d*(n+b)) d为最大数的位数，b为桶的个数，n为数组长度
// 空间复杂度 O(n+b) n为数组长度，b为桶的个数 O(n)
// 稳定
void radixSOrt(int arr[],int size){
    int maxData=arr[0];
    for(int i=1;i<size;i++){
        if(maxData<abs(arr[i])){
            maxData=abs(arr[i]);
        }
    }
    int len=to_string(maxData).size();
    vector<vector<int>>vecs;
    int mod=10;
    int dev=1;
    for(int i=0;i<len;i++,mod*=10,dev*=10){
        vector<vector<int>> vecs(20);
        for(int j=0;j<size;j++){
            int index=arr[j] %mod / dev +10;
            vecs[index].push_back(arr[j]);
        }
        int index = 0;
        for (auto vec : vecs)
        {
            for (int v : vec)
            {
                arr[index++] = v;
            }
        }
    }
    vecs.clear();

    
}
void radixSort(int arr[],int size){
    return radixSOrt(arr,size);
};

int main()
{
    srand(time(NULL));
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
    arr[9]=-123;
    for (int v : arr)
    {
        cout << v << " ";
    }
    cout << endl;
    arr[9]=-123;
    radixSort(arr, 10);
    for (int v : arr)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}