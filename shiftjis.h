#ifndef SHIFTJISCHECKER
#define SHIFTJISCHECKER

#include "checker.h"

class ShiftJISChecker:public CheckerBase
{
public:
    ShiftJISChecker();
    bool detect(string str) const;
};

#endif // SHIFTJISCHECKER

