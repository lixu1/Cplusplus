#include <iostream>
using namespace std;
void main()
{
	void avsco(int stunum,float *,float *);//��ƽ���ɼ�
	void good(int stunum,char course[5][10],int num[],float *pscore,float aver[]);//��ƽ���ɼ�90���ϻ������85���ϵ�����
	int i,j,stunum,*pnum,num[100];
	float score[100][5],aver[100],*pscore,*paver;
	char course[5][10],(*pcourse)[10];
	cout<<"input students number:"<<endl;
	cin>>stunum;//ѧ������
	cout<<"input course:"<<endl;
	pcourse = course;
	for( i=0;i<5;i++)
	{
		cin>>course[i];
	}
	cout<<"input NO. and scores:"<<endl;
	cout<<"NO.";
	for( i=0;i<5;i++)
		cout<<"��"<<course[i];
	cout<<endl;
	pscore =&score[0][0];
	pnum=&num[0];
	for(i=0;i<stunum;i++)
	{
		cin>>*(pnum+i);
		for(j=0;j<5;j++)
			cin>>*(pscore+5*i+j);
	}
	paver =&aver[0];
	cout<<endl<<endl;
	avsco(stunum,pscore,paver);
	good(stunum,pcourse,pnum,pscore,paver);
}

void avsco(int stunum,float *pscore,float *paver)
{
	int i,j;
	float sum,average;
	for(i=0;i<stunum;i++)
	{
		sum=0.0;
		for(j=0;j<5;j++)
			sum=sum+(*(pscore+5*i+j));
		average=sum/5;
		*(paver+i)=average;
	}
}

void good(int stunum,char course[100][10],int num[100],float *pscore,float aver[100])
{
	int i,j,k,n;
	cout<<"   ======Students whose score is good====="<<endl;
	cout<<"NO.   ";
	for(i=0;i<5;i++)
		cout<<course[i]<<" ";
	cout<<"  average"<<endl;
	for(i=0;i<stunum;i++)
	{
		n=0;
		for(j=0;j<5;j++)
			if(*(pscore + 5*i+j)>85.0) n++;
		if((n==5)||(aver[i]>=90))
		{
			cout<<num[i]<<"    ";
			for(k=0;k<5;k++)
				cout<<*(pscore+5*i+k)<<"    ";
			cout<<"    "<<aver[i]<<endl;
		}
	}
}

