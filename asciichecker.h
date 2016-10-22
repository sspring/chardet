#ifndef ASCIICHECKER
#define ASCIICHECKER

#include "chacker.h"

class AsciiChecker:public CharacterChacker
{
public:
    AsciiChecker()
        :CharacterChacker()
    {
        this->character_name = "Ascii";
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

