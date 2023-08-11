#include "../header/customer_function_provider.hpp"
#include<iostream>
int main()
{
    Customer_function obj;
    //obj.printingHead();
    //obj.deposit("123456");
    //obj.withdraw("123456");
    //obj.printingStatementInCSV("123456","+",2);
    obj.view_statement("123456");
    std::cout<<"hello"<<endl;
    return 0;
}