#include<iostream>
#include<fstream>
#include<string>
#include <string.h>

using namespace std;

class Student{
	public:
	char student_id[100];
	char student_name[100];
	char school_name[100];
	char class_name[100];
	char percentage_marks[100];
	char position[100];
};

int get_last_id(){
	return 1;
}

void add_new_student(){
	ofstream student_file("students.dat", ios::out|ios::app);
	
	Student new_std;
	cin.getline(new_std.student_id,100);
	
	
	cout<<"\n\n\t\t\t\t\tADD NEW STUDENT\t\t\t\t\t\n";
	cout<<"\t\t-----------------------------------------------------------------\n";
	cout<<"\t\t Enter student id: ";
	cin.getline(new_std.student_id,100);
	cout<<"\t\t Enter student name: ";
	cin.getline(new_std.student_name,100);
	
	cout<<"\t\t Enter school name: ";
	cin.getline(new_std.school_name,100);
	
	cout<<"\t\t Enter class name: ";
	cin.getline(new_std.class_name,100);
	
	cout<<"\t\t Enter percentage marks[%]: ";
	cin.getline(new_std.percentage_marks, 100);
	
	cout<<"\t\t Enter student position: ";
	cin.getline(new_std.position,100);
	
	//new_std.position[1]='1';
	
	// getting the last id of the student
	//new_std.student_id[1] = '1';
	
	// writing the data to the file
	
    student_file<<new_std.student_id<<"\t"<<new_std.student_name<<"\t"<<new_std.school_name<<"\t"<<new_std.class_name<<"\t"<<new_std.percentage_marks<<"\t"<<new_std.position<<"\n";  
	
	student_file.close();
	
}

void read_all(){
	fstream student_file;
	student_file.open("students.txt", ios::in);
	
	cout<<"\n\n\t\t\t\t\tREADING ALL STUDENTS\t\t\t\t\t\n";
	cout<<"\t\t-----------------------------------------------------------------\n";
	
	Student _student;
	
	ifstream inStudentFile("students.dat");
	
	
	while(inStudentFile >>_student.student_id >> _student.student_name >> _student.school_name >> _student.class_name >> _student.percentage_marks >> _student.position){
	
		cout<<"\t\t Student id   \t\t: \t"<<_student.student_id<<endl<<endl;
		cout<<"\t\t Student name \t\t: \t"<<_student.student_name<<endl<<endl;
		cout<<"\t\t School       \t\t: \t"<<_student.school_name<<endl<<endl;
		cout<<"\t\t Class        \t\t: \t"<<_student.class_name<<endl<<endl;
		cout<<"\t\t marks        \t\t: \t"<<_student.percentage_marks<<endl<<endl;
		cout<<"\t\t position     \t\t: \t"<<_student.position<<endl<<endl;
		cout<<"\t\t-----------------------------------------------------------------\n";
	
	}
	
	
	student_file.close();
}


void search_by_id(){
	
	
	fstream student_file;
	student_file.open("students.dat", ios::in);
	char student_id[100];
	cin.getline(student_id,100);
	int count=0;
	Student _student;
	
	cout<<"\n\n\t\t\t\t\tSEARCHING BY STUDENT ID\t\t\t\t\t\n";
	cout<<"\t\t-----------------------------------------------------------------\n";
	
	cout<<"\t\t Enter student id: ";
	cin.getline(student_id,100);
	
	while(student_file >>_student.student_id >> _student.student_name >> _student.school_name >> _student.class_name >> _student.percentage_marks >> _student.position){
			
		
		if(strcmp(_student.student_id,student_id) == 0) {
				count++;
				cout<<"\n\n\t\t------------------------- RESULTS ------------------------------\n";
				cout<<"\t\t Student id   \t\t: \t"<<_student.student_id<<endl<<endl;
				cout<<"\t\t Student name \t\t: \t"<<_student.student_name<<endl<<endl;
				cout<<"\t\t School       \t\t: \t"<<_student.school_name<<endl<<endl;
				cout<<"\t\t Class        \t\t: \t"<<_student.class_name<<endl<<endl;
				cout<<"\t\t marks        \t\t: \t"<<_student.percentage_marks<<endl<<endl;
				cout<<"\t\t position     \t\t: \t"<<_student.position<<endl<<endl;
				cout<<"\t\t-----------------------------------------------------------------\n";
		}
		

		
	}
	
	if(count == 0) {
		cout<<"\t\t-----------------------------------------------------------------\n";
		cout<<"\t\t\t\t NO RESULTS WITH ID: "<<student_id<<" IS FOUND. \n";
		cout<<"\t\t-----------------------------------------------------------------\n";
	}
	
	student_file.close();
}

