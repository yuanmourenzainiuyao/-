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
    printf("********1.��ջ      2.��ջ*********\n");
    printf("********3.ȡջ��    4.�˳�*********\n");
}

void PushToStack(SqStack &s)
{

{
	int n;
    Elemtype e;
    int flag;
	cout<<"��������ջԪ�ظ���";
	cin>>n;
	for(int i=0;i<n;i++)
	{
	 cout<<"�������"<<i+1<<"��Ԫ�ص�ֵ:";
	 cin>>e;
	 flag=Push(s,e);
	 if(flag)printf("%d����ջ\n",e);
	 else {printf("ջ����������\n");break;}
	}

}
}


void PopFromStack(SqStack &s)
{
    int n;
    Elemtype e;
    int flag;
    cout << "�������ջ�ĸ���";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        flag = Pop(s, e);
        if (flag)
            cout << e << "�ѳ���" << endl;
        else
        {
            cout << "ջ�ѿ�";
        }
    }
}

    void GetTopOfStack(SqStack & s)
    {
        Elemtype e;
        bool flag;
        flag = GetTop(s, e);
        if (flag)
            cout << "ջ��Ԫ��Ϊ" << e;
        else
            cout << "ջ�ѿ�";
    }

    int main()
    {
        SqStack s;
        int choice;
        InitStack(s);
        while (1)
        {
            menu();
            printf("������˵���ţ�\n");
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
                printf("������󣡣���\n");
            }
        }
        return 0;
    }
