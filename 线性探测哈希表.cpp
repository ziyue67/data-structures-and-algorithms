// #include <iostream>
// using namespace std;
// #include <vector>
// #include <cstdlib>
// #include <ctime>
// #include <cmath>
// #include <cstring>

// // ══════════════════════════════════════════════════════════════════
// // 线性探测哈希表（按课程原版修正）
// //
// // ★ 对比课程截图，修正了抄写时的 4 处偏差：
// //   [1] tableSize_/table_ 的赋值移出 if（课程第 51-52 行在 if 外）
// //       —— 原来放在 if 里，导致 HashTable ht; 时 table 是野指针 → 段错误
// //   [2] if (primeIdx_ == PRIME_SIZE) primeIdx_--; 移出 for 循环
// //       —— 课程在 for 之后（第 45 行），抄进循环里就是永远不执行的死代码
// //   [3] 素数表最后一个数：3469 → 42773，1741 → 1471（课程第 60 行）
// //   [4] find/erase 的循环条件：TABLE_USING → TABLE_EMPTY
// //       —— 遇"占用的桶"就停是错的，应该遇"真空桶"才停
// //
// // 另外补了：insert 里的重复 key 检查、dump() 调试函数
// // ══════════════════════════════════════════════════════════════════

// // 桶的三种状态（课程里叫 State）
// enum Status
// {
//     TABLE_EMPTY,   // 空
//     TABLE_USING,   // 正在使用
//     TABLE_DELETED  // 已删除（墓碑）
// };

// struct HashNode
// {
//     int key;
//     Status status;
//     HashNode() : key(0), status(TABLE_EMPTY) {}
// };

// class HashTable
// {
// public:
//     HashTable(int size = primes_[0], double loadFactor = 0.75)
//         : table(nullptr), useBuckNum(0), size(size), loadFactor(loadFactor), primeidx_(0)
//     {
//         // 把用户传入的 size 调整到最近的比较大的素数上
//         // ★[1] 注意：课程里这个 if 只负责"找素数下标"，
//         //        真正的赋值和 new 在 if 外面（见下面）
//         if (size != primes_[0])
//         {
//             for (; primeidx_ < PRIME_SIZE; primeidx_++)
//             {
//                 if (primes_[primeidx_] > size)
//                 {
//                     break;
//                 }
//             }
//             // ★[2] 用户传入的 size 值过大，已经超过最后一个素数，调整到最后一个素数
//             //       ★ 这行在 for 循环【外面】，抄进循环里就是死代码
//             if (primeidx_ == PRIME_SIZE)
//             {
//                 primeidx_--;
//             }
//         }

//         // ★[1] 这两行在 if【外面】—— 无论走哪条分支都要执行
//         //      课程原版：tableSize_ = primes_[primeIdx_];  table_ = new Bucket[tableSize_];
//         this->size = primes_[primeidx_];
//         table = new HashNode[this->size];
//     }

//     ~HashTable()
//     {
//         delete[] table;
//         table = nullptr;
//     }

//     // 禁止拷贝（浅拷贝会 double free）
//     HashTable(const HashTable &) = delete;
//     HashTable &operator=(const HashTable &) = delete;

//     bool insert(int key)
//     {
//         double fastor = useBuckNum * 1.0 / size;
//         // cout << "loadFactor:" << fastor << endl;   // 课程里的调试输出，太吵先注释
//         if (fastor > loadFactor)
//         {
//             expand();
//         }

//         int idx = key % size;
//         int i = idx;
//         do
//         {
//             // ★ 重复 key 直接返回，不要重复插入
//             if (table[i].status == TABLE_USING && table[i].key == key)
//             {
//                 return true;
//             }
//             // EMPTY 和 DELETED 都可以放新元素（墓碑位置可复用）
//             if (table[i].status != TABLE_USING)
//             {
//                 table[i].status = TABLE_USING;
//                 table[i].key = key;
//                 useBuckNum++;
//                 return true;
//             }
//             i = (i + 1) % size;
//         } while (i != idx);

