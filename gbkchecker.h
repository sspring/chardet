#ifndef GBKCHECKER
#define GBKCHECKER

#include "checker.h"

class GBKChecker:public CheckerBase
{
public:
    GBKChecker();
    bool detect(string str) const;
private:
    bool check_two_byte(const unsigned char* str)const;
};

#endif // GBKCHECKER

