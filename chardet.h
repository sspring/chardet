#ifndef CHARDET
#define CHARDET

#include "checker.h"
#include "asciichecker.h"
#include "gbkchecker.h"
#include "gb18030checker.h"
#include "utf8checker.h"
#include "big5checker.h"
#include <vector>

std::vector<CharsetChecker*> checker_collections = {
    &_asciichecker,
    &_gb18030checker,
    &_utf8checker,
    &_gbkchecker,
    &_big5checker};

std::string detect(std::string str)
{
    std::string char_set = "unknown";
    for(CharsetChecker* f:checker_collections)
    {
        if(f->detect(str))
        {
            char_set = f->get_charset_name();
            break;
        }
    }
    return char_set;
}
#endif // CHARDET

