#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 1000
typedef int ElemType;
typedef struct
{
	ElemType data;  //����
	int cur;        //�α꣨Cursor��
}Component, StaticLinkList[MAXSIZE];    //��̬������

void Free_SLL(StaticLinkList L, int j);
bool InitList(StaticLinkList space);
int Malloc_SLL(StaticLinkList space);
int ListInsert(StaticLinkList L, int i, int e);
int ListLength(StaticLinkList L);
int ListDelete(StaticLinkList L, int i);
int main(void)
{
	return 0;
}
bool InitList(StaticLinkList space)   //��̬����ĳ�ʼ��
{
	int i;
	for (i = 0; i <= MAXSIZE; i++) 
		space[i].cur = i + 1;
		space[MAXSIZE - 1].cur = 0;
		return true;
}

int Malloc_SLL(StaticLinkList space)    //���������ݵ�
{
	int i = space[0].cur;
	if (space[0].cur)
	{
		space[0].cur = space[i].cur;
		return i;
	}
	else return 0;
}

int ListInsert(StaticLinkList L, int i, int e)  //��λ��i������e
{
	int j, k, l;
	k = MAXSIZE - 1;
	if (i<1 || i>ListLength(L))
	{
		return 0;
	}
	j = Malloc_SLL(L);
	if (j)
	{
		L[j].data = e;
		for (l = 1; l <= i - 1; l++);
		k = L[k].cur;
		L[j].cur = L[k].cur;   //���½��Ľ��ĸ���ָ�� i-1λ��
		L[k].cur = j;		   //��ԭ���ڵ�iλ�ϵĽ��ĸ���ָ���½��Ľ��
		return 1;
	}
	else return 0;
}

int ListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while (i) {
		i = L[i].cur;  //ѭ���ҵ����һ��  ���һ������cur = 0��
		j++;
	}
	return j;
}

int ListDelete(StaticLinkList L, int i)
{
	int j, k;
	if (i<1 || i>ListLength(L))
		return 0;
	k = MAXSIZE - 1;
	for (j = 1; j <= i - 1; j++)
		k = L[k].cur;  //�ҵ�i-1λ
	j = L[k].cur;  //
	L[k].cur = L[j].cur;
	Free_SLL(L, j);
	return 1;
}

void Free_SLL(StaticLinkList L, int j)
{
	L[j].cur = L[0].cur;  //����jλ�ĸ��긳ֵΪ��1λ�ĸ���
	L[0].cur = j;   //����һλ����ָ��j
}
