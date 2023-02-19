#include<iostream>
#include<string>
#include "Template.h"
#include "Student.h"
#include "Scholar.h"
using namespace std;

Scholar::Scholar(string name, int rollno, int math_mark,int physics_mark,int programming_mark,int scholarship)
:Student(name,rollno,math_mark,physics_mark,programming_mark)
{
	setscholarship(rollno);
}
Scholar::~Scholar(){};

void Scholar::setscholarship(int rollno){
	if(studentrollno<3000){
		scholarship = 50;
	}
	else if(studentrollno>3000 && studentrollno<4000){
		scholarship = 75;
	}
	else{
		scholarship =100;
	}
}
int Scholar::getscholarship() const{
	return scholarship;
}
void Scholar::displayAllDataa(){
	cout<<"\nStudent Name: "<<getStudentName()<<endl;
	cout<<"Student Roll No: "<<getStudentRollNo()<<endl;
	cout<<"Student Scholarship(%): "<<getscholarship()<<endl;
	cout<<"Student Math Mark: "<<getStudentMathMark()<<endl;
	cout<<"Student Physics Mark: "<<getStudentPhysicsMark()<<endl;
	cout<<"Student Programming Mark: "<<getStudentProgrammingMark()<<endl;
	cout<<"Student Grade: "<<getStudentGrade()<<endl;
	cout<<"Student Average Point: "<<StudentAveragePoint(studentmath_mark,studentphysics_mark,studentprogramming_mark)<<endl;
}
