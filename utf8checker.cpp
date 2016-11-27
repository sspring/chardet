#include "utf8checker.h"

bool bytes_extra_check(const unsigned char* str,int length)  // check every byte in str
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

#define multibyte_utf8(a,b,num) [](const unsigned char* s,int len) \
                                {return (((*s)&a)==b && len>=num && \
                                         bytes_extra_check(s+1,num-1));}

std::map<int,std::function<bool(const unsigned char*,int)> >utf8_detect_function={ \
                        {1,multibyte_utf8(0x80,0x00,1)}, // ascii
                        {2,multibyte_utf8(0xE0,0xC0,2)},
                        {3,multibyte_utf8(0xF0,0xE0,3)},
                        {4,multibyte_utf8(0xF8,0xF0,4)},
                        {5,multibyte_utf8(0xFC,0xF8,5)},
                        {6,multibyte_utf8(0xFE,0xFC,6)}};


UTF8Checker::UTF8Checker()
    :CheckerBase("utf-8")
{

}

bool UTF8Checker::detect(string str) const
{
    int current_index = -1 ;
    int length = str.length();
    const unsigned char* buffer = (const unsigned char*)str.c_str();
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
