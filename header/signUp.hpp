#include<iostream>
#include<fstream>
#include <random>
#include <ctime>
using namespace std;
class SignUp{
    public:
        void form() {
            string accountNumber, FirstName, LastName, Address, PhoneNumber;

            std::mt19937 rng(std::time(nullptr));
            std::uniform_int_distribution<int> distribution(10000000, 99999999);
            long long int a = distribution(rng);
            accountNumber = std::to_string(a);

            cout << "Enter First Name" << endl;
            cin >> FirstName;
            cout << "Enter Last Name" << endl;
            cin >> LastName;

            // Clear the newline character from the input buffer
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "Enter address" << endl;
            std::getline(std::cin, Address);
            cout << "Enter Phone Number" << endl;
            cin >> PhoneNumber;

            cout << "Account Number: " << accountNumber << endl;
            fstream fstream_obj;
            fstream_obj.open("../csv/newAccountQueue.csv",std::fstream::app);
            if(fstream_obj.is_open())
            {
                fstream_obj<<accountNumber<<","<<FirstName<<","<<LastName<<","<<Address<<","<<PhoneNumber<<"\n";
            }
            fstream_obj.close();
        }

};