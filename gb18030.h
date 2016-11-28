#ifndef GB18030CHECKER
#define GB18030CHECKER

#include "checker.h"
#include <vector>
#include <functional>

class GB18030Checker:public CheckerBase
{
public:
    GB18030Checker();
    bool detect(string str) const;
};

#endif // GB18030CHECKER

