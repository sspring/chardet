#ifndef CHARDET
#define CHARDET

#include "checker.h"
#include "asciichecker.h"
#include "gbkchecker.h"
#include "gb18030checker.h"
#include "utf8checker.h"
#include <vector>

class Chardet
{
public:
    Chardet()
    {
        // change the order for ur case if necessary
        checker_collections = {
            new AsciiChecker(),
            new GB18030Checker(),
            new UTF8Checker(),
            new GBKChecker()};
    }
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
    ~Chardet()
    {
        for(CharsetChecker* f:checker_collections)
        {
            delete f;
        }
    }

private:
    std::vector<CharsetChecker*> checker_collections;
};

#endif // CHARDET

