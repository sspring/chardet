#include "big5checker.h"

#define Big5_two_byte_func(min,max) \
    [](const unsigned char* s){unsigned short value=(*s<<8)+s[1];return value>=min && value<= max;}

std::vector<std::function<bool(const unsigned char*)>> Big5_two_byte_detect = {
        Big5_two_byte_func(0xa140,0xa3bf),
        Big5_two_byte_func(0xa440,0xc67e),
        Big5_two_byte_func(0xc940,0xf9d5)};

Big5Checker::Big5Checker():
    CheckerBase("big5")
{
}

bool Big5Checker::detect(string str) const
{
    int current_index = -1;
    int length = str.length();
    const unsigned char* buffer = (const unsigned char*)str.c_str();
    while(current_index+1 < length)
    {
        if(*buffer <= 0x7F)
        {
            current_index += 1;
            buffer += 1;
        }
        if(check_two_bytes(buffer))
        {
            current_index += 2;
            buffer += 2;
        }
        else
        {
            break;
        }
    }
    return (current_index+1 == length);
}

bool Big5Checker::check_two_bytes(const unsigned char *buffer) const
{
    for(auto f:Big5_two_byte_detect)
    {
        if(f(buffer))
        {
            return true;
        }
    }
    return false;
}
