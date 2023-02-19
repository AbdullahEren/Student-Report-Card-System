#include <string>
#include <iostream>
#ifndef Student_H
#define Student_H
#include "Date.h"  
class Scholar;
using namespace std;
class Student
{
	friend ostream &operator<<(ostream &output, Student &myStudent);
	public:
		explicit Student(const Date &, const Date & );
		explicit Student(string name = "Abdullah", int rollno =4001, int math_mark = 90,int physics_mark = 80,int programming_mark = 80,int scholarship =100);
		~Student();
		void displayAllData();
		int changemarks();
		Student &operator++();
		Student &operator--();
		Student &operator+=(int number);
		
		void print() const; 
		
		void setscholarship(int rollno);
		int getscholarship() const;
		
		void getdata();	
		void showdata() const;
		
		void writedata();
		
		static int getNumberOfStudents();
		static double getAverageGrade();
			
	protected:
		double studentmath_mark,studentphysics_mark,studentprogramming_mark;
		string studentname,studentgrade,grade,name;
		int rollno,physics_mark,programming_mark,math_mark,number,per,studentrollno,scholarship;
		
		const Date FirstEnrollmentDate; 
   		const Date GraduationDate; 
   		
		static int numberOfStudents;
		static double AverageGrade;
		
		int getStudentMathMark() const;
		int getStudentPhysicsMark() const;
		int getStudentProgrammingMark() const;
		void setStudentName(string name);
		void setStudentRollNo(int rollno);
		void setStudentMathMark(int math_mark);
		void setStudentPhysicsMark(int physics_mark);
		void setStudentProgrammingMark(int programming_mark);
		void calculateStudentGrade();
		
		string getStudentName() const;
		int getStudentRollNo() const;
		
		string getStudentGrade() const;
};
#endif
