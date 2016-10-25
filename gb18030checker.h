#ifndef GB18030CHECKER
#define GB18030CHECKER

#include "checker.h"
#include <vector>
#include <functional>

#define GB18030_func_type std::function<bool(const uchar*)>

#define GB18030_two_byte_func(a,b,c,d) \
    [](const uchar* s){return *s>=a && *s<=b && s[1]>=c && s[1]<=d;}

#define GB18030_four_byte_func(min,max) \
    [](const uchar* s){return GB18030_two_byte_func(0x81,0x82,0x30,0x39)(s) && \
                             GB18030_two_byte_func(0x81,0xFE,0x30,0x39)(s+2);}

std::vector<std::pair<int,GB18030_func_type> > GB18030_detect = {
        {2,GB18030_two_byte_func(0xB0,0xF7,0xA1,0xFE)},
        {2,GB18030_two_byte_func(0x81,0xA0,0x40,0xFE)},
        {2,GB18030_two_byte_func(0xAA,0xFE,0x40,0xA0)},
        {4,GB18030_four_byte_func(0x81,0x82)},
        {4,GB18030_four_byte_func(0x91,0x98)}};

class GB18030Checker:public CharsetChecker
{
public:
    GB18030Checker():
        CharsetChecker()
    {
        this->charset_name = "gb18030";
    }

    bool detect(std::string str) const
    {
        int current_index = -1;
        int length = str.length();
        const uchar* buffer = (const uchar*)str.c_str();
        while(current_index+1 < length)
        {
            bool flag = false;
            int buffer_left_length = length-current_index-1;
            for(auto detect:GB18030_detect)
            {
                if(detect.first >= buffer_left_length &&
                        detect.second(buffer))
                {
                    current_index += detect.first;
                    buffer += detect.first;
                    flag = true;
                    break;
                }
            }
            if(flag==false) break;
        }
        return (current_index+1 == length);
    }
};

GB18030Checker _gb18030checker = GB18030Checker();

#endif // GB18030CHECKER

