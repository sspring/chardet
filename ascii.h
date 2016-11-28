#ifndef ASCIICHECKER
#define ASCIICHECKER

#include "checker.h"

class AsciiChecker:public CheckerBase
{
public:
    AsciiChecker();
    bool detect(string str)const;
};

// global variable --- like singleton

#endif // ASCIICHECKER

