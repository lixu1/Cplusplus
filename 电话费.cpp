#include<iostream> 
#include<cstdio> 
using namespace std; 

int a[10002]; 
int b[10002]; 
int n,s; 
char c[10002]; 
int main() 
{ 
   int i,q,k,u,j,l; 
   while(scanf("%d %d",&n,&s)!=EOF) 
   { 
      scanf("%s",c);//注意字符串不要加取地址符&！！！ 
           for(i=0;i<n;i++) 
           { 
                    a[i]=c[i]-'0'; 
           } 
           q=0;k=0;u=s+1;j=0; 
           while((j<s)&&(k<n-s+1)) 
            { 
                b[k]=a[q]; 
                l=q; 
                for(i=q+1;i<u;i++) 
                     { 
                          if(b[k]>a[i]) 
                          { 
                              if ((l==0)&&(a[i]==0)) continue; 
                              q=i; 
                              b[k]=a[i]; 
                          } 
                      } 
                                      k++; 
            } 

         for(i=0;i<n-s;i++) printf("%d",b[i]); 
         printf("\n"); 
     } 
     return 0; 
} 
