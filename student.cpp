#include <iostream>
#include<fstream>
#include <string>
#include <stdexcept>
#include "Student.h"
#include "Scholar.h"
#include "Template.h"
#include "Date.h" 
using namespace std;
int Student::numberOfStudents = 0;
double Student::AverageGrade = 0;
void getdata();
Student::Student(const Date &dateOfEnrollment, const Date &dateOfGraduate ):GraduationDate( dateOfGraduate ), FirstEnrollmentDate( dateOfEnrollment ){};
Student::Student(string name, int rollno, int math_mark,int physics_mark,int programming_mark,int scholarship){
	setStudentName(name);
	setStudentRollNo(rollno);
	setStudentMathMark(math_mark);
	setStudentPhysicsMark(physics_mark);
	setStudentProgrammingMark(programming_mark);
	calculateStudentGrade();
	
	setscholarship(rollno);
	
	numberOfStudents++;
	AverageGrade=(AverageGrade*(numberOfStudents-1) + per)/numberOfStudents;
}
Student::~Student(){}
void Student::displayAllData(){
	cout<<"\nStudent Name: "<<getStudentName()<<endl;
	cout<<"Student Roll No: "<<getStudentRollNo()<<endl;
	cout<<"Student Scholarship(%): "<<getscholarship()<<endl;
	cout<<"Student Math Mark: "<<getStudentMathMark()<<endl;
	cout<<"Student Physics Mark: "<<getStudentPhysicsMark()<<endl;
	cout<<"Student Programming Mark: "<<getStudentProgrammingMark()<<endl;
	cout<<"Student Grade: "<<getStudentGrade()<<endl;
	cout<<"Student Average Point: "<<StudentAveragePoint(studentmath_mark,studentphysics_mark,studentprogramming_mark)<<endl;
}
void Student::setStudentName(string name){
	studentname = name;
}
void Student::setStudentRollNo(int rollno){
	if(rollno>=1000 && rollno<=9999)
	{
		studentrollno = rollno;
	}
	else
	{
		throw invalid_argument("Roll no must be 1000-9999");
	}
	
}
void Student::setStudentMathMark(int math_mark){
	if(math_mark>=0 && math_mark<=100)
	{
		studentmath_mark = math_mark;
	}
	else
	{
		throw invalid_argument("Math mark must be 0-100");
	}
}
void Student::setStudentPhysicsMark(int physics_mark){
	if(physics_mark>=0 && physics_mark<=100)
	{
		 studentphysics_mark = physics_mark;
	}
	else
	{
		throw invalid_argument("Physics mark must be 0-100");
	}
}
void Student::setStudentProgrammingMark(int programming_mark){
	if(programming_mark>=0 && programming_mark<=100)
	{
		studentprogramming_mark = programming_mark;
	}
	else
	{
		throw invalid_argument("Programming mark must be 0-100");
	}
}

string Student::getStudentName() const{
	return studentname;
}
int Student::getStudentRollNo() const{
	return studentrollno;
}
int Student::getStudentMathMark() const{
	return studentmath_mark;
}
int Student::getStudentPhysicsMark() const{
	return studentphysics_mark;
}
int Student::getStudentProgrammingMark() const{
	return studentprogramming_mark;
}
string Student::getStudentGrade() const{
	return studentgrade;
}

void Student::calculateStudentGrade(){
	per = (studentmath_mark+studentphysics_mark+studentprogramming_mark)/3;
	if(per>=80){
		grade='A';
	}
	else if(per>=60){
		grade='B';
	}	
	else if(per>=40){
		grade='C';
	}
	else{
		grade='F';
	}
	studentgrade = grade;			
}

ostream &operator<<(ostream &output, Student &myStudent)
{
	output<<"Student Name: "<<myStudent.studentname
	<<"\nRoll No: "<<myStudent.studentrollno
	<<"\nScholarship(%): "<<myStudent.scholarship
	<<"\nMath Mark: "<<myStudent.studentmath_mark
	<<"\nPhysics Mark: "<<myStudent.studentphysics_mark
	<<"\nProgramming Mark: "<<myStudent.studentprogramming_mark
	<<"\nGrade: "<<myStudent.studentgrade;
	return output;
}

Student &Student::operator++()
{
	AverageGrade = (AverageGrade * numberOfStudents +50)/numberOfStudents;
	per += 5;	
	return *this;
}

Student &Student::operator--()
{
	AverageGrade = (AverageGrade * numberOfStudents - 30)/numberOfStudents;
	per -= 5;
	return *this;
}

Student &Student::operator+=(int number)
{
	AverageGrade = (AverageGrade * numberOfStudents +number)/numberOfStudents;
	per = per + number;
	
	return *this;
}

int Student::getNumberOfStudents()
{
	return numberOfStudents;
}
double Student::getAverageGrade()
{
	return AverageGrade;
}
void Student::print() const
{
   cout <<"\nFirst Enrollment Date: ";
   FirstEnrollmentDate.print();
   cout << endl;
   cout << "\nExpected Graduate Date: ";
   GraduationDate.print();
   cout << endl;
} 
void Student::setscholarship(int rollno){
	scholarship = 100;
}
int Student::getscholarship() const{
	return scholarship;
}

void Student::getdata()
{
	cout<<"\nEnter The roll number of student : ";
	cin>>studentrollno;
	cout<<"\n\nEnter The Name of student : ";
	cin>>studentname;
	cout<<"\nEnter The marks in physics out of 100 : ";
	cin>>studentphysics_mark;
	cout<<"\nEnter The marks in maths out of 100 : ";
	cin>>studentmath_mark;
	cout<<"\nEnter The marks in programming out of 100 : ";
	cin>>studentprogramming_mark;
}
void Student::showdata() const
{
	string StudentList;
	
	ifstream MyFile("StudentRecord.txt");
	
	if (MyFile.is_open())
	{
		while (getline(MyFile, StudentList))
		{
			cout<<StudentList<<endl;
		}
		MyFile.close();	
	}
	else
	{
		cout<<"Unable to open file!";
	}
	cout<<endl;	
}
void Student::writedata(){
	getdata();
	ofstream MyFile("StudentRecord.txt");
	MyFile<<"\n\nStudent rollno: "<<studentrollno<<"\nStudent name: "<<studentname<<"\nPhysics mark: "<<studentphysics_mark<<"\nMath mark: "<<studentmath_mark<<"\nProgramming Mark: "<<studentprogramming_mark;
	MyFile<<"\n\nStudent rollno: "<<3001<<"\nStudent name: "<<"Yunus"<<"\nPhysics mark: "<<55<<"\nMath mark: "<<60<<"\nProgramming Mark: "<<55;
	MyFile<<"\n\nStudent rollno: "<<4001<<"\nStudent name: "<<"Abdullah"<<"\nPhysics mark: "<<80<<"\nMath mark: "<<90<<"\nProgramming Mark: "<<80;
	MyFile<<"\n\nStudent rollno: "<<2001<<"\nStudent name: "<<"Eren"<<"\nPhysics mark: "<<60<<"\nMath mark: "<<75<<"\nProgramming Mark: "<<80;

	cout<<"\nStudents Recorded!!"<<endl;
	MyFile.close();
}

