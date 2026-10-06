#include  <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
#include <memory>





int main(){
    vector<int> vec{12 ,78 ,90 ,78 ,123,8 ,9, 90};

    int max=vec[0];
    for(int i=1;i<vec.size();i++){
        if(vec[i]>max){
            max=vec[i];
        }
    }
    int *bitmap=new int[max/32+1];
    unique_ptr<int[]>ptr(bitmap);

    for(auto key:vec){
        int index=key/32;
        int offset=key%32;

        if(0==(bitmap[index] &(1<<offset))){
            bitmap[index]|=(1<<offset);
        }
        else{
            cout<<"重复元素:"<<key<<endl;
        }

    }
    return 0;
}

