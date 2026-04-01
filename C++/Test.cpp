#include <iostream>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include "sqlite3.h"

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


static int callback(void* data, int argc, char** argv, char** colName) {
    bool* found = (bool*)data;
    *found = true;
    return 0;
}



    
//place holders for the functions
void signin()
{
    sqlite3* db;

    // OPEN DB
    sqlite3_open("Account.db", &db);

    // CREATE TABLE
    std::string create_sql =
        "CREATE TABLE IF NOT EXISTS users("
        "name TEXT, password TEXT);";

    sqlite3_exec(db, create_sql.c_str(), 0, 0, 0);

    // INPUT
    std::string name;
    std::string pwd;

    std::cout << "Signin \nUsername: ";
    std::cin >> name;
    std::cout << "\nPassword: ";
    std::cin >> pwd;

    // INSERT DATA
    std::string insert_sql =
        "INSERT INTO users (name, password) VALUES ('" + name + "', '" + pwd + "');";

    sqlite3_exec(db, insert_sql.c_str(), 0, 0, 0);

    // CLOSE DB
    sqlite3_close(db);

    system("cls");
    logpage("");
}
    
std::string login()
{
    sqlite3* db;

    //open db
    sqlite3_open("Account.db", &db);

    std::string name, pwd;
    std::cout << "login \nUsername: ";
    std::cin >> name;
    std::cout << "\nPassword: ";
    std::cin >> pwd;

    bool found = false;

    std::string sql =
        "SELECT * FROM users WHERE name='" + name +
        "' AND password='" + pwd + "';";

    sqlite3_exec(db, sql.c_str(), callback, &found, 0);

    
    sqlite3_close(db);

    system("cls");

    if (found) {
        return name;
    } else {
        std::cout << "Login failed!\n";
        return logpage("");
    }
}
std::string logpage(const std::string& input)
{   
    std::string username;
    char pick;
    std::cout << "1. Sign in \n2. Log in\n3. Exit\nType 1/2/3: ";
    std::cin >> pick;

    switch (pick)
    {
    case '1':
        signin();
        return 0;
        break;
    case '2':
        return login();
    case '3':
        exit(0);
        break;
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







