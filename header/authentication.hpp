#ifndef authentication_hpp
#define authentication_hpp

#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
using namespace std;

class authentication {
private:
    class loadData {
    public:
        string userid, password, type, active_status;
        loadData(string userid, string password, string type, string active_status)
            : userid(userid), password(password), type(type), active_status(active_status) {}
    };

    std::vector<std::string> convertSentenceToVector(const std::string& sentence) {
        std::vector<std::string> sentences;
        std::istringstream iss(sentence);
        std::string sentenceToken;

        while (std::getline(iss, sentenceToken, ',')) {
            sentences.push_back(sentenceToken);
        }

        return sentences;
    }

public:
    list<loadData> head;
    authentication() {
        ifstream obj;
        obj.open("../csv/login.csv");

        string line;
        while (getline(obj, line)) {
            vector<string> words_of_line = convertSentenceToVector(line);
            if (words_of_line.size() >= 4) {
                loadData loadData_obj(words_of_line[0], words_of_line[1], words_of_line[2], words_of_line[3]);
                head.push_back(loadData_obj);
            }
        }
        obj.close();
    }
    void print() {
        for (list<loadData>::const_iterator itr = head.begin(); itr != head.end(); ++itr) {
            const loadData& data = *itr;
            cout << "UserID: " << data.userid << endl;
            cout << "Password: " << data.password << endl;
            cout << "Type: " << data.type << endl;
            cout << "Active Status: " << data.active_status << endl;
            cout << "-----------------------------" << endl;
        }
    }
    bool logIn(string userid, string password , string type) {
        for (list<loadData>::iterator itr = head.begin(); itr != head.end(); ++itr) {
            if (itr->userid == userid && itr->password == password && itr->type ==type) {
                itr->active_status = "1"; // "1" to assign a string value
                return true;
            }
        }
        return false;
    }
    bool logOut(string userid, string password , string type)
    {
        for (list<loadData>::iterator itr = head.begin(); itr != head.end(); ++itr) {
            if (itr->userid == userid && itr->password == password && itr->type ==type) {
                itr->active_status = "0"; // "1" to assign a string value
                return true;
            }
        }
        return false;
    }
    ~authentication() {
        ofstream newlogin("../csv/newlogin.csv");
        for (const auto& data : head) {
            newlogin << data.userid << "," << data.password << "," << data.type << "," << data.active_status << endl;
        }
        newlogin.close(); // Close the output file
        remove("../csv/login.csv");
        rename("../csv/newlogin.csv", "../csv/login.csv");
    }
};

#endif // authentication_hpp
