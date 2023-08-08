#include<iostream>
#include "../header/authentication.hpp"
using namespace std;
int main()
{
    authentication obj;
    obj.print();
    cout<<obj.logIn("321","321","customer");
    return 0;
}