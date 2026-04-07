#include <iostream>

int main() {

    double Velositas;
    double Volt;
    double I;
    double r;

    double Area;
    double P_angin;
    double P_listrik;

    char pick;
    std::cout << "1. Area \n2. daya angin\n3. daya listrik\n(1/2/3): ";
    std::cin >> pick;

    if(pick == '1')
    {   
        std::cout << "Masukan radius: ";
        std::cin >> r;
        if(r > 0)   // nested if
        {
            Area = 3.14 * r * r;
            std::cout << Area << " Meter kuadrat";
        }
        else
        {
            std::cout << "Error";
        }
    }


    else if(pick == '2')
    {
        std::cout << "Masukan Area: ";
        std::cin >> Area;
        if(Area > 0)
        {
            std::cout << "Masukan Velositas: ";
            std::cin >> Velositas;

            if(Velositas > 0)   // nested if
            {
                //1.2 <- rho (densitas angin)
                P_angin = 0.5 * 1.2 * Area * Velositas * Velositas * Velositas;
                std::cout << P_angin << " Watt";
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


    else if(pick == '3')
    {
        std::cout << "Masukan Volt: ";
        std::cin >> Volt;

        if(Volt >= 0)
        {
            std::cout << "Masukan Arus listrik: ";
            std::cin >> I;

            if(I >= 0)   // nested if
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