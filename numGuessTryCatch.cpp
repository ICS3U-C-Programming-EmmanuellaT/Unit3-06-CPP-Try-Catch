// Copyright (c) 2026 Emmanuella Taiwo All rights reserved
// Created by: Emmanuella Taiwo
// Date: 20th Oct,2026
// This program asks the user
// to guess a number between 0 and 9,
// and checks if the guess is correct or not
// and uses try-catch to handle invalid input

#include <iostream>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>

int main() {
    // declare variables
    int someRandomNumber;
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(0, 9);
    someRandomNumber = idist(rgen);

    // get the number from the user
    std::cout << "Enter a number between 0 and 9: ";
    std::string input;

    try {
        int number;
        char extraCharacter;
        if (!(std::cin >> input)) {
            throw std::invalid_argument("Invalid input");
        }
        std::cout << "You guessed the wrong number. Try again!" << std::endl;
        std::istringstream inputStream(input);
        if (!(inputStream >> number) || (inputStream >> extraCharacter)) {
            throw std::invalid_argument("Invalid input");
        }

        // check if the number is within the valid range
        if (number < 0 || number > 9) {
        throw std::out_of_range
        ("Invalid input. Please enter a number between 0 and 9.");
        } else if (number == someRandomNumber) {
            std::cout << "you guessed the right number! " << std::endl;
        } else {
        std::cout << "you guessed the wrong number. Try again!" << std::endl;
        }
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    } catch (const std::invalid_argument& e) {
    std::cout << "The number is not valid, enter a valid input" << std::endl;
    }

    return 0;
}
