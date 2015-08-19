/**
*program: Sequence
*huho	first release
*Jay	second release	4, 3 2012
*note: format the code
*/

#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std ;

#define MaxSize 200

typedef int ElemType ;
typedef struct
{
	ElemType data[MaxSize] ;
	int length ;
} SqList;

void InitList(SqList *&L)
{
	L = (SqList*)malloc(sizeof(SqList)) ;
	L->length = 0 ;
}

void DestroyList(SqList *L)
{
	free(L) ;
}

int ListEmpty(SqList *L)
{
	return(L->length == 0) ;
}

int ListLength(SqList *L)
{
	return(L->length) ;
}
int ListDelete(SqList *&L , int i)
{
	int j ;
	if(i < 1 || i > L->length)
		{
			return 0 ;
		}
	i-- ;
	for(j = i ; j < L->length-1 ; j++)
		{
			L->data[j] = L->data[j+1] ;
		}
	L->length-- ;
	return 1 ;
}
void DispList(SqList *L)                //释放顺序表L
{
	int i ;
	if(ListEmpty(L))
		return ;
	for(i = 0 ; i < L->length ; i++)
		cout << L->data[i] << " " ;
	cout << endl ;
}

void MergeList(SqList *La , SqList *Lb , SqList *Lc)    // 合并两个表
{
	Lc->length = La->length + Lb->length ;
	int i = La->length ;
	for(int i = 0 ; i < La->length ; i++)
		{
			Lc->data[i] = La->data[i] ;
		}
	for(int j = 0 ; j < Lb->length ; j++)
		{
			Lc->data[i+j] = Lb->data[j] ;
		}
	DestroyList(La) ;
	DestroyList(Lb) ;
}

void SortList(SqList *L)
{
	ElemType temp ;
	for(int i = 0 ; i < L->length ; i++)
		{
			for(int j = i+1 ; j < L->length ; j++)
				{
					if(L->data[i] > L->data[j])
						{
							temp = L->data[i] ;
							L->data[i] = L->data[j] ;
							L->data[j] = temp ;
						}
				}
		}
}

int main()
{
	int t , a , b , c ;
	cin >> t ;
	while(t--)
		{
			cin >> a >> b >> c ;
			SqList *La , *Lb , *Lc ;
			InitList(La) ;
			InitList(Lb) ;
			InitList(Lc) ;
			La->length = a ;
			Lb->length = b ;
			for(int i = 0 ; i < a ; i++)
				{
					cin >> La->data[i] ;
				}
			for(int i = 0 ; i < b ; i++)
				{
					cin >> Lb->data[i] ;
				}
			MergeList(La , Lb , Lc) ;   //合并La、Lb到Lc
			SortList(Lc) ;              //Lc排序
			ListDelete(Lc , c) ;
			DispList(Lc) ;              //Lc输出
			DestroyList(Lc) ;           //释放Lc
		}
}