//         return false;   // 表满了
//     }

//     bool erase(int key)
//     {
//         int idx = key % size;
//         int i = idx;
//         // ★[4] 循环条件：只要没遇到"真空桶"就继续往后找
//         //   TABLE_EMPTY   → 探测链断了，key 一定不在后面 → 停
//         //   TABLE_DELETED → 墓碑，继续往后找
//         //   TABLE_USING   → 检查是不是目标，继续往后找
//         while (table[i].status != TABLE_EMPTY)
//         {
//             if (table[i].status == TABLE_USING && table[i].key == key)
//             {
//                 table[i].status = TABLE_DELETED;   // 墓碑，不能置 EMPTY
//                 useBuckNum--;
//                 return true;
//             }
//             i = (i + 1) % size;
//             if (i == idx)
//             {
//                 break;      // 绕了一圈
//             }
//         }

//         return false;
//     }

//     bool find(int key)
//     {
//         int idx = key % size;
//         int i = idx;
//         // ★[4] 同上：遇 EMPTY 才停
//         while (table[i].status != TABLE_EMPTY)
//         {
//             if (table[i].status == TABLE_USING && table[i].key == key)
//             {
//                 return true;
//             }
//             i = (i + 1) % size;
//             if (i == idx)
//             {
//                 break;
//             }
//         }

//         return false;
//     }

//     // 打印有效元素（课程原版）
//     void print()
//     {
//         for (int i = 0; i < size; i++)
//         {
//             if (table[i].status == TABLE_USING)
//             {
//                 cout << table[i].key << " ";
//             }
//         }
//         cout << endl;
//     }

//     // ★ 额外加的调试函数：能看到空位和墓碑在哪
//     void dump()
//     {
//         cout << "  [";
//         for (int i = 0; i < size; i++)
//         {
//             if (table[i].status == TABLE_USING)
//             {
//                 cout << " " << table[i].key;
//             }
//             else if (table[i].status == TABLE_DELETED)
//             {
//                 cout << " _";       // 墓碑
//             }
//             else
//             {
//                 cout << " .";       // 空
//             }
//         }
//         cout << " ]  元素=" << useBuckNum << " 容量=" << size << endl;
//     }

//     int getUseBuckNum() const { return useBuckNum; }
//     int getSize() const { return size; }

// private:
//     void expand()
//     {
//         ++primeidx_;
//         if (primeidx_ >= PRIME_SIZE)
//         {
//             throw "hash table is full, cannot expand";
//         }
//         int newSize = primes_[primeidx_];
//         HashNode *newTable = new HashNode[newSize];

//         // 把旧表里的有效元素重新哈希到新表
//         for (int i = 0; i < size; i++)
//         {
//             if (table[i].status == TABLE_USING)
//             {
//                 int idx = table[i].key % newSize;
//                 int k = idx;
//                 do
//                 {
//                     if (newTable[k].status != TABLE_USING)
//                     {
//                         newTable[k].status = TABLE_USING;
//                         newTable[k].key = table[i].key;
//                         break;
//                     }
//                     k = (k + 1) % newSize;
//                 } while (k != idx);
//             }
//         }

//         delete[] table;
//         table = newTable;
//         size = newSize;
//     }

// private:
//     HashNode *table;    // 指向动态开辟的哈希表（课程里叫 table_）
//     int size;           // 哈希表当前的长度（课程里叫 tableSize_）
//     int useBuckNum;     // 已经使用的桶的个数
//     double loadFactor;  // 哈希表的装载因子

//     static const int PRIME_SIZE = 10;  // 素数表的大小
//     static int primes_[PRIME_SIZE];    // 素数表
//     int primeidx_;                     // 当前使用的素数下标
// };

// // ★[3] 按课程截图第 60 行原样抄：最后一个是 42773，不是 3469
// int HashTable::primes_[PRIME_SIZE] = { 3, 7, 23, 47, 97, 251, 443, 911, 1471, 42773 };

