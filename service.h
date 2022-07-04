#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <stack>
#include<math.h>
#include<vector>
#include<sstream>

using namespace std;


enum class Banks {
	BK, 
	EQUITY 
};



class Account {
    public:
        int account_id;
        string account_name;
        string bank_name;
        int account_number;
        string username;
        int balance;
};

class Deposit{
    public:
        int deposit_id;
        int account_number;
        float amount;

};



vector<Account> read_account() {
    ifstream account_file("account.txt", ios::in);
    
    // create a vector accounts
    
    vector<Account> accounts;
    
    // create a line string to read each line from a file
    string line;
    
    while(getline(account_file, line)) {
        // create a string field to reach each part of the line, changing to the stringstream
    	
    	stringstream linestream(line);
    	vector<string> fields;
    	
    	string field;
    	
    	while(getline(linestream,field,',')) {
    		fields.push_back(field);
    	}
    	    	
    	Account account;
    	
    	account.account_id = stoi(fields[0]);
    	account.account_name = fields[1];
    	account.bank_name = fields[2];
    	account.account_number = stoi(fields[3]);
    	account.username = fields[4];
    	account.balance = stoi(fields[5]);
    	
    	accounts.push_back(account);
    }
    
    // create a vector fields to store field, then read it to the account class
    
    account_file.close();
    return accounts;
}


