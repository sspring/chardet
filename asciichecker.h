#ifndef ASCIICHECKER
#define ASCIICHECKER

#include "checker.h"

class AsciiChecker:public CheckerBase
{
public:
    AsciiChecker();
    bool detect(std::string str)const;
};

// global variable --- like singleton
//AsciiChecker _asciichecker = AsciiChecker();

#endif // ASCIICHECKER

