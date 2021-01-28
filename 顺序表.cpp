#include <bits/stdc++.h>
using namespace std;

#define Elemtype int
#define MaxSize 100
#define Status int

//˳������ݽṹ
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

//��ż���벢����
void SplitSort(Sqlist &L)
{
    int even = 0;           //ż���ĸ���
    int odd = L.length - 1; //�����ĸ���
    int i = 0;
    int j = L.length - 1;
    bool flag = false;
    if (L.length) //���L�ǿ�
        for (; i < j; i++, j--)
        { //�����˿�ʼ����
            while (L.data[i] % 2 != 0)
                i++;
            while (L.data[i] % 2 == 0)
                j--;
            if (L.data[i] % 2 == 0 && L.data[j] % 2 != 0 && i < j)
            {
                int t = L.data[i]; //��������ż�����ұ������������߻�����
                L.data[i] = L.data[j];
                L.data[j] = t;
                flag = true;
            }
            if (!flag)
            { //���û�л���˵��ȫ��ż��
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

//���˳���
void ClearList(Sqlist &L)
{
    L.length = 0;
}

//********************************���ܺ���*****************************************//
//������ܺ��� ��λ�ô�С�������˳�������Ԫ��
void PrintList(Sqlist L)
{
    cout << "��ǰ˳�������Ԫ��";
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i];
    }
}

//����˳���
void Create(Sqlist &L)
{
    int n;
    bool flag;
    cout << "������˳���ĳ��ȣ�";
    cin >> n;
    cout << "������" << n << "�����֣��պŸ���";
    flag = CreateList(L, n);
    if (flag)
    {
        cout << "success";
        PrintList(L);
    }
    else
        cout << "input error";
}

//����Ԫ��
void Insert(Sqlist &L)
{
    int place;
    Elemtype e;
    bool flag;
    cout << "������Ҫ����Ԫ�ص�λ�ü�Ԫ��";
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
    cout << "������Ҫɾ����λ�ã�";
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


//���ҹ��ܺ��� ����LocateElem����Ԫ��
void Search(Sqlist L)
{
	int e; int flag;
	printf("������Ҫ���ҵ�ֵ:\n");
	cin>>e;
	flag = LocateElem(L, e);
	if (flag)
	{
		printf("��Ԫ��λ��Ϊ:%d\n", flag);
	}
	else
		printf("δ�ҵ���Ԫ�أ�\n");
}

void menu()
{
    printf("********1.����                        2.����*********\n");
    printf("********3.ɾ��                        4.����*********\n");
    printf("********5.����                        6.����ż����***\n");
    printf("********7.���                        8.���*********\n");
    printf("********9.�˳�                              *********\n");
}


int main()
{
	Sqlist L; int choice;
	InitList(L);
	while (1)
	{
		menu();
		printf("������˵���ţ�\n");
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
		default:printf("������󣡣���\n");
		}
	}
	return 0;
}