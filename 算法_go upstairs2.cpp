#include<stdio.h>

//用结构体定义矩阵
typedef struct
{
    long long m_00; //数值很大long long类型.
    long long m_01;
    long long m_10;
    long long m_11;
} Matrix2By2;

/*------------两个矩阵相乘-----------------*/
Matrix2By2 MatrixMultiply(Matrix2By2 matrix1,Matrix2By2 matrix2)
{
    Matrix2By2 matrix;
    matrix.m_00=matrix1.m_00*matrix2.m_00+matrix1.m_01*matrix2.m_10;
    matrix.m_01=matrix1.m_00*matrix2.m_01+matrix1.m_01*matrix2.m_11;
    matrix.m_10=matrix1.m_10*matrix2.m_00+matrix1.m_11*matrix2.m_10;
    matrix.m_11=matrix1.m_10*matrix2.m_01+matrix1.m_11*matrix2.m_11;
    return matrix;
}
/*------------求矩阵 的N次方--------------*/
Matrix2By2 MatrixPower(unsigned int n)
{
    Matrix2By2 matrix;
    Matrix2By2 matrix_unit; //初始矩阵(1,1,1,0)
    matrix_unit.m_00=(long long)1;
    matrix_unit.m_01=(long long)1;
    matrix_unit.m_10=(long long)1;
    matrix_unit.m_11=(long long)0;
    if(n==1)    //如果是1次方,就是矩阵本身
    {
        matrix.m_00=(long long)1;//要数值转换
        matrix.m_01=(long long)1;
        matrix.m_10=(long long)1;
        matrix.m_11=(long long)0;
    }
    else if(n%2==0) //如果N是偶数,则先开方,再平方
    {
        matrix=MatrixPower(n/2);
        matrix=MatrixMultiply(matrix,matrix);
    }
    else if(n%2==1) //如果N是奇数
    {
        matrix=MatrixPower((n-1)/2);
        matrix=MatrixMultiply(matrix,matrix);
        matrix=MatrixMultiply(matrix,matrix_unit); //最后还要乘以一个初始矩
    }
    return matrix; //返回矩阵
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

