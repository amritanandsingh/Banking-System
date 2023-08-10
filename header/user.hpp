#ifndef user_hpp
#define user_hpp

#include <iostream>
#include<string>
using namespace std;
class User {
public:
    virtual string whoIm() = 0;
    User(){}
    virtual void menu(string s) {
        cout<<"User menu"<<endl;
    }
    virtual ~User(){}
};

#endif
