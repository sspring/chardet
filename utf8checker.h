#ifndef UTF8CHECKER
#define UTF8CHECKER

#include <iostream>
#include <string>
#include <map>
#include <functional>
#include "checker.h"

bool bytes_extra_check(const uchar* str,int length)  // check every byte in str
{
    // check utf8 string exclude first byte
    for(int i=0;i<length;++i)
    {
        if((str[i]&0xC0) !=0x80)
        {
            return false;
        }
    }
    return true;
}

#define multibyte_utf8(a,b,num) [](const uchar* s,int len) \
                                {return (((*s)&a)==b && len>=num && \
                                         bytes_extra_check(s+1,num-1));}

std::map<int,std::function<bool(const uchar*,int)> >utf8_detect_function={ \
                        {2,multibyte_utf8(0xE0,0xC0,2)},
                        {3,multibyte_utf8(0xF0,0xE0,3)},
                        {4,multibyte_utf8(0xF8,0xF0,4)},
                        {5,multibyte_utf8(0xFC,0xF8,5)},
                        {6,multibyte_utf8(0xFE,0xFC,6)}};

class UTF8Checker:public CharsetChecker
{
public:
    UTF8Checker()
        :CharsetChecker()
    {
        this->charset_name = "utf-8";
    }

    bool detect(std::string str)
    {
        int current_index = -1 ;
        int length = str.length();
        const uchar* buffer = (const uchar*)str.c_str();
        while(current_index+1 < length)
        {
            bool flag = false;
            for(auto& it:utf8_detect_function)
            {
                if(it.second(buffer,length-current_index-1))
                {
                    buffer += it.first;
                    current_index += it.first;
                    flag = true;
                    break;
                }
            }
            if(flag == false) break;
        }
        return (current_index+1==length);
    }
};

#endif // UTF8CHECKER

