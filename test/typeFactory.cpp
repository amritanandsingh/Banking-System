#include "../header/typeFactory.hpp"
#include<iostream>
using namespace std;
int main()
{   
    Factory obj;
    string s="customer";
    unique_ptr<user> ptr =  obj.createUser(s);

    return 0;
}