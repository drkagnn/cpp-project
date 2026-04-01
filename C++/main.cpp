#include <iostream>

int main() {

    double Velositas;
    double Volt;
    double I;
    double r;

    float rho = 1.2;

    double Area;
    double P_angin;
    double P_listrik;
    double efisiensi;

    char pick;
    std::cout << "1. Area \n2. daya angin\n3. daya listrik\n4. efesiensi turbin\n(1/2/3/4): ";
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
                P_angin = 0.5 * rho * Area * Velositas * Velositas * Velositas;
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
    else if(pick == '4') 
    {
        std::cout << "Masukan Daya listrik: ";
        std::cin >> P_listrik;

        if(P_listrik >= 0)
        {
            std::cout << "Masukan Daya angin: ";
            std::cin >> P_angin;

            if(P_angin > 0)   // nested if
            {
                efisiensi = (P_listrik / P_angin) * 100;
                std::cout << efisiensi << " %";
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