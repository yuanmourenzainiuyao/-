#include <bits/stdc++.h>
using namespace std;
#define Status int
#define ElemType int

//������Ķ���
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

//��ʼ��
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
    return sum - 1; //��ȥͷ���
}

//��巨
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
        cout << "����λ����Ч";
        return false;
    }
    s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//ɾ������
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
        cout << "ɾ��λ����Ч";
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

/*����ʵ�ֺ���*/

//�����������
void PrintList(LinkList L)
{
    LinkList p = L->next;
    if (ListLength(L))
    {
        cout << "��ǰ�������Ԫ���У�";
        while (p)
        {
            cout << p->data;
            p = p->next;
        }
        cout << endl;
    }
    else
    {
        cout << "��ǰ������Ϊ��";
    }
}

//���뺯��
void Insert(LinkList &L)
{
    int place;
    ElemType e;
    bool flag;
    cout << "������Ҫ�����λ�ü�Ԫ��";
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
    cout << "������Ҫɾ����λ��";
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
    cout << "������Ҫ���ҵ�Ԫ�أ�";
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
    printf("********1.���    2.ɾ��*********\n");
    printf("********3.����    4.���*********\n");
    printf("********5.�˳�          *********\n");
}
//������
int main()
{
    LinkList L;
    int choice;
    InitList(L);
    while (1)
    {
        menu();
        printf("������˵���ţ�\n");
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
            printf("������󣡣���\n");
        }
    }
    return 0;
}
