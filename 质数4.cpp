#include <stdio.h>
#include <math.h>

unsigned int s[100000] = {2};
unsigned int s_i = 1;

inline int is_sushu(unsigned int n)
{
    int m = sqrt(n)+1;
    for (int i=0; s[i]<=m; i++) {
        if (i==s_i)
            return 1;
        if (n%s[i]==0)
            return 0;
    }   
    return 1;
}

int main()
{
    for (int i=3; s_i!=100000; i+=2)
        if (is_sushu(i))
            s[s_i++] = i;
    printf("%d\n", s[99999]);
}
