// #include <iostream>
// #include <cstring>
// #include <stdexcept>
// using namespace std;

// class Stack
// {
// public:
//     Stack(int cap = 10) : mtop(0), mcap(cap)
//     {
//         mpStack = new int[mcap];
//     }

//     ~Stack()
//     {
//         delete[] mpStack;
//         mpStack = nullptr;
//     }

//     void push(int val)
//     {
//         if (mtop == mcap) 
//         {
//             expand(2 * mcap);
//         }
//         mpStack[mtop++] = val;
//     }

//     void pop()
//     {
//         if (mtop == 0)
//         {
//             throw runtime_error("stack is empty");
//         }
//         mtop--;
//     }

//     int top() const
//     {
//         if (mtop == 0)
//         {
//             throw runtime_error("stack is empty");
//         }
//         return mpStack[mtop - 1];
//     }

//     bool empty() const
//     {
//         return mtop == 0;
//     }

//     int size() const
//     {
//         return mtop; 
//     }

// private:
//     void expand(int newCap)
//     {
//         int *newStack = new int[newCap];
//         memcpy(newStack, mpStack, sizeof(int) * mcap);
//         delete[] mpStack;
//         mpStack = newStack;
//         mcap = newCap;
//     }

//     int *mpStack;
//     int mtop;
//     int mcap;
// };

// int main()
// {
//     int arr[]={12 ,4, 56 ,7 ,89, 31, 54 ,75};
//     Stack s;
//     for(int v:arr){
//         s.push(v);
//     }
//     while(!s.empty()){
//         cout<<s.top()<<" ";
//         s.pop();
//     }
//     cout<<endl;
//     return 0;
// }