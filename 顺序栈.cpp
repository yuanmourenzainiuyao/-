#include <bits/stdc++.h>
using namespace std;

#define Status int
#define Elemtype int
#define MaxSize 100

typedef struct Stack
{
    Elemtype *base;
    Elemtype *top;
    int stacksize;
} SqStack;

Status InitStack(SqStack &s)
{
    s.base = new Elemtype[MaxSize];
    if (!s.base)
    {
        cout << "fail";
        return 0;
    }
    else
    {
        s.top = s.base;
        s.stacksize = MaxSize;
        return 1;
    }
}

Status Push(SqStack &s, Elemtype e)
{
    if (s.top - s.base == s.stacksize)
        return 0;
    *(s.top++) = e;
    return 1;
}

Status Pop(SqStack &s, Elemtype e)
{
    if (s.top == s.base)
        return 0;
    e = *--s.top;
    return 1;
}

bool GetTop(SqStack s,Elemtype e)
{
    if (s.top == s.base)
        return false;
    else
    {
        e = *--s.top;
        return true;
    }
}

void menu()
{
    printf("********1.入栈      2.出栈*********\n");
    printf("********3.取栈顶    4.退出*********\n");
}

void PushToStack(SqStack &s)
{

{
	int n;
    Elemtype e;
    int flag;
	cout<<"请输入入栈元素个数";
	cin>>n;
	for(int i=0;i<n;i++)
	{
	 cout<<"请输入第"<<i+1<<"个元素的值:";
	 cin>>e;
	 flag=Push(s,e);
	 if(flag)printf("%d已入栈\n",e);
	 else {printf("栈已满！！！\n");break;}
	}

}
}


void PopFromStack(SqStack &s)
{
    int n;
    Elemtype e;
    int flag;
    cout << "请输入出栈的个数";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        flag = Pop(s, e);
        if (flag)
            cout << e << "已出棧" << endl;
        else
        {
            cout << "栈已空";
        }
    }
}

    void GetTopOfStack(SqStack & s)
    {
        Elemtype e;
        bool flag;
        flag = GetTop(s, e);
        if (flag)
            cout << "栈顶元素为" << e;
        else
            cout << "栈已空";
    }

    int main()
    {
        SqStack s;
        int choice;
        InitStack(s);
        while (1)
        {
            menu();
            printf("请输入菜单序号：\n");
            scanf("%d", &choice);
            if (choice == 4)
                break;
            switch (choice)
            {
            case 1:
                PushToStack(s);
                break;
            case 2:
                PopFromStack(s);
                break;
            case 3:
                GetTopOfStack(s);
                break;
            default:
                printf("输入错误！！！\n");
            }
        }
        return 0;
    }
