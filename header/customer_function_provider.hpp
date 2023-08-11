#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include <ctime>
#include <iomanip>
void removeSpecialCharsAndSpaces(std::string &inputString);

using namespace std;
class Customer_function{
    private:
        class Account{
            public:
                string accountnumber,firstName,lastName,address,phoneNumber;
                string balance;
                Account(string accountnumber, string firstName, string lastName, string address,string phoneNumber ,string balance);
                void operator - (double num)
                {
                    double bal = std::stod(this->balance);
                    if(num > bal)
                    {
                        throw "Not Sufficient Balance";
                    }
                    bal = bal - num;
                    this->balance =  std::to_string(bal);
                }
                void operator + (double num)
                {
                    double bal = std::stod(this->balance);
                    bal = bal + num;
                    this->balance =  std::to_string(bal);
                }

        };
        vector<string> convertSentenceToVector(const string& sentence);
        list<Account>::iterator findUser(string);
        vector<string> convertStringToVector(const string& str, char delimiter);
        
    public:
        list<Account> head;
        void printingHead();
        int menu();
        void withdraw(string userid);
        void deposit(string userid);
        void view_statement(string userid);
        Customer_function();
        ~Customer_function();
        void printingStatementInCSV(string , string ,double);
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
    list<Account>::iterator ptr= head.begin();
    // for(;ptr!=head.end();ptr++)
    // {
    //     cout<<ptr->accountnumber<<endl;
    // }
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

void Customer_function::withdraw(string userid)
{
    cout << "Enter Amount you Would like to Withdraw: ";
    double num;
    try {
        cin >> num;
        list<Customer_function::Account>::iterator obj = findUser(userid);  // Note: Changed from const Account&
        *obj-num;  //operator overloading   
        printingStatementInCSV(userid,"-",num);
        if(obj!=head.end())
        {
            std::cout<<"withdraw is Done"<<endl;
        }
        else{
            std::cout<<"User is Not Found !"<<endl;
        }
        
    }
    catch(...) {
        cout << "You have Not Sufficient Balance to make this transaction" << endl;
    }
}

void Customer_function::deposit(string userid)
{
    cout << "Enter Amount you Would like to Deposit: ";
    double num;
    try {
        cin >> num;
        list<Customer_function::Account>::iterator obj = findUser(userid);  // Note: Changed from const Account&
        *obj+num;  //operator overloading   
        printingStatementInCSV(userid,"+",num);
        if(obj!=head.end())
        {
            std::cout<<"Deposit is Done"<<endl;
        }
        else{
            std::cout<<"User is Not Found!"<<endl;
        }
    }
    catch(...) {
        cout << "Something went Wrong" << endl;
    }
}

list<Customer_function::Account>::iterator Customer_function::findUser(string userid)
{
    list<Account>::iterator ptr = head.begin();
    for (; ptr != head.end(); ++ptr)
    {
        if (ptr->accountnumber == userid)
            return ptr;
    }
    
    return head.end();  // Returning end iterator if user is not found
}

void Customer_function::printingStatementInCSV(std::string userid, std::string symbol, double d) {
    // config time
    time_t now = time(0);
    std::string dt = ctime(&now);
    
    // Remove special characters and spaces from dt
    removeSpecialCharsAndSpaces(dt);

    std::ofstream obj;
    obj.open("../csv/transactions.csv", std::ios::app);
    
    if (obj.is_open()) {
        std::string num = std::to_string(d);
        obj << userid << "," << symbol << "," << num << "," << dt ;
        obj.close();
    } else {
        std::cout << "Something Went Wrong With File" << std::endl;
    }
}

// not a class member function
bool isSpecialChar(char c) {
    // Define the set of special characters you want to remove
    const std::string specialChars = "!@#$%^&*()_+{}[]:\";'<>?,./\\| ";

    return specialChars.find(c) != std::string::npos;
}
// not a class member function
void removeSpecialCharsAndSpaces(std::string &inputString) {
    // Remove special characters and spaces using the isSpecialChar function
    inputString.erase(std::remove_if(inputString.begin(), inputString.end(), isSpecialChar), inputString.end());
}

vector<string> Customer_function::convertStringToVector(const string& str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}

void Customer_function::view_statement(string userid) {
    ifstream obj;
    obj.open("../csv/transactions.csv");
    string s;
    if (obj.is_open()) {
        while (getline(obj, s)) {
            vector<string> ss = convertStringToVector(s, ',');
            if (ss.size() >= 4 && ss[0] == userid) {
                std::cout << ss[0] << " " << ss[1] << ss[2] << " " << ss[3] << endl;
            }
        }
        obj.close();
    }
    else {
        cout << "Something Went Wrong while printing Statement" << endl;
    }
}


        
