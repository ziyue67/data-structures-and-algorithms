#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;
#include <stack>

bool Priority(char ch, char chartop)
{
    if (ch == '(')
    {
        return true;
    }
    if (chartop == '(')
    {
        return ch != ')';
    }
    if ((ch == '*' || ch == '/') && (chartop == '+' || chartop == '-'))
    {
        return true;
    }
    return false;
}

string minddle(string expr)
{
    string result;
    stack<char> s;
    for (char ch : expr)
    {
        if (ch == ' ')
            continue;
        if (ch >= '0' && ch <= '9')
        {
            result.push_back(ch);
        }
        else
        {
            while (true)
            {
                if (s.empty())
                {
                    s.push(ch);
                    break;
                }
                char chartop = s.top();
                if (Priority(ch, chartop))
                {
                    s.push(ch);
                    break;
                }
                else
                {
                    s.pop();
                    if (chartop == '(')
                    {
                        break;
                    }
                    result.push_back(chartop);
                }
            }
        }
    }
    while (!s.empty())
    {
        result.push_back(s.top());
        s.pop();
    }
    return result;
}

int calculate(string pstfix){
    stack<int>s;
    for(char ch:pstfix){
        if(ch>='0' &&ch<='9'){
            s.push(ch-'0');
        }
        else{
            int b=s.top(); s.pop();
            int a=s.top(); s.pop();
            switch(ch){
                case '+': s.push(a+b); break;
                case '-': s.push(a-b); break;
                case '*': s.push(a*b); break;
                case '/': s.push(a/b); break;
            }        }
    }
    return s.top();
}

int main()
{
    string tests[] = {
        "3+4*2/(1-5)",
        "(3+4)*2",
        "8/2+3*4",
        "7-(2+3)*4",
        "1+2*(3-4)/5",
        "((1+2)*3-4)/5",
        "9*8+7-6/3",
        "(5+6)*(7-8)/9",
        "2*3+4*5-6/2",
        "1+(2+3)*(4+5)",
        "(1+2)*(3+4)-5/6"};
    for (const string &e : tests)
    {
        string post = minddle(e);
        cout << e << "  =>  " << post
             << "  =  " << calculate(post) << endl;
    }
    return 0;
}