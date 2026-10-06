#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>
class HashTAble
{

public:
    HashTAble(int size = primes_[0], double loadFactor = 0.75)
        : useBuckNum(0), loadFactor(loadFactor), primeIdx(0)
    {
        if (size != primes_[0])
        {
            for (; primeIdx < PRIME_Size; primeIdx++)
            {
                if (primes_[primeIdx] > size)
                {
                    break;
                }
            }
            if (primeIdx == PRIME_Size)
            {
                primeIdx--;
            }
        }
        table.resize(primes_[primeIdx]);
        tableSize = table.size();
    }
    void insert(int key)
    {
        double factor = useBuckNum * 1.0 / tableSize;
        cout << "factor: " << factor << endl;
        if (factor >= loadFactor)
        {
            expand();
        }
        int idx = key % tableSize;
        if (table[idx].empty())
        {
            useBuckNum++;
            table[idx].push_back(key);
        }
        else
        {
            auto it = ::find(table[idx].begin(), table[idx].end(), key);
            if (it == table[idx].end())
            {
                table[idx].push_back(key);
            }
        }
    }
    void erase(int key)
    {
        int idx = key % tableSize;
        auto it = ::find(table[idx].begin(), table[idx].end(), key);
        if (it != table[idx].end())
        {
            table[idx].erase(it);
            if (table[idx].empty())
            {
                useBuckNum--;
            }
        }
    }
    bool find(int key)
    {
        int idx = key % tableSize;
        auto it = ::find(table[idx].begin(), table[idx].end(), key);
        return it != table[idx].end();
    }

private:
    void expand()
    {
        ++primeIdx;
        if (primeIdx >= PRIME_Size)
        {
            throw "HashTable is too large, can not expand anymore!";
        }
        vector<vector<int>> oldtable;
        swap(oldtable, table);
        table.resize(primes_[primeIdx]);
        tableSize = table.size();
        useBuckNum = 0;
        for (auto & list : oldtable)
        {
            for (auto key : list)
            {
                int idx = key % tableSize;
                if (table[idx].empty())
                {
                    useBuckNum++;
                }
                table[idx].push_back(key);
            }
        }
    }

private:
    vector<vector<int>> table; // 哈希表，二维数组，第一维是桶，第二维是链表
    int tableSize;             // 哈希表的大小
    int useBuckNum;            // 已使用的桶的数量
    double loadFactor;         // 装载因子

    static const int PRIME_Size = 10;
    static int primes_[PRIME_Size]; // 素数表
    int primeIdx;                   // 素数表下标
};
int HashTAble::primes_[PRIME_Size] = {7, 13, 23, 47, 97, 197, 397, 797, 1597, 3203};
int main()
{
    HashTAble ht;
    ht.insert(21);
    ht.insert(32);
    ht.insert(14);
    ht.insert(15);
    ht.insert(22);
    ht.insert(67);

    cout << ht.find(67) << endl; // 输出 1
    ht.erase(67);
    cout << ht.find(67) << endl; // 输出 0
    return 0;
}