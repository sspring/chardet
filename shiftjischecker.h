#ifndef SHIFTJISCHECKER
#define SHIFTJISCHECKER

#include <vector>
#include "checker.h"

#define ShiftJIS_func_type std::function<bool(const uchar*)>
#define ShiftJIS_one_byte_func(a,b) \
    [](const uchar* s){return *s>=a && *s<=b;}

#define ShiftJIS_two_byte_func(a,b,c,d) \
    [](const uchar* s){return *s>=a && *s<=b && s[1]>=c && s[1]<=d;}

std::vector<std::pair<int,ShiftJIS_func_type> > ShiftJIS_detect = {
        {2,ShiftJIS_two_byte_func(0x40,0x7E,0x80,0xFC)},  // make this before than 0x00,0x7F
        {2,ShiftJIS_two_byte_func(0x81,0x9F,0xE0,0xEF)},
        {1,ShiftJIS_one_byte_func(0x00,0x7F)},
        {1,ShiftJIS_one_byte_func(0xA1,0xDF)}};

class ShiftJISChecker:public CharsetChecker
{
public:
    ShiftJISChecker():
        CharsetChecker()
    {
        this->charset_name = "shift-jis";
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
            for(auto detect:ShiftJIS_detect)
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

ShiftJISChecker _shiftjischecker = ShiftJISChecker();
#endif // SHIFTJISCHECKER

