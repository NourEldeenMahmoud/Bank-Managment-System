#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include<fstream>
#include"clsDate.h"
class clsLoginScreen :protected clsScreen
{

private:

   
    static  bool _Login()
    {
        bool LoginFaild = false;
        short Trials=0;
        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                Trials++;
                cout << "\nInvlaid Username/Password!\n";
                cout << "You have " << 3-Trials << " Trials to login.\n";
               
            }
            if (Trials==3)
            {
                cout << "\nYou are locked after 3 failed trials";
                return false;
            }
            cout << "\nEnter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);
        
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};


