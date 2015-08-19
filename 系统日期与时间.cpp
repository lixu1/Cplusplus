#include <iostream>
#include <ctime>
using namespace std;
int main()
{
   time_t now_time;
   now_time=time(NULL);
   time_t const *nowt=&now_time;
   cout<<ctime(nowt);
   return 0;
}
