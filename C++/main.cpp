#include <iostream>

int main() {

    double Volt;
    double I;
    double r;
    double Area;
    double P_listrik;
    int pick;
    
    std::cout << "1. Area \n2. daya listrik\n(1/2): ";
    std::cin >> pick;

    if(pick == 1)
    {   
        std::cout << "Masukan radius: ";
        std::cin >> r;
        if(r > 0)   
        {
            Area = 3.14 * r * r;
            std::cout << Area << " Meter kuadrat";
        }
        else 
        {
            std::cout << "Error";
        }
    }

    else if(pick == 2)
    {
        std::cout << "Masukan Volt: ";
        std::cin >> Volt;

        if(Volt >= 0)
        {
            std::cout << "Masukan Arus listrik: ";
            std::cin >> I;

            if(I >= 0)
            {
                P_listrik = Volt * I;
                std::cout << P_listrik << " Watt";
            }
            else
            {
                std::cout << "Error";
            }
        }
        else
        {
            std::cout << "Error";
        }
    }

    else
    {
        std::cout << "Error";
    }

    return 0;
}