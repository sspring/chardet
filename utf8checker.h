#ifndef UTF8CHECKER
#define UTF8CHECKER

#include "checker.h"

class UTF8Checker:public CheckerBase
{
public:
    UTF8Checker();
    bool detect(std::string str) const;
};

//UTF8Checker _utf8checker = UTF8Checker();

#endif // UTF8CHECKER

