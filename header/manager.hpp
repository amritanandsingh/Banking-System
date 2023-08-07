#ifndef manager_hpp
#define manager_hpp

#include <iostream>
#include "user.hpp"

class Manager : public user {
public:
    void whoIm() override {
        std::cout << "I am manager";
    }
};

#endif
