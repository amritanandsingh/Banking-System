#ifndef SIGNUP_HPP
#define SIGNUP_HPP

#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <limits> // Include this for std::numeric_limits
#include <string> // Include this for string and getline
#include "validation.hpp"

class SignUp {
public:
    void form() {
        std::string accountNumber, FirstName, LastName, Address, PhoneNumber;

        std::mt19937 rng(std::time(nullptr));
        std::uniform_int_distribution<int> distribution(10000000, 99999999);
        long long int a = distribution(rng);
        accountNumber = std::to_string(a);

        std::cout << "Enter First Name: ";
        std::cin >> FirstName;
        std::cout << "Enter Last Name: ";
        std::cin >> LastName;

        // Clear the newline character from the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter Address: ";
        std::getline(std::cin, Address);
        std::cout << "Enter Phone Number: ";
        std::cin >> PhoneNumber;

        std::cout << "Account Number: " << accountNumber << std::endl;

        // Use a local scope to ensure the file is closed automatically
        {
            std::fstream fstream_obj ;
            validation valid_obj;
            fstream_obj.open("../csv/newAccountQueue.csv", std::fstream::app);
            if (fstream_obj.is_open() && valid_obj.isWord(FirstName) && valid_obj.isWord(LastName) && valid_obj.isNumber(PhoneNumber)) {
                fstream_obj << accountNumber << "," << FirstName << "," << LastName << ","
                            << Address << "," << PhoneNumber << "\n";
            }
            else{
                std::cout<<"Invalid Input"<<endl;
            }
            fstream_obj.close();
        }
    }
};

#endif // SIGNUP_HPP
