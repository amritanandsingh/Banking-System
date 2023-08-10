#ifndef typeFactory_hpp
#define typeFactory_hpp

#include <string>
#include <memory>
#include "customer.hpp"
#include "manager.hpp"
#include "user.hpp"

class Factory {
public:
    User* createUser(const std::string& type) {
        if (type == "manager") {
            return new Manager();
        }
        if (type == "customer") {
            return new Customer();
        }
        return NULL; // You can add error handling or throw an exception here
    }
};

#endif
