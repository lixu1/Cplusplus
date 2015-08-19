#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int fun(char *s1,char *s2);
int main()
{
   char a[80],b[80];
   int n;
      printf("Please input the first string:");
      gets(a);
      printf("Please input the second string:");
      gets(b);
      n = fun(a,b);
      if(n == 0)
           printf("No find\n");
      else
           printf("n=%d\n",n);
      system("pause");
      return 0;
}
int fun(char *s1,char *s2)
{
    int count = 0;
    int a = strlen(s2);
    char c[80];                                //用 于   存 放  s1每 次 向 后 偏 移 一 位 的 字 符 串
    strcpy(c , s2);                             //此 步 必 须 的，没 有 则 c 中 后 缀 显 示 乱  码
    for(int i = 0 ; i < (strlen(s1)-a+1); i++)   //结 束 条 件 不 是 strlen(s1),仔细体会
    {
            for(int k = 0; k < a ; k++)           //每次循环,s1都向后移位赋值给c字符串
            {
                    c[k] = s1[i + k];
            }
                                                 //puts(c);用于调试c后缀是否有乱码
            if(strcmp(s2 , c) == 0)
            {
                         count++;
            }
    }
    return count;
}
