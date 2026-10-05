#include <iostream>
using namespace std;
#include <cstring>

class  Quene{
    public:
        Quene(int capacity) : front_(0),
                              rear(0),
                              mcapacity(capacity)
        {
            pQuene_ = new int[capacity];
        }
        //  push   front back  size  empty
        void push(int value){
            if((rear +1 ) %mcapacity ==front_){
                expand(2*mcapacity);
            }
            pQuene_[rear]=value;
            rear =(rear +1)%mcapacity;
        }
        int back()const{
            if(rear ==front_){
                throw "Queue is empty";
            }
            return pQuene_[(rear -1 +mcapacity)%mcapacity];
        }

        int front ()const{
            if (front_ == rear)
            {
                throw "Queue is empty";
            }
            return pQuene_[front_];
        }
        bool empty()const{
            return front_ == rear;
        }
        int size()const{
            int size=0;
            for(int i=front_;i!=rear;i=(i+1)%mcapacity){
                size++;
            }
            return size;
        }
        void pop(){
            if (front_ == rear)
            {
                throw "Queue is empty";
            }
            front_ = (front_ + 1) % mcapacity;
        }
    private:
        void expand(int newmcapacity){
            int *newQuene_ = new int[newmcapacity];
            int i = 0;
            int j = front_;
            while (j != rear){
                newQuene_[i++] = pQuene_[j];
                j = (j + 1) % mcapacity;
            }
            delete[] pQuene_;
            pQuene_ = newQuene_;
            front_ = 0;
            rear = i;
            mcapacity = newmcapacity;
        }
        int *pQuene_;
        int front_;
        int rear;
        int mcapacity;
};



int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    Quene q(5);
    for(int v:arr){
        q.push(v);
    }
    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;
    cout << "size: " << q.size() << endl;
    cout << "empty: " << q.empty() << endl;
    q.push(11);
    q.push(12);
    q.push(13);
    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;
    while(!q.empty()){
        cout << q.front() << " "<< q.back() << endl;
        q.pop();
    }
    cout << endl;


    return 0;

}