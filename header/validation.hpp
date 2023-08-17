#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <string> // Add this line to include the <string> header
using namespace std;

class validation {
public:
    bool isWord(const string &s) // Use const reference for parameter
    {
        for (int i = 0; i < s.size(); i++) {
            if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))) {
                return false;
            }
        }
        return true;
    }

    bool isNumber(const string &s) // Use const reference for parameter
    {
        for (int i = 0; i < s.size(); i++) {
            if (!(s[i]>='0' && s[i]<='9')) {
                return false;
            }
        }
        return true;
    }

};

#endif // HEADER_HPP
