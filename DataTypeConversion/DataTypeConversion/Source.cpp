#include <iostream>
#include <stdint.h>
#include <afx.h>
using namespace std;

CStringA convert1(uint8_t * source, int size)
{
	char q[1000] = {0};
	for (int i = 0; i < size; i++)
	{
		int temp = source[i] - 0x00;
		if (temp / 16>0)
		{
			if (temp / 16 > 9)
				q[3*i]= ('A' + temp / 16 - 10);
			else
				q[3*i] = ('0' + temp / 16);
		}
		else
		{
			q[3*i] = '0';
		}
		temp = temp % 16;
		if (temp > 9)
			q[3*i+1] =  ('A' + temp - 10);
		else
			q[3*i + 1] = ('0' + temp);

		q[3 * i + 2] = ' ';
	}
	//CStringA result(q);
	CStringA result;
	result.Format("%s", q);
	return result;
}

int main()
{
	uint8_t cmd[13] = { 0x2D, 0xF1, 0xB2, 0xA0, 0xE2, 0x01, 0x00, 0x05, 0x00, 0x00, 0x00 };
	CStringA result = convert1(cmd,11);
	cout << result;
}