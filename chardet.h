#ifndef CHARDET
#define CHARDET

#include "checker.h"
#include "asciichecker.h"
#include "gbkchecker.h"
#include "gb18030checker.h"
#include "utf8checker.h"
#include "big5checker.h"
#include "shiftjischecker.h"
#include <algorithm>

std::map<std::string,std::string> charset_alians = {
        {"ascii","ascii"},
        {"utf-8","utf-8"},
        {"gb18030","gb18030"},
        {"gbk","gbk"},
        {"big5","big5"},
        {"iso_ir 100","ascii"},  // DICOM charset
        {"iso_ir 192","utf-8"},
        {"iso 2022 ir 13","shift_jis"}};  // DICOM charset

#define charset_pair_type std::pair<std::string,CharsetChecker*>
std::list<charset_pair_type> checker_collections = {
    {_asciichecker.get_charset_name(),&_asciichecker},
    {_utf8checker.get_charset_name(),&_utf8checker},
    {_gb18030checker.get_charset_name(),&_gb18030checker},
    {_shiftjischecker.get_charset_name(),&_shiftjischecker},
    {_gbkchecker.get_charset_name(),&_gbkchecker},
    {_big5checker.get_charset_name(),&_big5checker}};


bool check(std::string charset,std::string str)
{
    std::transform(charset.begin(),charset.end(),charset.begin(),::tolower);
    auto it_charset = charset_alians.find(charset);
    if(it_charset != charset_alians.end())
    {
        std::string mapped_charset = it_charset->first;
        auto checker_it = std::find_if(checker_collections.begin(),
                                    checker_collections.end(),
                                    [mapped_charset](const charset_pair_type& x)
                                    {return mapped_charset==x.first;});
        if(checker_it != checker_collections.end())
        {
            return checker_it->second->detect(str);
        }
    }
    return false;
}

std::string detect(std::string str)
{
    std::string char_set = "unknown";
    for(auto& checker:checker_collections)
    {
        if(checker.second->detect(str))
        {
            char_set = checker.first;
            break;
        }
    }
    return char_set;
}
#endif // CHARDET

