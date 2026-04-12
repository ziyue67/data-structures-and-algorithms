#include <iostream>
using namespace std;

struct Node{
    Node(int data=0)
    :data(data)
    ,next(nullptr)
    ,prev(nullptr){

    }
    int data;
    Node *next;   // 后一个节点指针
    Node *prev; // 前一个节点指针

};

class DoubleLinkedList{
    public:
    DoubleLinkedList(){
        head = new Node();
    }
    ~DoubleLinkedList(){
        //delete head;
        Node *curr =head; // 从头节点开始删除
        while(curr){
            Node *temp=curr->next;
            delete curr;
            curr=temp;
        }
    }

    void insertHead(int val){
       Node *node =new Node(val);
       node->next=head->next;
       if(head->next){
           head->next->prev=node;
       };
       head->next=node;
       node->prev=head;
    }
   
    void print(){
        Node *curr =head->next;
        while(curr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
    private:

    Node *head;
    
};



int main(){
    
}