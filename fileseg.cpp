#include<iostream>
#include<fstream>
using namespace std;

int main(){

	cout<<"Hello world, This is file example \n\n";
	
	char stud_details[100];
	
	cout<<"Enter student name and age: \n";
	cin.getline(stud_details, 100);
	
	ofstream myfile("student-db.txt",ios::out|ios::app);
	if(myfile.is_open()) cout<<"File is open ....\n\n";
	
	// writting to the file
	myfile<<stud_details;
	myfile.close();
	
	cout<<"WRITTING TO THE FILE is successfully"<<endl;
	
	// reading from the file
	
	cout<<"READING FROM THE FILE started .....\n\n";
	ifstream readfile("student-db.txt");
	char students_details[100];
	readfile.getline(students_details, 100);
	
	cout<<"Student content: "<<students_details<<endl<<endl;
	cout<<"READING FROM THE FILE completed ....\n\n";

	return 0;
}