void update_student(){
	
	
	cout<<"\n\n\t\t\t\t\tUPDATING STUDENT BY STUDENT ID\t\t\t\t\t\n";
	cout<<"\t\t-----------------------------------------------------------------\n";
	fstream student_file("students.dat",ios::in);
	
	ofstream temp_student_file("temp-students.dat", ios::out|ios::app);
	
	
	char student_id[100];
	cin.getline(student_id,100);
	int count=0;
	
	cout<<"\t\t Enter student id: ";
	cin.getline(student_id,100);
	Student _student;
	
		while(student_file >>_student.student_id >> _student.student_name >> _student.school_name >> _student.class_name >> _student.percentage_marks >> _student.position){
		
		if(strcmp(_student.student_id, student_id) == 0 ) {
			count++;
				
			cout<<"\t\t Enter student id: ";
			cin.getline(_student.student_id,100);
			cout<<"\t\t Enter student name: ";
			cin.getline(_student.student_name,100);
			
			cout<<"\t\t Enter school name: ";
			cin.getline(_student.school_name,100);
			
			cout<<"\t\t Enter class name: ";
			cin.getline(_student.class_name,100);
			
			cout<<"\t\t Enter percentage marks[%]: ";
			cin.getline(_student.percentage_marks, 100);
			
			cout<<"\t\t Enter student position: ";
			cin.getline(_student.position,100);
			temp_student_file<<_student.student_id<<"\t"<<_student.student_name<<"\t"<<_student.school_name<<"\t"<<_student.class_name<<"\t"<<_student.percentage_marks<<"\t"<<_student.position<<"\n";  
	
	
		}
		else if(strcmp(_student.student_id,student_id) != 0)
		{
			temp_student_file<<_student.student_id<<"\t"<<_student.student_name<<"\t"<<_student.school_name<<"\t"<<_student.class_name<<"\t"<<_student.percentage_marks<<"\t"<<_student.position<<"\n";
	
	
		}
	}
	
	if(count == 0) {
		cout<<"\t\t-----------------------------------------------------------------\n";
		cout<<"\t\t\t\t NO ENTRY WITH ID: "<<student_id<<" IS FOUND. \n";
		cout<<"\t\t-----------------------------------------------------------------\n";
	}
	else{
		cout<<"\t\t-----------------------------------------------------------------\n";
		cout<<"\t\t\t\t ENTRY WITH ID: "<<student_id<<" IS UPDATED SUCCESSFULLY. \n";
		cout<<"\t\t-----------------------------------------------------------------\n";
	}
	
	temp_student_file.close();
	student_file.close();
	remove("students.dat");
	rename("temp-students.dat","students.dat");
	
	
	
}



void delete_student(){
	cout<<"\n\n\t\t\t\t\tDELETING A STUDENT BY STUDENT ID\t\t\t\t\t\n";
	cout<<"\t\t-----------------------------------------------------------------\n";
	fstream student_file("students.dat",ios::in);
	
	ofstream temp_student_file("temp-students.dat", ios::out|ios::app);
	
	
	char student_id[100];
	int count=0;
	cin.getline(student_id,100);
	cout<<"\t\t Enter student id: ";
	cin.getline(student_id,100);
	Student _student;
	
	while(student_file >>_student.student_id >> _student.student_name >> _student.school_name >> _student.class_name >> _student.percentage_marks >> _student.position){
		
				
		if(strcmp(_student.student_id, student_id) == 0 ) {
			count++;
	
		}
		else if(strcmp(_student.student_id,student_id) != 0)
		{
			temp_student_file<<_student.student_id<<"\t"<<_student.student_name<<"\t"<<_student.school_name<<"\t"<<_student.class_name<<"\t"<<_student.percentage_marks<<"\t"<<_student.position<<"\n"; 
	
		}
	}
	
	if(count == 0) {
		cout<<"\t\t-----------------------------------------------------------------\n";
		cout<<"\t\t\t\t NO ENTRY WITH ID: "<<student_id<<" IS FOUND. \n";
		cout<<"\t\t-----------------------------------------------------------------\n";
	}
	else{
		cout<<"\t\t-----------------------------------------------------------------\n";
		cout<<"\t\t\t\t ENTRY WITH ID: "<<student_id<<" IS DELETED SUCCESSFULLY. \n";
		cout<<"\t\t-----------------------------------------------------------------\n";
	}
	
	temp_student_file.close();
	student_file.close();
	remove("students.dat");
	rename("temp-students.dat","students.dat");
	
	
	
}

void options(){
		int choise=0;

		cout<<"\t\t-----------------------------------------------------------------\n";
		cout<<"\t\t\t\t\t STUDENT RECORDING SYSTEM \n";
		cout<<"\t\t-----------------------------------------------------------------\n";
		cout<<"\t\t\t1. VIEW ALL STUDENTS \n";
		cout<<"\t\t\t2. ADD NEW STUDENT \n";
		cout<<"\t\t\t3. UPDATE A STUDENT \n";
		cout<<"\t\t\t4. SEARCH A STUDENT \n";
		cout<<"\t\t\t5. DELETE A STUDENT \n";
		cout<<"\t\t\t0. EXIT. \n";
		
		cout<<"\n\n\t\t\tCHOOSE OPTION: \n";
		cin>>choise;
		cout<<endl<<endl;
		
		switch(choise) {
			case 1:
				read_all();
				options();
				break;
			case 2:
				add_new_student();
				options();
				break;
			case 3:
				update_student();
				options();
				break;
			case 4:
				search_by_id();
				options();
				break;
			case 5:
				delete_student();
				options();
				break;
			default:
				cout<<"\n\n\t\t----------------------  THANK YOU FOR USING THIS SYSTEM ------------------------------\n";
				exit(0);
				
		
		}

}


int main(){
	options();
		
	//add_new_student();
		
	//read_all();
	
	//search_by_id();
	
	//update_student();
	
	//delete_student();
	
	return 0;	
}
