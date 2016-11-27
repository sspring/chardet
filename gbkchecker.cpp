#include "gbkchecker.h"

GBKChecker::GBKChecker()
    :CheckerBase("gbk")
{
}

bool GBKChecker::detect(string str) const
{
    int current_index = -1;
    int length = str.length();
    const unsigned char* buffer = (const unsigned char*)str.c_str();
    while(current_index+1 < length)
    {
        if(*buffer <= 0x7F) // ascii
        {
            current_index += 1;
            buffer += 1;
        }
        if(check_two_byte(buffer))
        {
            current_index += 2;
            buffer += 2;
        }
        else
        {
            break;   // error occured!
        }
    }
    return (current_index+1==length);
}

bool GBKChecker::check_two_byte(const unsigned char *str) const
{
    bool first_byte_valid = *str>=0x81 && *str<=0xFE;
    ++ str;  // let check second byte
    bool second_byte_valid = *str>=40 && *str<=0xFE && \
            *str!=0x7F;
    return first_byte_valid&&second_byte_valid;
}

