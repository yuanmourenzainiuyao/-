#include <bits/stdc++.h>
using namespace std;
#define Status int
#define ElemType int

//单链表的定义
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

//初始化
Status InitList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
    return 1;
}

int ListLength(LinkList L)
{
    LinkList p = L;
    int sum = 0;
    while (p)
    {
        sum++;
        p = p->next;
    }
    return sum - 1; //减去头结点
}

//后插法
bool InsertList(LinkList &L, int i, ElemType e)
{
    LNode *s;
    LinkList p = L;
    int j = 0;
    while (p || j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
    {
        cout << "插入位置无效";
        return false;
    }
    s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//删除函数
bool ListDelete(LinkList &L, int i)
{
    LNode *s;
    LinkList p = L;
    int j = 0;
    LinkList q;
    while (p && (j < i - 1))
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
    {
        cout << "删除位置无效";
        return false;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L;
    while (p && (p->data != e))
    {
        p = p->next;
    }
    return p;
}

/*功能实现函数*/

//遍历输出函数
void PrintList(LinkList L)
{
    LinkList p = L->next;
    if (ListLength(L))
    {
        cout << "当前单链表的元素有：";
        while (p)
        {
            cout << p->data;
            p = p->next;
        }
        cout << endl;
    }
    else
    {
        cout << "当前单链表为空";
    }
}

//插入函数
void Insert(LinkList &L)
{
    int place;
    ElemType e;
    bool flag;
    cout << "请输入要插入的位置及元素";
    cin >> place >> e;
    flag = InsertList(L, place, e);
    if (flag)
    {
        cout << "insert success";
        PrintList(L);
    }
    else
    {
        cout << "error";
    }
}

void Delete(LinkList &L)
{
    int place;
    bool flag;
    cout << "请输入要删除的位置";
    cin >> place;
    flag = ListDelete(L, place);
    if (flag)
    {
        cout << "delete success";
        PrintList(L);
    }
    else
    {
        cout << "error";
    }
}

void Search(LinkList L)
{
    ElemType e;
    LNode *q;
    cout << "请输入要查找的元素：";
    cin >> e;
    q = LocateElem(L, e);
    if (q)
    {
        cout << "find success";
    }
    else
    {
        cout << "find error";
    }
}

void menu()
{
    printf("********1.后插    2.删除*********\n");
    printf("********3.查找    4.输出*********\n");
    printf("********5.退出          *********\n");
}
//主函数
int main()
{
    LinkList L;
    int choice;
    InitList(L);
    while (1)
    {
        menu();
        printf("请输入菜单序号：\n");
        scanf("%d", &choice);
        if (choice == 5)
            break;
        switch (choice)
        {
        case 1:
            Insert(L);
            break;
        case 2:
            Delete(L);
            break;
        case 3:
            Search(L);
            break;
        case 4:
            PrintList(L);
            break;
        default:
            printf("输入错误！！！\n");
        }
    }
    return 0;
}
