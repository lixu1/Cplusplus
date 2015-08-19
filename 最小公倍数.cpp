#include <cstdio>
int main()
{
				unsigned long int a,b,c,d,e;
				while(scanf("%d%d",a,b)!=EOF)
				{
					 d=0;
						if(a==0&&b==0) break;
						c=a*b;
						if(a>b) e=a; else e=b;
						for(int i=e;i<=c;i++)
						{if((i%a==0)&&(i%b==0)) 	{d=i;break;}}
						printf("%d\n",d);
				}
				return 0;
}			    
