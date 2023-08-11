#ifndef manager_hpp
#define manager_hpp

#include <iostream>
#include<string>
#include "user.hpp"
#include "manager_function_provider.hpp"

using namespace std;

class Manager : public User {
    public:
        string whoIm() override {
            std::cout << "I am manager";
            return "manager";
        }

        Manager(){}
        void options()
        {   cout<<"0 for Exit "<<endl;
            cout<<"1 for Approve SignUp Customer"<<endl;
        }
        void menu(string userid)
        {   Manager_Function obj;
            int i;
            do{
            cout<<"you Log In as Manager"<<endl;
            options();
            cin>>i;
            switch(i)
            {
                case 0:
                    std::cout<<"Logged Out"<<endl;
                    break;
                case 1:
                    obj.Approve_Reject_User();
                    
                break;
                default:
                    std::cout<<"wrong INPUT"<<endl;  
            }
            }while(i!=0);
            
        }
};

#endif
