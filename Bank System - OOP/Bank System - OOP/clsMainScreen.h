#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include <iomanip>


using namespace std;

class clsMainScreen :protected clsScreen
{


private:
    enum enMainMenuOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6,
         eExit = 7
    };

    static short _ReadMainMenuOption()
    {
        cout << setw(37) << "" << "Choose what do you want to do? [1 to 7]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 7, "Enter Number between 1 to 7? ");
        return Choice;
    }

    static  void _GoBackToMainMenu()
    {
        cout << "\n\t\t\t\t\tPress any key to go back to Main Menu...\n";

        system("pause>0");
        ShowMainMenu();
    }

    static void _ShowAllClientsScreen()
    {
        //  cout << "\nClient List Screen Will be here...\n";
        clsClientListScreen::ShowClientsList();


    }

    static void _ShowAddNewClientsScreen()
    {
       // cout << "\nAdd New Client Screen Will be here...\n";
        clsAddNewClientScreen::ShowAddNewClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
        //cout << "\nDelete Client Screen Will be here...\n";
        clsDeleteClientScreen::ShowDeleteClientScreen();

    }

    static void _ShowUpdateClientScreen()
    {
       // cout << "\nUpdate Client Screen Will be here...\n";
        clsUpdateClientScreen::ShowUpdateClientScreen();

    }

    static void _ShowFindClientScreen()
    {
        //cout << "\nFind Client Screen Will be here...\n";
        clsShowFindClientScreen::ShowFindClientScreen();

    }

    static void _ShowTransactionsMenu()
    {
        //cout << "\nTransactions Menu Will be here...\n";
        clsTransactionsScreen::ShowTransactionsMenu();

    }

    static void _ShowEndScreen()
    {
        cout << "\n\t\t\t\t\t===========================================\n";
        cout << "\t\t\t\t\t\tThank you for using our system.\n";
        cout << "\t\t\t\t\t\t     Exiting... Goodbye!\n";
        cout << "\t\t\t\t\t===========================================\n\n";

    }

    static void _PerfromMainMenuOption(enMainMenuOptions MainMenuOption)
    {
        switch (MainMenuOption)
        {
        case enMainMenuOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eShowTransactionsMenu:
            system("cls");
            _ShowTransactionsMenu();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eExit:
            system("cls");
            _ShowEndScreen();
            

            break;
        }

    }



public:


    static void ShowMainMenu()
    {

        system("cls");

        _DrawScreenHeader("\t      Main Screen");

        cout << setw(37) << "" << "===========================================\n";
        cout << setw(37) << "" << "\t\t      Main Menu\n";
        cout << setw(37) << "" << "===========================================\n";
        cout << setw(37) << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << "" << "\t[5] Find Client.\n";
        cout << setw(37) << "" << "\t[6] Transactions.\n";
        cout << setw(37) << "" << "\t[7] Exit.\n";
        cout << setw(37) << "" << "===========================================\n";

        _PerfromMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
    }

};

