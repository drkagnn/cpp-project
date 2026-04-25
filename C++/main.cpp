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
// SELECT * FROM users
//DELETE FROM users WHERE name = 'john'; (spesifc rowww)

void clear(){
    std::cout << "\033[2J\033[H";
}


void logoname() {
    std::cout << "======================================================== \n\n";
    std::cout << "######    ######    ##   ##    ###      ######   ##   ## \n";
    std::cout << "##   ##   ##   ##   ##  ##    ## ##    ##        ###  ## \n";
    std::cout << "##   ##   ######    #####    ##   ##   ##  ####  #### ## \n";
    std::cout << "##   ##   ##  ##    ##  ##   #######   ##   ##   ## #### \n";
    std::cout << "######    ##   ##   ##   ##  ##   ##    ######   ##  ### \n\n";
    std::cout << "================Press any key to continue=============== \n\n";
    _getch();
    clear();
}
//forward declaration
std::string logpage();

//SQL
static int callback(void* data, int argc, char** argv, char** colName) {
    bool* found = (bool*)data;
    *found = true;
    return 0;
}

//place holders for the functions
void signin() {
    sqlite3* db;

    // OPEN DB W CHECK
    if (sqlite3_open("Account.db", &db) != SQLITE_OK) {
    clear();
    std::cout << "Failed to open database!\n";
    return;
}
    // INPUT
    std::string name;
    std::string pwd;

    std::cout << "Signin \nUsername: ";
    std::cin >> name;
    std::cout << "\nPassword: ";
    std::cin >> pwd;

    if (name.empty() || pwd.empty()) {
        clear();
        std::cout << "Username and password cannot be empty!\n";
        sqlite3_close(db);
        return;
    }

    // CHECK IF USER EXISTS
    bool exists = false;

    std::string check_sql =
        "SELECT 1 FROM users WHERE name='" + name + "';";

    if (sqlite3_exec(db, check_sql.c_str(), callback, &exists, 0) != SQLITE_OK) {
        clear();
        std::cout << "Error checking user!\n";
        sqlite3_close(db);
        return;
    }

    if (exists) {
        std::cout << "Username already exists!\n";
        sqlite3_close(db);
        return;
    }

    // INSERT DATA
    std::string insert_sql =
        "INSERT INTO users (name, password) VALUES ('" + name + "', '" + pwd + "');";

    if (sqlite3_exec(db, insert_sql.c_str(), 0, 0, 0) != SQLITE_OK) {
        clear();
        std::cout << "Error inserting data!\n";
    } else {
        clear();
        std::cout << "Account created successfully!\n";
    }

    // CLOSE DB
    sqlite3_close(db);

}
std::string login() {
    sqlite3* db;

    //open db
    if (sqlite3_open("Account.db", &db) != SQLITE_OK) {
        clear();
        std::cout << "Failed to open database!\n";
        return "";
    }
    std::string name, pwd;
    std::cout << "login \nUsername: ";
    std::cin >> name;
    std::cout << "\nPassword: ";
    std::cin >> pwd;

    if (name.empty() || pwd.empty()) {
        clear();
        std::cout << "Username and password cannot be empty!\n";
        return "";
    }


    bool found = false;

    std::string sql =
        "SELECT 1 FROM users WHERE name='" + name +
        "' AND password='" + pwd + "';";

    sqlite3_exec(db, sql.c_str(), callback, &found, 0);
    
    
    sqlite3_close(db);

    clear();

    if (found) {
        return name;
    } else {
        clear();
        std::cout << "Login failed!\n";
        return "";
    }
}
std::string logpage() {   
    char pick;
    std::cout << "1. Sign in \n2. Log in\n3. Exit\nType 1/2/3: ";
    std::cin >> pick;

    std::string x;
    switch (pick) {
    case '1':
        signin();
        return "";

    case '2':
        x = login();
        return x;

    case '3':
        clear();
        exit(0);
        break;
        
    default:
        clear();
        std::cout << "Invalid input! Please choose 1, 2, or 3.\n";
        return "";
    }
}

//statistic calculator

//g++ untitled-1.cpp -o main

char getChoice(const std::string& text) {
    char c;
    std::cout << text;
    std::cin >> c;
    return c;
}

namespace ugfunctions {

    int mean(std::vector<int> data){
        int len = data.size();
        int sum = 0;
        if(len == 0)return 0;
        
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
        if (data.empty()) return 0;
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
            if (data.empty()) return 0;
        
            if (len % 2 == 0) {
                return (data[len / 2 - 1] + data[len / 2]) / 2;
            } else {
                return data[len / 2];
            }           
    }
}

