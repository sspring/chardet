#ifndef GBKCHECKER
#define GBKCHECKER

#include "checker.h"

class GBKChecker:public CheckerBase
{
public:
    GBKChecker();
    bool detect(std::string str) const;
private:
    bool check_two_byte(const unsigned char* str)const;
};

//GBKChecker _gbkchecker = GBKChecker();
#endif // GBKCHECKER

