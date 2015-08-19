#include<iostream>
#include "malloc.h"
#include "stdio.h"
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
int StrLength(SqString *s)
{
	return s->length;
}
void StrChange(SqString *&s,SqString *s1,SqString *s2)
{
	int i=0,j=0;
	while(i<s->length)
	{
		while(i<s->length&&j<s1->length)
  {
  	if(s->data[i]==s1->data[j]){i++;j++;}
  	else{j=0;i=i-j+1;}
  }
		if(j>=s1->length)
		{
		   
					i=i-j+1;j=0;
					bool flag=true;
					if(i-2<0)
					{
						if((s->data[i+s1->length-1]<='z'&&s->data[i+s1->length-1]>='a')||
					(s->data[i+s1->length-1]<='Z'&&s->data[i+s1->length-1]>='A'))
					flag=false;
					}
					if(i-2>0&&i+s1->length-1 < s->length)
					{
						if((s->data[i-2]<='z'&&s->data[i-2]>='a')||(s->data[i-2]<='Z'&&s->data[i-2]>='A'))
						{
							if((s->data[i+s1->length-1]<='Z'&&s->data[i+s1->length-1]>='A')||
							(s->data[i+s1->length-1]<='z'&&s->data[i+s1->length-1]>='a'))
							flag=false;
							}
					}
		   if((s1->length==s2->length)&&(flag))
		   {
		      for(int p=0;p<s1->length;p++)
		      s->data[p+i-1]=s2->data[p];
		   }
		   if((s1->length<s2->length)&&(flag))
		   {
		      for(int p=s->length + s2->length - s1->length -1;p>i+ s1->length -1;p--)
		      s->data[p]=s->data[p+ s1->length - s2->length];
		      for(int p=0;p<s2->length;p++)
		      s->data[p+i-1]=s2->data[p];
		      s->length = s->length + s2->length - s1->length;
		   }
		   if((s1->length > s2->length)&&(flag))
		   {
		      for(int p=0;p<s->length - i -  s1->length+1;p++)
		      s->data[p+i+s2->length-1]=s->data[p+i + s1->length-1];
		      for(int p=0;p < s2->length;p++)
		      s->data[p+i-1]=s2->data[p];
		      s->length= s->length + s2->length - s1->length;
		   }
		}
	}
}
void ClearString(SqString *&s)
{
   free(s);
}
void DisplayStr(SqString *s)
{
   for(int i=0;i<s->length;i++)
   cout<<s->data[i];
   cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char a[100];
		char b[100];
		cin>>a;
		cin>>b;
		char c[1000];
		cin.ignore();
		cin.getline(c,1000);
		SqString *s1,*s2,*s;
		InitStr(s1);
		InitStr(s2);
		InitStr(s);
		StrAssign(s1,a);
		StrAssign(s2,b);
		StrAssign(s,c);
		StrChange(s,s1,s2);
		DisplayStr(s);
		ClearString(s);
		ClearString(s1);
		ClearString(s2);



	}
}
