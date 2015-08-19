#include<stdio.h>

//�ýṹ�嶨�����
typedef struct
{
    long long m_00; //��ֵ�ܴ�long long����.
    long long m_01;
    long long m_10;
    long long m_11;
} Matrix2By2;

/*------------�����������-----------------*/
Matrix2By2 MatrixMultiply(Matrix2By2 matrix1,Matrix2By2 matrix2)
{
    Matrix2By2 matrix;
    matrix.m_00=matrix1.m_00*matrix2.m_00+matrix1.m_01*matrix2.m_10;
    matrix.m_01=matrix1.m_00*matrix2.m_01+matrix1.m_01*matrix2.m_11;
    matrix.m_10=matrix1.m_10*matrix2.m_00+matrix1.m_11*matrix2.m_10;
    matrix.m_11=matrix1.m_10*matrix2.m_01+matrix1.m_11*matrix2.m_11;
    return matrix;
}
/*------------����� ��N�η�--------------*/
Matrix2By2 MatrixPower(unsigned int n)
{
    Matrix2By2 matrix;
    Matrix2By2 matrix_unit; //��ʼ����(1,1,1,0)
    matrix_unit.m_00=(long long)1;
    matrix_unit.m_01=(long long)1;
    matrix_unit.m_10=(long long)1;
    matrix_unit.m_11=(long long)0;
    if(n==1)    //�����1�η�,���Ǿ�����
    {
        matrix.m_00=(long long)1;//Ҫ��ֵת��
        matrix.m_01=(long long)1;
        matrix.m_10=(long long)1;
        matrix.m_11=(long long)0;
    }
    else if(n%2==0) //���N��ż��,���ȿ���,��ƽ��
    {
        matrix=MatrixPower(n/2);
        matrix=MatrixMultiply(matrix,matrix);
    }
    else if(n%2==1) //���N������
    {
        matrix=MatrixPower((n-1)/2);
        matrix=MatrixMultiply(matrix,matrix);
        matrix=MatrixMultiply(matrix,matrix_unit); //���Ҫ����һ����ʼ��
    }
    return matrix; //���ؾ���
}
/*--------------------------------------*/
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)    //f(0)=0
            printf("1\n");
        else if(n==1)   //f(1)=1
            printf("1\n");
        else
        {
            Matrix2By2 PowerNMinus2=MatrixPower(n-1);
            printf("%lld\n",(PowerNMinus2.m_00+PowerNMinus2.m_01)%100007);
        }
    }
}

