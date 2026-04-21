#include <iostream>
#include <vector>
#include <conio.h>
#include <limits>
#include <map>
#include <algorithm>


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

int main() {

    std::vector<int> test = {1,2,3,4,5};
    statistic("user");
    return 0;
    
}