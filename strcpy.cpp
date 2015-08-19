#include <iostream>
#include <cstring>
using namespace std;

int main( )
{
   char x[] = "Merry Christmas to You";
	  char y[25], z[25];

  	cout << "The string in array x is: " << x
		 << "\nThe string in array y is: " << strcpy(y,x) << '\n';
	  strncpy(z,x,14);  // does not copy null character
	  z[14] = '\0';
	  cout << "The string in array z is: " << z << endl;
	  system("pause");
	  return 0;
}