// // ══════════════════════════════════════════════════════════════════
// // 测试
// // ══════════════════════════════════════════════════════════════════
// static int g_fail = 0;
// static void check(bool ok, const char *name)
// {
//     cout << (ok ? "  ✅ " : "  ❌ ") << name << endl;
//     if (!ok)
//     {
//         g_fail++;
//     }
// }

// int main()
// {
//     // ─────────────────────────────────────────────
//     cout << "═══ 测试1：课程里的 main（容量 251，不会冲突）═══" << endl;
//     {
//         srand(time(NULL));
//         int arr[10];
//         for (int i = 0; i < 10; i++)
//         {
//             arr[i] = rand() % 100 + 1;
//         }
//         cout << "  随机数: ";
//         for (int v : arr)
//         {
//             cout << v << " ";
//         }
//         cout << endl;

//         HashTable ht(100, 0.75);
//         cout << "  实际容量: " << ht.getSize() << "（第一个 >100 的素数）" << endl;
//         cout << "  ⚠️ 数据 1~100，key%251==key → 永不冲突，测不到探测逻辑" << endl;

//         for (int v : arr)
//         {
//             ht.insert(v);
//         }
//         cout << "  插入后: ";
//         ht.print();
//     }

//     // ─────────────────────────────────────────────
//     cout << "\n═══ 测试2：★制造冲突（容量7，插 1/8/15 都%7==1）═══" << endl;
//     {
//         HashTable ht(4, 0.75);      // 4 → 第一个 >4 的素数 = 7
//         cout << "  容量: " << ht.getSize() << endl;

//         ht.insert(1);    // 1%7=1  → [1]
//         ht.insert(8);    // 8%7=1  → 冲突，探测到 [2]
//         ht.insert(15);   // 15%7=1 → 冲突，探测到 [3]

//         cout << "  内部: ";
//         ht.dump();
//         cout << endl;

//         check(ht.find(1),   "find(1)  → 找到");
//         check(ht.find(8),   "find(8)  → 找到（冲突存的）★[4] 关键");
//         check(ht.find(15),  "find(15) → 找到（冲突存的）");
//         check(!ht.find(99), "find(99) → 未找到");
//     }

//     // ─────────────────────────────────────────────
//     cout << "\n═══ 测试3：★冲突后删除（墓碑不能断链）═══" << endl;
//     {
//         HashTable ht(4, 0.75);
//         ht.insert(1);
//         ht.insert(8);
//         ht.insert(15);

//         cout << "  删除前: ";
//         ht.dump();

//         check(ht.erase(1), "erase(1) → 成功");

//         cout << "  删除后: ";
//         ht.dump();
//         cout << "  （下标 1 变成 _ 墓碑）" << endl << endl;

//         check(!ht.find(1),  "find(1)  → 未找到（已删）");
//         check(ht.find(8),   "find(8)  → 找到（没断链）");
//         check(ht.find(15),  "find(15) → 找到（没断链）");
//         check(ht.insert(22), "insert(22) 复用墓碑位置");
//         check(ht.find(22),  "find(22) → 找到");
//     }

//     // ─────────────────────────────────────────────
//     cout << "\n═══ 测试4：★默认构造 HashTable ht;（原来段错误）═══" << endl;
//     {
//         HashTable ht;       // size 用默认值 primes_[0] = 3
//         check(ht.getSize() == 3, "容量 = 3（★[1] 修复点）");
//         check(ht.insert(5), "插入 5");
//         check(ht.find(5),   "查找 5");
//         cout << "  内部: ";
//         ht.dump();
//     }

//     // ─────────────────────────────────────────────
//     cout << "\n═══ 测试5：★素数值过大的兜底（★[2] 修复点）═══" << endl;
//     {
//         HashTable ht(99999, 0.75);      // 比最后一个素数 42773 还大
//         check(ht.getSize() == 42773, "容量 = 42773（素数表最后一个）");
//         check(ht.insert(1), "能正常插入");
//     }

