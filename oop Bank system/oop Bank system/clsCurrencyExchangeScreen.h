#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsCurrensiesList.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"
using namespace std;
class clsCurrencyExchangeScreen:protected clsScreen
{

private:
    enum enCurrencyMenuOptions { eListCurrency =1,eFindCurrency=2,eUpdateRate=3,eCurrecnyCalculator=4,eMainMenu=5};
    static short ReadCurrencyExchangeMenuOpions()
    {
        cout << setw(37) << left << "" << "Choose What Do You Want To Do ? [1 To 5] ";
        short Choice = clsInputValidate::ReadFloatNumberBetween(1, 5, "Enter Number between 1 to 6? ");
        return Choice;
    }
    static void _GoBackToCurrencyExhcangeMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowCurrencyExchangeMenu();

    }

    static void _ShowListCurrenciesScreen()
    {
        clsCurrenciesList::ShowCurrenciesListScreen();
    }
    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateRateScreen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();

    }
    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

    }

    static void _PerformCurrencyExchangeMenueOption(enCurrencyMenuOptions CurrencyMenuOptions)
    {
        switch (CurrencyMenuOptions)
        {
        case enCurrencyMenuOptions::eListCurrency:
        {
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExhcangeMenue();
            break;
        }

        case enCurrencyMenuOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExhcangeMenue();
            break;
        }


        case enCurrencyMenuOptions::eUpdateRate:
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExhcangeMenue();
            break;
        }

        case enCurrencyMenuOptions::eCurrecnyCalculator:
        {

            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExhcangeMenue();
            break;

        }
        case enCurrencyMenuOptions::eMainMenu:
        {

           
            //do nothing here the main screen will handle it :-) ;
        }

       
        }
    }



public:
	static void ShowCurrencyExchangeMenu()
	{
        

            system("cls");
            _DrawScreenHeader("\Currecny Exchange Screen");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t  Currency Exchange Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
            cout << setw(37) << left << "" << "\t[2] Find Currencies.\n";
            cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
            cout << setw(37) << left << "" << "\t[4] Currecny Calculator.\n";
            cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerformCurrencyExchangeMenueOption((enCurrencyMenuOptions)ReadCurrencyExchangeMenuOpions());
        }
	
};

