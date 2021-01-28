#include <bits/stdc++.h>
using namespace std;

#define Elemtype int
#define MaxSize 100
#define Status int

//顺序表数据结构
typedef struct
{
    Elemtype data[MaxSize];
    int length;
} Sqlist;

Status InitList(Sqlist &L)
{
    memset(L.data, 0, sizeof(L));
    L.length = 0;
    return 0;
}

bool CreateList(Sqlist &L, int n)
{
    if (n < 0 || n > MaxSize)
        false;
    for (int i = 0; i < n; i++)
    {
        cin >> L.data[i];
        L.length++;
    }
    return true;
}

bool InsertList(Sqlist &L, int i, Elemtype e)
{
    if (i < 1 || i < L.length + 1)
    {
        cout << "wrong!";
        return false;
    }
    if (L.length >= MaxSize)
    {
        cout << "FULL!";
        return false;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(Sqlist &L, int i)
{
    if (i < 1 || i > L.length)
    {
        cout << "wrong!";
        return false;
    }
    for (int j = i; j < L.length - 1; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

int LocateElem(Sqlist L, Elemtype e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}

void Reverse(Sqlist &L)
{
    if (L.length)
    {
        for (int i = 0; i < L.length - 1 - i; i++)
        {
            int t = L.data[i];
            L.data[i] = L.data[L.length - 1 - i];
            L.data[L.length - 1 - i] = t;
        }
    }
}

//奇偶分离并排序
void SplitSort(Sqlist &L)
{
    int even = 0;           //偶数的个数
    int odd = L.length - 1; //奇数的个数
    int i = 0;
    int j = L.length - 1;
    bool flag = false;
    if (L.length) //如果L非空
        for (; i < j; i++, j--)
        { //从两端开始遍历
            while (L.data[i] % 2 != 0)
                i++;
            while (L.data[i] % 2 == 0)
                j--;
            if (L.data[i] % 2 == 0 && L.data[j] % 2 != 0 && i < j)
            {
                int t = L.data[i]; //如果左边是偶数。右边是奇数，两边互换。
                L.data[i] = L.data[j];
                L.data[j] = t;
                flag = true;
            }
            if (!flag)
            { //如果没有换，说明全是偶数
                even = L.length - 1;
                odd = 0;
            }
        }
    if (flag)
    {
        for (int i = 0; i < L.length; i++)
            if (L.data[i] % 2 == 0)
            {
                odd = i;
                even = i - 1;
                break;
            }
    }
    sort(L.data, L.data + even + 1);
    sort(L.data + odd, L.data + L.length);
}

//清空顺序表
void ClearList(Sqlist &L)
{
    L.length = 0;
}

//********************************功能函数*****************************************//
//输出功能函数 按位置从小到大输出顺序表所有元素
void PrintList(Sqlist L)
{
    cout << "当前顺序表所有元素";
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i];
    }
}

//创建顺序表
void Create(Sqlist &L)
{
    int n;
    bool flag;
    cout << "请输入顺序表的长度：";
    cin >> n;
    cout << "请输入" << n << "个数字，空号隔开";
    flag = CreateList(L, n);
    if (flag)
    {
        cout << "success";
        PrintList(L);
    }
    else
        cout << "input error";
}

//插入元素
void Insert(Sqlist &L)
{
    int place;
    Elemtype e;
    bool flag;
    cout << "请输入要插入元素的位置及元素";
    cin >> place >> e;
    flag = InsertList(L, place, e);
    if (flag)
    {
        cout << "insert success!";
        PrintList(L);
    }
}

void Delete(Sqlist &L)
{
    int place;
    bool flag;
    cout << "请输入要删除的位置：";
    flag = ListDelete(L, place);
    if (flag)
    {
        cout << "delete success!";
        PrintList(L);
    }
    else
    {
        cout << "do no find";
    }
}


//查找功能函数 调用LocateElem查找元素
void Search(Sqlist L)
{
	int e; int flag;
	printf("请输入要查找的值:\n");
	cin>>e;
	flag = LocateElem(L, e);
	if (flag)
	{
		printf("该元素位置为:%d\n", flag);
	}
	else
		printf("未找到该元素！\n");
}

void menu()
{
    printf("********1.创建                        2.插入*********\n");
    printf("********3.删除                        4.查找*********\n");
    printf("********5.倒置                        6.分奇偶排序***\n");
    printf("********7.输出                        8.清空*********\n");
    printf("********9.退出                              *********\n");
}


int main()
{
	Sqlist L; int choice;
	InitList(L);
	while (1)
	{
		menu();
		printf("请输入菜单序号：\n");
		scanf("%d", &choice);
		if (9 == choice) break;
		switch (choice)
		{
		case 1:Create(L); break;
		case 2:Insert(L); break;
		case 3:Delete(L); break;
		case 4:Search(L); break;
		case 5:Reverse(L); break;
		case 6:SplitSort(L); break;
		case 7:PrintList(L); break;
		case 8:ClearList(L); break;
		default:printf("输入错误！！！\n");
		}
	}
	return 0;
}