#include "stdio.h"
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a[n][n];
		int i=0,j=0,w=0;
		bool flag=true;
		for(int s=1;s<=2*n-1;s++)
		{
			if(flag)
			{
				while(i>=0&&j<=n-1)
				{
					a[i][j]=w;w++;
					i--;j++;
				}
				if(i<0&&j>n-1){ i++;j--;i++;}
				else
				{
					if(i<0) i++;
					if(j>n-1) {j--;i++;i++;}
				}
				flag=false;
			}
			else
			{
				while(i<=n-1&&j>=0)
				{
					a[i][j]=w;w++;
					i++;j--;
				}
				if(i>n-1&&j<0) {i--;j++;j++;}
				else
				{
					if(i>n-1){i--;j++;j++;}
					if(j<0) j++;
				}
				flag=true;
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-1;j++)
			printf("%d ",a[i][j]);
			printf("%d\n",a[i][j]);
		} 
	}
}
