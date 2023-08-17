#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;
class Manager_Function {
public:
    void Approve_Reject_User();
    vector<string> convertSentenceToVector(const string& sentence);
};
vector<string> Manager_Function::convertSentenceToVector(const string& sentence) {
        vector<string> sentences;
        istringstream iss(sentence);
        string sentenceToken;

        while (std::getline(iss, sentenceToken, ',')) {
            sentences.push_back(sentenceToken);
        }

        return sentences;
}

// approve or reject user
void Manager_Function::Approve_Reject_User() {
    ifstream obj;
    obj.open("../csv/newAccountQueue.csv");

    if (obj.is_open()) {
        string line;
        while (getline(obj, line)) {
            cout << line + ",0.0" << "\n"; // Using "\n" for newline
            cout << "Do You Wish this Customer in Your Branch yes or no ." << "\n";
            
            string answer;
            cin >> answer;
            
            vector<string> words = convertSentenceToVector(line); // Assuming this function is properly defined
            
            if (answer == "yes") {
                ofstream login_Obj;
                login_Obj.open("../csv/login.csv", ios::app);
                if (login_Obj.is_open()) {
                    string type="customer";
                    login_Obj << words[0] << ","<< words[0]<<","<<type<<","<<"0"<<endl;
                    login_Obj.close();
                } else {
                    cout << "error in opening file login.csv" << "\n";
                }
                
                ofstream account_Obj;
                account_Obj.open("../csv/account.csv", ios::app);
                if (account_Obj.is_open()) {
                    account_Obj << words[0] << "," << words[1] << "," << words[2] << "," << words[3] << "," << words[4] << "," << "0.0"<<endl;
                    account_Obj.close();
                } else {
                    cout << "error in opening account.csv" << "\n";
                }
            }
        }
        obj.close(); //  to close the file when done
        
        // Remove the newAccountQueue.csv file
    
       if (remove("../csv/newAccountQueue.csv") != 0) {
           cout << "Error deleting file newAccountQueue.csv" << "\n";
       }
    } else {
        cout << "Error in opening file" << "\n";
    }
}