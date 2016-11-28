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
    const unsigned char* buffer = (const uchar*)str.c_str();
    int length = str.size();
    // default encoding is ascii
    iso2022_jp_pair func = {1,[](const uchar*s){return *s<=0x7F;}};
//    while(length>0)
//    {
//        auto result = check_flag(buffer);
//        if(get<0>(result)==true) // ascii or error
//        {
//             return true;
//        }
//    }
    return false;
}

tuple<bool, iso2022_jp_pair> ISO2022_JPChecker::check_flag(char *str)
{
    tuple<bool, iso2022_jp_pair> ret=make_tuple(false,iso2022_jp_pair());
//    foreach( auto x,iso2022_jp_detect)
//    {
//        string flag = x.first;
//        if(strncmp(flag.c_str(),str,flag.size()))
//        {
//            cout<< flag.c_str()<< endl;
//            ret = make_tuple(true,x.second);
//            break;
//        }
//    }
    return ret;
}

//ISO2022_JPChecker _jp = ISO2022_JPChecker();
