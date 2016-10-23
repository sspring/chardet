#ifndef ASCIICHECKER
#define ASCIICHECKER

#include "checker.h"

class AsciiChecker:public CharsetChecker
{
public:
    AsciiChecker()
        :CharsetChecker()
    {
        this->charset_name = "ascii";
    }

    bool detect(std::string str)
    {
        for(uchar ch:str)
        {
            if(ch >> 7) // whether the first bit is 1
            {
                return false;
            }
        }
        return true;
    }
};

#endif // ASCIICHECKER

