#include<stdio.h>

void main()
{
    int a,b,num1,num2,temp;
    printf("Input a & b:");
    scanf("%d%d",&num1,&num2);
    if(num1>num2)                /*找出两个数中的较大值*/
    {
        temp=num1; num1=num2; num2=temp;     /*交换两个整数*/
    }
    a=num1; b=num2;
    while(b!=0)             /*采用辗转相除法求最大公约数*/
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    printf("The GCD of %d and %d is: %d\n",num1,num2,a);  /*输出最大公约数*/
    printf("The LCM of them is: %d\n",num1*num2/a);       /*输出最小公倍数*/
}
