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
    char c[80];                                //�� ��   �� ��  s1ÿ �� �� �� ƫ �� һ λ �� �� �� ��
    strcpy(c , s2);                             //�� �� �� �� �ģ�û �� �� c �� �� ׺ �� ʾ ��  ��
    for(int i = 0 ; i < (strlen(s1)-a+1); i++)   //�� �� �� �� �� �� strlen(s1),��ϸ���
    {
            for(int k = 0; k < a ; k++)           //ÿ��ѭ��,s1�������λ��ֵ��c�ַ���
            {
                    c[k] = s1[i + k];
            }
                                                 //puts(c);���ڵ���c��׺�Ƿ�������
            if(strcmp(s2 , c) == 0)
            {
                         count++;
            }
    }
    return count;
}
