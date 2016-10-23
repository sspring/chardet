#ifndef CHECKER
#define CHECKER

#include <string>
#include <list>

class CharsetChecker
{
public:
    virtual bool detect(std::string str)=0;
    std::string get_charset_name(){return this->charset_name;}
protected:
    std::string charset_name;
};

#endif // CHECKER

