#include <cstdlib>
#include <iostream>
#include <windows.h>

int main() {


    int input;
    std::cout << "Type 1 for a suprise: ";
    std::cin >> input;
    
    if(input == 1)
    {
        //system("start https://repository.smakstlouis1sby.sch.id/13/1/Essay%20Internalisasi%20Nilai-Nilai%20Pancasila%20di%20Kelas.pdf");
        system("start \"\" \"C:\\Users\\vallent\\Downloads\\test.jpeg\"");
        Sleep(500);
    }
     else
    {
    std::cout << "you suck";
    }

    return 0;
}