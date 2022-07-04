//
// Created by verie on 7/4/2022.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
using  namespace std;

class Account{
public:
    int accountId;
    int accountNumber;
    string username;
    int balance;
};


bool is_empty_file(std::ifstream &pFile) {
    return pFile.peek() == std::ifstream::traits_type::eof();
}

vector<Account> getAllAccounts(){
    ifstream file("account.txt", ios::in);
    vector<Account> accounts;
    string line;
    while (getline(file, line)){
        stringstream  stringstream1(line);
        vector<string> fields;
        string field;
        while (getline(stringstream1, field, ',')){
            fields.push_back(field);
        }

        Account account;
        account.accountId = stoi(fields[0]);
        account.accountNumber = stoi(fields[1]);
        account.username = fields[2];
        account.balance= stoi(fields[3]);

        accounts.push_back(account);
    }

    file.close();
    return accounts;
}

int getLatestId(){
    vector<Account> accounts =  getAllAccounts();
    return accounts.back().accountId;
}




bool accountNumberExists(int accNo){
    vector<Account> accounts = getAllAccounts();
    for(int i=0; i<accounts.size(); i++){
        if(accounts[i].accountNumber == accNo){
            return true;
        }
    }
    return false;
}

int generateAccountNumber(){
    start:
    int number = rand() % 9000000 + 1000000;
    if (accountNumberExists(number))
    {
        goto start;
    }
    return number;
}
void save_account()
{
    Account account;
    ofstream account_file("account.txt", ios::out | ios::app);

    cout << "Enter username: ";
    cin >> account.username;
    account.accountId = 2;
    account.accountNumber = generateAccountNumber();
    account.balance = 0;
    cout<<"Ndfadsf:S "<<account.accountId<<endl;
    account_file << account.accountId << "," << account.accountNumber << "," << account.username << "," << account.balance << endl;

    cout << "Account created successfully!" << endl;
    cout << "Account ID: " << account.accountId << endl;
    cout << "Account Number: " << account.accountNumber << endl;
    cout << "Balance: " << account.balance << endl;
    account_file.close();
}



void intro(){
    cout<<"\n\t BANK";
    cout<<"\n\t MANAGEMENT";
    cout<<"\n\t SYSTEM";
    cout<<"\n\t MADE BY: verie Best";
    cout<<"\n\n\t press any key to continue";
    cin.get();
}
int main(){
    int ch;
    int accountNumber;
    intro();
    do{
        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t01. NEW ACCOUNT";
        cout<<"\n\n\t02. DEPOSIT AMOUNT";
        cout<<"\n\n\t03. WITHDRAW AMOUNT";
        cout<<"\n\n\t04. BALANCE ENQUIRY";
        cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
        cout<<"\n\n\t06. CLOSE AN ACCOUNT";
        cout<<"\n\n\t07. MODIFY AN ACCOUNT";
        cout<<"\n\n\t08. EXIT";
        cout<<"\n\n\tSelect Your Option (1-8) ";
        cin>>ch;
//        system("cls");
        switch (ch) {

            case 1:
                save_account();
                break;

            default:
                cout<<"Invalid option!"<<endl;
                break;
        }
    } while (ch!=8);

    return 0;
}