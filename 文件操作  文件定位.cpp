#include <iostream> 
#include <stdio.h>
int main()
{   
				FILE *fp1,*fp2;
    fp1=fopen("C:\\Users\\lixu\\�ҵ��ĵ�2\\�ļ���λ����1.txt","r");
     fp2=fopen("C:\\Users\\lixu\\�ҵ��ĵ�2\\�ļ���λ����2.txt","w");
     while(!feof(fp1))  putchar(getc(fp1));
     rewind(fp1);
     while(!feof(fp1))  putc(getc(fp1),fp2);
     fclose(fp1);
     fclose(fp2);
     system("pause");
}
