// Copyright (c) 2020 Ahmad El-khawaldeh All rights reserved.
//
// Created by: Ahmad El-khawaldeh
// Created on: DEC 2020
// This program generates a random number so
// the user can guess what the number is

#include <iostream>
#include <string>
#include <random>

int main() {
    std::string integerAsString;
    int user_number;
    int RANDOM_NUMBER;


    std::cout << " enter a number from 1-10: " << std::endl;

    // input
    std::cout << "Enter a number: ";
    std::cin >> integerAsString;

    // process & output
    try {
        user_number = std::stoi(integerAsString);
        std::random_device rseed;
        std::mt19937 rgen(rseed());
        std::uniform_int_distribution<int> idist(1, 10);
        RANDOM_NUMBER = idist(rgen);
        if ( user_number == RANDOM_NUMBER ) {
            // Output
            std::cout << " correct, you got the right answer ";
        } else if ( user_number < 0 ) {
            std::cout << " it is not a positive integer " << std::endl;
        } else if ( user_number !=  RANDOM_NUMBER ) {
            while (true) {
                if ( user_number > RANDOM_NUMBER ) {
                    std::cout << " HINT: the number is too big, try again "
                    << std::endl;
                    std::cout << "Enter a number: ";
                    std::cin >> user_number;
                } else if ( user_number < RANDOM_NUMBER ) {
                    std::cout << " HINT: the number is too small, try again "
                    << std::endl;
                    std::cout << "Enter a number: ";
                    std::cin >> user_number;
                } else if ( user_number < 0 ) {
                    std::cout << " it is not a positive integer " << std::endl;
                    std::cout << "Enter a number: ";
                    std::cin >> user_number;
                } else if ( user_number == RANDOM_NUMBER ) {
                    std::cout << " you are correct " << std::endl;
                    break;
                }
            }
        }
    } catch (std::invalid_argument) {
        std::cout << "That was not a valid integer" << std::endl;
    }
}
