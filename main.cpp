#include <iostream>
#include <string>
#include "Student.h"
#include "Template.h"
#include "Scholar.h"
using namespace std;
int main(){
	int response,userrollno,number;
	do{
		cout<<"\n1.Search a student graduation and first enrollment date into the system"<<endl;
		cout<<"2.Search a student into the system"<<endl;
		cout<<"3.Change student average grade"<<endl;
		cout<<"4.Add a student to the system"<<endl;
		cout<<"5.Print all students to the system"<<endl;
		cout<<"6.Exit to the system"<<endl;
		cout<<"\nPlease select your option between to (1-6) :";
		cin>>response;
		if(response==1){
			cout<<"Enter a roll no :";
			cin>>userrollno;
			
			if(userrollno==3001){
				Date enrollment1( 24, 9, 2021);
   				Date graduate1( 20, 6, 2025 );
				Student studentdate1(enrollment1,graduate1);
				studentdate1.print();
				Scholar student1("Yunus",3001,60,55,55);
				student1.displayAllDataa();
			}
			else if(userrollno==2001){
				Date enrollment2( 30, 9, 2020 );
   				Date graduate2( 25, 6, 2024 );
				Student studentdate2(enrollment2,graduate2);
				studentdate2.print();
				Scholar student2("Eren",2001,75,60,80);
				student2.displayAllDataa();
			}
			else if(userrollno==4001){
				Date enrollment3( 10, 10, 2017 );
   				Date graduate3( 7, 7, 2021 );
				Student studentdate3(enrollment3,graduate3);
				studentdate3.print();
				Scholar student3;
				student3.displayAllDataa();
			}
			else{
				cout<<"The student with this roll number could not be found..."<<endl;
			}
		}
		else if(response==2){
			cout<<"Enter a roll no :";
			cin>>userrollno;
			
			if(userrollno==3001){
				Scholar student1("Yunus",3001,60,55,55);
				student1.displayAllDataa();
			}
			else if(userrollno==2001){
				Scholar student2("Eren",2001,75,60,80);
				student2.displayAllDataa();
			}
			else if(userrollno==4001){
				Scholar student3;
				student3.displayAllDataa();
			}
			else{
				cout<<"The student with this roll number could not be found..."<<endl;
			}
		}
		else if(response==3){
			cout<<"Please enter a value to increase: ";
			cin>>number;
			Student student1("Yunus",3001,60,55,55);
			Student student2("Eren",2001,75,60,80);
			Student student3;
			cout<<student1<<endl;
			cout<<endl;
			cout<<student2<<endl;
			cout<<endl;
			cout<<student3<<endl;
			cout<<endl;
			cout<<"Average Grade: "<<Student::getAverageGrade()<<endl;
			student1+=number;
			cout<<endl;
			cout<<"Average Grade(increasing operate with response): "<<Student::getAverageGrade()<<endl;
			--student1;
			cout<<"\nAverage Grade(decreasing operate): "<<Student::getAverageGrade()<<endl;
			++student1;
			cout<<"\nAverage Grade(increasing operate): "<<Student::getAverageGrade()<<endl;
		}
		else if(response==4){
			Student student;
			student.writedata();
		}
		else if(response==5){
			Student student;
			student.showdata();
		}	
	}while(response!= 6);
}
