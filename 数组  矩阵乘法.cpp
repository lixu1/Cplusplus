#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int matrix[1005][1005][12],out[1005][1005],temp[1005][1005];
int p[12],q[12];
int main()
{
   int n;
	bool flag;
	while(scanf("%d",&n)!=EOF)
	{
	    flag=true;
		 scanf("%d%d",&p[0],&q[0]);
		 for(int j=0;j<p[0];j++)
		 {
		     for(int k=0;k<q[0];k++)
           {
               scanf("%d",&matrix[j][k][0]);
		     }
       }
		 for(int i=1;i<n;i++)
		 {
		    scanf("%d%d",&p[i],&q[i]);
          if(p[i]!=q[i-1]) flag=false;
		    for(int j=0;j<p[i];j++)
		    {
               for(int k=0;k<q[i];k++)
               {
                  scanf("%d",&matrix[j][k][i]);
               }
		    }
		 }
		 if(flag)
		 {
		    for(int j=0;j<1005;j++)
            for(int k=0;k<1005;k++)
            temp[j][k]=matrix[j][k][0];
         for(int i=1;i<n;i++)
         {
            for(int j=0;j<p[0];j++)
            {
               for(int k=0;k<q[i];k++)
               {
                  out[j][k]=0;
                  for(int r=0;r<p[i];r++)
                  {
                     out[j][k]+=temp[j][r]*matrix[r][k][i];
                  }
               }
            }
            for(int j=0;j<p[0];j++)
               for(int k=0;k<q[i];k++)
               temp[j][k]=out[j][k];
         }
         for(int i=0;i<p[0];i++)
         {
            printf("%d",out[i][0]);
            for(int j=1;j<q[n-1];j++)
            printf("%d",out[i][j]);
            printf("\n");
         }
		 }
		 else printf("-1\n");
	}
	return 0;
}
