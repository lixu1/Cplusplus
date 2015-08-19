#include "stdio.h"
#include "malloc.h"
using namespace std;
typedef struct
{
	char data[10000];
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
   bool cunzai=false;
   for(int i=0;i<s1->length;i++)
   {
				if (s1->data[i]=='*') {cunzai=true;break;}
			}
			if(cunzai==false)
			{
				int j=0,k=-1;
				int nextval[s1->length];
				nextval[0]=-1;
				while(j<s1->length)
				{
					if(k==-1||s1->data[j]==s1->data[k])
					{
						j++;k++;
						if(s1->data[j]!=s1->data[k]) nextval[j]=k;
						else nextval[j]=nextval[k];
					}
						else k=nextval[k];
				}
				int i=0;
				j=0;
				while(i<s->length && j<s1->length)
				{
					if(j==-1||s->data[i]==s1->data[j]) {i++;j++;}
					else j=nextval[j];
				}
				if(j>=s1->length)
				flag=true;
				
			}
			else
		 {
			 int i=0,j=0;
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
						else 
						{
							i++;
							if(j>0) j=0;
						}
						if(j==(s1->length-1)&&s1->data[j]=='*') j++;
					}
				}
				if(j>=s1->length) flag=true;
			} 
   	return flag;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	char a[1000];
	scanf("%s",a);
	char *w;
	gets(w);
	char b[10000];
	gets(b);
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