namespace gfunctions {


    int mean(std::map<int,int> data){
    
        int Sum=0;
        int freq=0;
        if(freq == 0) return 0;

        int avg;

        for(const auto &[x_i,f_i] : data){
            Sum = Sum + x_i * f_i;
            freq = freq + f_i;
        }
        avg = Sum / freq;
        return avg;


    }

}

namespace getdata {

    std::vector<int> ugr() {

        int i;
        std::vector<int> data;

        while (true) {
            clear();
            std::cout << "The data is: ";
            for(int x : data){
                std::cout << x << " ";
            } std::cout << "\n";
            std::cout << "Input your data (type 0 to exit): ";
            
            //!(std::cin >> i)  output t/f

            if(!(std::cin >> i)) {
                clear();
                std::cout << "Invalid input! Enter a number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            } else if (i == 0) {
                clear();
                std::cout << "Done inputing data.\nThe data is: ";
                for(int x : data){
                    std::cout << x << " ";
                }
                std::cout << "\n";
                break;
            } else {
            data.push_back(i);
            clear();
            }
        }
        return data;
    }

    std::map<int,int> gr() {
        int index, frequency;
        std::map<int,int> data;

        while (true)
        {   

            std::cout << "input index (0,0 to exit): ";
            std::cin >> index;
            std::cout << "input frequency (0,0 to exit): ";
            std::cin >> frequency;

            if(index == 0 && frequency == 0){
                break;
            }else{
                data.insert({index, frequency});
                std::cout << index << "," << frequency;
            }
        }
        clear();
        return data;
    }
}

void ungroupstatistic(std::string username) {
    
    std::vector<int> data = getdata::ugr();

    std::cout << "What do you want to do " << username << "?\n";
    char pick;

    bool isLooprunning = true;
    while(isLooprunning) {  
        
        
        pick = getChoice("\n1. mean median modus \n2. exit\n(1/2): ");
        
        switch (pick) {
        case '1':
            clear();
            std::cout << "The data is: ";
            for(int x : data){
                std::cout << x << " ";
            } std::cout << "\n";
            std::cout << "Mean: " << ugfunctions::mean(data) << "\n";
            std::cout << "Median: " << ugfunctions::median(data) << "\n";
            std::cout << "Mode: " << ugfunctions::mode(data) << "\n";
            break;
        
        case '2':
            isLooprunning = false;
            clear();
            std::cout << "Exiting...";
            break;

        default:
            clear();
            std::cout << "Invalid input! Please choose 1, 2, or 3.\n";
            break;

        }
    }
}

void groupedstatistic() {
    std::map<int,int> data = getdata::gr();

    for (const auto &[k, v] : data) {
    std::cout << k << " -> " << v << std::endl;
    }

}

void statistic(std::string username) {
    
    bool isLooprunning = true;
    while(isLooprunning) {
        std::cout << "What type of data do you have " << username << "?";
        char pick = getChoice("\n1. Ungrouped data \n2. Grouped data \n3. Exit\n(1/2/3): ");
        
        switch (pick) {
        case '1':
            clear();
            ungroupstatistic(username);
            break;
        
        case '2':
            clear();
            groupedstatistic();
            break;

        case '3':
            isLooprunning = false;
            clear();
            std::cout << "Exiting... \n";
            break;

        default:
            clear();
            std::cout << "Invalid input! Please choose 1, 2, or 3.\n";
            break;
        }
    }
}

void mainmenu(std::string username) {
    std::cout << "What would you like to do?";
    char pick;
    bool isLooprunning = true;
    while(isLooprunning) {
        pick = getChoice("\n1. Statistic Calculator\n2. Exit\n(1/2): ");

        switch (pick) {
        case '1':
            clear();
            statistic(username);   
            break;

        case '2':
            isLooprunning = false;
            clear();
            std::cout << "Program closed \n";
            break;

        default:
            clear();
            std::cout << "Invalid input! Please choose 1, 2, or 3.\n";
            break;
        }

    }

}

int main() {   
    
    sqlite3* db;

    if (sqlite3_open("Account.db", &db) != SQLITE_OK) {
        std::cout << "Failed to open DB\n";
        return 1;
    }

    std::string create_sql =
        "CREATE TABLE IF NOT EXISTS users("
        "name TEXT, password TEXT);";

    sqlite3_exec(db, create_sql.c_str(), 0, 0, 0);

    sqlite3_close(db);

    logoname();

    std::string username;
    while (true){
        username = logpage();

        if(username != ""){
            std::cout << "Welcome " << username << "!\n"; 
            break;
        }
    }


    mainmenu(username);


    

    return 0;
}




