#include <iostream>

using namespace std;

typedef struct
{
	char ch;
	int pri;
}apri;
apri lpri[]={{'=',0} , {'(',1} , {'*',5}, {'/',5} ,{'+', 3},{'-',3},{')',6}};

apri rpri[]={{'=',0},{'(',6} , {'*',4}, {'/' ,4} ,{'+', 2},{'-',2},{')',1}};

int leftpri(char op)
{
	int i;
	for(i=0;i<7;i++)
	if(lpri[i].ch==op) return lpri[i].pri;
}

int rightpri(char op)
{
	int i;
	for(i=0;i<7;i++)
	{
		if(rpri[i].ch==op) return rpri[i].pri;
	}
}

int InOp(char ch)
{
	if(ch=='('||ch=='+'||ch=='-'||ch=='*'||ch=='/')
	return 1;
	else
	return 0;
}

int Precede(char op1,char op2)
{
	if(leftpri(op1)==rightpri(op2))
	return 0;
	else if(leftpri(op1)<rightpri(op2))
	return -1;
	else 
	return 1;
}

void trans(char *exp,char postexp[])
{
	struct 
	{
		char data[100];
		int  top;
	}op;
	int i=0;
	op.top=-1;
	op.top++;
	op.data[op.top]='=';
	while(*exp!='\0')
	{
		if(!InOp(*exp))
		{
			while(* exp>='0'&& *exp<='9')
			{
				postexp[i++]=*exp;
				exp++;
			}
			postexp[i++]='#';
			
		}
		else 
		switch(Precede(op.data[op.top],*exp))
		{
			case -1:
								op.top++;
								op.data[op.top]=* exp;
								exp++;
								break;
			case 0:
								op.top--;
								exp++;
								break;
			case 1:
								postexp[i++]=op.data[op.top];
								op.top--;
								break;
		}
	}
	while(op.data[op.top]!='=')
	{
		postexp[i++]=op.data[op.top];
		op.top--;
	}
	postexp[i]='\0';
}

float compvalue(char * postexp)
{
	struct 
	{
		float data[100];
		int top;
	}st;
	float d,a,b,c;
	st.top=-1;
	while(*postexp!='\0')
	{
		switch(*postexp)
		{
			case '+':
								a=st.data[st.top];
								st.top--;
								b=st.data[st.top];
								st.top--;
								c=a+b;
								st.top++;
								st.data[st.top]=c;
								break;
			case '-':
								a=st.data[st.top];
								st.top--;
								b=st.data[st.top];
								st.top--;
								c=b-a;
								st.top++;
								st.data[st.top]=c;
								break;
			case '*':
								a=st.data[st.top];
								st.top--;
								b=st.data[st.top];
								st.top--;
								c=a*b;
								st.top++;
								st.data[st.top]=c;
								break;
			case '/':
								a=st.data[st.top];
								st.top--;
								b=st.data[st.top];
								st.top--;
								if(a!=0)
								{
									c=b/a;
									st.top++;
									st.data[st.top]=c;
								}
								else
								{
									cout<<"\n\t除零错误\n";
									exit(0); 
								}
								break;
			default:
											d=0;
											while(*postexp>='0'&&*postexp<='9')
											{
												d=10*d+*postexp-'0';
												postexp++;
											}
											st.top++;
											st.data[st.top]=d;
											break;
		}
		postexp++;
	}
	return (st.data[st.top]);
}


int main()
{
	char exp[]="(56-20)/(4+2)";
	char postexp[100];
	trans(exp,postexp);
	cout<<"中缀表达式是"<<exp<<endl;
	cout<<"后缀表达式是"<<postexp<<endl;
	cout<<"表达式的值"<<compvalue(postexp)<<endl; 
	system("pause");
}
