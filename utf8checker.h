#ifndef UTF8CHECKER
#define UTF8CHECKER

#include "checker.h"

class UTF8Checker:public CheckerBase
{
public:
    UTF8Checker();
    bool detect(string str) const;
};

#endif // UTF8CHECKER

