#include<stdio.h>

void main()
{
    int a,b,num1,num2,temp;
    printf("Input a & b:");
    scanf("%d%d",&num1,&num2);
    if(num1>num2)                /*�ҳ��������еĽϴ�ֵ*/
    {
        temp=num1; num1=num2; num2=temp;     /*������������*/
    }
    a=num1; b=num2;
    while(b!=0)             /*����շת����������Լ��*/
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    printf("The GCD of %d and %d is: %d\n",num1,num2,a);  /*������Լ��*/
    printf("The LCM of them is: %d\n",num1*num2/a);       /*�����С������*/
}
