#include <iostream>
#include <iomanip>
#ifndef SALEPERSON_H_INCLUDED
#define SALEPERSON_H_INCLUDED
using namespace std;
class SalesPerson
{
public:
   static const int monthsPerYear = 12;
   SalesPerson()
   {
      for(int i=0;i<monthsPerYear;i++)
         sales[i]=0.0;
   }
   void getSalesFromUser()
   {
      double salesFigure;
      for(int i=1;i<=monthsPerYear;i++)
      {
         cout<<"Enter sales amount for month "<<i<<": ";
         cin>>salesFigure;
         setSales(i,salesFigure);
      }
   }
   void setSales(int month,double amount)
   {
      if(month>=1 && month<=monthsPerYear && amount>0)
         sales[month-1]=amount;
      else
         cout<<"Invalid month or sales Figure"<<endl;
   }
   void printAnnualSales()
   {
      cout<<setprecision(2)<<fixed<<"\nThe total annual sales are: $"
      <<totalAnnualSales()<<endl;
   }
private:
   double totalAnnualSales()
   {
      double total =0.0;
      for(int i=0;i<monthsPerYear;i++)
      total+=sales[i];
      return total;
   }
   double sales[ monthsPerYear ];
};

#endif // SALEPERSON_H_INCLUDED
