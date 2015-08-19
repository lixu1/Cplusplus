#include "stdio.h"
#include <iostream>
#include "malloc.h"
using namespace std;
typedef struct
{
	char data[1000];
	int length;
}SqString;

void InitStr(SqString *&s)
{
   s=(SqString *)malloc(sizeof(SqString));
   s->length=0;
}

void StrAssign(SqString *&s,char cstr[])
{
	int i;
	for(i=0;cstr[i]!='\0';i++)
	s->data[i]=cstr[i];
	s->length=i;
}
void ClearString(SqString *&s)
{
   free(s);
}
bool SearchStr(SqString *s,SqString *s1)
{
   bool flag=false;
   char a='+';
   for(int i=0;i<s1->length;i++)
   {
      if(s1->data[i]=='*') {a='*';break;}
      if(s1->data[i]=='?') {a='?';break;}
   }
   int i=0,j=0;
   if(a=='+')
   {
				while(i<s->length&&j<s1->length)
   	{
   		if(s->data[i]==s1->data[j]) {i++;j++;}
   		else{i=i-j+1;j=0;}
  		}
  		if(j>=s1->length) {flag=true;}
   	return flag;
			}
			if(a=='?')
			{
				while(i<s->length&&j<s1->length)
   	{
   		if( (s->data[i]==s1->data[j]) || (s1->data[j]==a) ) {i++;j++;}
   		else {i=i-j+1;j=0;}
  		}
  		if(j>=s1->length) {flag=true;}
   	return flag;
			}
			if(a=='*')
			{
				while(i<s->length&&j<s1->length)
				{
					if(s1->data[j]=='*')
					{
						while(s->data[i]!=s1->data[j+1]) {i++;}
						j++;
					}
					else
					{
						if(s->data[i]==s1->data[j]) {i++;j++;}
						else i++;
					}
				}
				if(j>=s1->length) {flag=true;}
   	return flag;
			}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	char a[100];
	scanf("%s",a);
	char b[1000];
	cin.ignore();
	cin.getline(b,1000);
	SqString *s;
	SqString *s1;
	InitStr(s);
	InitStr(s1);
	StrAssign(s,b);
	StrAssign(s1,a);
	if(SearchStr(s,s1))printf("Yes\n");
	else printf("No\n");
	ClearString(s);
	ClearString(s1);
}
}
