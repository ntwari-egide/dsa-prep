#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <stack>
#include<math.h>

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

bool is_empty_file(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

bool check_account_existence(int account_number) {
	ifstream account_file("account.txt", ios::in);
    Account account;
    while (account_file >> account.account_id >> account.account_name >> account.bank_name >> account.account_number >> account.username) {       
       return account.account_number == account_number ? true : false;
    }
    
    return false;
}

int generate_account_number() {
	start:
	int number = rand() % 900000 + 100000;
	
	if(check_account_existence(number)) goto start;
	
	return number;
}


int get_latest_id() {
    ifstream account_file("account.txt", ios::in);
    Account account;
    stack<int> accountIds;

    if (is_empty_file(account_file)) {
        return 0;
    }

    while (account_file >> account.account_id >> account.account_name >> account.bank_name >> account.account_number >> account.username) {
        accountIds.push(account.account_id);
    }
    return accountIds.top();
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
    
    account_file << account.account_id << " " << account.account_name << " " << account.bank_name << " " << account.account_number << " " << account.username << " " << account.balance<< endl;
    account_file.close();
}
void read_account() {
    ifstream account_file("account.txt", ios::in);
    Account account;
    while (account_file >> account.account_id >> account.account_name >> account.bank_name >> account.account_number >> account.username) {
        cout << account.account_id << " " << account.account_name << " " << account.bank_name << " " << account.account_number << " " << account.username << endl;
    }
}

int deposit_to_account(){
	int account_number, amount;
    cout << "Enter account number : " << endl;
    cin >> account_number;
    cout << "Enter amount to deposit : " << endl;
    cin >> amount;

    int total_balance = 0;

    if (!check_account_existence(account_number)) {
        cout << "Sorry, your account is not found" << endl;
        deposit_to_account();    
    }
    
    ifstream account_file("account.txt", ios::in);
    ofstream temp_file("temp.txt", ios::out | ios::app);

    Account account;

    while (account_file >> account.account_id >> account.account_name >> account.bank_name >> account.account_number >> account.username >> account.balance) {
        if (account.account_number == account_number) {
            total_balance = account.balance += amount;
            temp_file << account.account_id << " " << account.account_name << " " << account.bank_name << " " << account.account_number << " " << account.username << " " << account.balance << endl;
        } else {
            temp_file << account.account_id << " " << account.account_name << " " << account.bank_name << " " << account.account_number << " " << account.username << " " << account.balance << endl;
        }
    }
    remove("account.txt");
    rename("temp.txt", "account.txt");
    account_file.close();
    temp_file.close();
    return total_balance;
}



int withdraw_from_account(){
	int account_number, amount;
    cout << "Enter account number : " << endl;
    cin >> account_number;

    int total_balance = 0;

    if (!check_account_existence(account_number)) {	
        cout << "Sorry, your account is not found" << endl;
        withdraw_from_account();    
    }
    
    cout << "Enter amount to withdraw : " << endl;
    cin >> amount;
    
    if ( amount < 0) {
        cout << "Sorry, you can't withdraw money below zero" << endl;
        withdraw_from_account();    
    }
    else if( amount > 200000 ) {
    	cout<<"Sorry, You are not allowed to withdraw this amount at once!"<<endl;
    	withdraw_from_account(); 
    }
    
    ifstream account_file("account.txt", ios::in);
    ofstream temp_file("temp.txt", ios::out | ios::app);

    Account account;

    while (account_file >> account.account_id >> account.account_name >> account.bank_name >> account.account_number >> account.username >> account.balance) {
        if (account.account_number == account_number) {
            total_balance = account.balance -= amount;
            temp_file << account.account_id << " " << account.account_name << " " << account.bank_name << " " << account.account_number << " " << account.username << " " << account.balance << endl;
        } else {
            temp_file << account.account_id << " " << account.account_name << " " << account.bank_name << " " << account.account_number << " " << account.username << " " << account.balance << endl;
        }
    }
    remove("account.txt");
    rename("temp.txt", "account.txt");
    account_file.close();
    temp_file.close();
    // charging the discount
    
    if( amount > 10000  && amount < 50000 ) total_balance -= total_balance * 0.02;
    else if( amount <= 100000 ) total_balance -= total_balance * 0.03;
    
    return total_balance;
}

void update_account() {
    ifstream account_file("account.txt", ios::in);
    ofstream temp_file("temp.txt", ios::out | ios::app);

    Account account;

    int account_id;

    cout << "Enter account id: ";
    cin >> account_id;

    int count = 0;

    while(account_file >> account.account_id >> account.account_name >> account.bank_name >> account.account_number >> account.username) {
        if (account.account_id == account_id) {
            cout << "Update account name: ";
            cin >> account.account_name;
            cout << "Update bank name: ";
            cin >> account.bank_name;
            cout << "Update account number: ";
            cin >> account.
            
            account_number;
            cout << "Update username: ";
            cin >> account.username;
            temp_file << account.account_id << " " << account.account_name << " " << account.bank_name << " " << account.account_number << " " << account.username << endl;
            count ++;
        } else {
            temp_file << account.account_id << " " << account.account_name << " " << account.bank_name << " " << account.account_number << " " << account.username << endl;
        }
    }
    if (count == 0) {
        cout << "Sorry, account not found" << endl;
    }
    remove("account.txt");
    rename("temp.txt", "account.txt");

    account_file.close();
    temp_file.close();
}

void delete_account() {
    ifstream account_file("account.txt", ios::in);
    ofstream temp_file("temp.txt", ios::out | ios::app);

    Account account;

    int account_id;
    cout << "Enter account id: ";

    cin >> account_id;
    int count = 0;
    
     while (account_file >> account.account_id >> account.account_name >> account.bank_name >> account.account_number >> account.username) {
        if (account.account_id != account_id) count ++;
        else {
            temp_file << account.account_id << " " << account.account_name << " " << account.bank_name << " " << account.account_number << " " << account.username << endl;
        }
     }
    remove("account.txt");
    rename("temp.txt", "account.txt");
    account_file.close();
    temp_file.close();
}

int main () {

    int choice;
    do {
        cout << "1. Save account" << endl;
        cout << "2. Read account" << endl;
        cout << "3. Update account" << endl;
        cout << "4. Delete account" << endl;
        cout << "5. Exit" << endl;
        cout << "6. Get latest id" << endl;
        cout << "7. Deposit" << endl;
        cout << "8. Withdraw " << endl;
        cin >> choice;
        
        
        switch (choice) {
            case 1:
                save_account();
                break;
            case 2:
                read_account();
                break;
            case 3:
                update_account();
                break;
            case 4:     
                delete_account();
                break;
            case 5:
                return 0;
                break;
            case 6: 
                cout<<"New id : " << get_latest_id();
                break;
           	case 7: {
           		int new_balance= deposit_to_account();
                cout<<"Your new balance: " <<new_balance<<endl;
           		}
           	case 8: {
           		int new_balance = withdraw_from_account();
           		cout<<"Your new balance: " <<new_balance<<endl;
           		}
           		
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice == 1);
    return 0;
}
