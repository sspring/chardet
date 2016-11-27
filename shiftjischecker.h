#ifndef SHIFTJISCHECKER
#define SHIFTJISCHECKER

#include "checker.h"

class ShiftJISChecker:public CheckerBase
{
public:
    ShiftJISChecker();
    bool detect(std::string str) const;
};

//ShiftJISChecker _shiftjischecker = ShiftJISChecker();
#endif // SHIFTJISCHECKER

