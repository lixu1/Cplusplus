// ReadStruct.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

struct type1{
	int a;
	int b;
	int c;
};
struct type2{
	double a;
	double b;
	double c;
};
struct type3{
	double a;
	double b;
	double c;
	double d;
};
int _tmain(int argc, _TCHAR* argv[])
{
	ifstream input("C:\\Users\\noi\\Desktop\\import.dat", ios_base::in | ios_base::binary);
	ofstream output("C:\\Users\\noi\\Desktop\\output.dat", ios_base::out | ios_base::binary);
	int index = 0;
	while (1)
	{
		cout << index << "\n";
		index++;

		type1 temp1,temp2,temp3;
		type3 temp4,temp5;
		if(!(input >> temp1.a)) break;
		input>> temp1.b >> temp1.c >> temp2.a >> temp2.b >> temp2.c >> temp3.a >> temp3.b >> temp3.c;
		input >> temp4.a >> temp4.b >> temp4.c >> temp4.d >> temp5.a >> temp5.b >> temp5.c >> temp5.d;

		output << temp1.a << "\t" << temp1.b << "\t" << temp1.c << "\t";
		output << temp2.a << " \t" << temp2.b << "\t " << temp2.c << " \t";
		int flag;
		input >> flag;
		int num;
		input >> num;
		while (num--)
		{
			type2 temp3;
			input >> temp3.a >> temp3.b >> temp3.c;
			output << temp3.a << " \t" << temp3.b << "\t " << temp3.c << "\t ";
		}
		output << endl;
	}
}

