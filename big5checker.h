#ifndef BIG5CHECKER
#define BIG5CHECKER

#include "checker.h"

class Big5Checker:public CheckerBase
{
public:
    Big5Checker();
    bool detect(std::string str)const;
private:
    bool check_two_bytes(const unsigned char *buffer)const;
};

//Big5Checker _big5checker = Big5Checker();

#endif // BIG5CHECKER

