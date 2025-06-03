#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsCurrency.h"
#include"clsInputValidate.h"
using namespace std;
class clsFindCurrencyScreen:protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\Currency Card:";
        cout << "\n___________________";
        cout << "\nCountry   : " << Currency.Country();
        cout << "\nCode      : " << Currency.CurrencyCode();
        cout << "\nName      : " << Currency.CurrencyName();
        cout << "\nRate(1$)= : " << Currency.Rate();   
        cout << "\n___________________\n";

    }
    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }
public:

   static void ShowFindCurrencyScreen()
   {
       _DrawScreenHeader("\tFind Currency Screen");

       cout << "Find By : [1] Code or [2] Country ?";
       short Answer = 1;
       cin >> Answer;

       
     

       if (Answer == 1)
       {
           string CurrencyCode;
           cout << "\nPlease Enter CurrencyCode : ";
           CurrencyCode = clsInputValidate::ReadString();
           clsCurrency Currency =clsCurrency::FindByCode(CurrencyCode);
           _ShowResults(Currency);
       }
       else 
       {
           string CountryName;
           cout << "\nPlease Enter Country Name : ";
           CountryName = clsInputValidate::ReadString();
           clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
           _ShowResults(Currency);
       }

   }


};

