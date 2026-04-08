#include <iostream>
#include <vector>
#include <conio.h>
#include <limits>
#include <map>


//g++ untitled-1.cpp -o main
int mean(std::vector<int> data){
    int len = data.size();
    int sum;   
    for(int x : data){  
        sum = sum + x;
    }
    int mean = sum / len;

    return mean
    
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

    return mode, maxCount;
}

int median(std::vector<int> data){

    
    return 0;
}





void s_cal(std::string username) {

    int i;
    std::vector<int> data;

    while (true) {
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
            break;
        } else {
        data.push_back(i);
        system("cls");
        }
    }

    /*
    std::cout << "What do you want to do " << username << "?";
    std::cout << "1. mean median modus \n2.";

    char pick;

    switch (pick)
    {
    case '1':
    
        break;
    
    default:
        std::cout << "Invalid";
        break;

        */
}
    



int main() {

    std::vector<int> test = {1,2,3,4,5};
    mean(test);
    return 0;
    
}