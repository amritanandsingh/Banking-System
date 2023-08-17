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
        cin>>genral_user;    // to make requred type of instance.
        Factory factory_obj;
        if(genral_user=="signup")
        {
            SignUp signUp_obj;
            signUp_obj.form();
            cout<<"sign Up successfully"<<endl;
            return 0;
        }
        User *user= factory_obj.createUser(genral_user);   // factory pattern call

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
            authentication *auth_obj=new authentication;                // authentication class implementaion
            if(auth_obj->logIn(userid,password,type))
            {
                cout<<"sucessfull log in "<<endl;
                delete auth_obj;
                user->menu(userid);
                authentication makeLogout;
                makeLogout.logOut(userid,password,type);

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
