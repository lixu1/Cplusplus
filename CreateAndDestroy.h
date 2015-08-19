#include <iostream>
#ifndef CREATEANDDESTROY_H_INCLUDED
#define CREATEANDDESTROY_H_INCLUDED
using namespace std;
class CreateAndDestroy
{
public:
   CreateAndDestroy(int ID,string messageString )
   {
      objectID=ID;
      message=messageString;
      cout<<"Object "<<objectID<<"   constructor runs   "<<message<<endl;
   }
   ~CreateAndDestroy()
   {
      cout<<( objectID==1 || objectID==6 ? "\n":" ");
      cout<<"Object "<<objectID<<"   destructor runs   "<<message<<endl;
   }
private:
   int objectID;
   string message;
};


#endif // CREATEANDDESTROY_H_INCLUDED
