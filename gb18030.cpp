#include "gb18030.h"


#define GB18030_func_type function<bool(const unsigned char*)>

#define GB18030_two_byte_func(a,b,c,d) \
    [](const unsigned char* s){return *s>=a && *s<=b && s[1]>=c && s[1]<=d;}

#define GB18030_four_byte_func(min,max) \
    [](const unsigned char* s){return GB18030_two_byte_func(0x81,0x82,0x30,0x39)(s) && \
                             GB18030_two_byte_func(0x81,0xFE,0x30,0x39)(s+2);}

const vector<pair<int,GB18030_func_type> > GB18030_detect = {
        {1,[](const unsigned char* s){return  *s <= 0x7F;}}, // ascii
        {2,GB18030_two_byte_func(0xB0,0xF7,0xA1,0xFE)},
        {2,GB18030_two_byte_func(0x81,0xA0,0x40,0xFE)},
        {2,GB18030_two_byte_func(0xAA,0xFE,0x40,0xA0)},
        {4,GB18030_four_byte_func(0x81,0x82)},
        {4,GB18030_four_byte_func(0x95,0x98)}};


GB18030Checker::GB18030Checker():
    CheckerBase("gb18030")
{

}

bool GB18030Checker::detect(string str) const
{
    int current_index = -1;
    int length = str.length();
    const unsigned char* buffer = (const unsigned char*)str.c_str();
    while(current_index+1 < length)
    {
        bool flag = false;
        int buffer_left_length = length-current_index-1;
        for(auto detect:GB18030_detect)
        {
            if(detect.first <= buffer_left_length &&
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

GB18030Checker _gb18030checker = GB18030Checker();
