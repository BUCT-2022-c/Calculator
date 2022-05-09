#include "truth_table.h"
using namespace std;
//用二维数组为真值表赋值
int  table2[4][2]= {{0,0},{0,1},{1,0},{1,1}};
int  table3[8][3]= {{0,0,0},{0,0,1},{0,1,0},{1,0,0},
    {0,1,1},{1,0,1},{1,1,0},{1,1,1}
};
int table4[16][4]= {{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,1,0,0},
    {1,0,0,0},{0,0,1,1},{0,1,0,1},{1,0,0,1},
    {0,1,1,0},{1,0,1,0},{1,1,0,0},{0,1,1,1},
    {1,1,0,1},{1,0,1,1},{1,1,1,0},{1,1,1,1}
};
//*"合取",+"析取",!"",>"条件",<"双条件"
int prior(char ch)//确定优先级
{
    switch(ch)
    {
    case '!':
        return 5;
    case '+':
        return 3;
    case '*':
        return 4;
    case '>':
        return 2;
    case '<':
        return 1;
    default:
        return 0;
    }
}
bool isOperator(char ch)//判断是否为运算操作符
{
    switch(ch)
    {
    case '!':
    case '+':
    case '*':
    case '>':
    case '<':
        return true;
    default :
        return false;
    }
}
stack<char>s1;
stack<int>s2;
string getPostfix(string &infix)//中缀表达式转后缀表达式
{
    string postfix;
    while(!s1.empty())s1.pop();
    int i,j,k;
    char tmp;
    for(i=0; i<infix.size(); i++)
    {
        tmp=infix[i];
        if(isOperator(tmp))
        {
            while(!s1.empty()&&isOperator(s1.top())&&prior(s1.top())>=prior(tmp))
            {
                postfix.push_back(s1.top());
                s1.pop();
            }
            s1.push(tmp);
        }
        else if(tmp=='(')
        {
            s1.push(tmp);
        }
        else if(tmp==')')
        {
            while(s1.top()!='(')
            {
                postfix.push_back(s1.top());
                s1.pop();
            }
            s1.pop();
        }
        else if(tmp>='A'&&tmp<='Z')postfix.push_back(tmp);
        else
        {
            printf("请输入合法的表达式\n");
            break;
        }
    }
    while (!s1.empty())
    {
        postfix.push_back(s1.top());
        s1.pop();
    }
    return postfix;
}
int Calculate(const string& postfix)//计算后缀表达式
{
    int  left,right;
    int  flag;
    while(!s2.empty())s2.pop();
    for(int i=0; i<postfix.size(); ++i)
    {
        char c = postfix[i];
        switch (c)
        {
        case '+':
            right=s2.top();
            s2.pop();
            left=s2.top();
            s2.pop();
            if(left==0&&right==0)flag=0;
            else flag=1;
            s2.push(flag);
            break;
        case '*':
            right=s2.top();
            s2.pop();
            left=s2.top();
            s2.pop();
            if(left==1&&right==1)flag=1;
            else flag=0;
            s2.push(flag);
            break;
        case '>':
            right=s2.top();
            s2.pop();
            left=s2.top();
            s2.pop();
            if(left==1&&right==0)flag=0;
            else flag=1;
            s2.push(flag);
            break;
        case '<':
            right=s2.top();
            s2.pop();
            left=s2.top();
            s2.pop();
            if(left==right)flag=1;
            else flag=0;
            s2.push(flag);
            break;
        case '!':
            flag=s2.top();
            s2.pop();
            if(flag==0)flag=1;
            else flag=0;
            s2.push(flag);
            break;
        default:
            s2.push(c-'0');
            break;
        }
    }
    int result = s2.top();
    s2.pop();
    return result;
}
void Print(string &tmp,char name[],int n)//真值表输出
{
    //tmp是中缀式，tmp2是后缀式，n是变量的个数
    string tmp2;
    tmp2=getPostfix(tmp);
    int i,j,k,m;
    m=tmp2.size();//m保存后缀式的长度
    if(n==1)
    {
        printf("%5c",name[0]);
        printf("    ");
        cout<<tmp<<endl;//输出中缀式
        for(j=0; j<2; j++)
        {
            string tmp1=tmp2;//将后缀式赋给临时字符串，用于计算
            printf("%5d",j);
            i=0;
            while(i<m)
            {
                if(tmp1[i]==name[0])tmp1[i]=j+'0';
                i++;
            }
            printf("%5d\n",Calculate(tmp1));
        }
    }
    else if(n==2)
    {
        for(i=0; i<2; i++)printf("%5c",name[i]);
        printf("    ");
        cout<<tmp<<endl;//输出中缀式
        for(j=0; j<4; j++)
        {
            string tmp1=tmp2;//将后缀式赋给临时字符串，用于计算
            for(k=0; k<2; k++)printf("%5d",table2[j][k]);
            i=0;
            while(i<m)
            {
                if(tmp1[i]==name[0])tmp1[i]=table2[j][0]+'0';
                else if(tmp1[i]==name[1])tmp1[i]=table2[j][1]+'0';
                i++;
            }
            printf("%5d\n",Calculate(tmp1));
        }
    }
    else if(n==3)
    {
        for(i=0; i<3; i++)printf("%5c",name[i]);
        printf("    ");
        cout<<tmp<<endl;//输出中缀式
        for(j=0; j<8; j++)
        {
            string tmp1=tmp2;//将后缀式赋给临时字符串，用于计算
            for(k=0; k<3; k++)printf("%5d",table3[j][k]);
            i=0;
            while(i<m)
            {
                if(tmp1[i]==name[0])tmp1[i]=table3[j][0]+'0';
                else if(tmp1[i]==name[1])tmp1[i]=table3[j][1]+'0';
                else if(tmp1[i]==name[2])tmp1[i]=table3[j][2]+'0';
                i++;
            }
            printf("%5d\n",Calculate(tmp1));
        }
    }
    else if(n==4)
    {
        for(i=0; i<4; i++)printf("%5c",name[i]);
        printf("    ");
        cout<<tmp<<endl;//输出中缀式
        for(j=0; j<16; j++)
        {
            string tmp1=tmp2;//将后缀式赋给临时字符串，用于计算
            for(k=0; k<4; k++)printf("%5d",table4[j][k]);
            i=0;
            while(i<m)
            {
                if(tmp1[i]==name[0])tmp1[i]=table4[j][0]+'0';
                else if(tmp1[i]==name[1])tmp1[i]=table4[j][1]+'0';
                else if(tmp1[i]==name[2])tmp1[i]=table4[j][2]+'0';
                else if(tmp1[i]==name[3])tmp1[i]=table4[j][3]+'0';
                i++;
            }
            printf("%5d\n",Calculate(tmp1));
        }
    }
}
bool judge(char name[])//判断变量名是否合法
{
    int i,n=strlen(name);
    if(n>=5)return false;
    for(i=0; i<n; i++)if(name[i]<'A'||name[i]>'Z')return false;
    return true;
}