//     // ─────────────────────────────────────────────
//     cout << "\n═══ 测试6：★重复插入同一个 key ═══" << endl;
//     {
//         HashTable ht(4, 0.75);
//         ht.insert(7);
//         ht.insert(7);
//         ht.insert(7);
//         cout << "  插入 7 三次: ";
//         ht.dump();
//         check(ht.getUseBuckNum() == 1, "只有一个 7（原来变 7 7 7）");
//     }

//     // ─────────────────────────────────────────────
//     cout << "\n═══ 测试7：负载因子扩容 ═══" << endl;
//     {
//         HashTable ht(3, 0.75);
//         cout << "  初始容量: " << ht.getSize() << endl;
//         for (int i = 0; i < 10; i++)
//         {
//             ht.insert(i * 10 + 1);
//         }
//         cout << "  插入 10 个后: " << ht.getSize() << endl;
//         check(ht.getSize() > 3, "容量已扩容");

//         bool allFound = true;
//         for (int i = 0; i < 10; i++)
//         {
//             if (!ht.find(i * 10 + 1))
//             {
//                 allFound = false;
//             }
//         }
//         check(allFound, "扩容后 10 个元素都能找到");
//     }

//     // ─────────────────────────────────────────────
//     cout << "\n═══ 测试8：删除不存在的 key ═══" << endl;
//     {
//         HashTable ht(4, 0.75);
//         ht.insert(1);
//         ht.insert(2);
//         ht.insert(3);
//         int before = ht.getUseBuckNum();
//         check(!ht.erase(99), "erase(99) → false");
//         check(ht.getUseBuckNum() == before, "元素计数没变");
//     }

//     // ─────────────────────────────────────────────
//     cout << "\n════════════════════════════════════" << endl;
//     if (g_fail == 0)
//     {
//         cout << "🎉 全部通过！" << endl;
//     }
//     else
//     {
//         cout << "有 " << g_fail << " 项失败" << endl;
//     }
//     return g_fail;
// }

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// 1. 必须放在最前面，否则类里不认识
// enum State
// {
//     STATE_UNUSE, // 空（老师用的是 UNUSE）
//     STATE_USING, // 正在使用
//     STATE_DEL    // 已删除（墓碑）
// };

// struct Bucket
// {
//     Bucket() : key_(0), state_(STATE_UNUSE) {};
//     int key_;
//     State state_;
// };

// class HashTable
// {
//     // 2. 必须加 public:，否则 main 里访问不了
// public:
//     HashTable(int size = primes_[0], double loadFactor = 0.75)
//         : useBucketNum_(0), loadFactor_(loadFactor), primeIdx_(0)
//     {
//         // 把用户传入的size调整到最近的比较大的素数上
//         if (size != primes_[0])
//         {
//             for (; primeIdx_ < PRIME_SIZE; primeIdx_++)
//             {
//                 if (primes_[primeIdx_] > size)
//                 {
//                     break;
//                 }
//             }
//             // 用户传入的size值过大，已经超过最后一个素数，调整到最后一个素数
//             if (primeIdx_ == PRIME_SIZE)
//             {
//                 primeIdx_--;
//             }
//         }
//         tableSize_ = primes_[primeIdx_];
//         table_ = new Bucket[tableSize_];
//     }

//     // 3. 完全使用你截图5里老师的逻辑
//     bool insert(int key)
//     {
//         // 考虑扩容
//         double factor = useBucketNum_ * 1.0 / tableSize_;
//         if (factor > loadFactor_)
//         {
//             expand();
//         }

//         int idx = key % tableSize_;
//         int i = idx;
//         do
//         {
//             if (table_[i].state_ != STATE_USING) // 老师截图里的核心逻辑
//             {
//                 table_[i].state_ = STATE_USING;
//                 table_[i].key_ = key;
//                 useBucketNum_++;
//                 return true;
//             }
//             i = (i + 1) % tableSize_;
//         } while (i != idx);

