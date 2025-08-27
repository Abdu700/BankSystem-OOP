#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include <iomanip>

using namespace std;

class clsTransactionsScreen :protected clsScreen
{


private:

    enum enTransactionsMenuOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eShowMainMenu = 4
    };

    static short ReadTransactionsMenuOption()
    {
        cout << setw(37) << "" << "Choose what do you want to do? [1 to 4]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Invalid input. Please enter a number between 1 and 4: ");
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        //cout << "\n Deposit Screen will be here.\n";
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        //cout << "\n Withdraw Screen will be here.\n";
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
       // cout << "\n Balances Screen will be here.\n";
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _GoBackToTransactionsMenu()
    {
        cout << "\n\nPress any key to return to the Transactions Menu...";
        system("pause>0");
        ShowTransactionsMenu();

    }

    static void _PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionsMenuOption)
    {

        switch (TransactionsMenuOption)
        {
        case enTransactionsMenuOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenuOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenuOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenu();
            break;
        }


        case enTransactionsMenuOptions::eShowMainMenu:
        {
            // Main screen will handle it
        }
        }


    }



public:


    static void ShowTransactionsMenu()
    {


        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << "" << "===========================================\n";
        cout << setw(37) << "" << "\t\t  Transactions Menu\n";
        cout << setw(37) << "" << "===========================================\n";
        cout << setw(37) << "" << "\t[1] Deposit\n";
        cout << setw(37) << "" << "\t[2] Withdraw\n";
        cout << setw(37) << "" << "\t[3] Show total balances\n";
        cout << setw(37) << "" << "\t[4] Back to main menu\n";
        cout << setw(37) << "" << "===========================================\n";

        _PerformTransactionsMenuOption((enTransactionsMenuOptions)ReadTransactionsMenuOption());
    }

};

