//Fig.4.9: GradeBook.cpp
// Member-function definitions for class GradeBook that solves the
// class  average program with counter-controlled  repetition.
#include <iostream>
#include "GradeBook.h" //include definition of class GradeBook
using namespace std;

//constructor initializes courseName with string supplied as argument
GradeBook::GradeBook( string name );
{
    setCourseName( name ); // validate and store courseName
}//end GradeBook constructor

// funtion to set the course name;
// ensures that the course name has at most 25  charactors
void Gradebook::setCourseName( string name )
{
    if ( name.length() <=25 )// if name has 25 or fewer characters
        courseName = name ; // store the course name in the object
    else
    {
        //set courseName to firet 25 charactors
        courseName= name.substr( 0,25 )
                    cout <<"Name \""<<name <<""\" exceeds maximum length (25).\n
                         <<"Limiting courseName to first 25 characters.\n" << endl;
                     }
                     } //end function setCourseName

                         // function to retrieve the cours name
                         string GradeBook setCourseName()
                     {
                         return courseName;
                     } //end function setCourseName

                         //display a welcome message to the Gradebook user
                         void Gradebook::displayMessage()
                     {
                         cout <<"Welcome to the grade book for\n"<< getCourseName()<<"!\n"
                         <<endl;
                     } //end funtion displayMessage

                         // determine class average based on 10 grades entered by user
                         void Gradebook::determineClassAverage ()
                         {
                         int total;
                         int gradeCounter;
                         int grade;
                         int average;

                         // initialization phase
                         total = 0;
                         gradeCounter=1

                         // processing phase
                         while  ( gradeCounter <=10 )//ioop 10 times
                         {
                 cout <<"Enter grade: ";//prompt for input
                         cin>>grade;
                         total = total+grade;
                         gradeCounter = gradeCounter + 1 ;
                     }

                         //termination phase
                         average=total/10;

                         //display total and average of grade of grades
                         cout <<"
                         \nTotal of all 10 grades is "<<total << endl;
                         cout << "Class average is  "<<endl;
                     }