//         return false; // 表满了
//     }

//     // 4. 完全使用你截图4里老师的逻辑
//     bool erase(int key)
//     {
//         int idx = key % tableSize_;
//         int i = idx;
//         do
//         {
//             if (table_[i].state_ == STATE_USING && table_[i].key_ == key)
//             {
//                 table_[i].state_ = STATE_DEL;
//                 useBucketNum_--;
//                 return true; // 老师这里应该有 return true
//             }
//             i = (i + 1) % tableSize_;
//         } while (table_[i].state_ != STATE_UNUSE && i != idx);

//         return false;
//     }

//     bool find(int key)
//     {
//         int idx = key % tableSize_;
//         int i = idx;
//         do
//         {
//             if (table_[i].state_ == STATE_USING && table_[i].key_ == key)
//             {
//                 return true;
//             }
//             i = (i + 1) % tableSize_;
//         } while (table_[i].state_ != STATE_UNUSE && i != idx);

//         return false;
//     }

//     // 5. main 里需要的辅助函数
//     int getSize() { return tableSize_; }
//     int getUseBuckNum() { return useBucketNum_; }

//     void print()
//     {
//         for (int i = 0; i < tableSize_; i++)
//         {
//             if (table_[i].state_ == STATE_USING)
//             {
//                 cout << table_[i].key_ << " ";
//             }
//         }
//         cout << endl;
//     }

//     void dump()
//     {
//         for (int i = 0; i < tableSize_; i++)
//         {
//             if (table_[i].state_ == STATE_USING)
//                 cout << table_[i].key_ << " ";
//             else if (table_[i].state_ == STATE_DEL)
//                 cout << "_ ";
//             else
//                 cout << ". ";
//         }
//         cout << endl;
//     }

// private:
//     // 6. 完全使用你截图3里老师的扩容逻辑（这里修复了原代码的严重bug）
//     void expand()
//     {
//         ++primeIdx_;
//         if (primeIdx_ >= PRIME_SIZE)
//         {
//             throw "HashTable is too large, can not expand anymore!";
//         }

//         Bucket *newTable = new Bucket[primes_[primeIdx_]];
//         for (int i = 0; i < tableSize_; i++)
//         {
//             if (table_[i].state_ == STATE_USING)
//             {
//                 int idx = table_[i].key_ % primes_[primeIdx_];
//                 int k = idx;
//                 do
//                 {
//                     if (newTable[k].state_ != STATE_USING)
//                     {
//                         newTable[k].state_ = STATE_USING;
//                         newTable[k].key_ = table_[i].key_;
//                         break;
//                     }
//                     k = (k + 1) % primes_[primeIdx_];
//                 } while (k != idx);
//             }
//         }
//         delete[] table_;
//         table_ = newTable;
//         tableSize_ = primes_[primeIdx_];
//     }

// private:
//     Bucket *table_;
//     int tableSize_;
//     int useBucketNum_;
//     double loadFactor_;
//     int primeIdx_;

//     static const int PRIME_SIZE = 10;
//     static int primes_[PRIME_SIZE];
// };

// int HashTable::primes_[PRIME_SIZE] = {3, 7, 23, 47, 97, 251, 443, 911, 1471, 42773};

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// ⚠️ 必须放在最前面，否则类里不认识！
enum Status
{
    TABLE_EMPTY,  // 空
    TABLE_USING,  // 正在使用
    TABLE_DELETED // 已删除（墓碑）
};

struct Bucket
{
    Bucket() : key(0), status(TABLE_EMPTY) {} // 默认应该是 EMPTY，不能是 USING
    int key;
    Status status;
};

class HashTAble
{
public: // ⚠️ 必须加 public，否则 main 访问不了
    HashTAble(int size = primes_[0], double loadFactor = 0.75)
        : tableSize(0), useBuckNum(0), loadFactor(loadFactor), primeIdx(0)
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

