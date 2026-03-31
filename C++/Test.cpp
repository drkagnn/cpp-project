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

void login()
{

}



int main()
{
    
    logoname();

    


    //main structure
    struct id
    {
        std::string username;
        std::string Pwd;
    };


    static std::vector<id> list;

    id person;

    list.push_back(person);



 




}