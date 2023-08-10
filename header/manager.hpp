#ifndef manager_hpp
#define manager_hpp

#include <iostream>
#include<string>
#include "user.hpp"
using namespace std;

class Manager : public User {
    public:
        string whoIm() override {
            std::cout << "I am manager";
            return "manager";
        }

        Manager(){}

        void menu()
        {
                cout<<"you want Log In as "<<endl;

        }
};

#endif
