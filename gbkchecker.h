#ifndef GBKCHECKER
#define GBKCHECKER

#include "chacker.h"
#include <QDebug>

class GBKChecker:public CharacterChacker
{
public:
    GBKChecker()
        :CharacterChacker()
    {
        this->charset_name = "GBK";
    }

    bool detect(std::string str)
    {
        int current_index = -1;
        int length = str.length();
        if((length&1) == 0)  // check length first,gbk is fixed two_byte
        {
            const uchar* buffer = (const uchar*)str.c_str();
            while(current_index+1 < length)
            {
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
        }
        return (current_index+1==length);
    }
private:
    bool check_two_byte(const uchar* str)
    {
        bool first_byte_valid = *str>=0x81 && *str<=0xFE;
        ++ str;  // let check second byte
        bool second_byte_valid = *str>=40 && *str<=0xFE && \
                                *str!=0x7F;
        return first_byte_valid&&second_byte_valid;
    }
};

#endif // GBKCHECKER

