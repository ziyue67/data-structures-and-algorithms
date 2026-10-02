#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;

class Stacklist
{
public:
    Stacklist():size(0){
        head =new Node(0);
    }
    ~Stacklist(){
        Node *curr =head;
        while(curr){
            Node *temp=curr;
            curr=curr->next;
            delete temp;
        }
    }
    void push(int val){
        Node *node=new Node(val);
        node->next=head->next;
        head->next=node;
        size++;
    }
    void pop(){
        if(head->next==nullptr){
            throw runtime_error("stack is empty");
        }
        Node *temp =head->next;
        head->next=temp->next;
        delete temp;
        size--;
    }
    int top()const{
        if(head->next==nullptr){
            throw runtime_error("stack is empty");
        }
        return head->next->data;
    }
    bool empty()const{
        return head->next==nullptr;
    }
    int siez()const{
        return size;
    }
    struct Node
    {
        int data;
        Node *next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node *head;
    int size;
};

int main()
{
        int arr[]={12 ,4, 56 ,7 ,89, 31, 54 ,75};
        Stacklist s;
        for(int v:arr){
            s.push(v);
        }
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;

    return 0;
}