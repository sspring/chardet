#ifndef GB18030CHECKER
#define GB18030CHECKER

#include "checker.h"
#include <vector>
#include <functional>

class GB18030Checker:public CheckerBase
{
public:
    GB18030Checker();
    bool detect(std::string str) const;
};

//GB18030Checker _gb18030checker = GB18030Checker();

#endif // GB18030CHECKER

