#include <iostream>
 

int main() { //tempat untuk code utama

    //changeable variable
    double Velositas;   // kecepatan angin (m/s)
    double Volt;   // tegangan (Volt)
    double I;   // arus (Ampere)
    double r;   // jari-jari baling-baling (meter)

    //constant
    float rho = 1.2; // massa jenis udara (kg/m^3)

    //dependent variable
    double Area;         // luas sapuan turbin
    double P_angin;   // daya dari angin
    double P_listrik; // daya listrik
    double efisiensi; // efisiensi turbin
    
    //pilih mana yang mau dicari
    char pick;
    std::cout << "1. Area \n2. daya angin\n3. daya listrik\n4. efesiensi turbin\n(1/2/3/4):  "; 
    std::cin >> pick;

    if(pick == '1')
    {   
        std::cout << "Masukan radius: ";
        std::cin >> r;
        Area = 3.14 * r * r;
        std::cout << Area; std::cout << " Meter kuadrat";
    }else if(pick == '2')
    {
        std::cout << "Masukan Area: ";
        std::cin >> Area;
        std::cout << "Masukan Velositas: ";
        std::cin >> Velositas;
        P_angin = 0.5 * rho * Area * Velositas * Velositas * Velositas;
        std::cout << P_angin; std::cout << " Watt";
    }else if(pick == '3')
    {
        std::cout << "Masukan Volt: ";
        std::cin >> Volt;
        std::cout << "Masukan Arus listrik: ";
        std::cin >> I;
        P_listrik = Volt * I;
        std::cout << P_listrik; std::cout << " Watt";
    }else if(pick == '4') 
    {
        std::cout << "Masukan Daya listrik: ";
        std::cin >> Volt;
        std::cout << "Masukan Daya angin: ";
        std::cin >> I;
        efisiensi = (P_listrik / P_angin) * 100;
        std::cout << efisiensi;  std::cout << " %";
    }else
    {
        std::cout << "Error";
    }

    return 0;

}