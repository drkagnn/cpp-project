#include <iostream>
#include <vector>
#include <conio.h>
#include <cstdlib>

void logoname()
{
    std::cout << "######    ######    ##   ##    ###      ######   ##   ## \n";
    std::cout << "##   ##   ##   ##   ##  ##    ## ##    ##        ###  ## \n";
    std::cout << "##   ##   ######    #####    ##   ##   ##  ####  #### ## \n";
    std::cout << "##   ##   ##  ##    ##  ##   #######   ##   ##   ## #### \n";
    std::cout << "######    ##   ##   ##   ##  ##   ##    ######   ##  ### \n";
    _getch();
    system("cls");
}

void signin()
{
    std::cout << "signin";
}

void login()
{
    std::cout << "login"; 
}

void frontpage()
{
    char pick;
    std::cout << "1. Sign in \n2. Log in\nType 1/2: ";
    std::cin >> pick;

    if(pick == '1')
    {
    system("cls");    
    signin();
    }
    else if(pick == '2')
    {
    system("cls");
    login();
    }
}

int main()
{
    logoname();
    frontpage();
    return 0;

}







