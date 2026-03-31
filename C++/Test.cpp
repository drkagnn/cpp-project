#include <iostream>
#include <vector>
#include <conio.h>
#include <cstdlib>

void logoname()
{
    std::cout << "======================================================== \n\n";
    std::cout << "######    ######    ##   ##    ###      ######   ##   ## \n";
    std::cout << "##   ##   ##   ##   ##  ##    ## ##    ##        ###  ## \n";
    std::cout << "##   ##   ######    #####    ##   ##   ##  ####  #### ## \n";
    std::cout << "##   ##   ##  ##    ##  ##   #######   ##   ##   ## #### \n";
    std::cout << "######    ##   ##   ##   ##  ##   ##    ######   ##  ### \n\n";
    std::cout << "================Press any key to continue=============== \n\n";
    _getch();
    system("cls");
}


//place holders for the functions
std::string signin()
{
    std::string input;
    std::cout << "Signin \nUsername: ";
    std::cin >> input;
    system("cls");
    return input;
}
    
std::string login()
{   
    std::string input;
    std::cout << "login \nUsername: ";
    std::cin >> input;
    system("cls");
    return input;    
}

std::string logpage()
{   
    std::string username;
    char pick;
    std::cout << "1. Sign in \n2. Log in\nType 1/2: ";
    std::cin >> pick;

    switch (pick)
    {
    case '1':
        return signin();
    case '2':
        return login();
    default:
        return "Invalid input";
    }
}

int main()
{   
    std::string username;
    logoname();
    username = logpage();
    std::cout << "Welcome " << username << "!";  
    return 0;

}







