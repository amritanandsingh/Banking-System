#ifndef customer_hpp
#define customer_hpp

#include <iostream>
#include<string>
#include "user.hpp"
//#include "../header/customer_function_provider.hpp"
using namespace std;
class Customer : public User {
    public:
        
        string whoIm() override {
            std::cout << "I am customer";
            return "customer";
        }

        Customer(){}

        int logInSignUp()
        {
            cout<<"Enter 1 for LogIn 2 for SignUp"<<endl;
            int input;
            cin>>input;
            return input;
        }
        void menu(string userid)
        {
            
            cout<<"you want Log In as Customer"<<endl;
            //Customer_function customer_funtion_object;
            int x=0;
            do{
                //x = customer_funtion_object.menu();
                switch (x)
                {
                case 0:
                    cout<<"you pressed 0 now time to Exit menu "<<endl;
                    break;
                case 1:
                    //customer_funtion_object.withdraw(userid);
                    break;
                case 2: 
                    //customer_funtion_object.deposit(userid);
                    break;
                case 3:
                    //customer_funtion_object.view_statement(userid);
                default:
                    cout<<"Wrong Input"<<endl;
                    break;
                }
            }while(x!=0);
            
        }

};

#endif
