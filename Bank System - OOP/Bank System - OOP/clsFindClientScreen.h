#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

using namespace std;

class clsShowFindClientScreen : protected clsScreen 
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

    static void ShowFindClientScreen() {
        _DrawScreenHeader("\t  Find Client Screen");

        string AccountNumber = "";

        cout << "\nEnter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        if (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient found successfully.\n";
            clsBankClient Client = clsBankClient::Find(AccountNumber);
            _PrintClient(Client);
            
        }
        else
        {

            cout << "\nClient was not found.\n";
        }
    }

};

