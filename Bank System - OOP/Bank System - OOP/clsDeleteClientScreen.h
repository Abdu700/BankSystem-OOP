#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsAddNewClientScreen.h"
#include <iomanip>

class clsDeleteClientScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\n===========================================\n";
        cout << "\t    Client Information\n";
        cout << "===========================================\n";
        cout << "First Name    : " << Client.GetFirstName() << endl;
        cout << "Last Name     : " << Client.GetLastName() << endl;
        cout << "Full Name     : " << Client.FullName() << endl;
        cout << "Email         : " << Client.GetEmail() << endl;
        cout << "Phone         : " << Client.GetPhone() << endl;
        cout << "Account No.   : " << Client.GetAccountNumber() << endl;
        cout << "Pin Code      : " << Client.GetPinCode() << endl;
        cout << "Balance       : " << Client.GetAccountBalance() << endl;
        cout << "===========================================\n";

    }

public:

	static void ShowDeleteClientScreen() {
		_DrawScreenHeader("\t  Delete Client Screen");

		string AccountNumber = "";
        cout << "Please Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nAccount number not found. Please try again: ";
            AccountNumber = clsInputValidate::ReadString();
		}

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "\nConfirm delete (y/n): ";
        char Answer = 'n';
        cin >> Answer;

        if (toupper(Answer) == 'Y') {
            if(Client.Delete()){
                cout << "\nClient deleted successfully.\n";
            }
            else
                cout << "\nError: client could not be deleted.\n";
        }
        else
            cout << "\nOperation cancelled.\n";


	}

};

