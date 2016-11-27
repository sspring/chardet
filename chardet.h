#ifndef CHARDET
#define CHARDET

#include "checker.h"

map<string,string> charset_alians = {
        {"iso_ir 100","ascii"},  // DICOM charset
        {"iso_ir 192","utf-8"},
        {"iso 2022 ir 13","shift_jis"}};  // DICOM charset

bool check(string charset,string str)
{
    transform(charset.begin(),charset.end(),charset.begin(),::tolower);
    auto it_charset = charset_alians.find(charset);
    if(it_charset != charset_alians.end())
    {
        charset = it_charset->second;
    }
    if(CheckerBase::contains(charset))
    {
        return CheckerBase::get_checker(charset)->detect(str);
    }
    return false;
}

string detect(string str)
{
    string char_set = "unknown";
    foreach(auto& checker,CheckerBase::avaliable_checkers())
    {
        if(checker->detect(str))
        {
            char_set = checker->name;
            break;
        }
    }
    return char_set;
}
#endif // CHARDET