bool is_empty_file(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

bool check_account_existence(int account_number) {
    
    vector<Account> accounts = read_account();
    
    for(int i = 0; i < accounts.size(); i++ ) {
		Account account = accounts[i];
		    
       if(account.account_number == account_number ) {
       		return true;
       }
    }
    
    return false;
}

bool check_if_account_has_balance(int account_number, int amount) {

	
	vector<Account> accounts = read_account();
    
    for(int i = 0; i < accounts.size(); i++ ) {
		Account account = accounts[i];
		
       if(account.account_number > amount) {
       	if(account.account_number == account_number) {
       		return true;
       	}
       }
    }
    
    return false;
}

void update_file_from_vector(vector<Account> accounts) {
    ofstream account_file("temp-account.txt", ios::out | ios::app);

    for (int i = 0; i < accounts.size(); i++)
    {
        Account account = accounts[i];

        account_file << account.account_id << "," << account.account_name <<  ","<< account.bank_name <<  "," << account.account_number <<  "," << account.username <<  "," << account.balance<< endl;
    }

    account_file.close();

    remove("account.txt");
    rename("temp-account.txt","account.txt");
    
}

int generate_account_number() {
	start:
	int number = rand() % 900000 + 100000;
	
	if(check_account_existence(number)) goto start;
	
	return number;
}


int get_latest_id() {
    
    vector<Account> accounts = read_account();
    
    return accounts.back().account_id ;
}

void save_account() {
    Account account;
    ofstream account_file("account.txt", ios::out | ios::app);
    
    cout << "Enter account name: ";
    cin >> account.account_name;
    
    cout << "Enter bank name: ";
    cin >> account.bank_name;
  
    cout << "Enter username: ";
    cin >> account.username;
    account.account_id = get_latest_id() + 1;
    account.account_number = generate_account_number();
    account.balance = 0;
    
    account_file << account.account_id << "," << account.account_name <<  ","<< account.bank_name <<  "," << account.account_number <<  "," << account.username <<  "," << account.balance<< endl;
    account_file.close();
}

void reading_all_accounts (vector<Account> accounts) {
	
	for(int i = 0; i < accounts.size(); i++ ) {
		Account account = accounts[i];
		
		cout << account.account_id << " " << account.account_name << " " << account.bank_name << " " << account.account_number << " " << account.username << " " << account.balance <<endl;

	}

}

int increase_balance(int account_number, int amount) {
	
	int new_balance = 0;

    vector<Account> accounts = read_account();

    for (int i = 0; i < accounts.size(); i++)
    {
        Account account = accounts[i];

        if( account.account_number == account_number ) {

            accounts[i].balance += amount;
            new_balance = accounts[i].balance;
        }
        
    }
    
    update_file_from_vector(accounts);

	return new_balance;
}

int decrease_balance(int account_number, int amount) {
	
	int new_balance = 0;

    vector<Account> accounts = read_account();

    for (int i = 0; i < accounts.size(); i++)
    {
        Account account = accounts[i];

        if( account.account_number == account_number ) {

            accounts[i].balance -= amount;
            new_balance = accounts[i].balance;
        }
        
    }
    
    update_file_from_vector(accounts);

	return new_balance;
}

int deposit_to_account(){
	int account_number, amount;
    cout << "Enter account number : " << endl;
    cin >> account_number;

    if (!check_account_existence(account_number)) {
        cout << "Sorry, your account is not found" << endl;
        deposit_to_account();    
    }
    
    cout << "Enter amount to deposit : " << endl;
    cin >> amount;
    
    int new_balance = increase_balance(account_number, amount);

    cout<<"Deposited: "<<amount<<", "<<new_balance<<endl;

    return new_balance;
}



int withdraw_from_account(){
	cin.ignore();
	int account_number, amount;
    cout << "Enter account number : " << endl;
    cin >> account_number;

    if (!check_account_existence(account_number)) {	
        cout << "Sorry, your account is not found" << endl;
        withdraw_from_account();    
    }
    
    cout << "Enter amount to withdraw : " << endl;
    cin >> amount;

     if (!check_if_account_has_balance(account_number, amount)) {	
        cout << "Sorry, You don't have enough balance to withdraw!" << endl;
        withdraw_from_account();    
    }

    int total_balance = 0;

    
    if ( amount < 0) {
        cout << "Sorry, you can't withdraw money below zero" << endl;
        withdraw_from_account();    
    }
    else if( amount > 200000 ) {
    	cout<<"Sorry, You are not allowed to withdraw this amount at once!"<<endl;
    	withdraw_from_account(); 
    }
    
	if( amount > 10000  && amount < 50000 ) amount += amount * 0.02;
	else if( amount <= 100000 ) amount += amount * 0.02;
				
    return decrease_balance(account_number, amount);
    
}
	
void update_account() {

    Account account;

    int account_number;

    enter_sender:
    cout << "Enter account number: ";
    cin >> account_number;
    
    if (!check_account_existence(account_number)) {
        cout << "Sorry, senders account is not found" << endl;
        goto enter_sender;  
    }

    vector<Account> accounts = read_account();

    for (int i = 0; i < accounts.size(); i++)
    {
        Account account = accounts[i];

        if( account.account_number == account_number ) {

            cout << "Update account name: ";
            cin >> accounts[i].account_name;
            cout << "Update bank name: ";
            cin >> accounts[i].bank_name;
            
            cout << "Update username: ";
            cin >> accounts[i].username;

        }
        
    }
    
    update_file_from_vector(accounts);
}

void delete_account() {
    
    Account account;

    int account_number;

    enter_sender:
    cout << "Enter account number: ";
    cin >> account_number;
    
    if (!check_account_existence(account_number)) {
        cout << "Sorry, senders account is not found" << endl;
        goto enter_sender;  
    }

    vector<Account> accounts = read_account();

    for (int i = 0; i < accounts.size(); i++)
    {
        Account account = accounts[i];

        if( account.account_number == account_number ) accounts.erase(accounts.begin() + i);
        
    }
    
    update_file_from_vector(accounts);

}

// transfer money

void transfer_money(){

	// checking if the senders and recievers account exists
	int senders_account_number, recievers_account_number, amount;
	
	enter_sender:
	cout<<"Enter senders account number: \n";
	cin>>senders_account_number;
	
	if (!check_account_existence(senders_account_number)) {
        cout << "Sorry, senders account is not found" << endl;
        goto enter_sender;  
    }
	
	enter_reciever:
	cout<<"Enter recievers account number: \n";
	cin>>recievers_account_number;
	
	if (!check_account_existence(recievers_account_number)) {
        cout << "Sorry, recievers account is not found" << endl;
        goto enter_reciever;
    }
	
	cout <<"Enter amount to transfer: \n";
	cin.ignore();
	cin>>amount;
		
	// check if the amount to send is equivalent
	if(! check_if_account_has_balance(senders_account_number, amount)){
		cout<<"Your balance is not enough \n";
		cin.ignore();
		goto enter_reciever;
	}
	// Reducing the balance of sender
	int remaining_amount= decrease_balance(senders_account_number, amount);
	
	// Increasing the balance of reciever
	increase_balance(recievers_account_number, amount);
	
	cout<<"You have sent "<<amount<<", remaing with "<<remaining_amount<<" rwf \n";
	
}

// sorting balance


void sorting_accounts_by_input()
{
    vector<Account> accounts = read_account();

    for (int step = 0; step < (accounts.size() -1); ++step) {
      
    int swapped = 0;
    
    for (int i = 0; i < (accounts.size() -step-1); ++i) {
        
      if (accounts[i].balance < accounts[i + 1].balance) {

        Account temp = accounts[i];
        accounts[i] = accounts[i + 1];
        accounts[i + 1] = temp;
        
        swapped = 1;
      }
    }
    if (swapped == 0)
      break;
  }

    reading_all_accounts(accounts);
  
}



