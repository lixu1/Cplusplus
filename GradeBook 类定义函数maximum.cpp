#include <iostream>
using namespace std;
#include "GradeBook.h"
GradeBook::GradeBook( string name )
{
   setCousdeName( name );
   maximumGrade = 0;
}
void GradeBook;;setCourseName( string name )
{
   if  (name.length() <=25 )
      courseName = name;
   else
   {
      courseName = name.substr( 0,25 );
      cout<< "Name \"" << name << "\" exceeds maximum length (25).\n"
      <<"Limiting courseName to firsd 25 characters.\n"<<   endl;
   }
}
string GradeBook::getCourseName()
{
   return courseName
}
