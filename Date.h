#ifndef DATE_H
#define DATE_H

class Date 
{
public:
   static const int monthsPerYear = 12; 
   explicit Date( int d= 1, int m= 1, int y= 1900 ); 
   void print() const; 
   ~Date(); 
private:
   int month; 
   int day; 
   int year; 
   
   int checkDay( int d) const; 
}; 
#endif
