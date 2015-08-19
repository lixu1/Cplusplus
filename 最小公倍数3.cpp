#include<stdio.h>
int main()
{
    unsigned long int i, a, b;
    while(scanf("%d%d", &a, &b) && (a != 0 && b != 0))
    {
        if(a > b)     
        {
            a = a + b;
            b = a - b;
            a = a - b;
        }
        for(i = b;;i+=b)
            if(i % a == 0&&i%b==0)
            {
                printf("%d\n", i);
                break;
            }
    }
}
