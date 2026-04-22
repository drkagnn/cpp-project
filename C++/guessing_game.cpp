#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        int secret = std::rand() % 100 + 1;
        int guess   = 0;
        int attempts = 0;

        std::cout << "\n=== Number Guessing Game ===\n";
        std::cout << "I'm thinking of a number between 1 and 100.\n\n";

        while (guess != secret) {
            std::cout << "Your guess: ";
            if (!(std::cin >> guess)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Enter a number.\n";
                continue;
            }
            if (guess < 1 || guess > 100) {
                std::cout << "Please guess between 1 and 100.\n";
                continue;
            }

            ++attempts;

            if (guess < secret)
                std::cout << "Too low! Try higher.\n";
            else if (guess > secret)
                std::cout << "Too high! Try lower.\n";
            else
                std::cout << "\nCorrect! The number was " << secret
                          << ". You took " << attempts
                          << (attempts == 1 ? " attempt.\n" : " attempts.\n");
        }

        std::cout << "Play again? (y/n): ";
        std::cin >> playAgain;
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}