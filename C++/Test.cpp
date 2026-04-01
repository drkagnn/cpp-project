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


//forward declaration
std::string logpage(const std::string& input);




//place holders for the functions
void signin()
{
    std::string name;
    std::string pwd;
    std::cout << "Signin \nUsername: ";
    std::cin >> name;
    std::cout << "\nPassword: ";
    std::cin >> pwd;
    
    //write into data
    system("cls");
    logpage("");
}
    
std::string login()
{   
    
    std::string name;
    std::string pwd;
    std::cout << "login \nUsername: ";
    std::cin >> name;
    std::cout << "\nPassword: ";
    std::cin >> pwd;
    system("cls");
    return name;    
}

std::string logpage(const std::string& input)
{   
    std::string username;
    char pick;
    std::cout << "1. Sign in \n2. Log in\nType 1/2: ";
    std::cin >> pick;

    switch (pick)
    {
    case '1':
        signin();
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
    username = logpage("");
    std::cout << "Welcome " << username << "!";  
    return 0;

}







