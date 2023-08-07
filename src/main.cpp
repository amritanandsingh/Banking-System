#include <iostream>
#include "../header/typeFactory.hpp"

int main() {
    
    
    

    
    user* user1 = Factory::createVehicle("manager");
    user1->whoIm(); // Output: "I am manager"

    user* user2 = Factory::createVehicle("customer");
    user2->whoIm(); // Output: "I am customer"

    delete user1;
    delete user2;

    return 0;
}
