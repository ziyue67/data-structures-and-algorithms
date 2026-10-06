
#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
unsigned int BKRHash(const char *str)
{
    unsigned int hash = 0;
    while (*str)
    {
        hash = hash * 131 + (*str++); // 常见写法，也可以用 31
    }
    return hash;
}

// RSHash (Robert Sedgewick)
unsigned int RSHash(const char *str)
{
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;
    while (*str)
    {
        hash = hash * a + (*str++);
        a *= b;
    }
    return hash;
}

// APHash (Arash Partow)
unsigned int APHash(const char *str)
{
    unsigned int hash = 0xAAAAAAAA;
    unsigned int i = 0;
    while (*str)
    {
        if ((i & 1) == 0)
        {
            hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));
        }
        else
        {
            hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));
        }
        i++;
    }
    return hash;
}
class Bitmap
{
public:
    Bitmap(int bitsize=1471) : bitsize(bitsize)
    {
        bitmap.resize(bitsize / 32 + 1, 0);
    };
    void setBit(const char *str){
        int  idx1=BKRHash(str)%bitsize;
        int  idx2=RSHash(str)%bitsize;
        int idx3 =APHash(str)%bitsize;
        int index = 0;
        int offst = 0;

        index = idx1 / 32;
        offst = idx1 % 32;
        bitmap[index] |=(1<<offst);

        index = idx2 / 32;
        offst = idx2 % 32;
        bitmap[index] |= (1 << offst);

        index = idx3 / 32;
        offst = idx3 % 32;
        bitmap[index] |= (1 << offst);
    }
    bool getbit(const char *str){
        int idx1 = BKRHash(str) % bitsize;
        int idx2 = RSHash(str) % bitsize;
        int idx3 = APHash(str) % bitsize;

        int index = 0;
        int offst = 0;
        index = idx1 / 32;
        offst = idx1 % 32;
        if (0 == (bitmap[index] & (1 << offst)))
        {
            return false;
        }
        index = idx2 / 32;
        offst = idx2 % 32;
        if(0==(bitmap[index] & (1<<offst))){
            return false;
        }
        index = idx3 / 32;
        offst = idx3 % 32;
        if(0==(bitmap[index] & (1<<offst))){
            return false;
        }
        return true;
    }

private:
    vector<int> bitmap;
    int bitsize;
};

class BackHurl
{
public:
    void add(string url)
    {
        bf.setBit(url.c_str()); 
    }

    bool query(string url)
    {
        return bf.getbit(url.c_str());
    }

private:
    Bitmap bf; 
}; 
int main(){
    BackHurl bh;
    bh.add("www.baidu.com");
    bh.add("www.sina.com");
    bh.add("www.qq.com");
    cout<<bh.query("www.baidu.com")<<endl;
    cout<<bh.query("www.sina.com")<<endl;
    cout<<bh.query("www.qq.com")<<endl;
    cout<<bh.query("www.163.com")<<endl;
    return 0;
}