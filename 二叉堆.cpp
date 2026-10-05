#include <iostream>
using namespace std;
#include <cstring>
#include <random>
#include <functional>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
// 二叉堆 优先级排列

class PriorityQueue
{
    // 定义一个函数对象类型Comp，用于比较两个整数的优先级
    // push pop top size empty
public:
    using Comp = function<bool(int, int)>;
    PriorityQueue(int cap = 20, Comp comp = greater<int>())
        : size(0), capacity(cap), comp(comp)
    {
        que = new int[capacity];
    }
    PriorityQueue(Comp comp)
        : size(0), capacity(20), comp(comp)
    {
        que = new int[capacity];
    }
    ~PriorityQueue()
    {
        delete[] que;
        que = nullptr;
    }
    void push(int val)
    {
        if (size == capacity)
        {
            int *newQue = new int[capacity * 2];
            memcpy(newQue, que, capacity * sizeof(int));
            delete[] que;
            que = newQue;
            capacity *= 2;
        }

        if (size == 0)
        {
            que[size] = val;
        }
        else
        {
            sifUp(size, val);
        }
        size++;
    }
    void pop()
    {
        if (size == 0)
        {
            throw runtime_error("队列为空");
        }
        int val = que[size - 1];
        size--;
        if (size > 0)
        {
            sifDown(0, que[size]);
        }
    }
    bool empty() const
    {
        return size == 0;
    }
    int top() const
    {
        if (size == 0)
        {
            throw runtime_error("队列为空");
        }
        return que[0];
    }
    int getSize() const
    {
        return size;
    }

private:
    void sifDown(int i, int val)
    {
        while (i <= size / 2)
        {
            int child = i * 2 + 1;
            if (child + 1 < size && comp(que[child], que[child + 1]))
            {
                child = child + 1;
            }
            if (comp(val, que[child]))
            {
                que[i] = que[child];
                i = child;
            }
            else
            {
                break;
            }
            que[i] = val;
        }
    }
    void sifUp(int i, int val)
    {
        while (i > 0)
        {
            int father = (i - 1) / 2;
            if (comp(que[father], val))
            {
                que[i] = que[father];
                i = father;
            }
            else
            {
                break;
            }
        }
        que[i] = val;
    }

private:
    int *que;
    int size;
    int capacity;
    Comp comp;
};

int main()
{
    PriorityQueue qu;
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        qu.push(rand() % 100);
    }
    while (!qu.empty())
    {
        cout << qu.top() << " ";
        qu.pop();
    }
    cout << endl;

    return 0;
}