#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
// 线性探测哈希表
enum Status
{
    TABLE_EMPTY,
    TABLE_USING,
    TABLE_DELETED
};

struct HashNode
{
    int key;
    Status status;
    HashNode() : key(0), status(TABLE_EMPTY) {}
};

class HashTable
{
public:
    HashTable(int size = primes_[0], double loadFactor = 0.75)
        : useBuckNum(0), size(size), primeidx_(0), loadFactor(loadFactor)
    {
        // 用户穿入的size调整到比较大的素数上
        if (size != primes_[0])
        {
            static const int PRIME_SIZE = 10; // 素数表大小
            for (; primeidx_ < PRIME_SIZE; primeidx_++)
            {
                if (primes_[primeidx_] > size)
                {
                    size = primes_[primeidx_];
                    break;
                }
                if (primeidx_ == PRIME_SIZE)
                {
                    primeidx_--;
                }
            }
            this->size = size;                // ← 补这行
            table = new HashNode[this->size]; // ← 补这行
        }

    }
    ~HashTable()
    {
        delete[] table;
        table = nullptr;
    }
    bool insert(int key)
    {
        double fastor = useBuckNum * 1.0 / size;
        cout << "loadFactor:" << fastor << endl;
        if (fastor > loadFactor)
        {
            expand();
        }

        int idx = key % size;
        int i = idx;
        do
        {
            if (table[i].status != TABLE_USING)
            {
                table[i].status = TABLE_USING;
                table[i].key = key;
                useBuckNum++;
                return true;
            }
            i = (i + 1) % size;
        } while (i != idx);

        return false;
    }
    bool erase(int key)
    {
        int idx = key % size;
        int i = idx;
        do
        {
            if (table[i].status == TABLE_USING && table[i].key == key)
            {
                table[i].status = TABLE_DELETED;
                useBuckNum--;
                return true;
            }
            i = (i + 1) % size;
        } while (table[i].status != TABLE_USING && i != idx);

        return false;
    }
    bool find(int key)
    {
        int idx = key % size;
        int i = idx;
        do
        {
            if (table[i].status == TABLE_USING && table[i].key == key)
            {
                return true;
            }
            i = (i + 1) % size;
        } while (table[i].status != TABLE_USING && i != idx);

        return false;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            if (table[i].status == TABLE_USING)
            {
                cout << table[i].key << " ";
            }
        }
        cout << endl;
    }

private:
    void expand()
    {
        ++primeidx_;
        if (primeidx_ >= PRIME_SIZE)
        {
            throw "hash table is full, cannot expand";
        }
        int newSize = primes_[primeidx_];
        HashNode *newTable = new HashNode[newSize];
        for (int i = 0; i < size; i++)
        {
            if (table[i].status == TABLE_USING)
            {
                int idx = table[i].key % newSize;
                int k = idx;
                do
                {
                    if (newTable[k].status != TABLE_USING)
                    {
                        newTable[k].status = TABLE_USING;
                        newTable[k].key = table[i].key;
                        break;
                    }
                    k = (k + 1) % newSize;
                } while (k != idx);
            }
        }
        delete[] table;
        table = newTable;
        size = newSize;
        
    
        // if (primeidx_ == PRIME_SIZE - 1)
        // {
        //     cout << "哈希表已满，无法扩容" << endl;
        //     return;
        // }
        // int newSize = primes_[++primeidx_];
        // HashNode *newTable = new HashNode[newSize];
        // memcpy(newTable, table, sizeof(HashNode) * size);
        // delete[] table;
        // table = newTable;
        // size = newSize;
    }
   
private:
    HashNode *table;   // 哈希表数组
    int size;          // 哈希表大小
    int useBuckNum;    // 已使用的桶数量
    double loadFactor; // 负载因子

    static const int PRIME_SIZE = 10; // 素数表大小
    static int primes_[PRIME_SIZE];   // 素数表
    int primeidx_;                    // 当前素数表索引
};
int HashTable::primes_[PRIME_SIZE] = {3, 7, 23, 47, 97, 251, 443, 911, 1741, 3469};


int main()
{
    srand(time(NULL));
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
    for (int v : arr)
    {
        cout << v << " ";
    }
    cout << endl;
    HashTable ht(100, 0.75);
    for (int v : arr)
    {
        ht.insert(v);
    }
    ht.print();
    ht.erase(50);
    ht.print();
    cout << "查找 50: " << (ht.find(50) ? "找到" : "未找到") << endl;
}