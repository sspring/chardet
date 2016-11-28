#include "iso2022_jp.h"

map<string,iso2022_jp_pair> iso2022_jp_detect = {
    {("\x1b(B"),{1,[](const uchar* str){return true;}}},
    {("\x1b(J"),{1,[](const uchar* str){return true;}}},
    {("\x1b$@"),{2,[](const uchar* str){return true;}}},
    {("\x1b$B"),{2,[](const uchar* str){return true;}}}};

ISO2022_JPChecker::ISO2022_JPChecker()
    :CheckerBase("iso2022_jp")
{

}

bool ISO2022_JPChecker::detect(string str) const
{
    const char* buffer = str.c_str();
    // default encoding is ascii
    iso2022_jp_pair func = {1,[](const uchar*s){return *s<=0x7F;}};
    while(strlen(buffer))
    {
        auto result = check_flag(buffer);
        if(get<0>(result)) // flag detected
        {
             func = get<1>(result);
        }
        else // continue old encoding
        {
            if(func.second((const uchar*)buffer))
            {
                buffer += func.first;
            }
            else
            {
                break;
            }
        }
    }
    return (strlen(buffer)==0);
}

tuple<bool, iso2022_jp_pair> ISO2022_JPChecker::check_flag(const char *&str) const
{
    tuple<bool, iso2022_jp_pair> ret=make_tuple(false,iso2022_jp_pair());
    for(auto& x:iso2022_jp_detect)
    {
        string flag = x.first;
        if(!strncmp(flag.c_str(),(const char*)str,flag.size()))
        {
            str += flag.size();
            ret = make_tuple(true,x.second);
            break;
        }
    }
    return ret;
}

ISO2022_JPChecker _jp = ISO2022_JPChecker();