        tableSize = primes_[primeIdx];
        table = new Bucket[tableSize];
    }

    ~HashTAble()
    {
        delete[] table;
        table = nullptr;
    }

    bool insert(int key)
    {
        double fathor = useBuckNum * 1.0 / tableSize;
        if (fathor >= loadFactor)
        {
            expand();
        }
        int idx = key % tableSize; 
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
            i = (i + 1) % tableSize;
        } while (i != idx);
        return false;
    }

    bool erase(int key)
    {
        int idx = key % tableSize;
        int i = idx;
        do
        {
            if (table[i].status == TABLE_USING && table[i].key == key)
            {
                table[i].status = TABLE_DELETED;
                useBuckNum--;
                return true;
            }
            i = (i + 1) % tableSize;
        } while (table[i].status != TABLE_EMPTY && i != idx); 
        return false;
    }

    bool find(int key)
    {
        int idx = key % tableSize;
        int i = idx;
        do
        {
            if (table[i].status == TABLE_USING && table[i].key == key)
            {
                return true;
            }
            i = (i + 1) % tableSize;
        } while (table[i].status != TABLE_EMPTY && i != idx); 
        return false;
    }

    // 5. main 里需要的辅助函数
    int getSize() { return tableSize; }
    int getUseBuckNum() { return useBuckNum; }

    void print()
    {
        for (int i = 0; i < tableSize; i++)
        {
            if (table[i].status == TABLE_USING)
            {
                cout << table[i].key << " ";
            }
        }
        cout << endl;
    }

    void dump()
    {
        for (int i = 0; i < tableSize; i++)
        {
            if (table[i].status == TABLE_USING)
                cout << table[i].key << " ";
            else if (table[i].status == TABLE_DELETED)
                cout << "_ ";
            else
                cout << ". ";
        }
        cout << endl;
    }

private:
    void expand()
    {
        ++primeIdx;
        if (primeIdx >= PRIME_Size)
        {
            throw "HashTable is too large, can not expand anymore!";
        }
        Bucket *newTable = new Bucket[primes_[primeIdx]];
        for (int i = 0; i < tableSize; i++)
        {
            if (table[i].status == TABLE_USING)
            {

                int idx = table[i].key % primes_[primeIdx];
                int k = idx;
                do
                {
                    if (newTable[k].status != TABLE_USING)
                    {                                     // 必须查 newTable
                        newTable[k].status = TABLE_USING; // 必须改 newTable
                        newTable[k].key = table[i].key;   // 必须存 newTable
                        break;
                    }
                    k = (k + 1) % primes_[primeIdx]; 
                } while (k != idx);
            }
        }
        delete[] table;
        table = newTable;
        tableSize = primes_[primeIdx];
    }

private:
    Bucket *table;     // 哈希表指针
    int tableSize;     // 哈希表当前的长度
    int useBuckNum;    // 已经使用的桶的个数
    double loadFactor; // 装载因子
    int primeIdx;      // 素数表下标

    static const int PRIME_Size = 10;
    static int primes_[PRIME_Size]; // 素数表
};
int HashTAble::primes_[PRIME_Size] = {3, 7, 23, 47, 97, 251, 443, 911, 1471, 42773};

// 7. 补全 main 需要的 check 和 g_fail
int g_fail = 0;
void check(bool cond, const string &msg)
{
    if (cond)
        cout << "  [PASS] " << msg << endl;
    else
    {
        cout << "  [FAIL] " << msg << endl;
        ++g_fail;
    }
}

