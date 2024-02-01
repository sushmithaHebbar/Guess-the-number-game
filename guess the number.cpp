#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>  // Include for INT_MAX

class GuessTheNumber {
private:
    const int MAX_NUMBER = 100;  // Define the maximum value for the secret number
    int secretNumber;
    int maxAttempts;
    int currentAttempt;

public:
    GuessTheNumber(int max) : maxAttempts(max), currentAttempt(0) {
        srand(static_cast<unsigned int>(time(nullptr)));
        secretNumber = rand() % MAX_NUMBER + 1;
    }

    int getMaxNumber() const {
        return MAX_NUMBER;
    }

    void playGame() {
        std::cout << "Welcome to Guess the Number Game!\n";
        std::cout << "Can you guess the secret number between 1 and " << getMaxNumber() << "?\n";

        while (currentAttempt < maxAttempts) {
            int guess;
            std::cout << "Enter your guess: ";
            std::cin >> guess;

            if (std::cin.fail()) {
                std::cout << "Invalid input. Please enter a valid number.\n";
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                continue;
            }

            currentAttempt++;

            if (guess == secretNumber) {
                std::cout << "Congratulations! You guessed the correct number in " << currentAttempt << " attempts.\n";
                return;
            } else if (guess < secretNumber) {
                std::cout << "Too low! Try again.\n";
            } else {
                std::cout << "Too high! Try again.\n";
            }
        }

        std::cout << "Sorry, you've run out of attempts. The correct number was: " << secretNumber << "\n";
    }
};

int main() {
    GuessTheNumber game(5);

    game.playGame();

    return 0;
}
