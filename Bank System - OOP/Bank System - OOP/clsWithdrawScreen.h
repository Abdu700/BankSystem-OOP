#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsWithdrawScreen : protected clsScreen
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

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nEnter Account Number: ";
        cin >> AccountNumber;
        return AccountNumber;
    }


public:

    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t    Withdraw Screen");

        string AccountNumber = _ReadAccountNumber();


        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\n[Error] No client found with Account Number (" << AccountNumber << ").\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);


        float Amount = 0;
        cout << "\nEnter Withdraw Amount: ";
        Amount = clsInputValidate::ReadFloatNumber();

        cout << "\nConfirm Transaction (y/n): ";
        char Answer = 'n';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (Client.Withdraw(Amount))
            {
                cout << "\n[Success] Withdrawal completed successfully.\n";
                cout << "New Balance: " << Client.GetAccountBalance() << endl;
            }
            else
            {
                cout << "\n[Error] Withdrawal failed: Insufficient Balance.\n";
                cout << "Requested Amount: " << Amount << endl;
                cout << "Available Balance: " << Client.GetAccountBalance() << endl;

            }
        }
        else
        {
            cout << "\nTransaction cancelled by user.\n";
        }

    }

};



