#include <iostream>
using namespace std;

#if 0
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
        delete head;
    }

    void insertHead(int val){
       Node *node =new Node(val);
       node->next=head->next;
       node->prev = head;
       if(head->next){
           head->next->prev=node;
       };
       head->next=node;
    }
    void InsterTail(int val){
        Node *node = new Node(val);
        Node *curr =head;
        while(curr->next){
            curr=curr->next;
        }
        curr->next=node;
        node->prev=curr;
    }
    void Remove(int val){
      Node *curr =head->next;
      while(curr){
        if(curr->data==val){
            curr->prev->next=curr->next;
            if(curr->next){
                curr->next->prev=curr->prev;
            }
            delete curr;
            return;
        }
        curr=curr->next;
      }
    }
    void RemoveAll(int val)
    {
        Node *curr = head->next;
        while (curr){
            if(curr->data==val){
                curr->prev->next=curr->next;
                if(curr->next){
                    curr->next->prev=curr->prev;
                }
                Node *temp = curr;
                curr=curr->next;
                delete temp;
            }
            else{
                curr=curr->next;
            }
        }
    }
    bool Find(int val){
        Node*curr =head->next;
        while(curr){
            if(curr->data==val){
                return true;
            }
            curr=curr->next;
        }
        return false;
    }

    void show(){
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
    DoubleLinkedList dlink;
    srand(time(0));
    for(int i=0;i<10;i++){
       dlink.insertHead(rand()%100);
    }
    dlink.show();
    dlink.insertHead(200);
    dlink.show();
    dlink.InsterTail(300);
    dlink.show();
    dlink.Remove(200);
    dlink.show();
    dlink.RemoveAll(300);
    dlink.show();
    cout<<dlink.Find(200)<<endl;
    cout<<dlink.Find(300)<<endl;

    return 0;
}
#endif



struct Node{
    Node(int data=0)
    :data(data)
    ,next(nullptr)
    ,prev(nullptr){
        
    }
    int data;
    Node *next;
    Node *prev;
};

class DoubleLinkedList{
    public:
    DoubleLinkedList(){
        head = new Node();
    }
    ~DoubleLinkedList(){
        Node*curr=head;
        while(curr){
            Node *temp=curr->next;
            delete curr;
            curr=temp;
        }
        delete head;
    }
    void insertHead(int val){
        Node *node =new Node(val);
        node->next=head->next;
        node->prev = head;
        if(head->next){
            head->next->prev=node;
        }
        head->next=node;
    }
    void InsterTail(int val){
        Node *node = new Node(val);
        Node *curr =head->next;
        while(curr->next){
            curr=curr->next;
        }
        curr->next=node;
        node->prev=curr;       
    }
    void Remove(int val){
     Node *curr =head->next;
     while(curr){
        if(curr->data==val){
            curr->prev->next=curr->next;
            if(curr->next){
                curr->next->prev=curr->prev;
            }
            delete curr;
            return;
        }
        curr=curr->next;
        }
    }
    void RemoveAll(int val){
        Node *curr =head->next;
        while(curr){
            if(curr->data==val){
                curr->prev->next=curr->next;
                if(curr->next){
                    curr->next->prev=curr->prev;
                }
                Node *temp = curr;
                curr=curr->next;
                delete temp;
            }
            else{
                curr=curr->next;
            }
        }
    }
    bool Find(int val){
        Node *curr =head->next;
        while(curr){
            if(curr->data==val){
                return true;
            }
            curr=curr->next;
        }
        return false;
    }
    void show(){
        Node *curr =head->next;
        while(curr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
    private:
     Node*head;

};

int main(){
    DoubleLinkedList dlink;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        dlink.insertHead(rand() % 100);
    }
    dlink.show();
    dlink.insertHead(200);
    dlink.show();
    dlink.InsterTail(300);
    dlink.show();
    dlink.Remove(200);
    dlink.show();
    dlink.RemoveAll(300);
    dlink.show();
    cout << dlink.Find(200) << endl;
    cout << dlink.Find(300) << endl;

    return 0;
}