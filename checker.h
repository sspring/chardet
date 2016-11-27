#ifndef CHECKER
#define CHECKER

// common used headers
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <functional>
using namespace std;

class CheckerBase
{
public:
    CheckerBase(string charset);
    virtual bool detect(std::string str)const =0;
    std::string get_charset_name()const{return this->charset_name;}
protected:
    std::string charset_name;
};

#endif // CHECKER

