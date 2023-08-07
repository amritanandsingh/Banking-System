#ifndef customer_hpp
#define customer_hpp

#include <iostream>
#include "user.hpp"

class Customer : public user {
public:
    void whoIm() override {
        std::cout << "I am customer";
    }
};

#endif
