#include<iostream>
#include<cstring>
#include<stdio.h>
#include<string.h>
#include<stack>
#include<fstream>
#include <string>

using namespace std;

class Account{
	public:
		char account_id[100];
		char account_name[100];
		char bank_name[100];
		char account_number[100];
		char login_id[100];
		
};


class Deposit{
	public:
		int deposit_id;
		int account_number;
		float amount;
		char deposited_at[100];
};

int get_latest_id(){
	ifstream account_file("accounts.txt", ios::in);
	
	Account account;
	
	stack<int> id_stack;
	
	while(account_file >> account.account_id >> account.account_name >> account.bank_name >> account.account_number >> account.login_id) {
		id_stack.push(stoi(account.account_id));
	}	
	
	cout<<"Last id: "<<id_stack.top();
	
	return 0;
	
}

void save_account(){

	ofstream account_file("accounts.dat", ios::out|ios::app);
	
	Account account;
	
	cout<<"\t\t Enter account id: ";
	cin.getline(account.account_id,100);
	
	cout<<"\t\t Enter account name: ";
	cin.getline(account.account_name,100);
	
	cout<<"\t\t Enter bank name: ";
	cin.getline(account.bank_name,100);
	
	cout<<"\t\t Enter account number: ";
	cin.getline(account.account_number, 100);
	
	cout<<"\t\t Enter login Id: ";
	cin.getline(account.login_id, 100);
	
	
	account_file << account.account_id <<"\t"<< account.account_name <<"\t"<< account.bank_name <<"\t"<< account.account_number <<"\t"<< account.login_id<<"\n";
	
	account_file.close();
}

void reading_accounts(){
	ifstream account_file("accounts.dat", ios::in);
	
	Account account;
	
	
	cout<<"\n\n\t\t\t\t\tREADING ALL ACCOUNTS\t\t\t\t\t\n";
	cout<<"\t\t-----------------------------------------------------------------\n";
	
	while(account_file >> account.account_id >> account.account_name >> account.bank_name >> account.account_number >>account.login_id ){
		
		cout<<"\t\t Account id       \t\t: \t"<<account.account_id <<endl<<endl;
		cout<<"\t\t Account name     \t\t: \t"<<account.account_name <<endl<<endl;
		cout<<"\t\t Bank name        \t\t: \t"<<account.bank_name <<endl<<endl;
		cout<<"\t\t Account number   \t\t: \t"<<account.account_number <<endl<<endl;
		cout<<"\t\t Login ID            \t\t: \t"<<account.login_id <<endl<<endl;
		cout<<"\t\t-----------------------------------------------------------------\n";
		
	}

}


// 1. ifstream -- students
// 2. ofstream -- temp-student

void update_account(){
	ifstream account_file("accounts.dat", ios::in);
	ofstream account_temp_file("temp-accounts.dat", ios::out|ios::app);
	Account account;
	int counter = 0;
	
	char account_id[100];
	
	cout<<"\t\t Enter account id: ";
	cin.getline(account_id,100);
	
	while(account_file >> account.account_id >> account.account_name >> account.bank_name >> account.account_number >> account.login_id) {
		if(strcmp(account.account_id,account_id) == 0) {
			counter++;
			// receive the inputs from the user key
			
			cout<<"\t\t Enter account name: ";
			cin.getline(account.account_name,100);
			
			cout<<"\t\t Enter bank name: ";
			cin.getline(account.bank_name,100);
			
			cout<<"\t\t Enter account number: ";
			cin.getline(account.account_number, 100);
			
			cout<<"\t\t Enter login Id: ";
			cin.getline(account.login_id, 100);
	
			account_temp_file << account.account_id <<"\t"<< account.account_name <<"\t"<< account.bank_name <<"\t"<< account.account_number <<"\t"<<account.login_id<<"\n";
		}
		else{
		account_temp_file << account.account_id <<"\t"<< account.account_name <<"\t"<< account.bank_name <<"\t"<< account.account_number <<"\t"<<account.login_id<<"\n";
		}
		
	}
	
	if(counter == 0) {
		cout<<"\t\t-----------------------------------------------------------------\n";
		cout<<"\t\t\t\t NO ACCOUNT WITH ID: "<<account_id<<" IS FOUND. \n";
		cout<<"\t\t-----------------------------------------------------------------\n";
	}
	else{
		cout<<"\t\t-----------------------------------------------------------------\n";
		cout<<"\t\t\t\t ENTRY ACCOUNT ID: "<<account_id<<" IS DELETED SUCCESSFULLY. \n";
		cout<<"\t\t-----------------------------------------------------------------\n";
	}
	
	remove("accounts.dat");
	rename("temp-accounts.dat", "accounts.dat");
		
		
	account_file.close();
	account_temp_file.close();
}


void delete_account(){

	Account account;
	
	ifstream  account_file("accounts.dat", ios::in);
	
	ofstream tem_account_file("temp-accounts.dat",ios::out | ios::app);
	
	int counter = 0;
	
	char account_id[100];
	
	cout<<"\t\t Enter account id: ";
	cin.getline(account_id,100);
	
	cin>>account_id;
	while(account_file >> account.account_id >> account.account_name >> account.bank_name >> account.account_number >> account.login_id) {
		if(strcmp(account.account_id,account_id) == 0) counter ++;
		else{
			tem_account_file << account.account_id <<"\t"<< account.account_name <<"\t"<< account.bank_name <<"\t"<< account.account_number <<"\t"<<account.login_id<<"\n";
		}
		
	
	}
	if(counter == 0) {
		cout<<"\t\t-----------------------------------------------------------------\n";
		cout<<"\t\t\t\t NO ACCOUNT WITH ID: "<<account_id<<" IS FOUND. \n";
		cout<<"\t\t-----------------------------------------------------------------\n";
	}
	else{
		cout<<"\t\t-----------------------------------------------------------------\n";
		cout<<"\t\t\t\t ENTRY ACCOUNT ID: "<<account_id<<" IS DELETED SUCCESSFULLY. \n";
		cout<<"\t\t-----------------------------------------------------------------\n";
	}
	
	tem_account_file.close();
	account_file.close();
	
	remove("accounts.dat");
	rename("temp-accounts.dat","accounts.dat");
	
}


int main(){
	get_latest_id();
	save_account();
	reading_accounts();
	update_account();
	delete_account();
	
	
	return 0;
}
