#include <iostream>
#include "../header/typeFactory.hpp"
#include "../header/authentication.hpp"
#include<string>
using namespace std;
int main() {
    
    
    
    string genral_user , userid , password;
    
    cout<<"who you are ? ";
    cin>>genral_user;

    user* user = Factory::createVehicle(genral_user);
    string type = user->whoIm(); // Output: type of class
    
    if(user==nullptr)
    {
        cout<<"invalid user";
    }
    else{
        cout<<endl<<"Enter userID and Password "<<endl;
        cin>>userid>>password;
        authentication auth_obj;
        if(auth_obj.logIn(userid,password,type))
        {
            cout<<"sucessfull log in ";

        }
        else{
            cout<<"Invalid userid or password ";
        }
    }

    delete user;

    return 0;
}
