#include"stdio.h"
int main()
{
    double p1,p2,p3;
    while(scanf("%lf%lf%lf",&p1,&p2,&p3)!=EOF)
    {
        double ans=p3*p1/(p3*p1+(1-p3)*(1-p2));
        printf("%.3lf\n",ans);
    }

}