int truth_table()
{
    int i,n;
    char variablename[10];
    std::cout<<"*********真值表*********"<<std::endl;
    get_time();

    while(1)
    {
        
        printf("请您输入变量名(温馨提示:变量名均为大写字母,变量名之间不能有空格,输入\"q\"退出)\n");
        scanf("%s",variablename);//输入变量名
        if(strcmp(variablename,"q")==0)break;
        n=strlen(variablename);
        if(!judge(variablename))//判断变量名输入是否合法
        {
            printf("表达式不合法或者变量超过四个,请重新输入\n");
            continue;
        }
        write_history tru("truth_table");
        string postfixtmp;
        
        printf("请您输入合法表达式(*表示与,+表示或，!表示非，>表示异或,<表示同或)\n");
        cin>>postfixtmp;
        tru.write_his(postfixtmp);
        Print(postfixtmp,variablename,n);//输出真值表
    }
    return 0;
}


// 参考代码:

// #include <iostream>
// #include <string>
// #include <stack>
// using namespace std;


// int prior(char c)
// {
//     switch (c)
//     {
//     case '+':
//     case '-':
//         return 1;
//     case '*':
//     case '/':
//         return 2;
//     default:
//         return 0;
//     }
// }


// bool isOperator(char c)
// {
//     switch (c)
//     {
//     case '+':
//     case '-':
//     case '*':
//     case '/':
//         return true;
//     default:
//         return false;
//     }
// }


// string getPostfix(const string& expr)
// {
//     string output;  // 输出
//     stack<char> s;  // 操作符栈
//     for(int i=0; i<expr.size(); ++i)
//     {
//         char c = expr[i];
//         if(isOperator(c))
//         {
//             while(!s.empty() && isOperator(s.top()) && prior(s.top())>=prior(c))
//             {
//                 output.push_back(s.top());
//                 s.pop();
//             }
//             s.push(c);
//         }
//         else if(c == '(')
//         {
//             s.push(c);
//         }
//         else if(c == ')')
//         {
//             while(s.top() != '(')
//             {
//                 output.push_back(s.top());
//                 s.pop();
//             }
//             s.pop();
//         }
//         else
//         {
//             output.push_back(c);
//         }
//     }
//     while (!s.empty())
//     {
//         output.push_back(s.top());
//         s.pop();
//     }
//     return output;
// }


// // 从栈中连续弹出两个操作数
// void popTwoNumbers(stack<int>& s, int& first, int& second)
// {
//     first = s.top();
//     s.pop();
//     second = s.top();
//     s.pop();
// }


// // 计算后缀表达式的值


// int Calculate(string& postfix)
// {
//     int first,second;
//     stack<int>s;
//     for(int i=0; i<postfix.size(); ++i)
//     {
//         char c = postfix[i];
//         switch (c)
//         {
//         case '+':
//             popTwoNumbers(s, first, second);
//             s.push(second+first);
//             break;
//         case '-':
//             popTwoNumbers(s, first, second);
//             s.push(second-first);
//             break;
//         case '*':
//             popTwoNumbers(s, first, second);
//             s.push(second*first);
//             break;
//         case '/':
//             popTwoNumbers(s, first, second);
//             s.push(second/first);
//             break;
//         default:
//             s.push(c-'0');
//             break;
//         }
//     }
//     int result = s.top();
//     s.pop();
//     return result;
// }


// int main()
// {
//    string expr = "5+2*(6-3)-4/2";
//     string postfix =getPostfix(expr);
//     int result = Calculate(postfix);
//     cout << "The result is: " << result << endl;
//     return 0;
// }