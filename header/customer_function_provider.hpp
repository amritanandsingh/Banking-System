#include<iostream>
#include<list>
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;
class Account;
class Customer_function{
    private:
        class Account{
            public:
                string accountnumber,firstName,lastName,address,phoneNumber;
                string balance;
                Account(string accountnumber, string firstName, string lastName, string address,string phoneNumber ,string balance);
        };
        vector<string> convertSentenceToVector(const string& sentence);
        Account& findUser(string);
    public:
        list<Account> head;
        void printingHead();
        int menu();
        //void withdraw(string userid);
        //void deposit(string userid);
        //void view_statement(string userid);
        Customer_function();
        ~Customer_function();


};

Customer_function::Account::Account(string accountnumber, string firstName, string lastName, string address,string phoneNumber ,string balance)
{
    this->accountnumber =  accountnumber ;
    this->firstName = firstName ;
    this->lastName =  lastName ;
    this->address = address ;
    this->phoneNumber = phoneNumber;
    this->balance = balance;
}

vector<string> Customer_function::convertSentenceToVector(const string& sentence) {
        vector<string> sentences;
        istringstream iss(sentence);
        string sentenceToken;

        while (std::getline(iss, sentenceToken, ',')) {
            sentences.push_back(sentenceToken);
        }

        return sentences;
}

Customer_function::Customer_function()
{
    fstream fstream_obj;
    fstream_obj.open("../csv/account.csv",std::fstream::in);
    if(fstream_obj.is_open())
    {
        string s;
        while(fstream_obj>>s)
        {
            vector<string> words = convertSentenceToVector(s);
            Account account_obj(words[0],words[1],words[2],words[3],words[4],words[5]);
            head.push_back(account_obj);
        }
    }
    else{
        cout<<"Error in opening File account.csv";
    }
}

Customer_function::~Customer_function() {  // Destructor to write account info to a new CSV file
    std::ofstream newaccount("../csv/newaccount.csv");  // Open the file for writing

    if (newaccount.is_open()) {  // Check if the file is opened successfully
        for (const Account &acc : head) {  // Loop through the accounts in the list
            newaccount << acc.accountnumber << "," << acc.firstName << "," << acc.lastName << ","
                       << acc.address<<","<<acc.phoneNumber << "," << acc.balance << "\n";
        }

        newaccount.close();  // Close the file
        remove("../csv/account.csv");
        rename("../csv/newaccount.csv","../csv/account.csv");
    } else {
        std::cout << "Error in opening file newaccount.csv" << std::endl;
    }
}

void Customer_function::printingHead()
{
    
    for(const Account & i:head)
    {
        cout<<"Account number "<<i.accountnumber<<endl;
        cout<<"Account first name "<<i.firstName<<endl;
        cout<<"Account last name "<<i.lastName<<endl;
        cout<<"Account address "<<i.address<<endl;
        cout<<"Account phone number "<<i.phoneNumber<<endl;
        cout<<"Account balance "<<i.balance<<endl;
        cout<<endl;
    }
}
int Customer_function::menu()
{   
    cout<<"0 for Exit "<<endl;
    cout<<"1 for withdraw Cash"<<endl;
    cout<<"2 for Deposit Cash"<<endl;
    cout<<"3 for view statement"<<endl;
    int i;
    cin>>i;
    return i;
}



// void Customer_function::withdraw(string userid)
// {
//     cout << "Enter Amount you Would like to Withdraw: ";
//     double num;
//     try {
//         cin >> num;
//         Account &obj = findUser(userid);  // Note: Changed from const Account&
//         //obj -= num;  // Corrected syntax for subtracting from account balance
//     }
//     catch(...) {
//         cout << "Something Went Wrong During Withdraw" << endl;
//     }
// }

// Account & Customer_function::findUser(string userid)
// {
//     for (Account &i : head)  // Note: Changed from const Account&
//     {
//         if (i.accountnumber == userid)
//             return i;
//     }
//     throw std::runtime_error("User not found (Customer_function::findUser)");  // Throwing an exception if user is not found
// }
