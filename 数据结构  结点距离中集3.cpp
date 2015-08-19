#include<stdio.h>
#include<cstdlib>
struct No
{
    int data;
    int parent,pl,pr;
};
int main()
{
    int t;
    int m,n,o,d,q,p;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d",&m);scanf("%d",&n);
         No shu[m+1];int top=-1;
         for(int i=0;i<m+1;i++)shu[i].parent=shu[i].pl=shu[i].pr=shu[i].data=-1;
         for(int i=0;i<m;i++)
         {
              scanf("%d",&o);scanf("%d",&d);
              if(shu[o].data==-1){shu[o].data=o;}
              if(shu[d].data==-1){shu[d].data=d;}
              shu[d].parent=o;
              if(shu[o].pl==-1)shu[o].pl=d;
              else shu[o].pr=d;
         }
         int s[n];
         for(int i=0;i<n;i++)
         {
              scanf("%d",&q);scanf("%d",&p);
              if(p==q){s[i]=0;}
              else
              {
                  s[i]=0;
                  int hold[m],hold1=q,j=-1;bool y=false;
                  while(hold1!=-1){hold[++j]=hold1;hold1=shu[hold1].parent;}hold1=p;
                  while(hold1!=-1){for(int u=0;u<=j;u++)if(hold1==hold[u]){y=true;break;}if(y)break;hold1=shu[hold1].parent;}
                  while(q!=hold1){s[i]++;q=shu[q].parent;}
                  while(p!=hold1){s[i]++;p=shu[p].parent;}
                  //printf("%d\n",hold1);
              }
         }
         for(int i=0;i<n;i++)printf("%d\n",s[i]);
    }
}
