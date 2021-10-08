#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 1000
typedef int ElemType;
typedef struct
{
	ElemType data;  //数据
	int cur;        //游标（Cursor）
}Component, StaticLinkList[MAXSIZE];    //静态链表定义

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
bool InitList(StaticLinkList space)   //静态链表的初始化
{
	int i;
	for (i = 0; i <= MAXSIZE; i++) 
		space[i].cur = i + 1;
		space[MAXSIZE - 1].cur = 0;
		return true;
}

int Malloc_SLL(StaticLinkList space)    //建立新数据点
{
	int i = space[0].cur;
	if (space[0].cur)
	{
		space[0].cur = space[i].cur;
		return i;
	}
	else return 0;
}

int ListInsert(StaticLinkList L, int i, int e)  //在位置i插入结点e
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
		L[j].cur = L[k].cur;   //将新建的结点的浮标指向 i-1位；
		L[k].cur = j;		   //将原来在第i位上的结点的浮标指向新建的结点
		return 1;
	}
	else return 0;
}

int ListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while (i) {
		i = L[i].cur;  //循环找到最后一个  最后一个结点的cur = 0；
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
		k = L[k].cur;  //找到i-1位
	j = L[k].cur;  //
	L[k].cur = L[j].cur;
	Free_SLL(L, j);
	return 1;
}

void Free_SLL(StaticLinkList L, int j)
{
	L[j].cur = L[0].cur;  //将第j位的浮标赋值为第1位的浮标
	L[0].cur = j;   //将第一位浮标指向j
}
