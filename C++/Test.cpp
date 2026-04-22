#include <iostream>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <limits>
#include <map>
#include <algorithm>
#include "sqlite3.h"


/* to compile use gcc -c sqlite3.c  this will make sqlite3.o */
/* to compile use g++ main.cpp sqlite3.o -o app.exe */

void logoname() {
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

//SQL
static int callback(void* data, int argc, char** argv, char** colName) {
    bool* found = (bool*)data;
    *found = true;
    return 0;
}

//place holders for the functions
void signin() {
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
std::string login() {
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
std::string logpage(const std::string& input) {   
    std::string username;
    char pick;
    std::cout << "1. Sign in \n2. Log in\n3. Exit\nType 1/2/3: ";
    std::cin >> pick;

    std::string x;
    switch (pick) {
    case '1':
        signin();
        return 0;
        break;
    case '2':
        x = login();
        return x;
    case '3':
        system("cls");
        exit(0);
        break;
    default:
        return "Invalid input";
    }
}

//statistic calculator

//g++ untitled-1.cpp -o main
int mean(std::vector<int> data){
    int len = data.size();
    int sum;   
    for(int x : data){  
        sum = sum + x;
    }
    int mean = sum / len;

    return mean;
    
}

int mode(std::vector<int> data){
    std::map<int, int> freq;

    // count frequency
    for (int x : data) {
        freq[x]++;
    }

    int mode = data[0];
    int maxCount = 0;

    // find most frequent
    for (auto pair : freq) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mode = pair.first;
        }
    }

    return mode;
}

int median(std::vector<int> data){
        int len = data.size();
        std::sort(data.begin(), data.end());
    
        if (len % 2 == 0) {
            return (data[len / 2 - 1] + data[len / 2]) / 2;
        } else {
            return data[len / 2];
        }           
}

std::vector<int> getdata() {

    int i;
    std::vector<int> data;

    while (true) {
        system("cls");
        std::cout << "Input your data (type 0 to exit): ";

        //!(std::cin >> i)  output t/f

        if(!(std::cin >> i)) {
            system("cls");
            std::cout << "Invalid input! Enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        } else if (i == 0) {
            system("cls");
            std::cout << "Done inputing data.\nThe data is: ";
            for(int x : data){
                std::cout << x << " ";
            }
            std::cout << "\n";
            break;
        } else {
        data.push_back(i);
        system("cls");
        }
    }
    return data;
}

void ungroupstatistic(std::string username) {
    
    std::vector<int> data = getdata();

    std::cout << "What do you want to do " << username << "?";
    std::cout << "\n------------------------\n1. mean median modus \n2. exit\n(1/2): ";

    char pick;

    bool run2 = true;
    while(run2 == true) {  
        
        
        std::cin >> pick;
        
        switch (pick) {
        case '1':
            system("cls");
            std::cout << "\n------------------------\n";
            std::cout << "Mean: " << mean(data) << "\n";
            std::cout << "Median: " << median(data) << "\n";
            std::cout << "Mode: " << mode(data) << "\n";
            std::cout << "-------------------------\n";
            std::cout << "1. mean median modus \n2. exit\n(1/2): ";
            break;
        
        case '2':
            run2 = false;
            system("cls");
            std::cout << "Program closed \n";
            break;

        case '3':
            run2 = false;
            system("cls");
            std::cout << "Program closed \n";
            break;
        default:
            std::cout << "Invalid";
            break;

        }
    }
}

void groupedstatistic() {

}


void statistic(std::string username) {
    
    bool run1 = true;
    while(run1) {
        std::cout << "What type of data do you have " << username << "?";
        std::cout << "\n------------------------\n1. Ungrouped data \n2. Grouped data \n3. Exit\n(1/2/3): ";

        char pick;

        std::cin >> pick;
        
        switch (pick) {
        case '1':
            system("cls");
            ungroupstatistic(username);
            break;
        
        case '2':
            system("cls");
            groupedstatistic();
            break;
        default:
            system("cls");
            std::cout << "Invalid input! Please choose 1, 2, or 3.\n";
            break;
        }


    }


}


int main()
{   
    char pick;

    std::string username;
    logoname();
    username = logpage("");
    std::cout << "Welcome " << username << "!\n"; 
    
    std::cout << "What would you like to do?";
    

    int statpick;
    bool run = true;
    while(run == true) {
        std::cout << "\n1. Statistic Calculator\n2. Exit\n(1/2): ";
        std::cin >> pick;
        switch (pick) {
        case '1':
            system("cls");
            std::cout << "\n1. Statistic Calculator\n2. Exit\n(1/2): ";
            std::cin >> statpick;
            if (statpick == 1)
            {
                system("cls");
                statistic(username);
            } else if (statpick == 2) {
                run = false;
                system("cls");
                std::cout << "Program closed \n";
            } else {
                system("cls");
                std::cout << "Invalid input! Please choose 1 or 2.\n";
                std::cout << "\n1. Statistic Calculator\n2. Exit\n(1/2): ";
            }
            
            break;
        
        case '2':
            run = false;
            system("cls");
            std::cout << "Program closed \n";
            break; 

        default:
            system("cls");
            std::cout << "Error";
            break;
        }
    }


    return 0;

}







