#ifndef GB18030CHECKER
#define GB18030CHECKER

#include <vector>
#include <functional>
#include "chacker.h"

#define func_type std::function<bool(const uchar*)>

#define two_byte_func(a,b,c,d) \
    [](const uchar* s){return *s>=a && *s<=b && s[1]>=c && s[1]<=d;}
std::vector<func_type > two_byte_detect = {
        two_byte_func(0xB0,0xF7,0xA1,0xFE),
        two_byte_func(0x81,0xA0,0x40,0xFE),
        two_byte_func(0xAA,0xFE,0x40,0xA0)};

#define four_byte_func(min,max) \
    [](const uchar* s){return two_byte_func(0x81,0x82,0x30,0x39)(s) && \
                             two_byte_func(0x81,0xFE,0x30,0x39)(s+2);}
std::vector<func_type > four_byte_detect = {
    four_byte_func(0x81,0x82),
    four_byte_func(0x91,0x98)};

class GB18030Checker:public CharacterChacker
{
public:
    GB18030Checker():
        CharacterChacker()
    {
        this->charset_name = "GB18030";
    }

    bool detect(std::string str)
    {
        int current_index = -1;
        int length = str.length();
        const uchar* buffer = (const uchar*)str.c_str();
        while(current_index+1 < length)
        {
            bool flag = false;
            int buffer_left_length = length-current_index-1;
            if(buffer_left_length>=2)
            {
                for(auto f:two_byte_detect)
                {
                    if(f(buffer))
                    {
                        current_index += 2;
                        buffer += 2;
                        flag = true;
                        break;
                    }
                }
            }
            if(flag==false && buffer_left_length>=4)
            {
                for(auto f:four_byte_detect)
                {
                    if(f(buffer))
                    {
                        current_index += 4;
                        buffer += 4;
                        flag = true;
                        break;
                    }
                }
            }
            if(flag==false) break;
        }
        return (current_index+1 == length);
    }
};

#endif // GB18030CHECKER

