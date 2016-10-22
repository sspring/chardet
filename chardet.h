#ifndef CHARDET
#define CHARDET

#include "chacker.h"
#include "asciichecker.h"
#include "gbkchecker.h"
#include "gb18030checker.h"
#include "utf8checker.h"
#include <vector>

// change the order for ur case if necessary
std::vector<CharacterChacker*> checker_collections = {
    new AsciiChecker(),
    new GB18030Checker(),
    new UTF8Checker(),
    new GBKChecker()};

std::string detect(std::string str)
{
    std::string character = "unknown";
    for(CharacterChacker* f:checker_collections)
    {
        if(f->detect(str))
        {
            character = f->character_name;
            break;
        }
    }
    return character;
}

#endif // CHARDET

