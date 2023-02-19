#ifndef SCHOLAR_H
#define SCHOLAR_H
class Student; 
#include <string>
using namespace std;

class Scholar: public Student{
	
	public:
		explicit Scholar(string name = "Abdullah", int rollno =4001, int math_mark = 90,int physics_mark = 80,int programming_mark = 80,int scholarship =100);
		~Scholar();
		
		void setscholarship(int rollno);
		void displayAllDataa();
		int getscholarship() const;
};

#endif 
