#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <stack>
#include<math.h>
#include "./service.h"

using namespace std;

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
        cout << "9. Transfer money " <<endl;
        
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
   			case 9: transfer_money();
           		
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice == 1);
    return 0;
}
