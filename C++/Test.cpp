
#include <iostream>
#include <string>
#include <cctype> 


//functions
double addition(double a, double b){
    return a+b;
}

double subtraction(double a, double b){
    return a-b;
}

double multiplication(double a, double b){
    return a*b;
}

double division(double a, double b){
    if (b == 0) {
        return 0;

    }else {
        return a/b;
    }
}



int main() {
    double a,b;
    char op;
    double result;
    bool exitloop = false;
    std::string input;

    while(true){
        
        
        std::cout << "input a: ";    
        std::cin >> a;
        std::cout << "input b: ";
        std::cin >> b;


        std::cout << "input operation (+ - * /): ";
        std::cin >> op;

        switch(op){

            case '+': result = addition(a,b); break;
            case '-': result = subtraction(a,b); break;
            case '*': result = multiplication(a,b); break;
            case '/': result = division(a,b); break;
            default: std::cout << "Invalid"; break;
        }

        std::cout << result << std::endl;
        while(true){
            char terminate;
            std::cout << "play again (Y/N): " << std::endl;
            std::cin >> terminate;

            if(terminate == 'Y'){
                break;

            }else if(terminate == 'N'){
                exitloop = true;
                break; 
            }else{

            }

        }
        if (exitloop == true){
            break;
        }else{

        }
    }

    return 0;
}