#include <iostream>
#include "../header/typeFactory.hpp"
#include "../header/authentication.hpp"
#include "../header/signUp.hpp"
#include<string>
//#include<stdexcept>
using namespace std;
int main() {
    try{
        string genral_user , userid , password ,type;
        
        cout<<"who you are ? if New type 'signup' for Sign Up "<<endl;
        cin>>genral_user;
        Factory factory_obj;
        if(genral_user=="signup")
        {
            SignUp signUp_obj;
            signUp_obj.form();
            cout<<"sign Up successfully"<<endl;
            return 0;
        }
        User *user= factory_obj.createUser(genral_user);

        if(user!=NULL)
        {
            type = user->whoIm(); // Output: type of class
        }
        if(user==NULL)
        {
            cout<<"Invalid User Type"<<endl;
            exit(0);
        }
        else{
            cout<<endl<<"Enter userID and Password "<<endl;
            cin>>userid>>password;
            authentication auth_obj;
            if(auth_obj.logIn(userid,password,type))
            {
                cout<<"sucessfull log in "<<endl;
                user->menu(userid);
            }
            else{
                cout<<"Invalid userid or password "<<endl;
            }
        }
        delete user;
    }
    catch(...)
    {
        std::cerr << "An error occurred: "<< std::endl;
    }
    
    
    return 0;
}