int main()
{
    cout << "═══ 测试1：课程里的 main（容量 251，不会冲突）═══" << endl;
    {
        srand(time(NULL));
        int arr[10];
        for (int i = 0; i < 10; i++)
            arr[i] = rand() % 100 + 1;
        cout << "  随机数: ";
        for (int v : arr)
            cout << v << " ";
        cout << endl;

        // 修复：ht 必须在调用前声明
        HashTAble ht(100, 0.75);
        cout << "  实际容量: " << ht.getSize() << "（第一个 >100 的素数）" << endl;
        cout << "  插入前: ";
        ht.print();

        for (int v : arr)
            ht.insert(v);
        cout << "  插入后: ";
        ht.print();
    }

    cout << "\n═══ 测试2：★制造冲突（容量7，插 1/8/15 都%7==1）═══" << endl;
    {
        HashTAble ht(4, 0.75);
        cout << "  容量: " << ht.getSize() << endl;
        ht.insert(1);
        ht.insert(8);
        ht.insert(15);
        cout << "  内部: ";
        ht.dump();
        check(ht.find(1), "find(1)  → 找到");
        check(ht.find(8), "find(8)  → 找到（冲突存的）★[4] 关键");
        check(ht.find(15), "find(15) → 找到（冲突存的）");
        check(!ht.find(99), "find(99) → 未找到");
    }

    cout << "\n═══ 测试3：★冲突后删除（墓碑不能断链）═══" << endl;
    {
        HashTAble ht(4, 0.75);
        ht.insert(1);
        ht.insert(8);
        ht.insert(15);
        cout << "  删除前: ";
        ht.dump();
        check(ht.erase(1), "erase(1) → 成功");
        cout << "  删除后: ";
        ht.dump();
        check(!ht.find(1), "find(1)  → 未找到（已删）");
        check(ht.find(8), "find(8)  → 找到（没断链）");
        check(ht.find(15), "find(15) → 找到（没断链）");
        check(ht.insert(22), "insert(22) 复用墓碑位置");
        check(ht.find(22), "find(22) → 找到");
    }

    cout << "\n═══ 测试4：★默认构造 HashTable ht;（原来段错误）═══" << endl;
    {
        HashTAble ht;
        check(ht.getSize() == 3, "容量 = 3（★[1] 修复点）");
        check(ht.insert(5), "插入 5");
        check(ht.find(5), "查找 5");
        cout << "  内部: ";
        ht.dump();
    }

    cout << "\n═══ 测试5：★素数值过大的兜底（★[2] 修复点）═══" << endl;
    {
        HashTAble ht(99999, 0.75);
        check(ht.getSize() == 42773, "容量 = 42773（素数表最后一个）");
        check(ht.insert(1), "能正常插入");
    }

    cout << "\n═══ 测试6：★重复插入同一个 key ═══" << endl;
    {
        HashTAble ht(4, 0.75);
        ht.insert(7);
        ht.insert(7);
        ht.insert(7);
        cout << "  插入 7 三次: ";
        ht.dump();
        // ⚠️ 注意：如果老师教的是不去重，这里应该是 3。如果是去重，这里才是 1。
        check(ht.getUseBuckNum() == 3, "插入了 3 个 7（不去重版本）");
    }

    cout << "\n═══ 测试7：负载因子扩容 ═══" << endl;
    {
        HashTAble ht(3, 0.75);
        cout << "  初始容量: " << ht.getSize() << endl;
        for (int i = 0; i < 10; i++)
            ht.insert(i * 10 + 1);
        cout << "  插入 10 个后: " << ht.getSize() << endl;
        check(ht.getSize() > 3, "容量已扩容");
        bool allFound = true;
        for (int i = 0; i < 10; i++)
            if (!ht.find(i * 10 + 1))
                allFound = false;
        check(allFound, "扩容后 10 个元素都能找到");
    }

    cout << "\n═══ 测试8：删除不存在的 key ═══" << endl;
    {
        HashTAble ht(4, 0.75);
        ht.insert(1);
        ht.insert(2);
        ht.insert(3);
        int before = ht.getUseBuckNum();
        check(!ht.erase(99), "erase(99) → false");
        check(ht.getUseBuckNum() == before, "元素计数没变");
    }

    cout << "\n════════════════════════════════════" << endl;
    if (g_fail == 0)
        cout << "🎉 全部通过！" << endl;
    else
        cout << "有 " << g_fail << " 项失败" << endl;
    return g_fail;
}