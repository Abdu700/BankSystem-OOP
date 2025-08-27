#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

using namespace std;


class clsUpdateClientScreen : protected clsScreen
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

    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.SetFirstName(clsInputValidate::ReadString());

        cout << "\nEnter LastName: ";
        Client.SetLastName(clsInputValidate::ReadString());

        cout << "\nEnter Email: ";
        Client.SetEmail(clsInputValidate::ReadString());

        cout << "\nEnter Phone: ";
        Client.SetPhone(clsInputValidate::ReadString());

        cout << "\nEnter PinCode: ";
        Client.SetPinCode(clsInputValidate::ReadString());

        cout << "\nEnter Account Balance: ";
        Client.SetAccountBalance(clsInputValidate::ReadFloatNumber());
    }

public:

	static void ShowUpdateClientScreen() {

		_DrawScreenHeader("\t  Update Client Screen");

        string AccountNumber = "";

        cout << "\nEnter account number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number not found. Please enter a valid account number: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClient(Client);

        cout << "\nAre you sure you want to update this client? (y/n): ";

        char Answer = 'n';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {

            cout << "\n\nUpdate client information:";
            cout << "\n__________________________\n";


            _ReadClientInfo(Client);

            clsBankClient::enSaveResults SaveResult;

            SaveResult = Client.Save();

            switch (SaveResult)
            {
            case  clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\nClient account updated successfully.\n";


                _PrintClient(Client);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError: Account was not saved because it is empty.";
                break;

            }

            }

        }

    }


};

